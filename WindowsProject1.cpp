#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
#include <time.h>
#include<stdio.h>
#include <mmsystem.h>
#include <conio.h>
#include "framework.h"
#include <iostream>
#include <string>
#pragma comment(lib, "winmm.lib")


#define SOUND_FILE_NAME "opening.wav"
#define SOUND_FILE_BGM1 "warriors.wav"
#define SOUND_FILE_BGM2 "worldmap.wav"
#define SOUND_FILE_BGM3 "bgmmain.wav"

#define SOUND_FUN "fun.wav"

#define SOUND_SHOUTING_CLALP1 "shouting_clap1.wav"
#define SOUND_SHOUTING_CLALP2 "shouting_clap2.wav"
#define SOUND_SHOUTING_CLALP3 "shouting_clap3.wav"




#define R 10
#define M 20
#define MAX_LOADSTRING 100


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);

LRESULT CALLBACK PopupProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK KeyProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK DoKeyProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK Event1Proc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK Event2Proc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK Man1Proc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK Man2Proc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
void MakeRect(LPRECT lpRect, int right, int top, int left, int bottom);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)
    // UNICODE 사용시 wWinMain() 형태    
    // hPrevInstance 이전 인스턴스 항상 0값
    // lpszCmdLine > 외부에서 (내부로) 입력받는 변수
    // nCmdShow 윈도우 출력 형태에 관련한 값
{



    HWND     hwnd;
    MSG       msg;
    WNDCLASS WndClass;

    hInst = hInstance;

    WndClass.style = CS_HREDRAW | CS_VREDRAW;   //height, vertical redraw
    WndClass.lpfnWndProc = WndProc;      // Proc 설정
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   // 형변환
    WndClass.lpszMenuName = MAKEINTRESOURCE(IDC_WINDOWSPROJECT1);
    // resource.h 파일 에서 메뉴이름 확인 109번
    WndClass.lpszClassName = _T("Window Class Name");
    RegisterClass(&WndClass);      // WndClass 등록



    hwnd = CreateWindow(_T("Window Class Name"),
        _T("다같이 마셔마셔-주루마블"),      // 타이틀바, 학번이름 체크
        WS_OVERLAPPEDWINDOW,      // 윈도우 스타일
        300, 200,               // 창출력좌표 x, y 
        1300, 660,               // 창크기 x, y축
        NULL,                  // 부모 윈도우
        NULL,                  // 메뉴바 핸들
        hInstance,               // 인스턴스
        NULL                  // 여분, NULL
    );
    ShowWindow(hwnd, nCmdShow);      // 윈도우 출력, WM_PAINT 출력내용 가져옴
    UpdateWindow(hwnd);            // WM_PAINT 출력내용 발생해서 출력하도록
                  // hwnd 핸들을 통해 보여주고 갱신

    //ShowWindow(hwnd, SW_SHOW);   // 위와 같음
    //UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))   // 메시지 큐의 메시지를 가져옴
    {
        TranslateMessage(&msg);      // 키입력에 반응하는 메시지 변환, WM_KEYDOWN (키가 눌릴때) WM_CHAR 메시지 발생
        DispatchMessage(&msg);      // WndProc() 함수 호출과 WndProc()으로 메세지 전달
    }                        // 종료는 WM_QUIT 발생할때 FALSE 리턴하면서 종료
    return (int)msg.wParam;         // wParam, lParam 윈도우 크기가 어떻게 변했는지, 변경된 클라이언트, 키보드, 마우스 값

}

LRESULT CALLBACK DoKeyProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

    HDC hdc, memdc;
    PAINTSTRUCT ps;
    static HBITMAP hBitmapMAN1, oldBitMAN;
    switch (iMsg) {
    case WM_CREATE:
        hBitmapMAN1 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_DoKey));
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        memdc = CreateCompatibleDC(hdc);
        oldBitMAN = (HBITMAP)SelectObject(memdc, hBitmapMAN1);
        BitBlt(hdc, 0, 0, 600, 450, memdc, 0, 0, SRCCOPY);
        SelectObject(memdc, oldBitMAN);
        DeleteDC(memdc);
        EndPaint(hwnd, &ps);
        break;

    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

LRESULT CALLBACK Man1Proc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

    HDC hdc, memdc;
    PAINTSTRUCT ps;
    static HBITMAP hBitmapMAN1, oldBitMAN;
    switch (iMsg) {
    case WM_CREATE:
        hBitmapMAN1 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_MAN1));
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        memdc = CreateCompatibleDC(hdc);
        oldBitMAN = (HBITMAP)SelectObject(memdc, hBitmapMAN1);
        BitBlt(hdc, 0, 0, 600, 450, memdc, 0, 0, SRCCOPY);
        SelectObject(memdc, oldBitMAN);
        DeleteDC(memdc);
        EndPaint(hwnd, &ps);
        break;

    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

LRESULT CALLBACK Man2Proc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

    HDC hdc, memdc;
    PAINTSTRUCT ps;
    static HBITMAP hBitmapMAN2, oldBitMAN;
    switch (iMsg) {
    case WM_CREATE:
        hBitmapMAN2 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_MAN2));
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        memdc = CreateCompatibleDC(hdc);
        oldBitMAN = (HBITMAP)SelectObject(memdc, hBitmapMAN2);
        BitBlt(hdc, 0, 0, 600, 450, memdc, 0, 0, SRCCOPY);
        SelectObject(memdc, oldBitMAN);
        DeleteDC(memdc);
        EndPaint(hwnd, &ps);
        break;

    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);

}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BINGO));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCE(IDC_BINGO);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

#include <math.h>
#define BSIZE 20

void MakeRect(LPRECT lpRect, int right, int top, int left, int bottom)
{
    lpRect->right = right;
    lpRect->top = top;
    lpRect->left = left;
    lpRect->bottom = bottom;
}



#define IDC_BUTTON 100 // 버튼 콘트롤의 ID

MDICREATESTRUCT mdicreate;

void Animation(int xPos, int yPos, HDC hdc)
{
    HDC memdc;
    HBITMAP RunBit[10], hBit, oldBit;
    static int count;
    int i;
    count++;
    count = count % 10;
    RunBit[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)); // f o r 

    RunBit[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14)); //
    RunBit[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)); //
    RunBit[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14)); //
    RunBit[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)); //
    RunBit[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14)); //
    RunBit[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)); //
    RunBit[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14)); //
    RunBit[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)); //
    RunBit[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14)); //
    memdc = CreateCompatibleDC(hdc);
    hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
    oldBit = (HBITMAP)SelectObject(memdc, hBit);
    StretchBlt(hdc, 550, 100, 200, 200, memdc, 0, 0, 200, 200, SRCCOPY);
    SelectObject(memdc, RunBit[count]);
    StretchBlt(hdc, 550, 100, 200, 200, memdc, 0, 0, 200, 200, SRCCOPY);
    SelectObject(memdc, oldBit);
    for (i = 0; i < 10; i++)
        DeleteObject(RunBit[i]);
    DeleteDC(memdc);
    DeleteObject(hBit);
}


