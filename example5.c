#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int radius1 = 10; // Radijus prvog kruga
    static int radius2 = 10; // Radijus drugog kruga

    switch (uMsg)
    {
    case WM_CREATE:
        {
            // Kreiranje 9 dugmadi
            for (int i = 0; i < 9; i++)
            {
                char text[2];
                sprintf(text, "%d", i);
                CreateWindowEx(
                    0, "BUTTON", text,
                    WS_CHILD | WS_VISIBLE,
                    10 + (i % 3) * 60, 10 + (i / 3) * 60, 50, 50,
                    hwnd, (HMENU)(100 + i), ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            }
        }
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) >= 100 && LOWORD(wParam) <= 108) // Klik na dugme
        {
            int value = LOWORD(wParam) - 100; // Vrijednost na dugmetu
            radius1 = value * 10; // Ažuriranje radijusa prvog kruga
            radius2 = (8 - value) * 10; // Ažuriranje radijusa drugog kruga
            InvalidateRect(hwnd, NULL, TRUE); // Forsiranje ponovnog iscrtavanja
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Crtanje prvog kruga
            Ellipse(hdc, 150 - radius1, 200 - radius1, 150 + radius1, 200 + radius1);

            // Crtanje drugog kruga
            Ellipse(hdc, 250 - radius2, 200 - radius2, 250 + radius2, 200 + radius2);

            EndPaint(hwnd, &ps);
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
        0, CLASS_NAME, "Kruzna Testera",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
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
