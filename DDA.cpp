#include<iostream>
#include<GL/glut.h>
using namespace std;

int Algo, type;

void Init()
{ 
 glClearColor(0,0,0,0);
 glColor3f(0,1,0);
 gluOrtho2D(0,640,0,480);
 glClear(GL_COLOR_BUFFER_BIT);
}

int sign(float a){

 if(a==0){
   return 0;
   }
   
 if(a>0){
   return 1;
   }
 return -1;
}

void B_Line(int x_1,int y_1,int x_2,int y_2,int t){
  float dy, dx, m, P;
  dy = y_2 - y_1;
  dx = x_2 - x_1;
  
  m = dy/dx;
  
  P = 2*dy - dx;
  
  int x = x_1, y = y_1;
  cout<<"\n x1 = " <<x<<" y1= "<<y;
  if (m<1){
     int cnt=1;
     for(int i=0; i<=dx;i++) {
        if (t == 1){
             glBegin(GL_POINTS);
                 glVertex2i(x,y);
             glEnd();
        }
        if (t == 2) {
          if(i%2==0){
              glBegin(GL_POINTS);
                  glVertex2i(x,y)
              glEnd();
          }
       }
       if(t == 3){
          if(cnt <= 10){
          glBegin(GL_POINTS)
              glVertex2i(x,y);
          glEnd();
       }
       cnt++;
       if(cnt == 15){
          cnt = 1;
          }
       }
       
       if(P<0){
         x = x +1;
         y = y;
         P = P + 2*dy - 2*dx;
         }
       else{
         x = x+1;
         y = y+1;
         P = P + 2*dy - 2*dx;
         }
       }
  }
  else{
    int cnt = 1;
    for(int i=0; i<=dy;i++){
    if(t == 1){
     glBegin(GL_POINTS);
       glVertex2i(x,y);
     glEnd();
    }
    if(t ==2){
      if(i%2==0){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        }
     }
     if(t == 3){
     if(cnt <= 10){
       glBegin(GL_POINTS);
         glVertex2i(x,y);
