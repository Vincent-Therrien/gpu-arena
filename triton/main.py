"""Calculate a sum reduction and a softmax function with Triton."""

import triton
import triton.language as tl
import torch


@triton.jit
def fold(
        x_ptr,
        middle: tl.constexpr,
        end: tl.constexpr,
        n_elements,
        BLOCK_SIZE: tl.constexpr
    ):
    """Perform one sum reduction pass.

    This function has to be separate from ``sum_reduction`` because the values
    used by the kernel change between iterations. Since Triton must compile the
    kernels before executing them, the parameters must be of type
    ``tl.constexpr``, not ``int``.

    Args:
        x_ptr: Pointer to the input tensor. Modified in place!
        middle: Half of the size of the current reduction.
        end: Size of the current reduction.
        n_elements: Total number of elements in the tensor. Can be of type
            ``int`` because it is used for masking only.
        BLOCK_SIZE: Number of elements processed by each program.
    """
    m = tl.program_id(axis=0)
    block_start = m * BLOCK_SIZE
    right_offsets = block_start + tl.arange(middle, end)
    right_x = tl.load(x_ptr + right_offsets, mask=(right_offsets < n_elements))
    left_offsets = block_start + tl.arange(0, middle)
    left_x = tl.load(x_ptr + left_offsets, mask=(left_offsets < n_elements))
    tl.store(x_ptr + left_offsets, left_x + right_x, mask=(left_offsets < n_elements))


def sum_reduction(x_ptr, n_elements, BLOCK_SIZE: tl.constexpr):
    """GPU-accelerated sum reduction.

    This function adds up the elements in an array in pairs. For instance:

    Initial array:    0  1  2  3  4  5  6  7
    First reduction:  4  6  8  10            <- (0 + 4) (1 + 5) (2 + 6) (3 + 7)
    Second reduction: 12 16
    Final reduction:  28

    Refer to the file https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
    for a detailed discussion!

    Args:
        x_ptr: Pointer to the input tensor to sum. Modified in place!
        n_elements: Total number of elements to sum.
        BLOCK_SIZE: Number of elements processed by each program.
    """
    stride = BLOCK_SIZE // 2
    while stride > 0:
        grid = (n_elements, )
        fold[grid](x_ptr, stride, stride * 2, n_elements, BLOCK_SIZE)
        stride //= 2


print("Trying out sum reduction with Triton!")
X = torch.Tensor((0, 1, 2, 3, 4, 5, 6, 7)).to('cuda')
print(f"    Input values: {X}")
sum_reduction(X, len(X), len(X))
print(f"    Output values: {X}")
print(f"    Sum: {X[0]}\n")


@triton.jit
def softmax(Y, stride_ym, stride_yn, X, stride_xm, stride_xn, N):
    """Compute a sum reduction.

    This function is taken from the blog post https://openai.com/index/triton/
    by OpenAI.

    Args:
        Y: Pointer to the output tensor.
        stride_ym: Stride in axis 0.
        stride_yn: Stride in axis 1.
        X: Pointer to the input tensor.
        stride_xm: Stride in axis 0.
        stride_xn: Stride in axis 1.
        N: Number of columns.
    """
    m = tl.program_id(0)
    BLOCK_SIZE: tl.constexpr = 1024
    n = tl.arange(0, BLOCK_SIZE)
    X = X + m * stride_xm + n * stride_xn
    x = tl.load(X, mask=n < N, other=-float('inf'))
    z = x - tl.max(x, axis=0)
    num = tl.exp(z)
    denom = tl.sum(num, axis=0)
    y = num / denom
    Y = Y + m * stride_ym + n * stride_yn
    tl.store(Y, y, mask=n < N)


print("Trying out a Softmax function with Triton!")
X = torch.normal(0, 1, size=(4, 4), device='cuda')
Y = torch.empty_like(X)
grid = (X.shape[0], )
softmax[grid](Y, Y.stride(0), Y.stride(1),
              X, X.stride(0), X.stride(1),
              X.shape[1])
print(f"Input values:\n{X}")
print(f"Output values:\n{Y}\n")
