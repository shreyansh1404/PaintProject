#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

POINT cursorPosition;
int leftcolor[15];
void freehand(int x1, int y1, char draw);
//int getkey();
void draw_color_panel();
void line1();
void rect();
void gola();
void draw_shape_panel();
void eraser();
void change_color(int,int);
char change_shape(int,int);
/*void showmouseptr();
void hidemouseptr();
void restrictmouseptr(int,int,int,int);
void getmousepos(int *button,int *x,int *y);
*/
int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(1920, 1080, "C-ART", -3, -3);

    int maxx,maxy,x,y,button,temp1,temp2,key,color,a,mX,mY;
    POINT cursorPosition, cursorPosition1;
    char draw = 'f' ;

   maxx = getmaxx();
   maxy = getmaxy();

   setcolor(BLUE);
   rectangle(0,0,maxx,maxy);

   setcolor(WHITE);

   draw_color_panel();
   draw_shape_panel();
   bar(2,2,1116,686);
   setviewport(1,1,1117,687,1);

   while(1)
    {
        GetCursorPos(&cursorPosition);
        if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
        {
            x=cursorPosition.x;
            y=cursorPosition.y;
            printf("%d %d\n",x,y);
             //if( x > 4 && y > 713 && x < 1361 && y < 764 )
            //   printf("IN COLOR MENU\n");
	         if ( x > 1126 && x < 1355 && y > 32 && y < 505 )
            {
	        //printf("IN SHAPE MENU\n");
	        draw=change_shape(x,y);
            }

	        GetCursorPos(&cursorPosition);
            temp1=cursorPosition.x;
            temp2=cursorPosition.y;

            if( draw == 'f')
            {
                setcolor(RED);
                while(GetAsyncKeyState(VK_LBUTTON))
                {
                    GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                    line(temp1,temp2,mX,mY);
                    temp1 = mX;
	                temp2 = mY;
	                GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                }
            }
            while(GetAsyncKeyState(VK_LBUTTON))
                {
                    GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                }

            if( draw == 'p')
            {
            putpixel(x,y,getcolor());
            }

            else if ( draw == 'l')
            {
                line1();
            }

            else if ( draw == 'r')
            {
                rect();
            }

            else if ( draw == 'd')
            {
                gola();
            }


            else if ( draw == 'x')
            {
                eraser();
            }

            else if ( draw == 'c' )
	       {
	        draw = 'f';          // SETTING TO FREEHAND DRAWING
	        clearviewport();
            color = getcolor();
	        setcolor(WHITE);
	        bar(2,2,1116,686);
	        setcolor(color);
	       }
         //delay(0);
        }
    }
    getch();
    closegraph();

}


void draw_color_panel()
{
   int left, top, c, color;

   left = 320;
   top = 700;

   color = getcolor();
   setcolor(GREEN);
   rectangle(4,690,1362,742);
   setcolor(RED);
   settextstyle(TRIPLEX_FONT,0,4);
   outtextxy(60,700,"Colors : ");

   for( c = 1 ; c <= 15 ; c++ )
   {
      setfillstyle(SOLID_FILL, c);
      bar(left, top, left+35, top+35);
      leftcolor[c-1] = left;
      left += 65;
   }

   setcolor(color);
}

//-----------------------------------------------------------------------------
void eraser()
{
    int mX,mY,temp1,temp2;
                setcolor(WHITE);
                while(GetAsyncKeyState(VK_LBUTTON))
                {
                    GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                    BAR(temp1,temp2,mX,mY);
                    temp1 = mX;
	                temp2 = mY;
	                GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                }

            while(GetAsyncKeyState(VK_LBUTTON))
                {
                    GetCursorPos(&cursorPosition);
                    mX = cursorPosition.x;
                    mY = cursorPosition.y;
                }

}

//-----------------------------------------------------------------------------

