//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

struct Student {
char* firstName;
char* lastName;
unsigned int age;
long id;
};

void createStudent(char* fname, char* lname, int age, int id)
{
Student *student = (Student*)malloc(sizeof(Student));
student->firstName = (char*)malloc(sizeof(&fname));
student->lastName = (char*)malloc(sizeof(&lname));
strcpy(student->firstName, fname);
strcpy(student->lastName, lname);
student->age = age;
student->id = id;
students[numStudents] = student;
numStudents++;
}


void deleteStudent(Student* student)
{
free(student->firstName);
free(student->lastName);
free(student);
  
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
for (int i = 0; i < numStudents; i++)
{
deleteStudent(students[i]);
students[i] = 0;
}
numStudents = 0;
}


void saveStudents(int key)
{
FILE* fp;
fp = fopen("studentdata.txt", "w");
char buff[256];
if (fp)
{
for (int i = 0; i < numStudents; i++)
{          
	Student* student = students[i];   
	sprintf(buff, "%s %s %d %ld", student->firstName, student->lastName, student->age, student->id);
	   if (key != 0)
	   {
		caesarEncrypt(buff, key);
}
		printf("saving: %s\n", buff);
		fprintf(fp, "%s\n", buff);	  
		}
fclose(fp);
}
}


void loadStudents(int key)
{
   char buf1[256];
        char buf2[256];
        char buf3[256];
        char buf4[256];
if (numStudents < 0)
{
deleteStudents();
}

FILE* fp;
fp = fopen("studentdata.txt", "r");
if (fp)
{
	while(1){
	int match = fscanf(fp, "%s %s %s %s", buf1, buf2, buf3, buf4);
	if (match == 4)
	{
		if (key != 0)
			{
			caesarDecrypt(buf1, key);
			caesarDecrypt(buf2, key);
			caesarDecrypt(buf3, key);
			caesarDecrypt(buf4, key);
			}
		int age;
		long id;
		sscanf(buf3, "%d", &age);
		sscanf(buf4, "%ld", &id);
		createStudent(buf1, buf2, age, id);
	}
else
	break;
}
	printf("loaded %d students", numStudents);
	fclose(fp);
}
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




