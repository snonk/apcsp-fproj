#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct funcroots {
  float root1;
  float root2;
};

struct funcroots getroot(float a, float b, float c){
  struct funcroots func;
  float discriminant = (b*b)-(4*a*c);
  float root1 = (-b+sqrt(discriminant))/2/a;
  float root2 = (-b-sqrt(discriminant))/2/a;
  printf("First Root: %f", func.root1);
  printf("Second Root: %f", func.root2);
  if (func.root1 > 0 && func.root2 > 0){
    printf("Quadratic in factored form: (x-%f)(x-%f)", func.root1, func.root2);
  }
  else if (func.root1 < 0){
    printf("Quadratic in factored form: (x%f)(x-%f)", func.root1, func.root2);
  }
  else if (func.root2 < 0){
    printf("Quadratic in factored form: (x-%f)(x%f)", func.root1, func.root2);
  }
  else if (func.root1 < 0 && func.root2 < 0){
    printf("Quadratic in factored form: (x%f)(x%f)", func.root1, func.root2);
  }
  else if (func.root1 == 0){
    printf("Quadratic in factored form: (x)(x%f)", func.root2);
  }
  else if (func.root2 == 0){
    printf("Quadratic in factored form: (x)(x%f)", func.root1);
  }
  else{
    printf("0");
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
    float a = strtof(achar, NULL);
    char *bchar = argv[2];
    float b = strtof(bchar, NULL);
    char *cchar = argv[3];
    float c = strtof(cchar, NULL);

    printf("%f %f %f", a, b, c);

  }
  }




