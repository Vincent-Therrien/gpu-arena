// Thread group size
#define GROUP_SIZE 256

// Input and output buffers
RWStructuredBuffer<float> inputBuffer : register(u0);
RWStructuredBuffer<float> outputBuffer : register(u1);

// Shared memory for local reduction
groupshared float localSum[GROUP_SIZE];

[numthreads(GROUP_SIZE, 1, 1)]
void main(uint3 threadID : SV_DispatchThreadID, uint3 groupID : SV_GroupID, uint3 localID : SV_GroupThreadID) {
    // Load data into shared memory
    localSum[localID.x] = inputBuffer[threadID.x];
    GroupMemoryBarrierWithGroupSync();

    // Parallel reduction within the group
    for (uint stride = GROUP_SIZE / 2; stride > 0; stride /= 2) {
        if (localID.x < stride) {
            localSum[localID.x] += localSum[localID.x + stride];
        }
        GroupMemoryBarrierWithGroupSync();
    }

    // Store the partial sum from each group into the output buffer
    if (localID.x == 0) {
        outputBuffer[groupID.x] = localSum[0];
    }
}
