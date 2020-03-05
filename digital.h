#ifndef DIGITAL_H_INCLUDED
#define DIGITAL_H_INCLUDED

enum light{OFF,ON};
namespace digital{
    void colon(int x,int y){
        glColor3f(0.9,0,0);
        glBegin(GL_QUADS);
            glVertex2f(0+x,-25+y);
            glVertex2f(9+x,-25+y);
            glVertex2f(9+x,-25-9+y);
            glVertex2f(0+x,-25-9+y);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2f(0+x,-25-40-9+y);
            glVertex2f(9+x,-25-40-9+y);
            glVertex2f(9+x,-25-9-40-9+y);
            glVertex2f(0+x,-25-9-40-9+y);
        glEnd();
    }

    void sevenSegmentDisplay(int a,int b,int c,int d,int e, int f, int g,int x, int y){
        int width = 9,height = 40;
        if(a==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(width+x,0+y);
            glVertex2f(width+height+x,0+y);
            glVertex2f(width+height+x,-width+y);
            glVertex2f(width+x,-width+y);
        glEnd();
        if(b==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(width+height+x,-width+y);
            glVertex2f(2*width+height+x,-width+y);
            glVertex2f(2*width+height+x,-width-height+y);
            glVertex2f(width+height+x,-width-height+y);
        glEnd();
        if(c==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(width+height+x,-width*2-height+y);
            glVertex2f(2*width+height+x,-width*2-height+y);
            glVertex2f(2*width+height+x,-width*2-height*2+y);
            glVertex2f(width+height+x,-width*2-height*2+y);
        glEnd();

        if(d==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(width+x,-2*width-2*height+y);
            glVertex2f(width+height+x,-2*width-2*height+y);
            glVertex2f(width+height+x,-3*width-2*height+y);
            glVertex2f(width+x,-3*width-2*height+y);
        glEnd();

        if(e==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(0+x,-width*2-height+y);
            glVertex2f(width+x,-width*2-height+y);
            glVertex2f(width+x,-width*2-height*2+y);
            glVertex2f(0+x,-width*2-height*2+y);
        glEnd();

        if(f==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(0+x,-width+y);
            glVertex2f(width+x,-width+y);
            glVertex2f(width+x,-width-height+y);
            glVertex2f(0+x,-width-height+y);
        glEnd();

        if(g==1){
            glColor3f(0.9,0,0);
        }else{
            glColor3f(0,0,0);
        }
        glBegin(GL_QUADS);
            glVertex2f(width+x,-width-height+y);
            glVertex2f(width+height+x,-width-height+y);
            glVertex2f(width+height+x,-2*width-height+y);
            glVertex2f(width+x,-2*width-height+y);
        glEnd();

    }

    void displayNum(int n,int x,int y){
        switch (n){
        case 0:
            sevenSegmentDisplay(1,1,1,1,1,1,0,x,y);
            break;
        case 1:
            sevenSegmentDisplay(0,1,1,0,0,0,0,x,y);
            break;
        case 2:
            sevenSegmentDisplay(1,1,0,1,1,0,1,x,y);
            break;
        case 3:
            sevenSegmentDisplay(1,1,1,1,0,0,1,x,y);
            break;
        case 4:
            sevenSegmentDisplay(0,1,1,0,0,1,1,x,y);
            break;
        case 5:
            sevenSegmentDisplay(1,0,1,1,0,1,1,x,y);
            break;
        case 6:
            sevenSegmentDisplay(1,0,1,1,1,1,1,x,y);
            break;
        case 7:
            sevenSegmentDisplay(1,1,1,0,0,0,0,x,y);
            break;
        case 8:
            sevenSegmentDisplay(1,1,1,1,1,1,1,x,y);
            break;
        case 9:
            sevenSegmentDisplay(1,1,1,1,0,1,1,x,y);
            break;
        default:
            break;
        }
    }

    void displayDigital(int hr, int minute,int sec){
        printf("%d : %d : %d\n",hr,minute,sec);
        int sec1,sec0;
        int min1,min0;
        int hr1,hr0;
        sec0 = sec%10;
        sec1 = (sec/10)%10;
        min0 = minute%10;
        min1 = (minute/10)%10;
        hr0 = hr%10;
        hr1 = (hr/10)%10;

        printf("conv %d%d:%d%d:%d%d\n",hr1,hr0,min1,min0,sec1,sec0);
        displayNum(sec0,200,-250);
        displayNum(sec1,130,-250);
        colon(100,-250);
        displayNum(min0,00,-250);
        displayNum(min1,-70,-250);
        colon(-100,-250);
        displayNum(hr0,-200,-250);
        displayNum(hr1,-270,-250);
    }
}

#endif // DIGITAL_H_INCLUDED
