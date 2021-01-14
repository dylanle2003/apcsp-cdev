#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

int areaOfCircle(float radius)
{
float a;
a = M_PI* radius * radius * radius;
return a;
}

int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
 // for testing only - do not change
char input[256];
  float radius;
  float radius2;
  printf("Enter the first radius\n");
while (1)
{  
fgets(input, 256, stdin);
 if (sscanf(input, "%f", radius) == 1 && input > 0) break;
printf("not a valid positive number -- try again\n");
 } 

printf("Enter the second radius\n");
while (1)
{
fgets(input, 256, stdin);
if (sscanf(input, "%f", radius2) == 1 && radius2 > radius) break;
printf("pick a number greater than the first radius\n");
}

    
  // add your code below to call areaOfCircle function with values between
  // start and end

printf("lower input: %f\n", radius);
printf("upper input: %f\n", radius2);
for (int i = radius; i < radius2; i++)
{
printf("area of circle with radius of %f: %f\n", i, areaOfCircle(i));
}


  
}
