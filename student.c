#include <stdio.h>
#include <string.h>


// student structure
//struct Student...
struct Student {
char firstname[256];
char lastname[256];
int age;
int studentid;
};

void printStudent(struct Student* student)
{
printf("%s, %s\n", student->firstname, student->lastname);
printf("Age:%d,id: %d\n", student->age, student->studentid);  
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
for (int i=0;i<num;i++){
printf("Student %d\n",i);
printStudent(&students[i]);
}

}


int main()
{
struct Student students[20];
  // an array of students
  //xxx students;


  int numStudents = 0;
  while (1)
  {
	char input[256];
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
      // print all student
printAllStudents(students, numStudents);
    //printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
char input[256];
printf("firstname?\n");
fgets(input, 256, stdin);
strcpy(students[numStudents].firstname, input);

printf("lastname?\n");
fgets(input, 256, stdin);
strcpy(students[numStudents].lastname, input);

printf("age?\n");
int ageTemp;
while (1)
{
fgets(input, 256, stdin);
if (sscanf(input,"%d", &ageTemp)==1) break;
printf("Not valid, try again!\n");
}
students[numStudents].age = ageTemp;
printf("id?\n");
int idTemp;
while (1)
{
fgets(input, 256, stdin);
if (sscanf(input,"%d", &idTemp)==1) break;
printf("Not valid, try again!\n");
}
students[numStudents].studentid = idTemp;

numStudents++;
 }
  }
 
  printf("\nGoodbye!\n");
}
