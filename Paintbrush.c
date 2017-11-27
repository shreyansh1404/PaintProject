#include<graphics.h>
#include<windows.h>

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "", -3, -3);

    POINT cursorPosition;
    int mX, mY;

    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX = cursorPosition.x;
        mY = cursorPosition.y;
        if(GetAsyncKeyState(VK_LBUTTON)) bar(mX, mY, mX+10, mY+10);

     //   delay(0);

    }

    getch();
    closegraph();
}
