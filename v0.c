#include <stdio.h>
int main()
{
	char str[]="3+4";
	int a=str[0]-'0';
	int b=str[2]-'0';
	int c=a+b;
	printf("%d\n",c);
	return 0;
}