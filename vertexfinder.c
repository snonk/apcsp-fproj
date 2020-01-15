#include <stdio.h>
#include <stdlib.h>


float findVX(float a, float b) {
  float vx = -b / (2 * a);
  return vx;
}

float findVY(float a, float b, float c, float vx) {
  float vy = (a * vx * vx) + (b * vx) + c;
  return vy;
}

void printvform(float a,float vx,float vy) {
  //printf("The vertex form is %f(x-%f)+%f\n",a,vx,vy);
  printf("The vertex form is ");
  if (a != 1) {
      printf("%f",a);  
      printf("(x");
    if (vx > 0) {
      printf("-%f",vx);
    }
    else if (vx < 0) {
      float tmp = vx * -1;      
      printf("+%f",tmp);
    }
    printf(")^2");
    if (vy > 0) {
      printf("+%f\n",vy);
    }
    else if (vy < 0) {
      printf("%f\n",vy);
    }
    else {
      printf("\n");
    }
  }
  else {
    float tmp = vx + vy;
    if (tmp > 0) {
      printf("x^2+%f\n",tmp);
    }
    else if (tmp < 0) {
      printf("x^2%f\n",tmp);
    }
    else {
      printf("x^2\n");
    }
    //printf("");
  }
}

void doall (float a, float b, float c) {
  float vx = findVX(a,b);
  float vy = findVY(a,b,c,vx);
  printf("The vertex is (%f,%f)\n", vx, vy);
  printvform(a,vx,vy);
}

int main (int argc, char* argv[]) {
  if (argc == 4) {
    float a = atoi(argv[1]);
    float b = atoi(argv[2]);
    float c = atoi(argv[3]);
    
    if (a == 0) {
      printf("Please enter a valid number for each argument.\n");
      return 0;
    }
    
    doall(a,b,c);
    return 0;
    
  }
  else {
    printf("Please enter a valid number for each argument.\n");
    return 0;
  }
}