LRESULT CALLBACK PopupProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc, memdc, hdc2;
    HWND hButton, hHelp;
    PAINTSTRUCT ps;
    RECT rect;
    HFONT hFont, OldFont;
    static HBITMAP hBitmap, hBitmap2, hBitmap3, hBitmap4, hBitmap5;

    CLIENTCREATESTRUCT clientcreate;
    MDICREATESTRUCT mdicreate;


    static HWND hwndClient;
    switch (iMsg)
    {
    case WM_CREATE:


        hButton = CreateWindow(L"button", L"게임시작",
            //버튼의 윈도우 클래스 이름은 “button”
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            // 자식 윈도우이고 누르는 형태의 버튼 스타일
            350, 500, 100, 25, hwnd,
            (HMENU)IDC_BUTTON, hInst, NULL);
        sndPlaySoundA("opening.wav", SND_ASYNC | SND_LOOP);
        hBitmap = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_JURU_OPEN));
        hBitmap2 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_BITMAP2));
        hBitmap3 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_BITMAP10));
        hBitmap4 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_BITMAP11));
        hBitmap5 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_BITMAP9));

        SetTimer(hwnd, 1, 500, NULL);

        break;
    case WM_TIMER:


        InvalidateRgn(hwnd, NULL, true);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);


        Rectangle(hdc, 0, 0, 800, 680);
        //Rectangle(hdc, 200, 200, 600,400);

        //MakeRect(&rect, 0,700,10,900);


        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap);
        StretchBlt(hdc, 200, 100, 400, 350, memdc, 0, 0, 300, 225, SRCCOPY);
        //그림 좌표(0.0)에서 w600/h600만큼, hdc 좌표 (0.0)부터 w530/h530 그림(축소)
        DeleteDC(memdc);

        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap2);
        StretchBlt(hdc, 50, 400, 200, 200, memdc, 0, 0, 600, 600, SRCCOPY);
        DeleteDC(memdc);

        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap3);
        StretchBlt(hdc, 650, 350, 350, 350, memdc, 0, 0, 600, 600, SRCCOPY);
        DeleteDC(memdc);

        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap4);
        StretchBlt(hdc, 250, 350, 350, 350, memdc, 0, 0, 600, 600, SRCCOPY);
        DeleteDC(memdc);

        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap5);
        StretchBlt(hdc, 130, 200, 350, 350, memdc, 0, 0, 600, 600, SRCCOPY);
        DeleteDC(memdc);

        Animation(600, 300, hdc);

        Rectangle(hdc, 800, 0, 1300, 680);
        MakeRect(&rect, 800, 0, 1300, 680);
        hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
            VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
        OldFont = (HFONT)SelectObject(hdc, hFont);
        DrawText(hdc, _T("\n게임설명\n\n주루마블은\n모두의마블과 부루마블을\n모티브로 만들어졌습니다.\n총 4명이서 진행하는 보드게임형\n술게임으로 주사위를 던져\n 타일에 있는 \n컨텐츠를 진행하면서 \n먼저 10바퀴를 완주하세요!!\n먼저 완주하는 사람이 승리합니다.\n\n행운을 빌겠습니다~\n\n레츠 고"), _tcslen(_T("\n게임설명\n\n주루마블은\n모두의마블과 부루마블을\n모티브로 만들어졌습니다.\n총 4명이서 진행하는 보드게임형\n술게임으로 주사위를 던져\n 타일에 있는 \n컨텐츠를 진행하면서 \n먼저 10바퀴를 완주하세요!!\n먼저 완주하는 사람이 승리합니다.\n\n행운을 빌겠습니다~\n\n레츠 고")), &rect, DT_CENTER);

        SelectObject(hdc, OldFont);
        DeleteObject(hFont);
        EndPaint(hwnd, &ps);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON:
            hdc = GetDC(hwnd);

            DestroyWindow(hwnd);
            PlaySound(NULL, 0, 0);


            // sndPlaySoundA("bgmmain.wav", SND_ASYNC | SND_LOOP);
            PlaySound(TEXT("bgmmain.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            // PlaySound(TEXT("bgmmain.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);

        }
    case WM_DESTROY:
        KillTimer(hwnd, 1);

        break;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


LRESULT CALLBACK KeyProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc, memdc;
    PAINTSTRUCT ps;
    static int Keycount;
    static HBITMAP hBitmapEVENT[15], hKEYButton;
    switch (iMsg) {
    case WM_CREATE:
        hBitmapEVENT[0] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY1));
        hBitmapEVENT[1] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY2));
        hBitmapEVENT[2] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY3));
        hBitmapEVENT[3] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY4));
        hBitmapEVENT[4] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY5));
        hBitmapEVENT[5] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY6));
        hBitmapEVENT[6] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY7));
        hBitmapEVENT[7] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY8));
        hBitmapEVENT[8] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY9));
        hBitmapEVENT[9] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY10));
        hBitmapEVENT[10] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY11));
        hBitmapEVENT[11] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY12));
        hBitmapEVENT[12] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY13));
        hBitmapEVENT[13] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY14));
        hBitmapEVENT[14] = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
            MAKEINTRESOURCE(IDB_KEY15));

        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        memdc = CreateCompatibleDC(hdc);
        Keycount = 0;
        Keycount = (rand() % 15);
        SelectObject(memdc, hBitmapEVENT[Keycount]);
        BitBlt(hdc, 0, 0, 332, 240, memdc, 0, 0, SRCCOPY);
        DeleteDC(memdc);
        EndPaint(hwnd, &ps);
        break;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

#define TRUE 1
#define FALSE 0
LPCTSTR lpszClass = TEXT("cat");

