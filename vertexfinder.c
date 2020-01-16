#include <stdio.h>
#include <stdlib.h>


double findVX(double a, double b) {
  double vx = -b / (2 * a);
  if (vx == 0){
    return 0;
  }
  else {
    return vx;
  }
}

double findY(double a, double b, double c, double x) {
  double y = (a * x * x) + (b * x) + c;
  return y;
}

void printvform(double a,double vx,double y) {
  //printf("The vertex form is %f(x-%f)+%f\n",a,vx,y);
  printf("The vertex form is ");
  if (a != 1) {
      printf("%f",a);  
      printf("(x");
    if (vx > 0) {
      printf("-%f",vx);
    }
    else if (vx < 0) {
      double tmp = vx * -1;      
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
    double tmp = vx + y;
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

void rpoints(double vx, double a, double b, double c) {
  printf("Some points near the vertex are: \n");
  double tempx;
  double tempy;
  for (int i = -3; i <= 3; i++) {
    tempx = vx + i;
    tempy = findY(a,b,c,tempx);
    printf("(%f, %f)\n",tempx,tempy);
  }
}

void doVertex (double a, double b, double c) {
  double vx = findVX(a,b);
  double vy = findY(a,b,c,vx);
  printf("The vertex is (%f, %f)\n", vx, vy);
  printvform(a,vx,vy);
  rpoints(vx,a,b,c);
}

int main (int argc, char* argv[]) {
  if (argc == 4) {
    double a = atoi(argv[1]);
    double b = atoi(argv[2]);
    double c = atoi(argv[3]);
    
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
