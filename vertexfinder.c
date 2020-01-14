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

void printvform(float a, float c,float vx,float vy) {
  if(vx < 0) {
    if (a == 1) {
      if (vx > 0){
        printf("The vertex form is (x-%f)+%f\n",vx,vy);
      }
      else {
        printf("The vertex form is (x%f)+%f\n",vx,vy);
      }
    }
    else if (vy == 0){
      printf("The vertex form is (x-%f)\n",vx);
    }
    else {
      printf("The vertex form is %f(x%f)+%f\n",a,vx,vy);
    }

  }
  else if (vx == 0) {
    printf("The vertex form is %fx+%f\n",a,vy);
  }
  else {
    printf("The vertex form is %f(x-%f)+%f\n",a,vx,vy);
  }
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

    float vx = findVX(a,b);
    float vy = findVY(a,b,c,vx);
    printf("The vertex is (%f,%f)\n", vx, vy);
    printvform(a,c,vx,vy);
    
  }
  else {
    printf("Please enter a valid number for each argument.\n");
  }
}
