#include <d3d11.h>
#include <d3dcompiler.h>
#include <vector>
#include <iostream>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define GROUP_SIZE 256

// Error checking macro
#define HR_CHECK(hr) if (FAILED(hr)) { std::cerr << "D3D Error at line " << __LINE__ << std::endl; return -1; }

int main() {
    // Sample data (must be a multiple of GROUP_SIZE for simplicity)
    const int dataSize = 1024;
    std::vector<float> data(dataSize, 1.0f); // Fill with ones for easy sum verification
    int numGroups = dataSize / GROUP_SIZE;

    // Step 1: Initialize Direct3D
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* context = nullptr;
    D3D_FEATURE_LEVEL featureLevel;
    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, &featureLevel, &context);

    // Step 2: Compile Compute Shader
    ID3DBlob* csBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;
    HRESULT hr = D3DCompileFromFile(L"sum.hlsl", nullptr, nullptr, "main", "cs_5_0", 0, 0, &csBlob, &errorBlob);
    if (FAILED(hr)) {
        if (errorBlob) std::cerr << (char*)errorBlob->GetBufferPointer();
        return -1;
    }

    // Step 3: Create Compute Shader
    ID3D11ComputeShader* computeShader = nullptr;
    HR_CHECK(device->CreateComputeShader(csBlob->GetBufferPointer(), csBlob->GetBufferSize(), nullptr, &computeShader));
    csBlob->Release();
std::cout << "*" << std::endl;
    // Step 4: Create Buffers (Input & Output)
    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = dataSize * sizeof(float);
    bufferDesc.BindFlags = D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_SHADER_RESOURCE;
    bufferDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
    bufferDesc.StructureByteStride = sizeof(float);

    D3D11_SUBRESOURCE_DATA initData = { data.data(), 0, 0 };
    ID3D11Buffer* inputBuffer = nullptr;
    HR_CHECK(device->CreateBuffer(&bufferDesc, &initData, &inputBuffer));

    bufferDesc.ByteWidth = numGroups * sizeof(float);
    ID3D11Buffer* outputBuffer = nullptr;
    HR_CHECK(device->CreateBuffer(&bufferDesc, nullptr, &outputBuffer));
std::cout << "*" << std::endl;
    // Step 5: Create Unordered Access Views (UAV)
    D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
    uavDesc.Format = DXGI_FORMAT_UNKNOWN;
    uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
    uavDesc.Buffer.NumElements = dataSize;
    ID3D11UnorderedAccessView* inputUAV = nullptr;
    HR_CHECK(device->CreateUnorderedAccessView(inputBuffer, &uavDesc, &inputUAV));

    uavDesc.Buffer.NumElements = numGroups;
    ID3D11UnorderedAccessView* outputUAV = nullptr;
    HR_CHECK(device->CreateUnorderedAccessView(outputBuffer, &uavDesc, &outputUAV));
std::cout << "*" << std::endl;
    // Step 6: Run the Compute Shader
    context->CSSetShader(computeShader, nullptr, 0);
    context->CSSetUnorderedAccessViews(0, 1, &inputUAV, nullptr);
    context->CSSetUnorderedAccessViews(1, 1, &outputUAV, nullptr);
    context->Dispatch(numGroups, 1, 1);
std::cout << "*" << std::endl;
    // Step 7: Read Back Result
    std::vector<float> partialSums(numGroups);
    D3D11_BUFFER_DESC readbackDesc = {};
    readbackDesc.Usage = D3D11_USAGE_STAGING;
    readbackDesc.ByteWidth = numGroups * sizeof(float);
    readbackDesc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    readbackDesc.StructureByteStride = sizeof(float);
    ID3D11Buffer* readbackBuffer = nullptr;
    HR_CHECK(device->CreateBuffer(&readbackDesc, nullptr, &readbackBuffer));

    context->CopyResource(readbackBuffer, outputBuffer);
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    HR_CHECK(context->Map(readbackBuffer, 0, D3D11_MAP_READ, 0, &mappedResource));
    memcpy(partialSums.data(), mappedResource.pData, numGroups * sizeof(float));
    context->Unmap(readbackBuffer, 0);
std::cout << "*" << std::endl;
    // Step 8: Compute Final Sum on CPU
    float finalSum = 0.0f;
    for (float val : partialSums) {
        finalSum += val;
    }

    std::cout << "Sum of elements: " << finalSum << std::endl; // Expected: 1024

    // Cleanup
    inputUAV->Release();
    outputUAV->Release();
    inputBuffer->Release();
    outputBuffer->Release();
    readbackBuffer->Release();
    computeShader->Release();
    context->Release();
    device->Release();

    return 0;
}
