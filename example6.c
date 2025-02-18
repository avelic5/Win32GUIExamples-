#include <windows.h>
#include <stdio.h>
LPCTSTR ClsName = "BasicApp";
LPCTSTR WndName = "Tasteri";
char * note[7]={"Do","Re","Mi","Fa","So","La","Si"};
HWND  hDugme[7],hEdit=NULL;
char natpis[50];
LRESULT CALLBACK WndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM
lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    int i;
    switch(Msg)    {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        break;
    case WM_COMMAND:
        GetWindowText((HWND)lParam,natpis,40);
        InvalidateRect(hWnd,NULL,TRUE);
        break;
    case WM_PAINT:
        hdc=BeginPaint(hWnd,&ps);
        TextOut(hdc,0,200,natpis,40);
        EndPaint(hWnd,&ps);
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
    return 0;
}


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
               LPSTR lpCmdLine, int nCmdShow){
 MSG        Msg;
 HWND       hWnd;
 WNDCLASSEX WndClsEx;
 WndClsEx.cbSize        = sizeof(WNDCLASSEX);
 WndClsEx.style         = CS_HREDRAW | CS_VREDRAW;
 WndClsEx.lpfnWndProc   = WndProcedure;
 WndClsEx.cbClsExtra    = 0;
 WndClsEx.cbWndExtra    = 0;
 WndClsEx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
 WndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
 WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
 WndClsEx.lpszMenuName  = NULL;
 WndClsEx.lpszClassName = ClsName;
 WndClsEx.hInstance     = hInstance;
 WndClsEx.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
 RegisterClassEx(&WndClsEx);
 hWnd = CreateWindow(ClsName,WndName,WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
        NULL, NULL, hInstance, NULL);
        char ime[5];
        int i;
        for (i=0; i<4; i++) {
      hDugme[i] = CreateWindow("BUTTON",note[i],WS_CHILD |WS_VISIBLE,
           30*i, 30, 30, 80,hWnd, NULL, hInstance, NULL);
        }
        for (i=4; i<7; i++) {
      hDugme[i] = CreateWindow("BUTTON",note[i],WS_CHILD |WS_VISIBLE,
           30*(i-4), 110, 30, 80,hWnd, NULL, hInstance, NULL);
        }
        SetWindowText(hEdit,"no");
        UpdateWindow(hWnd);

 ShowWindow(hWnd, SW_SHOWNORMAL);
        while( GetMessage(&Msg, NULL, 0, 0) ) {
             TranslateMessage(&Msg);
             DispatchMessage(&Msg);
 }
        return Msg.wParam;
}