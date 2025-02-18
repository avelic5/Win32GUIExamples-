#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Postavljanje boja krugova
            HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 112, 192));
            HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            HPEN redPen = CreatePen(PS_SOLID, 3, RGB(192, 0, 0));
            HPEN yellowPen = CreatePen(PS_SOLID, 3, RGB(255, 192, 0));
            HPEN greenPen = CreatePen(PS_SOLID, 3, RGB(0, 176, 80));

            // Postavljanje koordinata i veličine krugova
            int radius = 50;
            int xOffset = 120;
            int yOffset = 60;

            // Plavi krug (gore lijevo)
            SelectObject(hdc, bluePen);
            Ellipse(hdc, 100, 100, 100 + 2 * radius, 100 + 2 * radius);

            // Crni krug (gore sredina)
            SelectObject(hdc, blackPen);
            Ellipse(hdc, 100 + xOffset, 100, 100 + xOffset + 2 * radius, 100 + 2 * radius);

            // Crveni krug (gore desno)
            SelectObject(hdc, redPen);
            Ellipse(hdc, 100 + 2 * xOffset, 100, 100 + 2 * xOffset + 2 * radius, 100 + 2 * radius);

            // Žuti krug (dolje lijevo)
            SelectObject(hdc, yellowPen);
            Ellipse(hdc, 100 + xOffset / 2, 100 + yOffset, 100 + xOffset / 2 + 2 * radius, 100 + yOffset + 2 * radius);

            // Zeleni krug (dolje desno)
            SelectObject(hdc, greenPen);
            Ellipse(hdc, 100 + 3 * xOffset / 2, 100 + yOffset, 100 + 3 * xOffset / 2 + 2 * radius, 100 + yOffset + 2 * radius);

            // Čišćenje resursa
            DeleteObject(bluePen);
            DeleteObject(blackPen);
            DeleteObject(redPen);
            DeleteObject(yellowPen);
            DeleteObject(greenPen);

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
    const char CLASS_NAME[] = "OlympicRings";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Olimpijski Znak",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
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
