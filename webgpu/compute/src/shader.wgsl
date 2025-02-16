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
@workgroup_size(64)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(workgroup_id) workgroup_id: vec3<u32>) {

    let index = global_id.x;
    let local_index = local_id.x;
    let workgroup_index = workgroup_id.x;

    var offset: u32 = 0;
    while (offset < 64) {
        if (local_index == 0) {
            outputBuffer.data[workgroup_index * 64] += inputBuffer.data[workgroup_index * 64 + offset];
        }
        offset += 1;
    }
    workgroupBarrier();

    offset = 64;
    while (offset < arrayLength(&inputBuffer.data)) {
        if (index == 0) {
            outputBuffer.data[0] += outputBuffer.data[offset];
        }
        offset += 64;
    }
}
