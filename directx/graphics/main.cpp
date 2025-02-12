#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <iostream>

// Link required libraries
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

// Direct3D globals
IDXGISwapChain* swapChain = nullptr;
ID3D11Device* device = nullptr;
ID3D11DeviceContext* deviceContext = nullptr;
ID3D11RenderTargetView* renderTargetView = nullptr;
ID3D11VertexShader* vertexShader = nullptr;
ID3D11PixelShader* pixelShader = nullptr;
ID3D11InputLayout* inputLayout = nullptr;
ID3D11Buffer* vertexBuffer = nullptr;

// Vertex structure
struct Vertex {
    DirectX::XMFLOAT3 position;
    DirectX::XMFLOAT4 color;
};

// Shader source
const char* vertexShaderSource = R"(
    struct VS_INPUT {
        float3 pos : POSITION;
        float4 color : COLOR;
    };

    struct PS_INPUT {
        float4 pos : SV_POSITION;
        float4 color : COLOR;
    };

    PS_INPUT main(VS_INPUT input) {
        PS_INPUT output;
        output.pos = float4(input.pos, 1.0);
        output.color = input.color;
        return output;
    }
)";

const char* pixelShaderSource = R"(
    struct PS_INPUT {
        float4 pos : SV_POSITION;
        float4 color : COLOR;
    };

    float4 main(PS_INPUT input) : SV_TARGET {
        return input.color;
    }
)";

// Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Compile shader
ID3DBlob* CompileShader(const char* source, const char* entryPoint, const char* target) {
    ID3DBlob* shaderBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;
    if (FAILED(D3DCompile(source, strlen(source), nullptr, nullptr, nullptr, entryPoint, target, 0, 0, &shaderBlob, &errorBlob))) {
        if (errorBlob) {
            std::cerr << (char*)errorBlob->GetBufferPointer() << std::endl;
            errorBlob->Release();
        }
        return nullptr;
    }
    return shaderBlob;
}

// Initialize Direct3D
bool InitD3D(HWND hwnd) {
    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hwnd;
    scd.SampleDesc.Count = 1;
    scd.Windowed = TRUE;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
        D3D11_SDK_VERSION, &scd, &swapChain, &device, nullptr, &deviceContext))) {
        return false;
    }

    D3D11_VIEWPORT viewport = {};
    viewport.Width = 800.0f;
    viewport.Height = 600.0f;
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;

    deviceContext->RSSetViewports(1, &viewport);

    // Get back buffer
    ID3D11Texture2D* backBuffer = nullptr;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();
    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    // Compile shaders
    ID3DBlob* vsBlob = CompileShader(vertexShaderSource, "main", "vs_5_0");
    ID3DBlob* psBlob = CompileShader(pixelShaderSource, "main", "ps_5_0");

    if (!vsBlob || !psBlob) return false;

    // Create shaders
    device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader);
    device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader);

    // Input layout
    D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };
    device->CreateInputLayout(layoutDesc, 2, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &inputLayout);
    deviceContext->IASetInputLayout(inputLayout);

    vsBlob->Release();
    psBlob->Release();

    // Triangle vertices
    Vertex vertices[] = {
        {{  0.0f,  0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f }},
        {{  0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f }},
        {{ -0.5f, -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f }}
    };

    // Create vertex buffer
    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(vertices);
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = { vertices };
    device->CreateBuffer(&bufferDesc, &initData, &vertexBuffer);

    return true;
}

// Render function
void Render() {
    float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);

    // Set shaders
    deviceContext->VSSetShader(vertexShader, nullptr, 0);
    deviceContext->PSSetShader(pixelShader, nullptr, 0);

    // Bind vertex buffer
    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // Draw triangle
    deviceContext->Draw(3, 0);

    swapChain->Present(1, 0);
}

// Cleanup
void CleanupD3D() {
    if (swapChain) swapChain->Release();
    if (renderTargetView) renderTargetView->Release();
    if (deviceContext) deviceContext->Release();
    if (device) device->Release();
    if (vertexShader) vertexShader->Release();
    if (pixelShader) pixelShader->Release();
    if (inputLayout) inputLayout->Release();
    if (vertexBuffer) vertexBuffer->Release();
}

// Main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Direct3DWindowClass";
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "Direct3D Triangle", WS_OVERLAPPEDWINDOW,
        100, 100, 800, 600, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow);

    if (!InitD3D(hwnd)) return -1;

    MSG msg = {};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            Render();
        }
    }

    CleanupD3D();
    return 0;
}
