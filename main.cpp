#include"stdio.h"
#include"string.h"
#define chang 100
int main()
{
	char a[chang];
	gets(a);
	int in=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='i'&&a[i+1]=='n')
		{
			in++;
		}
	}
	printf("%d\n",in);
	return 0;
}
