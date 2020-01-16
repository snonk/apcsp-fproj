#include <stdio.h>
#include <stdlib.h>


float findVX(float a, float b) {
  float vx = -b / (2 * a);
  if (vx == 0){
    return 0;
  }
  else {
    return vx;
  }
}

float findY(float a, float b, float c, float x) {
  float y = (a * x * x) + (b * x) + c;
  return y;
}

void printvform(float a,float vx,float y) {
  //printf("The vertex form is %f(x-%f)+%f\n",a,vx,y);
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
    if (y > 0) {
      printf("+%f\n",y);
    }
    else if (y < 0) {
      printf("%f\n",y);
    }
    else {
      printf("\n");
    }
  }
  else {
    float tmp = vx + y;
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

void rpoints(float vx, float a, float b, float c) {
  printf("Some points near the vertex are: \n");
  float tempx;
  float tempy;
  for (int i = -3; i <= 3; i++) {
    tempx = vx + i;
    tempy = findY(a,b,c,tempx);
    printf("(%f, %f)\n",tempx,tempy);
  }
}

void doVertex (float a, float b, float c) {
  float vx = findVX(a,b);
  float vy = findY(a,b,c,vx);
  printf("The vertex is (%f, %f)\n", vx, vy);
  printvform(a,vx,vy);
  rpoints(vx,a,b,c);
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
    
    doVertex(a,b,c);
    return 0;
    
  }
  else {
    printf("Please enter a valid number for each argument.\n");
    return 0;
  }
}
