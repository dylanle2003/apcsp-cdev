#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
 int d = a; 
  a = c;

  c = d;
  printf("values of a: %d, b: %d, and c: %d\n", a, b, c);
}