void draw_shape_panel()
{
   int left, top, c, color;

   left = 1125;
   top = 8;

   color = getcolor();
   setcolor(BLUE);
   rectangle(1362,687,1120,3);

   for( c = 1 ; c <= 8 ; c++ )
   {
      rectangle(left, top, left+232, top+55);
      top += 60;
   }
   setcolor(RED);
   settextstyle(TRIPLEX_FONT,0,4);
   outtextxy(1206,20,"Bar");
   outtextxy(1200,80,"Line");
   outtextxy(1190,140,"Pixel");
   outtextxy(1136,200,"Rectangle");
   outtextxy(1172,260,"Eraser");
   outtextxy(1147,320,"Freehand");
   outtextxy(1175,380,"Circle");
   outtextxy(1180,440,"Clear");
   setcolor(color);
}

char change_shape(int x, int y)
{
    char draw;
   if ( x > 1126 && x < 1355 && y > 32 && y < 82 )
   {
       draw='b';
       //printf("%c",draw);
      return 'b';
   }
   else if ( x > 1126 && x < 1355 && y > 90 && y < 143 )
   {
       draw='l';
       printf("line");
      return 'l';
   }
   else if ( x > 1126 && x < 1355 && y > 150 && y < 204 )
   {
       draw='p';
       //printf("pixel");
      return 'p';
   }
   else if ( x > 1126 && x < 1355 && y > 211 && y < 263 )
   {
       draw='r';
       //printf("rectangle");
      return 'r';
   }
   else if (  x > 1126 && x < 1355 && y > 270 && y < 323 )
   {
       draw='x';
       //printf("eraser");
      return 'x';
   }
   else if ( x > 1126 && x < 1355 && y > 331 && y < 383 )
   {
       draw='f';
       printf("freehand\n");
       //freehand(x,y,draw);
      return 'f';
   }
   else if ( x > 1126 && x < 1355 && y > 390 && y < 443 )
   {
       draw='d';
       //printf("circle");
      return 'd'; /* d is for circle */
   }
   else if ( x > 1126 && x < 1355 && y > 451 && y < 505 )
   {
       draw='c';
       //printf("erase");
      return 'c';
   }
}

/*void freehand(int x1, int y1, char draw1)
{
    int mX , mY,fx=1;
     POINT cursorPosition1;
     printf("%c",draw1);
    if(draw1=='f');
    {
        printf("in while\n");
        GetCursorPos(&cursorPosition1);
        mX = cursorPosition1.x;
        mY = cursorPosition1.y;
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL,getcolor());
            bar(mX, mY, mX+2, mY+2);
        }
        while(fx==1)
        {
            GetCursorPos(&cursorPosition1);
            if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
            {
              mX = cursorPosition1.x;
              mY = cursorPosition1.y;
              fx=0;
            }
        }
        draw1=change_shape(mX,mY);
        freehand(mX,mY,draw1);
    }
}*/


/****************************************************************************
FUNCTION TO CHANGE THE COLOR
****************************************************************************/
void change_color(int x, int y)
{
   int c;

   for( c = 0 ; c <= 13 ; c++ )
   {
      if( x > leftcolor[c] && x < leftcolor[c+1] && y > 437 && y < 453 )
	 setcolor(c+1);
      if( x > leftcolor[14] && x < 505 && y > 437 && y < 453 )
	 setcolor(WHITE);
   }
}




void line1()
{
    POINT cursorPosition1, cursorPosition2;
    int x=1,y=1,x1, y1, x2, y2,i ;
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
    printf("%d %d",x2,y2);
    line(x1, y1, x2, y2);
}

void rect()
{
    POINT cursorPosition1, cursorPosition2;
    int x=1,y=1,z=1,x1, y1, x2, y2, x3, y3;
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
    printf("%d %d \n",x2,y2);
    line(x1, y1, x2, y1);
    line(x1, y1, x1, y2);
    line(x1, y2, x2, y2);
    line(x2, y1, x2, y2);
}

void gola()
{
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
}
