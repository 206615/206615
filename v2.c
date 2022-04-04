#include <stdio.h>
#include <string.h>
int main()
{
	char str[]="2*2/4*1/1*2*3/2";
	int num=str[0]-'0';
	int i=1;
	for(i=1;i<strlen(str);i++)
	{
		if(str[i]=='*')
		{
			int a=str[i+1]-'0';
			num=num*a;
			i++;
		}
		else if(str[i]=='/')
		{
			int b=str[i+1]-'0';
			num=num/b;
			i++;
		}
	}
	printf("num = %d\n",num);
	return 0;
}