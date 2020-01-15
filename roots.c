#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct funcroots {
  double root1;
  double root2;
};

struct funcroots getroot(double a, double b, double c){
  struct funcroots func;
  double discriminant = (b*b)-(4*a*c);
  printf("\nDISC: %f\n", discriminant);
  printf("\nSQRT: %f\n", sqrt(discriminant));
  if (discriminant < 0){
    printf("Your function has no real roots.\n");
  }
  else if (a == 0){
    func.root1 = -c/b;
    printf("First Root: %f\n", func.root1);
    if (b >= 0) {
      printf("Quadratic in factored form: %fx + %f", b, c);
    }
    else{
      printf("Quadratic in factored form: %fx - %f", b, -c);
    }
  }
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

    char *achar = argv[1];
    double a = strtof(achar, NULL);
    char *bchar = argv[2];
    double b = strtof(bchar, NULL);
    char *cchar = argv[3];
    double c = strtof(cchar, NULL);

    printf("%f %f %f", a, b, c);
    getroot(a, b, c);

  }
  }




