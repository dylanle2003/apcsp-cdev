#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student structure
//struct Student...
struct Student {
char first[1000];
char last [1000];
int age;
int id;
};

void printStudent(struct Student* student)
{
printf("First name: %s\n", student -> first);
printf("Last name: %s\n", student -> last);
printf("Age: %d\n", student -> age);
printf("ID: %d\n", student -> id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
for (int i = 0; i < num; i++)
{
printf("------------student %d ------- \n", num);
printStudent(&students[i]);
}
}


int main()
{

  // an array of students
  //xxx students;
struct Student studentArr[15];
char input[256];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(studentArr, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
    printf("What is your first name?\n");
fgets ( studentArr[numStudents].first, 50, stdin);
printf("What is your last name?\n");
fgets ( studentArr[numStudents].last, 50, stdin);
printf("What is your age?\n");
scanf("%d", &studentArr[numStudents].age);
printf("What is your id?\n");
scanf("%d", &studentArr[numStudents].id);
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
