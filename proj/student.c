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


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
Student* st = (Student*)malloc(50*sizeof(Student));
st -> firstName = (char*)malloc(50*sizeof(char));
st -> lastName = (char*)malloc(50*sizeof(char));
strcpy(st->firstName, fname); 
strcpy(st->lastName, lname);
st->age = age;
st->id = id;
students[numStudents]=st;
numStudents++;
}


void deleteStudent(Student* student)
{
free(student->firstName);
free(student->lastName);
free(student); 
 // free the memory associated with a student including the strings
}


void deleteStudents()
{
  for (int i =0; i < numStudents; i++)
{
    deleteStudents(students[i]);
    students[i] = 0;
}
numStudents = 0;
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
}


void saveStudents(int key)
{ 
FILE* fp;
fp = fopen("studentdata.txt", "w");
char ab[256];
char ib[256];
  if (fp){
    for (int i = 0; i < numStudents; i++)
{
      sprintf(ab, "%d", students[i]->age);
      sprintf(ib, "%ld", students[i]->id);
      caesarEncrypt(students[i]->firstName, key);
      caesarEncrypt(students[i]->lastName, key);
      caesarEncrypt(ab, key);
      caesarEncrypt(ib, key);
      fprintf(fp, "%s %s %s %s\n", students[i]->firstName, students[i]->lastName, ab, ib);
      printf("Saved: %s %s %s %s\n", students[i]->firstName, students[i]->lastName, ab, ib);
}}
fclose(fp);
}


void loadStudents(int key)
{
char b1 [256];
char b2 [256];
char b3 [256];
char b4 [256];
  if (numStudents > 0)
{
    deleteStudents();
} else {
FILE* fp;
fp = fopen("studentdata.txt", "r");
  if (fp){
    while(1){
    if (fscanf(fp, "%s %s %s %s\n", b1, b2, b3, b4) == 4)
{
      int age;
      long id;
      caesarDecrypt(b1, key);
      caesarDecrypt(b2, key);
      caesarDecrypt(b3, key);
      caesarDecrypt(b4, key);
      sscanf(b3, "%d", &age);
      sscanf(b4, "%ld", &id);
      createStudent(b1, b2, age, id);
      printf("Loaded: %s %s %d %ld", b1, b2, age, id);
}   else{
      break;
}}}
      fclose(fp);
}}

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




