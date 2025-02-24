import triton
import triton.language as tl
import torch


@triton.jit
def softmax(Y, stride_ym, stride_yn, X, stride_xm, stride_xn, M, N):
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


print("Softmax:")
X = torch.normal(0, 1, size=(4, 4), device='cuda')
Y = torch.empty_like(X)
grid = (X.shape[0], )
softmax[grid](Y, Y.stride(0), Y.stride(1),
              X, X.stride(0), X.stride(1),
              X.shape[0]    , X.shape[1])
print(f"Input values:\n{X}\n")
print(f"Output values:\n{Y}\n")
