static bool FX_EXAMPLE_CLOSE = false;

#if defined(FX_DX11_EXAMPLE)
static ID3D11Device* FX_DX11_DEVICE = NULL;
static ID3D11DeviceContext* FX_DX11_DEVICE_CTX = NULL;
static ID3D11SwapChain* FX_DX11_SWAP_CHAIN = NULL;
static ID3D11Texture2D* FX_DX11_RENDER_TARGET = NULL;
static ID3D11RenderTargetView* FX_DX11_RENDER_TARGET_VIEW = NULL;
static ID3D11Texture2D* FX_DX11_RENDER_TARGET_DEPTH = NULL;
static ID3D11RenderTargetView* FX_DX11_RENDER_TARGET_VIEW_DEPTH = NULL;
static LRESULT CALLBACK _fx_dx11_winproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE: FX_EXAMPLE_CLOSE = true; return FALSE;
        case WM_ERASEBKGND: return TRUE;
        default: break;
    }
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
#else
static GLFWwindow* FX_EXAMPLE_WINDOW;
#endif

static void example(uint32_t width, uint32_t height, const char* title) {
#if defined(FX_DX11_EXAMPLE)
    WNDCLASSW wc = {};
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
    wc.lpfnWndProc = (WNDPROC) d3d11_winproc,
    wc.hInstance = GetModuleHandleW(NULL),
    wc.hCursor = LoadCursor(NULL, IDC_ARROW),
    wc.lpszClassName = L"FX_DX11_EXAMPLE"
    RegisterClassW(&wc);

    DWORD style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX;
    DWORD ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
    RECT rect = { 0, 0, width, height };
    AdjustWindowRectEx(&rect, style, FALSE, ex_style);
    const int adjusted = rect.right - rect.left;
    const int win_height = rect.bottom - rect.top;
    hwnd = CreateWindowExW(ex_style, wc.lpszClassName, title, style, CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOW);

    DXGI_SWAP_CHAIN_DESC swap_chain_desc;
    swap_chain_desc.BufferCount = 1;
    swap_chain_desc.BufferDesc.Width = width;
    swap_chain_desc.BufferDesc.Height = height;
    swap_chain_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swap_chain_desc.BufferDesc.RefreshRate.Numerator = 60;
    swap_chain_desc.BufferDesc.RefreshRate.Denominator = 1;
    swap_chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swap_chain_desc.OutputWindow = GetActiveWindow();
    swap_chain_desc.SampleDesc.Count = 1;
    swap_chain_desc.SampleDesc.Quality = D3D11_STANDARD_MULTISAMPLE_PATTERN;
    swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    swap_chain_desc.Windowed = TRUE;
    UINT flags = D3D11_CREATE_DEVICE_DEBUG;

    D3D_FEATURE_LEVEL level;
    HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, flags, NULL, 0, D3D11_SDK_VERSION, &swap_chain_desc, &FX_DX11_SWAP_CHAIN, &FX_DX11_DEVICE, &level, &FX_DX11_DEVICE_CTX);
    FX_ASSERT(SUCCEEDED(hr));

    hr = IDXGISwapChain_GetBuffer(FX_DX11_SWAP_CHAIN, &IID_ID3D11Texture2D, (LPVOID*) &FX_DX11_RENDER_TARGET);
    FX_ASSERT(SUCCEEDED(hr));
    hr = IDXGIDevice_CreateRenderTargetView(FX_DX11_RENDER_TARGET, (ID3D11Resource*) FX_DX11_RENDER_TARGET, NULL, &FX_DX11_RENDER_TARGET_VIEW);
    FX_ASSERT(SUCCEEDED(hr));

    D3D11_TEXTURE2D_DESC depth_stencil_desc;
    depth_stencil_desc.Width = width;
    depth_stencil_desc.Height = height;
    depth_stencil_desc.MipLevels = 1;
    depth_stencil_desc.ArraySize = 1;
    depth_stencil_desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depth_stencil_desc.SampleDesc = swap_chain_desc.SampleDesc;
    depth_stencil_desc.Usage = D3D11_USAGE_DEFAULT;
    depth_stencil_desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    hr = ID3D11Device_CreateTexture2D(device, &depth_stencil_desc, NULL, &FX_DX11_RENDER_TARGET_DEPTH);
    FX_ASSERT(SUCCEEDED(hr));

    D3D11_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_desc = {};
    depth_stencil_view_desc.Format = depth_stencil_desc.Format,
    depth_stencil_view_desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    hr = ID3D11Device_CreateDepthStencilView(device, (ID3D11Resource*) FX_DX11_RENDER_TARGET_DEPTH, &depth_stencil_view_desc, &FX_DX11_RENDER_TARGET_VIEW_DEPTH);
    FX_ASSERT(SUCCEEDED(hr));

    float colour[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    res->ctx->ClearRenderTargetView(res->default_pass.rtv, colour);
    res->swap_chain->Present(1, 0);
#else
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    FX_EXAMPLE_WINDOW = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(FX_EXAMPLE_WINDOW);
    glfwSwapInterval(1);
#endif
}

bool example_should_close() {
#if defined(FX_DX11_EXAMPLE)
    return FX_EXAMPLE_CLOSE;
#else
    return glfwWindowShouldClose(FX_EXAMPLE_WINDOW);
#endif
}
