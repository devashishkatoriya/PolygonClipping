//Program to implement Sutherland-Hodgeman Polygon Clipping Algorithm

/*
 * Created be Devashish Katoriya on 28-03-2017
 */

#include <iostream>
#include <graphics.h>

using namespace std;

#define LIMIT 50

int xl,yl,xh,yh;

void draw(int x[],int y[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        line(x[i], y[i], x[i+1], y[i+1]);
    }
    line(x[0], y[0], x[n-1], y[n-1]);
}

void leftClip(int x[],int y[],int *n)
{
    int tempX[LIMIT],tempY[LIMIT],i,j,count,x1,x2,y1,y2;
    j = 0;
    count = 0;
    for(i=0;i<(*n);i++)
    {
        x1 = x[i];
        x2 = x[i+1];
        y1 = y[i];
        y2 = y[i+1];
        if(x1<xl && x2<xl)
        {
            //both pts are outside, so store none of them
        }
        else if(x1>xl && x2>xl)
        {
            //both pts are inside, store the second vertex
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else if(x1<xl && x2>xl)
        {
            //from outside to inside, store intersection and second vertex
            int X = xl;
            int Y = y1 + (((xl-x1)*(y1-y2))/(x1-x2));

            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else
        {
            //inside to outside, store the intersection only
            int X = xl;
            int Y = y1 + (((xl-x1)*(y2-y1))/(x2-x1));
            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
        }
    }

    x1 = x[*n-1];
    x2 = x[0];
    y1 = y[*n-1];
    y2 = y[0];
    if(x1<xl && x2<xl)
    {
        //both pts are outside, so store none of them
    }
    else if(x1>xl && x2>xl)
    {
        //both pts are inside, store the second vertex
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else if(x1<xl && x2>xl)
    {
        //from outside to inside, store intersection and second vertex
        int X = xl;
        int Y = y1 + (((xl-x1)*(y1-y2))/(x1-x2));

        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else
    {
        //inside to outside, store the intersection only
        int X = xl;
        int Y = y1 + (((xl-x1)*(y2-y1))/(x2-x1));
        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
    }

    *n = count;
    for(i=0;i<*n;i++)
    {
        x[i] = tempX[i];
        y[i] = tempY[i];
    }
}

void rightClip(int x[],int y[],int *n)
{
    int tempX[LIMIT],tempY[LIMIT],i,j,count,x1,x2,y1,y2;
    j = 0;
    count = 0;
    for(i=0;i<(*n)-1;i++)
    {
        x1 = x[i];
        x2 = x[i+1];
        y1 = y[i];
        y2 = y[i+1];
        if(x1>xh && x2>xh)
        {
            //both pts are outside, so store none of them
        }
        else if(x1<xh && x2<xh)
        {
            //both pts are inside, store the second vertex
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else if(x1>xh && x2<xh)
        {
            //from outside to inside, store intersection and second vertex
            int X = xh;
            int Y = y1 + (((xh-x1)*(y2-y1))/(x2-x1));

            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else
        {
            //inside to outside, store the intersection only
            int X = xh;
            int Y = y1 + (((xh-x1)*(y2-y1))/(x2-x1));
            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
        }
    }



    x1 = x[*n-1];
    x2 = x[0];
    y1 = y[*n-1];
    y2 = y[0];
    if(x1>xh && x2>xh)
    {
        //both pts are outside, so store none of them
    }
    else if(x1<=xh && x2<=xh)
    {
        //both pts are inside, store the second vertex
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else if(x1>xh && x2<xh)
    {
        //from outside to inside, store intersection and second vertex
        int X = xh;
        int Y = y1 + (((xh-x1)*(y2-y1))/(x2-x1));

        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else
    {
        //inside to outside, store the intersection only
        int X = xh;
        int Y = y1 + (((xh-x1)*(y2-y1))/(x2-x1));
        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
    }


    *n = count;
    for(i=0;i<*n;i++)
    {
        x[i] = tempX[i];
        y[i] = tempY[i];
    }
}

void topClip(int x[],int y[],int *n)
{
    int tempX[LIMIT],tempY[LIMIT],i,j,count,x1,x2,y1,y2;
    j = 0;
    count = 0;
    for(i=0;i<(*n)-1;i++)
    {
        x1 = x[i];
        x2 = x[i+1];
        y1 = y[i];
        y2 = y[i+1];
        if(y1<yl && y2<yl)
        {
            //both pts are outside, so store none of them
        }
        else if(y1>yl && y2>yl)
        {
            //both pts are inside, store the second vertex
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else if(y1<yl && y2>yl)
        {
            //from outside to inside, store intersection and second vertex
            int X = x1 + (((yl-y1)*(x2-x1))/(y2-y1));
            int Y = yl;

            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else
        {
            //inside to outside, store the intersection only
            int X = x1 + (((yl-y1)*(x2-x1))/(y2-y1));
            int Y = yl;
            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
        }
    }




    x1 = x[*n-1];
    x2 = x[0];
    y1 = y[*n-1];
    y2 = y[0];
    if(y1<yl && y2<yl)
    {
        //both pts are outside, so store none of them
    }
    else if(y1>yl && y2>yl)
    {
        //both pts are inside, store the second vertex
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else if(y1<yl && y2>yl)
    {
        //from outside to inside, store intersection and second vertex
        int X = x1 + (((yl-y1)*(x2-x1))/(y2-y1));
        int Y = yl;

        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else
    {
        //inside to outside, store the intersection only
        int X = x1 + (((yl-y1)*(x2-x1))/(y2-y1));
        int Y = yl;
        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
    }







    *n = count;
    for(i=0;i<*n;i++)
    {
        x[i] = tempX[i];
        y[i] = tempY[i];
    }
}

void bottomClip(int x[],int y[],int *n)
{
    int tempX[LIMIT],tempY[LIMIT],i,j,count,x1,x2,y1,y2;
    j = 0;
    count = 0;
    for(i=0;i<(*n)-1;i++)
    {
        x1 = x[i];
        x2 = x[i+1];
        y1 = y[i];
        y2 = y[i+1];
        if(y1>yh && y2>yh)
        {
            //both pts are outside, so store none of them
        }
        else if(y1<yh && y2<yh)
        {
            //both pts are inside, store the second vertex
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else if(y1>yh && y2<yh)
        {
            //from outside to inside, store intersection and second vertex
            int X = x1 + ((yh-y1)*(x2-x1))/(y2-y1);
            int Y = yh;

            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
            tempX[j] = x2;
            tempY[j] = y2;
            j++;
            count++;
        }
        else
        {
            //inside to outside, store the intersection only
            int X = x1 + ((yh-y1)*(x2-x1))/(y2-y1);
            int Y = yh;
            tempX[j] = X;
            tempY[j] = Y;
            j++;
            count++;
        }
    }


    x1 = x[*n-1];
    x2 = x[0];
    y1 = y[*n-1];
    y2 = y[0];
    if(y1>yh && y2>yh)
    {
        //both pts are outside, so store none of them
    }
    else if(y1<yh && y2<yh)
    {
        //both pts are inside, store the second vertex
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else if(y1>yh && y2<yh)
    {
        //from outside to inside, store intersection and second vertex
        int X = x1 + ((yh-y1)*(x2-x1))/(y2-y1);
        int Y = yh;

        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
        tempX[j] = x2;
        tempY[j] = y2;
        j++;
        count++;
    }
    else
    {
        //inside to outside, store the intersection only
        int X = x1 + ((yh-y1)*(x2-x1))/(y2-y1);
        int Y = yh;
        tempX[j] = X;
        tempY[j] = Y;
        j++;
        count++;
    }





    *n = count;
    for(i=0;i<*n;i++)
    {
        x[i] = tempX[i];
        y[i] = tempY[i];
    }
}

int main()
{
    int x[LIMIT],y[LIMIT],n,i;
    char ch;
    int gd,gm;
    gd = DETECT;
    initgraph(&gd,&gm,NULL);

    cout<<"\nEnter the windows co-ordinates :- \n";
    cin>>xl>>yl>>xh>>yh;

    do
    {
        cleardevice();
        setcolor(BLUE);
        rectangle(xl,yl,xh,yh);
        ch = 'n';
        cout<<"\nEnter how many vertices ? ";
        cin>>n;
        cout<<"\nEnter the vertices :- \n";
        for(i=0;i<n;i++)
        {
            cout<<"\n";
            cin>>x[i]>>y[i];
        }
        draw(x,y,n);

        leftClip(x,y,&n);
        rightClip(x,y,&n);
        topClip(x,y,&n);
        bottomClip(x,y,&n);

        setcolor(WHITE);
        draw(x,y,n);
        cout<<"\nDo you want to continue (y/n) ? ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    closegraph();
    cout<<"\nThank you for using this program :)";
    return 0;
}

// Window - 100 100 400 400
// 4 - 50 150 150 125 150 325 50 350    //left
// 4 - 50 125 150 125 150 325 50 325    //left
// 4 - 50 150 450 125 450 325 50 350    //left-right

// 4 - 50 50 150 25 150 325 50 350      //left-top
// 4 - 50 150 150 125 150 425 50 450    //left-bottom
// 4 - 50 50 150 25 150 425 50 450      //left-bottom-top
// 4 - 50 150 450 125 450 425 50 450    //left-right-bottom
// 4 - 50 50 450 25 450 325 50 350      //left-right-top