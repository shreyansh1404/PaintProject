
#include<math.h>
#include<graphics.h>
#include<windows.h>
#include<stdio.h>
int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "", -3, -3);

    POINT cursorPosition1, cursorPosition2;
    int x=1,y=1,x1, y1, x2, y2, radius;
     while(x==1)
    {
        GetCursorPos(&cursorPosition1);
        if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
        {
            x1=cursorPosition1.x;
            y1=cursorPosition1.y;
            x=0;
        }
        delay(0);

    }
    printf("%d %d\n",x1,y1);

     while(y==1)
    {
        GetCursorPos(&cursorPosition2);
        if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
        {
            x2=cursorPosition2.x;
            y2=cursorPosition2.y;
            y=0;
        }
        delay(0);

    }
    printf("%d %d\n",x2,y2);
    radius=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("%d",radius);
    circle(x1, y1, radius);
    getch();
    closegraph();
}
