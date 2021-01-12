#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

float d;
float e;
  float* ptrtod;
  float* ptrtoe;

  ptrtod = &d;
  ptrtoe = &e;

  d = 5.4;
  e = 3.7;
  printf("The value of d is %f and the value of e is %f\n", d, e);
  printf("The address of d is %p and the address of e is %p\n", (void*)ptrtod, (void*)ptrtoe);
float b = *ptrtod;
 d = *ptrtoe;
 e = b;
  printf("The value of d is %f and the value of e is %f\n", d, e);
}
