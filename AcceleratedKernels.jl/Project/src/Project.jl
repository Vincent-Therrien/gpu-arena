import AcceleratedKernels as AK
using CUDA, GPUArrays

# Define a reduce function used to sum up all two elements.
f = (a, b) -> a + b

# Define a neutral element for the operation. This is used when there are more threads than elements
# to reduce. Some elements will be reduced with `0` when they cannot be paired with another element.
GPUArrays.neutral_element(::typeof(f), ::Type{T}) where T = zero(T)

# Create a vector of elements comprised within the range [-1.0, 1.0].
v = CuArray(rand(Float32, 10000) * 2.0 .- 1.0)

# Apply the function f to elements in v to produce the result. `init` defines the initial value of
# the reduction.
vsum = AK.reduce(f, v; init=zero(eltype(v)))

# The result of the sum follows a shifted Irwin–Hall distribution. Since there are 10000 elements,
# std = sqrt(10000 / 3) ~ 57.7. So the sum will mostly fall in the range [-58, 58].
print(vsum)
