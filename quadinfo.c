#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct funcroots {
  double root1;
  double root2;
};


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

struct funcroots getroot(double a, double b, double c){
  struct funcroots func;
  double discriminant = (b*b)-(4*a*c);
  printf("\nDiscriminant: %f\n", discriminant);
  if (discriminant < 0){
    printf("Your function has no real roots.\n");
  }
  else {

    //If function is linear:
    if (a == 0){
      func.root1 = -c/b;
      printf("First Root: %f\n", func.root1);
      if (b >= 0) {
        printf("Quadratic in factored form: %fx + %f", b, c);
      }
      else{
        printf("Quadratic in factored form: %fx - %f", b, -c);
      }
    }

    //If function is quadratic:
    else {
      func.root1 = (0-b+sqrt(discriminant))/(2*a);
      func.root2 = (0-b-sqrt(discriminant))/(2*a);
      if (func.root1 == func.root2){
        printf("Double Root: %f\n", func.root1);
      }
      else {
        printf("First Root: %f\n", func.root1);
        printf("Second Root: %f\n", func.root2);
      }
      
      //Quadratic with a-value of 1, print.
      if (a!=1){
        if (func.root1 >= 0 && func.root2 >= 0){
          printf("Quadratic in factored form: %f(x-%f)(x-%f)\n", a, func.root1, func.root2);
        }
        else if (func.root1 <= 0 && func.root2 >= 0){
          printf("Quadratic in factored form: %f(x+%f)(x-%f)\n", a, 0-func.root1, func.root2);
        }
        else if (func.root2 <= 0 && func.root1 >= 0){
          printf("Quadratic in factored form: %f(x-%f)(x+%f)\n", a,func.root1, 0-func.root2);
        }
        else if (func.root1 <= 0 && func.root2 <= 0){
          printf("Quadratic in factored form: %f(x+%f)(x+%f)\n", a,0-func.root1, 0-func.root2);
        }
      }
      //Quadratic with other a-value, print.
      else{
        if (func.root1 >= 0 && func.root2 >= 0){
          printf("Quadratic in factored form: (x-%f)(x-%f)\n",  func.root1, func.root2);
        }
        else if (func.root1 <= 0 && func.root2 >= 0){
          printf("Quadratic in factored form: (x+%f)(x-%f)\n",  0-func.root1, func.root2);
        }
        else if (func.root2 <= 0 && func.root1 >= 0){
          printf("Quadratic in factored form: (x-%f)(x+%f)\n", func.root1, 0-func.root2);
        }
        else if (func.root1 <= 0 && func.root2 <= 0){
          printf("Quadratic in factored form: (x+%f)(x+%f)\n", 0-func.root1, 0-func.root2);
        }
      }

      //Other values close to thing.
      printf("\nHere are some coordinates close to the roots: \n");

      printf("Root 1: ");
        for (double i=func.root1-2; i<=func.root1+2; i++){
          printf("(%f, %f)", i, a*i*i+b*i+c);
        }
      if(func.root1 != func.root2){
        printf("\nRoot 2: ");
        for (double i=func.root2-2; i<=func.root2+2; i++){
          printf("(%f, %f)", i, a*i*i+b*i+c);
        }
      }  
    }
  } 
  return func;
}

int main(int argc, char* argv[])
{

  if (argc != 4){
    printf("Please enter values into all three variables.\n");
  }

  else {

  //define variables
    char *tempa;
    char *tempb;
    char *tempc;
    char *achar = argv[1];
    double a = strtof(achar, &tempa);
    char *bchar = argv[2];
    double b = strtof(bchar, &tempb);
    char *cchar = argv[3];
    double c = strtof(cchar, &tempc);

    if (tempa==achar || tempb==bchar || tempc==cchar){
      printf("Please enter real numbers into all three variables.\n");
    } 

    else if(tempa[strspn(tempa, " \t\r\n")] != '\0' || tempb[strspn(tempb, " \t\r\n")] != '\0' || tempc[strspn(tempc, " \t\r\n")] != '\0'){
      printf("Please enter only real numbers into all three variables and remove invalid trailing characters.\n");
    }

    else{
      printf("You entered %f, %f, and %f.\n", a, b, c);
      getroot(a, b, c);
      printf("\n\n\n");
      doVertex(a, b, c);
    }

    

  }
  }




