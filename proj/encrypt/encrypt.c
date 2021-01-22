
//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;

int find_index(char c)
{
for (int i = 0; i < 62; i++)
	{
		if (CHARS[i] == c)
		{
			return i;
		}
	}
}

char shiftChar(char c, int shift, int direction)
{
int trueshift;
int index;

if (c == ' ')
{
return ' ';
}

if (direction == 1){
        trueshift = shift;
} else {
        trueshift = 62 - shift;
}

index = CHARS[(find_index(c) + trueshift) % 62];

return index;
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


