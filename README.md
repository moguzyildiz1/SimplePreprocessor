# SimplePreprocessor
This is a simple C preprocessor. 
# Usage
When it is run, program will ask the user to enter the name of a C file.
Program will open the C file in text mode, it will find all preprocessor definitions in the form 
#define
and will replace all define occurrences with the defined counterpart and will write the new C program into a new file.
For example, consider the following C program (named myprog.c) that includes the lines below:
#include <stdio.h>
#define SIZE 10
#define MAX 5
#define DOUBLE double

int main()
{
*******	DOUBLE a[SIZE], j;
*******	for (j = 0; j < MAX; ++j)
*******	printf(“DOUBLE : %f\n”, j);
*******	return 0;
}

# On console
Enter the C program name:
myprog.c
Your result is in file myprog_pro.c
The file myprog_pro.c will contain the following lines:
#include <stdio.h>

int main()
{
*******	int a[10], j;
*******	for (j = 0; j < 5; ++j)
*******	printf(“Integer : %d\n”, j);
*******	return 0;
}
