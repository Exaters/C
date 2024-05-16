#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
// Register the window class
const wchar_t CLASS_NAME[]  = L"Sample Window Class";

WNDCLASS wc = { };

wc.lpfnWndProc   = WindowProc;
wc.hInstance     = hInstance;
wc.lpszClassName = CLASS_NAME;

RegisterClass(&wc);

// Create the window
HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        L"WinAPI Basic Window",         // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
);

if (hwnd == NULL)
{
return 0;
}

ShowWindow(hwnd, nCmdShow);

// Run the message loop
MSG msg = { };
while (GetMessage(&msg, NULL, 0, 0))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}

return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
switch (uMsg)
{
case WM_CLOSE:
DestroyWindow(hwnd);
break;
case WM_DESTROY:
PostQuitMessage(0);
break;
case WM_CREATE:
// Create buttons here
CreateWindowW(L"BUTTON", L"Modal", WS_VISIBLE | WS_CHILD, 10, 10, 100, 30, hwnd, (HMENU)1, NULL, NULL);
CreateWindowW(L"BUTTON", L"Modeless", WS_VISIBLE | WS_CHILD, 120, 10, 100, 30, hwnd, (HMENU)2, NULL, NULL);
CreateWindowW(L"BUTTON", L"Multiple", WS_VISIBLE | WS_CHILD, 230, 10, 100, 30, hwnd, (HMENU)3, NULL, NULL);
break;
case WM_COMMAND:
switch (LOWORD(wParam))
{
case 1:
MessageBox(hwnd, L"Modal Message", L"Modal", MB_OK | MB_ICONINFORMATION);
break;
case 2:
MessageBox(hwnd, L"Modeless Message", L"Modeless", MB_OK | MB_ICONINFORMATION | MB_MODELESS);
break;
case 3:
MessageBox(hwnd, L"Multiple Message", L"Multiple", MB_OK | MB_ICONINFORMATION);
MessageBox(hwnd, L"Another Multiple Message", L"Multiple", MB_OK | MB_ICONINFORMATION);
break;
}
break;
default:
return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
return 0;
}
