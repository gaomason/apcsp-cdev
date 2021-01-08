 #include<stdio.h>

int main()
{
  int a = 545;
char b = 'c';
float d = 1.23;
double e = 1.24213;
unsigned int f = 0;
signed int g = -2;
  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a)); 
   printf("char b value: %c and size: %lu bytes\n", b, sizeof(b)); 
   printf("float b value: %f and size: %lu bytes\n", d, sizeof(d)); 
   printf("double b value: %f and size: %lu bytes\n", e, sizeof(e)); 
  printf("unsigned int f value: %d and size: %lu bytes\n", f, sizeof(f)); 
  printf("signed int g value: %d and size: %lu bytes\n", g, sizeof(g)); 

}
