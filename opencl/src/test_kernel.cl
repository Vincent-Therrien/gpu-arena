__kernel void add(__global float* buffer, float scalar) {
    buffer[get_global_id(0)] += scalar;
}
