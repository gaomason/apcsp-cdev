#include <stdio.h>
#include <math.h>

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
float areaofCircle(float radius)

{
float pi = M_PI;

return radius*radius*pi;
}



int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start=5.2;
	float start2 = start;
  int reps;
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  
  // add your code below to call areaOfCircle function with values between
  // start and end
printf("Start of radius?\n");
int n = scanf("%f",&start); 
if (n !=1){
printf("Not a valid input\n");
}else{
printf("reps?\n");
int b = scanf("%d", &reps);
if (b != 1)
{printf("Not a valid input\n");
}else{
printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
 for (int i =0;i<reps;i++)
{
float r = areaofCircle(start);
printf("%f\n",r);
start++; 
}}
}
}