float LengthPts(int x1, int y1, int x2, int y2)                     // sqrt 수학함수
{
    return (sqrt((float)(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

BOOL Catch(int x, int y, int mx, int my)
{
    if (LengthPts(x, y, mx, my) < 20) return TRUE;
    else return FALSE;
}

LRESULT CALLBACK Event1Proc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // 미니게임 1 - 고양이 쥐게임
{
    HDC hdc;
    PAINTSTRUCT ps;
    static POINT mouse, cat;
    static BOOL Drag;
    static int stepX, stepY, count;

    switch (iMsg)
    {
    case WM_CREATE:
        cat.x = 100; cat.y = 100;
        Drag = FALSE;
        count = 0;
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        if (Drag)
        {
            TextOut(hdc, mouse.x, mouse.y, L"쥐", 1);
        }
        TextOut(hdc, cat.x, cat.y, L"고양이", 3);
        if (Catch(cat.x, cat.y, mouse.x, mouse.y))
        {
            KillTimer(hwnd, 1);
            stepX = NULL;
            stepY = NULL;
            MessageBeep(1);
            if (MessageBox(hwnd, TEXT("GAME OUT"), TEXT("GAME OUT"), MB_OK) == IDOK)
            {
                DestroyWindow(hwnd);
                return(0);


            }
        }
        EndPaint(hwnd, &ps);
        return 0;

    case WM_LBUTTONDOWN:
        mouse.x = LOWORD(lParam);
        mouse.y = HIWORD(lParam);
        Drag = TRUE;
        stepX = (mouse.x - cat.x) / 10;
        stepY = (mouse.y - cat.y) / 10;
        InvalidateRect(hwnd, NULL, TRUE);
        count = 0;
        SetTimer(hwnd, 1, 100, NULL);
        return 0;

    case WM_LBUTTONUP:
        Drag = FALSE;
        KillTimer(hwnd, 1);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_MOUSEMOVE:
        if (!Drag) return 0;
        mouse.x = LOWORD(lParam);
        mouse.y = HIWORD(lParam);
        stepX = (mouse.x - cat.x) / 2;
        stepY = (mouse.y - cat.y) / 2;
        count = 0;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_TIMER:
        count++;
        cat.x += stepX;
        cat.y += stepY;
        InvalidateRect(hwnd, NULL, TRUE);
        if (count == 10)
        {
            stepX = 0;
            stepY = 0;
        }
        return 0;

    }
    return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



//  메시지 처리
INT_PTR CALLBACK About(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (iMsg)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

bool over;

enum { UP, DOWN, LEFT, RIGHT };

struct Worm

{

    POINT body[100];

    POINT head;

    int length;

    short go;

    void move(HDC hdc);  //머리를 한칸 앞으로 옮긴다

    void bodyMove(POINT); //몸들이 자신의 앞에 있던 몸의 좌표를 받아 좌표를 옮긴다

    bool isOver(int, int); //게임 끝 판정

    bool check_body(int, int); //머리가 자기 몸에 닿음을 판정

    void draw(HDC); //화면에 뱀을 출력한다

    POINT* isEat(POINT, POINT*, int); //먹이를 먹었는지 판정, 먹이를 지우기 위해 POINT *를 리턴한다.

} w;

void baitSet(POINT*, int); //먹이가 지정된 판안에서 중복되지 않게 셋팅한다

POINT bait[12]; //먹이의 갯수, 마지막 bait[11]은 뱀의 머리로 설정 된다.

double line(POINT, POINT); //두 점 사이의 거리. 

int random()

{

    int result;

    while (1)

    {

        result = rand() % 400;

        if (result > 15 && result < 385)

            return result;

    }

}


void Worm::move(HDC hdc)

{

    POINT p = head;

    POINT* del;

    switch (go)

    {

    case UP:

        if (isOver(head.x, head.y - M))

        {

            p.y -= M;

        }

        else

        {

            over = true;

            return;

        }

        break;

    case DOWN:

        if (isOver(head.x, head.y + M))

        {

            p.y += M;

        }

        else

        {

            over = true;

            return;

        }

        break;

    case LEFT:

        if (isOver(head.x - M, head.y))

        {

            p.x -= M;

        }

        else

        {

            over = true;

            return;

        }

        break;

    case RIGHT:

        if (isOver(head.x + M, head.y))

        {


            p.x += M;

        }

        else {

            over = true;

            return;
        }

        break;

    }

    del = isEat(p, bait, 10);

    if (del->x != bait[10].x)

    {



        Ellipse(hdc, del->x - R, del->y - R, del->x + R, del->y + R);

        del->x = -10; del->y = -10;

        length++;

    }

    bodyMove(p);

}

bool Worm::isOver(int x, int y)

{

    if (x - R < 0 || x + R>410)

        return false;

    else if (y - R < 0 || y + R>410)

        return false;

    else if (check_body(x, y))

        return false;

    else

        return true;

}

bool Worm::check_body(int ax, int ay)

{

    POINT P;

    P.x = ax;

    P.y = ay;

    for (int i = 1; i < length; i++)

    {

        if (line(P, body[i]) < R * 2)

            return true;

    }

    return false;

}

void Worm::draw(HDC hdc)

{

    for (int i = 0; i < length; i++)

    {

        Ellipse(hdc, body[i].x - R, body[i].y - R, body[i].x + R, body[i].y + R);

    }

}

void Worm::bodyMove(POINT p)

{

    for (int i = length - 1; i >= 1; i--)

    {

        body[i] = body[i - 1];

    }

    head = body[0] = p;

}

POINT* Worm::isEat(POINT p, POINT* bait, int len)

{

    POINT x;

    x.x = 0; x.y = 0;

    for (int i = 0; i < len; i++)

    {

        if (line(p, bait[i]) < R * 2)

            return &bait[i];

    }

    return &bait[10];

}

void baitSet(POINT* b, int length)

{

    for (int i = 0; i < length; i++)

    {

        b[i].x = random(); b[i].y = random();

        for (int j = 1; j < i; j++)

        {

            while (1)

            {


                if ((b[i].x > b[j].x + R || b[i].x < b[j].x - R) && (b[i].y > b[j].y + R || b[i].y < b[j].y - R))

                    break;

                else

                {

                    b[i].x = random(); b[i].y = random();

                }

            }

        }

    }

}

double line(POINT P, POINT B)

{

    return(sqrt((double)((P.x - B.x) * (P.x - B.x) + (P.y - B.y) * (P.y - B.y))));

}


LRESULT CALLBACK Event2Proc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) // 미니게임 2 - 지렁이 게임
{
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN oldpen, Hpen;
    HBRUSH oldB, Brush;

    static int count = 0;
    switch (iMsg)
    {
    case WM_CREATE:

        w.length = 1;

        w.body[0] = w.head = bait[10];

        w.go = RIGHT;

        break;

    case WM_PAINT:

        hdc = BeginPaint(hwnd, &ps);

        Hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));

        oldpen = (HPEN)SelectObject(hdc, Hpen);

        Rectangle(hdc, 0, 0, 400, 400);

        Hpen = (HPEN)SelectObject(hdc, oldpen);

        Brush = CreateSolidBrush(RGB(0, 0, 0));

        oldB = (HBRUSH)SelectObject(hdc, Brush);

        for (int i = 0; i < 10; i++)

        {

            if (bait[i].x < 0)

                continue;

            Ellipse(hdc, bait[i].x - R, bait[i].y - R, bait[i].x + R, bait[i].y + R);

        }


        EndPaint(hwnd, &ps);

        break;

    case WM_TIMER:

        hdc = GetDC(hwnd);



        SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));

        w.draw(hdc);

        w.move(hdc);

        SelectObject(hdc, (HPEN)GetStockObject(BLACK_PEN));

        w.draw(hdc);



        if (w.length == 11)

        {
            KillTimer(hwnd, 1);

            if (MessageBox(hwnd, _T("참 잘했어요~"), _T("YOU WIN"), MB_OK) == IDOK)
            {

                DestroyWindow(hwnd);
            }
        }



        ReleaseDC(hwnd, hdc);

        break;

    case WM_KEYDOWN:

        switch (wParam)

        {

        case VK_UP:

            w.go = UP;

            break;

        case VK_DOWN:

            w.go = DOWN;

            break;

        case VK_LEFT:

            w.go = LEFT;

            break;

        case VK_RIGHT:

            w.go = RIGHT;

            break;

        case VK_RETURN:

            SetTimer(hwnd, 1, 100, NULL);

            InvalidateRect(hwnd, NULL, true);

            break;

        }
        //   InvalidateRect(hwnd, NULL, true);

        break;

    case WM_DESTROY:


        break;
    default:
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
    }
    return 0;
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
    WPARAM wParam, LPARAM lParam)
    //   WinDef.h 에서 정의
    //   wPram > unsigned ptr, lParam > long ptr 
{

    srand((unsigned int)time(NULL));
    baitSet(bait, 11);
    static RECT rectView;
    static HBITMAP hBitmap, hBitmap2, hBitmapBASE, hBitmapKEY;
    HDC             hdc, memdc, mem2dc;
    HWND  hButton, hEdit, hPopup, hKey, hDoKey, hEvent1, hEvent2, hMan1, hMan2;

    static WNDCLASS wndclass[8];
    wndclass[0].lpfnWndProc = PopupProc;
    wndclass[0].lpszClassName = TEXT("Popup");
    wndclass[0].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[0]);

    wndclass[1].lpfnWndProc = KeyProc;
    wndclass[1].lpszClassName = TEXT("Key");
    wndclass[1].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[1]);

    wndclass[2].lpfnWndProc = Event1Proc;
    wndclass[2].lpszClassName = TEXT("Event1");
    wndclass[2].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[2]);

    wndclass[3].lpfnWndProc = Event2Proc;
    wndclass[3].lpszClassName = TEXT("Event2");
    wndclass[3].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[3]);

    wndclass[4].lpfnWndProc = Man1Proc;
    wndclass[4].lpszClassName = TEXT("Man1");
    wndclass[4].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[5]);

    wndclass[5].lpfnWndProc = Man2Proc;
    wndclass[5].lpszClassName = TEXT("Man2");
    wndclass[5].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[5]);

    wndclass[6].lpfnWndProc = DoKeyProc;
    wndclass[6].lpszClassName = TEXT("DoKey");
    wndclass[6].hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wndclass[6]);


    PAINTSTRUCT     ps;
    HBRUSH          hBrush, oldBrush;
    HPEN hPen, oldPen;
    HINSTANCE hinst;

    HPEN hPen1, hPen2, oldPen1, oldPen2, red, redold;
    RECT rt, rect, rect1, rect2, rect3, rect4;
    static int x[4], y[4];
    static int max_x[4], min_x[4], max_y[4], min_y[4];
    static int dice;
    int button_mx, button_my;
    static int button_x, button_y;
    static int flag_x[4], flag_y[4];
    static int count[4];
    static int dicetime = 0;

    static int turn = 1;
    static int tile_count[4];
    static int x_ladder;
    static int island[4];


    HWND hHelp;

    rt = { 0,0,0,0 };

    rect1 = { 50, 0, 165, 40 };
    rect2 = { 165, 0, 280,40 };
    rect3 = { 280, 0, 395,40 };
    rect4 = { 395, 0, 510,40 };

    static BOOL Selection;
    static BOOL Start_Selection;

    srand(time(NULL));
    int stepsize = 115;
    int stepsize_y = 65;

    static int i;

    HFONT hFont, OldFont;

    WCHAR player[][5] = { L"빨강뚜껑",L"파랑뚜껑",L"검정뚜껑",L"초록뚜껑" };

    switch (iMsg)
    {
    case WM_CREATE:
        hPopup = CreateWindow(
            _T("Popup"),
            _T("PopupText"),
            WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
            300,
            200,
            1300,
            680,
            hwnd,
            NULL,
            hInst,
            NULL
        );


        // x[0] = 175; y[0] = 465;// 440 + (505 - 440) / 2;
        x[0] = 80; y[0] = 460;//플레이어 좌표 설정
        x[1] = 80; y[1] = 490;
        x[2] = 110; y[2] = 460;
        x[3] = 110; y[3] = 490;


        max_x[0] = 770; min_x[0] = 80;//게임보드의 최대/최소 설정-X
        max_x[1] = 770; min_x[1] = 80;
        max_x[2] = 800; min_x[2] = 110;
        max_x[3] = 800; min_x[3] = 110;

        max_y[0] = 460; min_y[0] = 70;//게임보드의 최대/최소 설정-Y
        max_y[1] = 490; min_y[1] = 100;
        max_y[2] = 460; min_y[2] = 70;
        max_y[3] = 490; min_y[3] = 100;

        flag_x[0] = 0; flag_y[0] = 0;//flag값을 설정하여 게임보드 안에 있다는 것을 인식함.
        flag_x[1] = 0; flag_y[1] = 0;
        flag_x[2] = 0; flag_y[2] = 0;
        flag_x[3] = 0; flag_y[3] = 0;

        count[0] = 0;//플레이어 마다 바퀴 수 설정
        count[1] = 0;
        count[2] = 0;
        count[3] = 0;

        island[0] = 0;
        island[0] = 0;
        island[0] = 0;
        island[0] = 0;

        i = 0;
        dice = 0;
        button_x = 200; button_y = 410;
        Selection = FALSE;

        TCHAR str[128];
        hButton = CreateWindow( //버튼 생성
            _T("button"), // 버튼형식의 윈도우 스타일
            _T("주사위 굴리기"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            180,
            350,
            100,
            25,
            hwnd,
            (HMENU)IDC_BUTTON,
            hInst,
            NULL
        );


        hBitmap = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP5));
        hBitmap2 = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP4));
        hBitmapBASE = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_JURU_OPEN));


        tile_count[0] = 0;
        tile_count[1] = 0;
        tile_count[2] = 0;
        tile_count[3] = 0;

        Start_Selection = false;



        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//타일 테두리

        Rectangle(hdc, 50, 50, 855, 505);



        hBrush = (HBRUSH)CreateSolidBrush(RGB(235, 245, 245));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 0, 0, 900, 600);
        MakeRect(&rect, 0, 0, 900, 600);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);


        Rectangle(hdc, 165, 115, 740, 440);

        Rectangle(hdc, 900, 0, 1300, 600);
        MakeRect(&rect, 900, 0, 1300, 600);
        ///////////////////////////////////////
        //상단그리기//
        Rectangle(hdc, 900, 0, 1300, 40);
        MakeRect(&rect, 900, 0, 1300, 40);

        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어1(빨강) 그리기
        Ellipse(hdc, 940, 10, 960, 30);
        DeleteObject(hPen);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어2(파랑) 그리기
        Ellipse(hdc, 1040, 10, 1060, 30);
        DeleteObject(hPen);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어3(검정) 그리기
        Ellipse(hdc, 1140, 10, 1160, 30);
        DeleteObject(hPen);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어4(초록) 그리기
        Ellipse(hdc, 1240, 10, 1260, 30);
        DeleteObject(hPen);
        ///////////////////////////////////////
        //히단그리기//
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//타일 테두리

        Rectangle(hdc, 900, 560, 1300, 600);
        MakeRect(&rect, 900, 560, 1300, 600);

        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어1(빨강) 그리기
        Ellipse(hdc, 940, 570, 960, 590);
        DeleteObject(hPen);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어2(파랑) 그리기
        Ellipse(hdc, 1040, 570, 1060, 590);
        DeleteObject(hPen);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어3(검정) 그리기
        Ellipse(hdc, 1140, 570, 1160, 590);
        DeleteObject(hPen);

        hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어4(초록) 그리기

        Ellipse(hdc, 1240, 570, 1260, 590);
        DeleteObject(hPen);
        ////////////////////////////////////////
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어3(검정) 그리기

        hFont = CreateFont(0, 8, 0, 0, FW_BLACK, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
            VARIABLE_PITCH | FF_ROMAN | FW_HEAVY, TEXT("고딕"));
        OldFont = (HFONT)SelectObject(hdc, hFont);


        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmapBASE);
        StretchBlt(hdc, 200, 100, 400, 350, memdc, 0, 0, 300, 225, SRCCOPY);//중심그림
        DeleteDC(memdc);


        Rectangle(hdc, button_x - BSIZE, button_y - BSIZE, button_x + BSIZE, button_y + BSIZE);
        MakeRect(&rect, button_x - BSIZE, button_y - BSIZE, button_x + BSIZE, button_y + BSIZE);

        hBrush = CreateSolidBrush(RGB(255, 184, 112));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        SetBkMode(hdc, TRANSPARENT);
        Rectangle(hdc, 50, 50, 165, 115);
        MakeRect(&rect, 50, 50, 165, 115);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);



        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap2);
        StretchBlt(hdc, 50, 50, 195, 150, memdc, 0, 0, 950, 950, SRCCOPY);//무인도그림
        DeleteDC(memdc);
        SetTextColor(hdc, RGB(255, 255, 255));

        DrawText(hdc, _T("무인도 "), _tcsclen(_T("무인도 ")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        Rectangle(hdc, 165, 50, 280, 115);
        MakeRect(&rect, 165, 50, 280, 115);

        SetTextColor(hdc, RGB(0, 0, 0));

        DrawText(hdc, _T("안주 TIME"), _tcsclen(_T("안주 TIME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        hBrush = CreateSolidBrush(RGB(255, 193, 158));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 280, 50, 395, 115);
        MakeRect(&rect, 280, 50, 395, 115);
        SetBkMode(hdc, TRANSPARENT);
        DrawText(hdc, _T("MINI GAME"), _tcsclen(_T("MINI GAME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        Rectangle(hdc, 395, 50, 510, 115);
        MakeRect(&rect, 395, 50, 510, 115);
        DrawText(hdc, _T("폭탄주 한잔"), _tcsclen(_T("폭탄주 한잔")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        hBrush = CreateSolidBrush(RGB(250, 237, 125));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 510, 50, 625, 115);
        MakeRect(&rect, 510, 50, 625, 115);

        DrawText(hdc, _T("황금열쇠"), _tcsclen(_T("황금열쇠")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        Rectangle(hdc, 625, 50, 740, 115);
        MakeRect(&rect, 625, 50, 740, 115);
        DrawText(hdc, _T("다 같이 한잔"), _tcsclen(_T("다 같이 한잔")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        hBrush = CreateSolidBrush(RGB(184, 223, 248));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        SetBkMode(hdc, TRANSPARENT);
        Rectangle(hdc, 740, 50, 855, 115);
        MakeRect(&rect, 740, 50, 855, 115);


        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitmap);
        StretchBlt(hdc, 740, 50, 115, 115, memdc, 0, 0, 600, 600, SRCCOPY);
        DeleteDC(memdc);
        SetTextColor(hdc, RGB(0, 0, 150));

        DrawText(hdc, _T("\n복불복\n세계여행"), _tcsclen(_T("\n복불복\n세계여행 ")), &rect, DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        SetTextColor(hdc, RGB(0, 0, 0));

        Rectangle(hdc, 50, 115, 165, 180); //왼쪽 위 두번쨰부터 6칸
        MakeRect(&rect, 50, 115, 165, 180);
        DrawText(hdc, _T("\n내 왼쪽\n마셔마셔"), _tcsclen(_T("\n내 왼쪽\n마셔마셔")), &rect, DT_VCENTER | DT_CENTER);
        Rectangle(hdc, 50, 180, 165, 245);
        MakeRect(&rect, 50, 180, 165, 245);
        DrawText(hdc, _T("전화 걸기"), _tcsclen(_T("전화 걸기")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        Rectangle(hdc, 50, 245, 165, 310);
        MakeRect(&rect, 50, 245, 165, 310);
        DrawText(hdc, _T("뒤로 5칸 가자"), _tcsclen(_T("뒤로 5칸 가자")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        hBrush = CreateSolidBrush(RGB(255, 193, 158));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 50, 310, 165, 375);
        MakeRect(&rect, 50, 310, 165, 375);
        DrawText(hdc, _T("MINI GAME"), _tcsclen(_T("MINI GAME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        hBrush = CreateSolidBrush(RGB(250, 237, 125));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 50, 375, 165, 440);
        MakeRect(&rect, 50, 375, 165, 440);
        DrawText(hdc, _T("황금열쇠"), _tcsclen(_T("황금열쇠")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        Rectangle(hdc, 50, 440, 165, 505);
        MakeRect(&rect, 50, 440, 165, 505);
        SetBkMode(hdc, TRANSPARENT);
        DrawText(hdc, _T("출발 -->"), _tcsclen(_T("출발 -->")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        Rectangle(hdc, 740, 115, 855, 180); // 오른쪽 위 두번째부터 6칸        
        MakeRect(&rect, 740, 115, 855, 180);
        DrawText(hdc, _T("\n내 오른쪽\n마셔마셔"), _tcsclen(_T("\n내 오른쪽\n마셔마셔")), &rect, DT_VCENTER | DT_CENTER);
        Rectangle(hdc, 740, 180, 855, 245);
        MakeRect(&rect, 740, 180, 855, 245);
        DrawText(hdc, _T("\n출발부터\n다시시작"), _tcsclen(_T("\n출발부터\n다시시작")), &rect, DT_VCENTER | DT_CENTER);

        hBrush = CreateSolidBrush(RGB(255, 193, 158));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 740, 245, 855, 310);
        MakeRect(&rect, 740, 245, 855, 310);
        DrawText(hdc, _T("MINI GAME"), _tcsclen(_T("MINI GAME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        Rectangle(hdc, 740, 310, 855, 375);
        MakeRect(&rect, 740, 310, 855, 375);
        DrawText(hdc, _T("\n주사위\n 한 번 더"), _tcsclen(_T("\n주사위\n 한 번 더 ")), &rect, DT_VCENTER | DT_CENTER);

        hBrush = CreateSolidBrush(RGB(250, 237, 125));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 740, 375, 855, 440);
        MakeRect(&rect, 740, 375, 855, 440);
        DrawText(hdc, _T("황금열쇠"), _tcsclen(_T("황금열쇠")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);


        hBrush = CreateSolidBrush(RGB(232, 130, 141));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 740, 440, 855, 505);
        MakeRect(&rect, 740, 440, 855, 505);
        SetBkMode(hdc, TRANSPARENT);
        DrawText(hdc, _T(" 폭탄주 제조"), _tcsclen(_T("폭탄주 제조 ")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        Rectangle(hdc, 165, 440, 280, 505); //아래 왼쪽 두번쨰부터 5칸
        MakeRect(&rect, 165, 440, 280, 505);
        DrawText(hdc, _T(" 파도타기"), _tcsclen(_T("파도타기 ")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        Rectangle(hdc, 280, 440, 395, 505);
        MakeRect(&rect, 280, 440, 395, 505);
        DrawText(hdc, _T("소주병\n돌려돌려"), _tcsclen(_T("소주병\n돌려돌려")), &rect, DT_VCENTER | DT_CENTER);
        hBrush = CreateSolidBrush(RGB(250, 237, 125));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 395, 440, 510, 505);
        MakeRect(&rect, 395, 440, 510, 505);
        DrawText(hdc, _T("황금열쇠"), _tcsclen(_T("황금열쇠")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        hBrush = CreateSolidBrush(RGB(255, 193, 158));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, 510, 440, 625, 505);
        MakeRect(&rect, 510, 440, 625, 505);
        DrawText(hdc, _T("MINI GAME"), _tcsclen(_T("MINI GAME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
        Rectangle(hdc, 625, 440, 740, 505);
        MakeRect(&rect, 625, 440, 740, 505);
        DrawText(hdc, _T("사다리 TIME"), _tcsclen(_T("사다리 TIME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        Rectangle(hdc, 650, 115, 705, 180); //사다리
        Rectangle(hdc, 650, 180, 705, 245);
        Rectangle(hdc, 650, 245, 705, 310);
        Rectangle(hdc, 650, 310, 705, 375);
        Rectangle(hdc, 650, 375, 705, 440);

        MakeRect(&rect, 740, 245, 855, 310);
        DrawText(hdc, _T("MINI GAME"), _tcsclen(_T("MINI GAME")), &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        hBrush = CreateSolidBrush(RGB(255, 93, 118));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어1(빨강) 그리기
        Ellipse(hdc, x[0] - 10, y[0] - 10, x[0] + 10, y[0] + 10); SelectObject(hdc, oldPen);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        hBrush = CreateSolidBrush(RGB(118, 93, 255));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어2(파랑) 그리기
        Ellipse(hdc, x[1] - 10, y[1] - 10, x[1] + 10, y[1] + 10); SelectObject(hdc, oldPen);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);


        hBrush = CreateSolidBrush(RGB(100, 100, 100));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어3(검정) 그리기
        Ellipse(hdc, x[2] - 10, y[2] - 10, x[2] + 10, y[2] + 10); SelectObject(hdc, oldPen);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        hBrush = CreateSolidBrush(RGB(118, 255, 93));
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); oldPen = (HPEN)SelectObject(hdc, hPen);//플레이어4(초록) 그리기
        Ellipse(hdc, x[3] - 10, y[3] - 10, x[3] + 10, y[3] + 10); SelectObject(hdc, oldPen);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        if (dice == 1)//주사위 1면 그리기
        {
            Rectangle(hdc, button_x - BSIZE, button_y - BSIZE, button_x + BSIZE, button_y + BSIZE);
            MakeRect(&rect, button_x - BSIZE, button_y - BSIZE, button_x + BSIZE, button_y + BSIZE);

            Ellipse(hdc, button_x - 5, button_y - 5, button_x + 5, button_y + 5);

        }
        else if (dice == 2)//주사위 2면 그리기
        {
            Ellipse(hdc, button_x - 15, button_y - 5, button_x - 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y - 5, button_x + 15, button_y + 5);
        }
        else if (dice == 3)//주사위 3면 그리기
        {
            Ellipse(hdc, button_x - 15, button_y - 15, button_x - 5, button_y - 5);
            Ellipse(hdc, button_x - 5, button_y - 5, button_x + 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y + 15, button_x + 15, button_y + 5);
        }
        else if (dice == 4)//주사위 4면 그리기
        {
            Ellipse(hdc, button_x - 15, button_y - 15, button_x - 5, button_y - 5);
            Ellipse(hdc, button_x + 5, button_y - 15, button_x + 15, button_y - 5);
            Ellipse(hdc, button_x - 15, button_y + 15, button_x - 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y + 15, button_x + 15, button_y + 5);
        }
        else if (dice == 5)//주사위 5면 그리기
        {
            Ellipse(hdc, button_x - 5, button_y - 5, button_x + 5, button_y + 5);
            Ellipse(hdc, button_x - 15, button_y - 15, button_x - 5, button_y - 5);
            Ellipse(hdc, button_x + 5, button_y - 15, button_x + 15, button_y - 5);
            Ellipse(hdc, button_x - 15, button_y + 15, button_x - 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y + 15, button_x + 15, button_y + 5);
        }
        else if (dice == 6)//주사위 6면 그리기
        {
            Ellipse(hdc, button_x - 15, button_y - 5, button_x - 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y - 5, button_x + 15, button_y + 5);
            Ellipse(hdc, button_x - 15, button_y - 15, button_x - 5, button_y - 5);
            Ellipse(hdc, button_x + 5, button_y - 15, button_x + 15, button_y - 5);
            Ellipse(hdc, button_x - 15, button_y + 15, button_x - 5, button_y + 5);
            Ellipse(hdc, button_x + 5, button_y + 15, button_x + 15, button_y + 5);

        }
        wsprintf(str, TEXT("주사위 : %d"), dice);//주사위 텍스트로 출력
        TextOut(hdc, 240, 410, str, lstrlen(str));

        wsprintf(str, TEXT("빨간색 말 : %d 바퀴"), count[0]);//1 말(빨강) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 420, str, lstrlen(str));
        wsprintf(str, TEXT("파란색 말 : %d 바퀴"), count[1]);//2 말(파랑) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 440, str, lstrlen(str));
        wsprintf(str, TEXT("검은색 말 : %d 바퀴"), count[2]);//3 말(검정) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 460, str, lstrlen(str));
        wsprintf(str, TEXT("초록색 말 : %d 바퀴"), count[3]);//4 말(초록) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 480, str, lstrlen(str));

        wsprintf(str, TEXT("빨간색 말 타일 COUNT : %d "), tile_count[0]);//1 말(빨강) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 160, str, lstrlen(str));
        wsprintf(str, TEXT("파란색 말 타일 COUNT : %d "), tile_count[1]);//2 말(파랑) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 180, str, lstrlen(str));
        wsprintf(str, TEXT("검은색 말 타일 COUNT : %d "), tile_count[2]);//3 말(검정) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 200, str, lstrlen(str));
        wsprintf(str, TEXT("초록색 말 타일 COUNT : %d "), tile_count[3]);//4 말(초록) 바퀴수 텍스트로 출력
        TextOut(hdc, 910, 220, str, lstrlen(str));


        for (int y = 0; y < 4; y++)// 텍스트로 순서 알려주기
        {
            wsprintf(str, TEXT("%d번째 말 %s이 주사위 던질 차례입니다."), i + 1, player[i]);
            TextOut(hdc, 910, 60, str, lstrlen(str));


        }// 말 이름 텍스트로 출력


        DeleteObject(hPen);

        EndPaint(hwnd, &ps);
        return 0;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON:

            dice = (rand() % 6) + 1; // (rand() % 6) + 1;//주사위 랜덤 값

            hButton = GetDlgItem(hwnd, IDC_BUTTON);
            EnableWindow(hButton, FALSE);
            if (island[i] >= 1)
            {
                island[i]++;
            }


            //어떤이벤트할지 정하고
            if (0 <= i && i < 4) { //SetTimer를 통한 플레이어 움직임 표시


               //switch (turn) { //조건- 일반,사다리,

            //   case 1:
                SetTimer(hwnd, 1, 300, NULL);
                turn = 1;
                /*case 0:
                   SetTimer(hwnd, 2, 500, NULL);*/
                if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                {
                    i = 0;
                }

            }
            break;

        case ID_BGM_BGMON:
            PlaySoundA(SOUND_FILE_BGM3, nullptr, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);

            break;


        case ID_BGM_BGMOFF:
            PlaySoundA(nullptr, nullptr, 0);

            break;
        case ID_DO:
            hDoKey = CreateWindow(
                _T("DoKey"),
                _T("게임 설명서"),
                WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                100,
                300,
                615,
                490,
                hwnd,
                NULL,
                hInst,
                NULL
            );
        }
        InvalidateRgn(hwnd, NULL, TRUE);

        break;


        // ReleaseDC(hwnd, hdc);

    case WM_TIMER:

        hButton = GetDlgItem(hwnd, IDC_BUTTON);
        switch (turn)
        {
        case 1:
        back:
            if (flag_x[i] == 1 && flag_y[i] == 0 && island[i] == 0)//flag값을 이용해 경계에 있을때 플레이어 방향 제어-폭탄주제조 타일 위치
            {
                x[i] = max_x[i];
                y[i] = y[i] - stepsize_y;
                tile_count[i] = tile_count[i] + 1;

                if (y[i] == min_y[i])
                {
                    flag_y[i] = 1;
                }


            }
            else if (flag_x[i] == 1 && flag_y[i] == 1 && island[i] == 0)//flag값을 이용해 경계에 있을때 플레이어 방향 제어-세계여행 타일 위치
            {
                y[i] = min_y[i];
                x[i] = x[i] - stepsize;
                tile_count[i] = tile_count[i] + 1;

                if (x[i] == min_x[i])
                {
                    flag_x[i] = 0;
                }
            }
            else if (flag_x[i] == 0 && flag_y[i] == 1 && island[i] == 0)//flag값을 이용해 경계에 있을때 플레이어 방향 제어-무인도 타일 위치
            {
                x[i] = min_x[i];
                y[i] = y[i] + stepsize_y;
                tile_count[i] = tile_count[i] + 1;

                if (y[i] == max_y[i])
                {
                    flag_y[i] = 0;
                    count[i] += 1;
                    if (count[i] == 10)
                    {
                        InvalidateRgn(hwnd, NULL, TRUE);
                        EnableWindow(hButton, FALSE);
                        if (i == 0)
                        {
                            KillTimer(hwnd, 1);
                            PlaySoundA(nullptr, nullptr, 0);
                            if (MessageBox(hwnd, _T("빨간색 말이 승리 하였습니다!! \n축하드립니다"), _T("빨간색 말이 승리!"), MB_OK) == IDOK)
                            {
                            }
                            DestroyWindow(hwnd);
                        }
                        else if (i == 1)
                        {
                            KillTimer(hwnd, 1);
                            PlaySoundA(nullptr, nullptr, 0);
                            if (MessageBox(hwnd, _T("파란색 말이 승리 하였습니다!! \n축하드립니다"), _T("파란색 말이 승리!"), MB_OK) == IDOK)
                            {
                            }
                            DestroyWindow(hwnd);
                        }
                        else if (i == 2)
                        {
                            KillTimer(hwnd, 1);
                            PlaySoundA(nullptr, nullptr, 0);
                            if (MessageBox(hwnd, _T("검은색 말이 승리 하였습니다!! \n축하드립니다"), _T("검은색 말이 승리!"), MB_OK) == IDOK)
                            {
                            }
                            DestroyWindow(hwnd);
                        }
                        else if (i == 3)
                        {
                            KillTimer(hwnd, 1);
                            PlaySoundA(nullptr, nullptr, 0);
                            if (MessageBox(hwnd, _T("초록색 말이 승리 하였습니다!! \n축하드립니다"), _T("초록색 말이 승리!"), MB_OK) == IDOK)
                            {
                            }
                            DestroyWindow(hwnd);
                        }

                    }
                    tile_count[i] = 0;

                }
            }
            else if (flag_x[i] == 0 && flag_y[i] == 0 && island[i] == 0)//flag값을 이용해 경계에 있을때 플레이어 방향 제어-출발 타일 위치
            {
                y[i] = max_y[i];
                x[i] = x[i] + stepsize;
                tile_count[i] = tile_count[i] + 1;

                if (x[i] == max_x[i])
                {
                    flag_x[i] = 1;
                }
            }

            if (island[i] == 0)
            {
                dicetime = dicetime + 1;
            }
            else
            {
                dicetime = dice;
            }

            if (dice <= dicetime)//주사위 카운트와 주사위값 비교하여 증가 및 이동시키고 주사위 값보다 커지면 KillTimer 호출
            {
                KillTimer(hwnd, 1);

                if (x[i] == max_x[i] - stepsize && y[i] == max_y[i]) //--> 여기가 원래 tilecount==5 였음 그러면 주사위가 5가 나올때마다 사다리 타는 코드 실행됨. 그래서 사다리 탄후 2번째 시행부터 진행불가함 따라서 좌표일치로 바꿈
                {
                    SetTimer(hwnd, 2, 500, NULL);
                    turn = 2;
                    break;

                } //사다리타임

                else if ((x[i] == min_x[i] + (3 * stepsize) && y[i] == max_y[i]))//1 황금열쇠
                {
                    hKey = CreateWindow(
                        _T("Key"),
                        _T("황금 열쇠"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        600,
                        450,
                        300,
                        200,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);
                }
                else if ((x[i] == min_x[i] + (4 * stepsize) && y[i] == max_y[i])) //1미니게임
                {
                    hMan1 = CreateWindow(
                        _T("Man1"),
                        _T("게임 설명서"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        100,
                        300,
                        615,
                        490,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    hEvent1 = CreateWindow(
                        _T("Event1"),
                        _T("고양이 쥐 게임"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        800,
                        300,
                        800,
                        500,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);
                }


                else if (x[i] == max_x[i] && y[i] == min_y[i] + (5 * stepsize_y)) //2황금열쇠
                {
                    hKey = CreateWindow(
                        _T("Key"),
                        _T("황금 열쇠"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        600,
                        450,
                        300,
                        200,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);

                }

                else if (x[i] == max_x[i] && y[i] == min_y[i] + (3 * stepsize_y)) //2미니게임
                {
                    hMan2 = CreateWindow(
                        _T("Man2"),
                        _T("게임 설명서"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        100,
                        300,
                        615,
                        490,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    hEvent2 = CreateWindow(
                        _T("Event2"),
                        _T("지렁이 게임"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        800,
                        300,
                        410,
                        430,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    EnableWindow(hButton, TRUE);
                }


                else if (x[i] == min_x[i] + (4 * stepsize) && y[i] == min_y[i]) //3황금열쇠
                {
                    hKey = CreateWindow(
                        _T("Key"),
                        _T("황금 열쇠"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        600,
                        450,
                        300,
                        200,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);

                }
                else if (x[i] == min_x[i] + (2 * stepsize) && y[i] == min_y[i]) //3미니게임
                {
                    hMan1 = CreateWindow(
                        _T("Man1"),
                        _T("게임 설명서"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        100,
                        300,
                        615,
                        490,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    hEvent1 = CreateWindow(
                        _T("Event1"),
                        _T("고양이 쥐 게임"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        800,
                        300,
                        800,
                        500,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);

                }

                else if (x[i] == min_x[i] && y[i] == max_y[i] - (stepsize_y)) //4황금열쇠
                {
                    hKey = CreateWindow(
                        _T("Key"),
                        _T("황금 열쇠"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        600,
                        450,
                        300,
                        200,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);

                }
                else if (x[i] == min_x[i] && y[i] == max_y[i] - (2 * stepsize_y)) //4미니게임
                {
                    hMan2 = CreateWindow(
                        _T("Man2"),
                        _T("게임 설명서"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        100,
                        300,
                        615,
                        490,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    hEvent2 = CreateWindow(
                        _T("Event2"),
                        _T("지렁이 게임"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        800,
                        300,
                        410,
                        430,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    EnableWindow(hButton, TRUE);
                }

                else if (x[i] == max_x[i] && y[i] == min_y[i] + (2 * stepsize_y))//출발부터 다시시작
                {
                    SetTimer(hwnd, 3, 300, NULL);

                    turn = 3;
                    break;

                }
                else if (x[i] == max_x[i] && y[i] == min_y[i] + (4 * stepsize_y))
                {

                    dicetime = 0;
                    if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                    {
                        i = 0;
                    }
                    InvalidateRgn(hwnd, NULL, TRUE);


                    if (MessageBox(hwnd, _T("주사위 한번 더~~"), _T("주사위 한 번 더"), MB_OK) == IDOK)
                    {


                    }
                    EnableWindow(hButton, TRUE);

                    break;

                }//주사위 한 번 더

                else if (x[i] == min_x[i] && y[i] == min_y[i] + (3 * stepsize_y))
                {
                    InvalidateRgn(hwnd, NULL, TRUE);
                    if (MessageBox(hwnd, _T("아이고~~ 안타깝네요! \n 뒤로 5칸 가볼게요...ㅎㅎ"), _T("뒤로 5칸"), MB_OK) == IDOK)
                    {

                    }
                    SetTimer(hwnd, 4, 300, NULL);

                    turn = 4;
                    break;

                }//뒤로 5칸 가자

                else if (x[i] == min_x[i] + stepsize && y[i] == max_y[i])
                {

                    InvalidateRgn(hwnd, NULL, TRUE);

                    if (MessageBox(hwnd, _T("걸린사람 오른쪽으로 파도타기~~"), _T("걸린사람 오른쪽으로 파도타기~~ "), MB_OK) == IDOK)
                    {

                    }
                    EnableWindow(hButton, TRUE);

                }//파도타기
                else if (x[i] == min_x[i] + (2 * stepsize) && y[i] == max_y[i])
                {
                    InvalidateRgn(hwnd, NULL, TRUE);
                    if (MessageBox(hwnd, _T("소주병 돌려서 입구쪽방향 걸린 사람 술 한잔~\n"), _T(" 소주병 돌려 돌려"), MB_OK) == IDOK)
                    {

                    }
                    EnableWindow(hButton, TRUE);

                }//소주병 돌려돌려

                else if (x[i] == max_x[i] && y[i] == max_y[i])
                {
                    InvalidateRgn(hwnd, NULL, TRUE);
                    if (MessageBox(hwnd, _T("아주아주 큰 칸,컵,통을 꺼내주세요~~!\n 꺼내셨나요? 그러면 거기다 술을 왕창 쏟아 봅시다!"), _T("폭탄주 제조"), MB_OK) == IDOK)
                    {

                    }
                    EnableWindow(hButton, TRUE);

                }//폭탄주 제조

                ////////////////////////////////////////////////////////////////////////////////////////
                else if (x[i] == max_x[i] && y[i] == min_y[i])
                {
                    InvalidateRgn(hwnd, NULL, TRUE);


                    if (MessageBox(hwnd, _T("복불복 세계여행 가즈아~"), _T("복불복 세계여행 가즈아~ "), MB_OK) == IDOK)
                    {
                        dice = (rand() % 23) + 1;//주사위 랜덤 값

                        dicetime = 0;
                        island[i] = 0;
                        SetTimer(hwnd, 1, 300, NULL);

                        goto back;


                    }


                    EnableWindow(hButton, TRUE);
                    InvalidateRgn(hwnd, NULL, TRUE);


                }//세계여행

                else if (x[i] == min_x[i] && y[i] == min_y[i])
                {
                    if (island[i] == 0)
                    {
                        island[i] = 1;
                    }
                    else if (island[i] == 4)
                    {
                        island[i] = 0;
                    }

                    InvalidateRgn(hwnd, NULL, TRUE);
                    if (MessageBox(hwnd, _T("앙 무인도~~"), _T("앙 무인도~~"), MB_OK) == IDOK)
                    {

                    }
                    EnableWindow(hButton, TRUE);
                    //이벤트발생->환호 효과음 & 메시지박스 & 두 턴 동안 못움직여

                }//무인도
                else if (x[i] == min_x[i] && y[i] == min_y[i] + (2 * stepsize_y))
                {
                    InvalidateRgn(hwnd, NULL, TRUE);
                    if (MessageBox(hwnd, _T("친구 아무한테나 전화를 걸어요! \n 가장 늦게 받는 사람이 마셔마셔!"), _T("전화걸기"), MB_OK) == IDOK)
                    {

                    }
                    EnableWindow(hButton, TRUE);

                }//전화걸기
                else
                {
                    EnableWindow(hButton, TRUE);
                }

                //    EnableWindow(hButton, TRUE);

                i++;
                dicetime = 0;
                if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                {
                    i = 0;
                }

                InvalidateRgn(hwnd, NULL, TRUE);
                break;
            }
            break;

        case 2:

            x_ladder = max_x[i] - 115;

            if (flag_x[i] == 0 && flag_y[i] == 0)//flag값을 이용해 경계에 있을때 플레이어 방향 제어-폭탄주제조 타일 위치
            {

                x[i] = x_ladder;


                y[i] = y[i] - 65;
                if (y[i] <= min_y[i])
                {
                    flag_y[i] = 1;
                    flag_x[i] = 1;
                    KillTimer(hwnd, 2);
                    EnableWindow(hButton, TRUE);
                    tile_count[i] = 13;
                    turn = 1;
                    i++;
                    dicetime = 0;

                    if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                    {
                        i = 0;

                    }


                    break;//test용


                }

                break;//test용

            }
            break;//test용
        case 3:

            if (flag_x[i] == 1 && flag_y[i] == 0)
            {
                y[i] = y[i] + 65;
                if (y[i] >= max_y[i])
                {
                    flag_y[i] = 0;
                    flag_x[i] = 0;
                    break;
                }
            }
            else if (flag_x[i] == 0 && flag_y[i] == 0)
            {
                x[i] = x[i] - stepsize;

                if (x[i] == min_x[i])
                {
                    KillTimer(hwnd, 3);
                    EnableWindow(hButton, TRUE);
                    tile_count[i] = 0;
                    i++;
                    dicetime = 0;
                    if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                    {
                        i = 0;

                    }
                    break;
                }

            }
            break;



        case 4:
            if (flag_x[i] == 0 && flag_y[i] == 1)
            {
                y[i] = y[i] - stepsize_y;
                if (y[i] <= min_y[i])
                {
                    flag_y[i] = 1;
                    flag_x[i] = 1;
                    break;
                }
            }
            else if (flag_x[i] == 1 && flag_y[i] == 1)
            {
                x[i] = x[i] + stepsize;

                if (x[i] == min_x[i] + (2 * stepsize))
                {
                    KillTimer(hwnd, 4);
                    EnableWindow(hButton, TRUE);
                    tile_count[i] = 16;
                    i++;
                    dicetime = 0;
                    hMan1 = CreateWindow(
                        _T("Man1"),
                        _T("게임 설명서"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        100,
                        300,
                        615,
                        490,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );

                    hEvent1 = CreateWindow(
                        _T("Event1"),
                        _T("고양이 쥐게임"),
                        WS_SYSMENU | WS_POPUP | WS_CAPTION | WS_VISIBLE,
                        800,
                        300,
                        800,
                        500,
                        hwnd,
                        NULL,
                        hInst,
                        NULL
                    );
                    if (i == 4)// 플레이어 4명이므로 i가 4이상 된다면 0으로 초기화
                    {
                        i = 0;

                    }
                    break;
                }

            }

            break;
        }


        InvalidateRgn(hwnd, NULL, TRUE);
}