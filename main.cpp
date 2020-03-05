#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include"digital.h"
#define pi 3.1415926

void init()
{
    // For displaying the window color
    glClearColor(0, 0, 0, 0);
    // Choosing the type of projection
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(3);
    // for setting the transformation which here is 2D
    gluOrtho2D(-300,300,-400,300);
}

void drawCircle(int radius)
{
    float x,y;
    glPointSize(6);
    for(float i=0;i<2*pi;i+=0.01){
        x = radius * cos(i);
        y = radius * sin(i);
        glColor3f(0.9,.9,y/radius);
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        glEnd();
    }
}

void drawOuter(int radius)
{
    float x ,y,x1,y1;
    glLineWidth(3);
    int a = 5;
    int co = 0;
    for(float i=0;i<2*pi;i+=2*pi/60){
        x = radius * cos(i);
        y = radius * sin(i);
        x1 = (radius-a) * cos(i);
        y1 = (radius-a) * sin(i);
        glColor3f(0.9,0.9,y/radius);
        glBegin(GL_LINES);
            glVertex2f(x,y);
            glVertex2f(x1,y1);
        glEnd();
        co++;
        if(co%5==0){
            a = 25;
            glLineWidth(5);
        }else{
            a = 10;
            glLineWidth(3);
        }
    }
}

float degtorad(float deg)
{
    return pi/180*deg;
}
void drawHand(float x, int n,int L,int width){
    float deg = (float)x/n*360;
    deg = -deg+90;
    float rad = degtorad(deg);
    float xc,yc;
    xc = L * cos(rad);
    yc = L * sin(rad);
    float xt,yt;
    glLineWidth(width);
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(xc,yc);
    glEnd();
}
void display()
{
    time_t rawtime;
    tm *info;
    time(&rawtime);
    info = gmtime(&rawtime);

    float sec=info->tm_sec,minute=info->tm_min + 45,hr=info->tm_hour + 5;
    if(minute>=60){
        minute=minute-60;
        hr++;
    }
    if(hr>=24){
        hr=hr-24;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    drawOuter(200);
    drawCircle(200+20);
    drawCircle(5);
    //Second Hand
    drawHand(sec,60,130,3);
    //Minute Hand
    drawHand(minute+sec/60,60,150,4);
    //Hour Hand
    drawHand(hr+minute/60+sec/3600,12,100,6);
    digital::displayDigital(hr,minute,sec);
    glFlush();

}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/25,timer,0);
}
int main(int agrc, char ** argv)
{
    // Initialize GLUT
    glutInit(&agrc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(600, 700);
    // Create display window with the given title
    glutCreateWindow("Analog Clock");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(display);

    glutTimerFunc(0,timer,0);
    // Display everything and wait.
    glutMainLoop();
}

