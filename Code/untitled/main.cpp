#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);
#define ID_MODAL_MSG 1
#define ID_MODELESS_MSG 2
#define ID_MULTIPLE_MSG 3

HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    WNDCLASS wc = {0};
    wc.lpfnWndProc = MainWinProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = static_cast<LPCSTR>("BasicWinApiClass");

    if (!RegisterClass(&wc))
        return FALSE;

    HWND hWnd = CreateWindow(reinterpret_cast<LPCSTR>(L"BasicWinApiClass"),
                             reinterpret_cast<LPCSTR>(L"Basic WinAPI Example"), WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, hInstance, NULL);

    if (!hWnd)
        return FALSE;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

void CreateMessageBox(HWND hWnd, LPCWSTR text, const CHAR *caption, UINT type) {
    MessageBox(hWnd, reinterpret_cast<LPCSTR>(text), (caption), type);
}

LRESULT CALLBACK MainWinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE: {
            CreateWindow(reinterpret_cast<LPCSTR>(L"BUTTON"), reinterpret_cast<LPCSTR>(L"Modal Message Box"), WS_VISIBLE | WS_CHILD, 50, 50, 150, 30, hWnd, (HMENU)ID_MODAL_MSG, hInst, NULL);
            CreateWindow(reinterpret_cast<LPCSTR>(L"BUTTON"), reinterpret_cast<LPCSTR>(L"Modeless Message Box"), WS_VISIBLE | WS_CHILD, 50, 100, 150, 30, hWnd, (HMENU)ID_MODELESS_MSG, hInst, NULL);
            CreateWindow(reinterpret_cast<LPCSTR>(L"BUTTON"), reinterpret_cast<LPCSTR>(L"Multiple Message Box"), WS_VISIBLE | WS_CHILD, 50, 150, 150, 30, hWnd, (HMENU)ID_MULTIPLE_MSG, hInst, NULL);
            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case ID_MODAL_MSG:
                    CreateMessageBox(hWnd, L"This is a modal message box!", reinterpret_cast<const CHAR *>(L"Modal"), MB_OK | MB_ICONINFORMATION);
                    break;
                case ID_MODELESS_MSG:
                    CreateMessageBox(hWnd, L"This is a modeless message box!",
                                     reinterpret_cast<const CHAR *>(L"Modeless"), MB_MODEMASK);
                    break;
                case ID_MULTIPLE_MSG:
                    for (int i = 0; i < 3; ++i)
                        CreateMessageBox(hWnd, L"Multiple Message Box!", reinterpret_cast<const CHAR *>(L"Multiple"), MB_OK | MB_ICONWARNING);
                    break;
            }
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
