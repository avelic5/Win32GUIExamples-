#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit, hButton;
    static int seconds = 0;
    static char buffer[256];

    switch (uMsg)
    {
    case WM_CREATE:
        // Kreiranje EDIT kontrola za prikaz vremena
        hEdit = CreateWindowEx(
            0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
            10, 50, 200, 20,
            hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        // Kreiranje BUTTON kontrola za pokretanje brojača
        hButton = CreateWindowEx(
            0, "BUTTON", "Kreni",
            WS_CHILD | WS_VISIBLE,
            10, 10, 80, 30,
            hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) // Klik na dugme "Kreni"
        {
            SetTimer(hwnd, 1, 1000, NULL); // Postavljanje tajmera na 1 sekundu
        }
        break;

    case WM_TIMER:
        if (wParam == 1)
        {
            seconds++;
            sprintf(buffer, "Proslo je %d sekundi", seconds);
            SetWindowText(hEdit, buffer); // Ažuriranje teksta u EDIT polju
        }
        break;

    case WM_DESTROY:
        KillTimer(hwnd, 1); // Zaustavljanje tajmera
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
        0, CLASS_NAME, "Vrijeme",
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