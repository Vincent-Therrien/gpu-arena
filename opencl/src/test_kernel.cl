__kernel void add(__global float* buffer) {
    buffer[get_global_id(0)] += 2.0;
}
