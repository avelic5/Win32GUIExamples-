#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit;

    switch (uMsg)
    {
    case WM_CREATE:
        // Kreiranje unosa (EDIT kontrola)
        hEdit = CreateWindowEx(
            0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 10, 200, 20,
            hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        // Kreiranje dugmeta (BUTTON kontrola)
        CreateWindowEx(
            0, "BUTTON", "Prikaz",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 50, 80, 30,
            hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) // Klik na dugme
        {
            char text[256];
            GetWindowText(hEdit, text, sizeof(text)); // Preuzimanje teksta iz unosa

            MessageBox(hwnd, text, "Poruka", MB_OK); // Prikaz teksta u poruci
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Zadatak 12",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 150,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}