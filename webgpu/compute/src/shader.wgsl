struct DataBuf {
    data: array<f32>,
}

@group(0)
@binding(0)
var<storage, read> inputBuffer: DataBuf;

@group(0)
@binding(1)
var<storage, read_write> outputBuffer: DataBuf;

@compute
@workgroup_size(1) // Todo: use higher group size
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    outputBuffer.data[global_id.x] = inputBuffer.data[global_id.x] + 42.0;
}

/*

@group(0) @binding(0)
var<storage, read> inputBuffer: array<f32>;

@group(0) @binding(1)
var<storage, read_write> outputBuffer: array<f32>;

@group(0) @binding(2)
var<workgroup> localSums: array<f32, 64>; // Workgroup shared memory

@compute @workgroup_size(64)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(workgroup_id) workgroup_id: vec3<u32>) {

    let index = global_id.x;
    let local_index = local_id.x;

    // Load element into shared memory (check bounds)
    if (index < arrayLength(&inputBuffer)) {
        localSums[local_index] = inputBuffer[index];
    } else {
        localSums[local_index] = 0.0;
    }

    workgroupBarrier(); // Ensure all threads have written their values

    // Parallel reduction sum
    var stride: u32 = 32;
    while (stride > 0) {
        if (local_index < stride) {
            localSums[local_index] += localSums[local_index + stride];
        }
        stride = stride / 2;
        workgroupBarrier(); // Synchronize after each step
    }

    // Write final sum from first thread of workgroup to output
    if (local_index == 0) {
        outputBuffer[workgroup_id.x] = localSums[0];
    }
}
*/