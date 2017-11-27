#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

POINT cursorPosition;
int leftcolor[15];
void fill();
int fillcolor();
void freehand(int x1, int y1, char draw);
void draw_color_panel();
void line1();
void rect();
void circle1();
void draw_shape_panel();
void change_color(int,int);
char change_shape(int,int);

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "C-ART", -3, -3);

    int maxx,maxy,x,y,button,temp1,temp2,key,color,a,mX,mY,col2;
    POINT  cursorPosition1;
    char draw;

   maxx = getmaxx();
   maxy = getmaxy();

   setcolor(BLUE);
   rectangle(0,0,maxx,maxy);

   setcolor(WHITE);

   draw_color_panel();
   draw_shape_panel();
   bar(2,2,1116,686);


   while(1)
    {
        GetCursorPos(&cursorPosition);
        if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
        {
            x=cursorPosition.x;
            y=cursorPosition.y;
            printf("%d %d\n",x,y);

	         if ( x > 1126 && x < 1355 && y > 32 && y < 565 )
            {
	           draw=change_shape(x,y);
            }

	        GetCursorPos(&cursorPosition);
            temp1=cursorPosition.x;
            temp2=cursorPosition.y;

            if( draw == 'f')
            {
                  setviewport(1,1,1117,687,1);
                setcolor(BLACK);
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
           else
           {
               switch(draw)
                {
                  case 'p' :
                  {
                        setviewport(1,1,1117,687,1);
                         setcolor(BLACK);
                    putpixel(x,y,getcolor());
                    break;
                  }

                  case 'l' :
                  {
                    line1();
                    break;
                  }

                  case 'e' :
                  {
                    setviewport(1,1,1117,687,1);
                    writeimagefile();
                    break;
                  }

                  case 'o' :
                  {
                    setviewport(1,1,1117,687,1);
                    readimagefile();
                    break;
                  }

                 case 'r' :
                 {
                   rect();
                   break;
                 }

                 case 'd' :
                 {
                   circle1();
                   break;
                 }

                 case 'b' :
                 {
                   fill();
                   break;
                 }


                 case 'c' :
	             {
	               draw = 'f';
	               setviewport(1,1,1117,687,1);
	               clearviewport();
	              bar(2,2,1116,686);
	               setcolor(BLACK);
	               break;
                 }
                }
           }
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

}


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
   outtextxy(1190,20,"Fill");
   outtextxy(1190,80,"Line");
   outtextxy(1187,140,"Pixel ");

   outtextxy(1185,260,"Save");
   outtextxy(1149,320,"Freehand");
   outtextxy(1175,380,"Circle");
   outtextxy(1180,440,"Clear");
    //outtextxy(1180,500,"Open");
   settextstyle(TRIPLEX_FONT,0,4);
   outtextxy(1138,205,"Rectangle");
   setcolor(color);
}

char change_shape(int x, int y)
{
    char draw;
   if ( x > 1126 && x < 1355 && y > 32 && y < 82 )
   {
       draw='b';
        setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1190,20,"Fill");
       printf("COLOR");
      return 'b';
   }
   else if ( x > 1126 && x < 1355 && y > 90 && y < 143 )
   {
       draw='l';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1190,80,"Line");
       printf("line");
      return 'l';
   }
   else if ( x > 1126 && x < 1355 && y > 150 && y < 204 )
   {
       draw='p';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1187,140,"Pixel ");
      return 'p';
   }
   else if ( x > 1126 && x < 1355 && y > 211 && y < 263 )
   {
       draw='r';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1138,205,"Rectangle");
      return 'r';
   }
   else if (  x > 1126 && x < 1355 && y > 270 && y < 323 )
   {
       draw='e';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1185,260,"Save");
      return 'e';
   }
   else if ( x > 1126 && x < 1355 && y > 331 && y < 383 )
   {
       draw='f';
       printf("freehand\n");
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1149,320,"Freehand");
      return 'f';
   }
   else if ( x > 1126 && x < 1355 && y > 390 && y < 443 )
   {
       draw='d';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1175,380,"Circle");
      return 'd'; /* d is for circle */
   }
   else if ( x > 1126 && x < 1355 && y > 451 && y < 505 )
   {
       draw='c';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1180,440,"Clear");
       printf("erase");
      return 'c';
   }
   else if( x > 1126 && x < 1355 && y > 511 && y < 565 )
   {
       draw='o';
       setviewport(0,0,1365,767,1);
       draw_shape_panel();
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT,0,4);
       outtextxy(1180,500,"Open");
       printf("open");
      return 'o';
   }
}

