//
// encrypt.c
//

#include <string.h>
#include <stdio.h>
#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
char a;
  for (int i = 0; i < 62; i++)
{
    if (c == CHARS[i]){
      if (direction ==1){
	if (62<i+shift){
	  a = CHARS[i+shift-62];
}       else {
          a = CHARS[i+shift];
}}    else {
        if (0>i-shift){
          a = CHARS[i-shift+62];
}       else {
          a = CHARS[i-shift];
}}}}
return a; 
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}



