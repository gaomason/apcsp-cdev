#include <stdio.h>
#include <string.h>

int main ()
{
char str[26];
 for 
(int i = 0; i < 26; i=i+1)
{ str[i]= i + 97;
}
str[26]=0;
char* str2 = "abcdefghijklmnopqrstuvwxyz";
if (strcmp(str, str2) == 0)
	printf("the strings are the same\n");
else
	printf("NO\n");
printf("str: %s str2: %s\n", str, str2);
for (int i =0; i < 26; i=i+1)
{str[i] = str[i] - 32;
}
if (strcmp(str, str2) == 0)
	printf("the strings are the same\n");
else{
	printf("NO\n");
}
printf("str: %s str2: %s\n", str, str2);

char str3[52];
strcpy(str3, str);
strcat(str3, str2);
printf("str: %s , str2: %s , str3 : %s", str, str2, str3);
}
