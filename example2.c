#include <windows.h>
#include <stdio.h>

#define ID_EDIT1 101
#define ID_EDIT2 102
#define ID_BUTTON 103
#define ID_RESULT 104

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hEdit1, hEdit2, hButton, hResult;

    switch (uMsg) {
        case WM_CREATE: {
            hEdit1 = CreateWindow(
                "EDIT",
                "",
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                10, 10, 160, 25,
                hwnd, (HMENU)ID_EDIT1, NULL, NULL
            );

            hEdit2 = CreateWindow(
                "EDIT",
                "",
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                10, 40, 160, 25,
                hwnd, (HMENU)ID_EDIT2, NULL, NULL
            );

            hButton = CreateWindow(
                "BUTTON",
                "Spoji",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                10, 70, 75, 30,
                hwnd, (HMENU)ID_BUTTON, NULL, NULL
            );

            hResult = CreateWindow(
                "EDIT",
                "",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
                10, 110, 160, 25,
                hwnd, (HMENU)ID_RESULT, NULL, NULL
            );

            break;
        }

        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_BUTTON) {
                char text1[256], text2[256], result[512];

                GetWindowText(hEdit1, text1, sizeof(text1));
                GetWindowText(hEdit2, text2, sizeof(text2));

                snprintf(result, sizeof(result), "%s %s", text1, text2);

                SetWindowText(hResult, result);
            }
            break;
        }

        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}





INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "SampleWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Ponavljac",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 200, 200,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
