#include<stdio.h>

int main()
{
  int a = 54;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
 char b = 'd';

  // print value and size of an char variable
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));
float c = 12.345;

  // print value and size of an char variable
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));
double d = 123.456;

  // print value and size of an char variable
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
signed int e = -4;

  // print value and size of an char variable
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));
long int f = 24;

  // print value and size of an char variable
  printf("long int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