void line1()
{
    POINT cursorPosition1, cursorPosition2;
    int x=1,y=1,x1, y1, x2, y2,i ;
      setviewport(1,1,1117,687,1);
       setcolor(BLACK);
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
      setviewport(1,1,1117,687,1);
       setcolor(BLACK);
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

void circle1()
{
     POINT cursorPosition1, cursorPosition2;
    int x=1,y=1,x1, y1, x2, y2, radius;
      setviewport(1,1,1117,687,1);
       setcolor(BLACK);
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

void fill()
{
    POINT cursorPosition1;
    int x=1,x1, y1,col1;
      setviewport(1,1,1117,687,1);
    col1=fillcolor();
    setfillstyle(SOLID_FILL,col1);
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
   floodfill(x1, y1,BLACK);

    printf("in fill %d",col1);
   setfillstyle(SOLID_FILL,WHITE);
}

int fillcolor()
{
    POINT cursorPosition1;
    int col,x,y,x1=1;
      setviewport(1,1,1117,687,1);
    printf("in fillcolor");

     while(x1==1)
    {
        GetCursorPos(&cursorPosition1);
        if(GetAsyncKeyState(VK_LBUTTON)& 0x01)
        {
            x=cursorPosition1.x;
            y=cursorPosition1.y;
            x1=0;
            printf("getting color");
        }
        delay(0);

    }

    if ( x > 320 && x < 355 && y > 723 && y < 758 )
   {
      col=1;
      setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(320,700,353,733);
      setcolor(BLACK);
      return 1;
   }

    else if ( x > 385 && x < 420 && y > 723 && y < 758 )
   {
      col=2;
      setviewport(0,0,1365,767,1);
      //printf("green");
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(385,700,417,733);
      setcolor(BLACK);

      return 2;
   }

   else if ( x > 450 && x < 485 && y > 723 && y < 758 )
   {
      col=3;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(450,700,483,733);
      setcolor(BLACK);
      return 3;
   }

   else if ( x > 515 && x < 550 && y > 723 && y < 758 )
   {
      col=4;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(515,700,548,733);
      setcolor(BLACK);
      return 4;
   }

   else if ( x > 580 && x < 615 && y > 723 && y < 758 )
   {
      col=5;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(580,700,613,733);
      setcolor(BLACK);
      return 5;
   }

   else if ( x > 645 && x < 680 && y > 723 && y < 758 )
   {
      col=6;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(645,700,678,733);
      setcolor(BLACK);
      return 6;
   }

   else if ( x > 710 && x < 745 && y > 723 && y < 758 )
   {
      col=7;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(710,700,743,733);
      setcolor(BLACK);
      return 7;
   }

   else if ( x > 775 && x < 810 && y > 723 && y < 758 )
   {
      col=8;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(775,700,808,733);
      setcolor(BLACK);
      return 8;
   }

   else if ( x > 840 && x < 875 && y > 723 && y < 758 )
   {
      col=9;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(840,700,873,733);
      setcolor(BLACK);
      return 9;
   }

   else if ( x > 905 && x < 940 && y > 723 && y < 758 )
   {
      col=10;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(905,700,938,733);
      setcolor(BLACK);
      return 10;
   }

   else if ( x > 970 && x < 1005 && y > 723 && y < 758 )
   {
      col=11;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(970,700,1003,733);
      setcolor(BLACK);
      return 11;
   }

   else if ( x > 1035 && x < 1070 && y > 723 && y < 758 )
   {
      col=12;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(1035,700,1068,733);
      setcolor(BLACK);
      return 12;
   }

   else if ( x > 1100 && x < 1135 && y > 723 && y < 758 )
   {
      col=13;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(1100,700,1133,733);
      setcolor(BLACK);
      return 13;
   }

   else if ( x > 1165 && x < 1200 && y > 723 && y < 758 )
   {
      col=14;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(1165,700,1198,733);
      setcolor(BLACK);
      return 14;
   }

   else if ( x > 1230 && x < 1265 && y > 723 && y < 758 )
   {
      col=15;
       setviewport(0,0,1365,767,1);
       draw_color_panel();
       draw_shape_panel();
       setcolor(WHITE);
      setfillstyle(SOLID_FILL, col);
      rectangle(1230,700,1263,733);
      setcolor(BLACK);
      return 15;
   }
   else
   {
       col=2;
       return 2;
   }

}
