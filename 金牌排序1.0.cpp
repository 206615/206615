#include<stdio.h>
#include<stdlib.h> 

struct Country
{
	char name[100];
	int goldNum;
	int silverNum;
	int bronzeNum;
	int totalNum;
};

typedef struct Country Country;

void printCountry(Country c)
{
	printf("%s\t%d\t%d\t%d\t%d\n",c.name,c.goldNum,c.silverNum,c.bronzeNum,c.totalNum); 
} 


void bubbleSort(Country a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		//每一轮要干嘛
		for(int j=0;j<n-1;j++) 
		{
			if(a[j].goldNum<a[j+1].goldNum)
			{
				//交换
				Country temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp; 
			}
		}
	}
}

 
int main()
{
	Country c[8];
	FILE*fp=fopen("F:\c语言","r");
	if(fp==NULL)
	{
		printf("Error\n");
		exit(0);
	}
	for(int i=0;i<8;i++)
	{
		fscanf(fp,"%s %d %d %d %d",c[i].name,&c[i].goldNum,&c[i].silverNum,&c[i].bronzeNum,&c[i].totalNum);
	}
	fclose(fp);
	
	bubbleSort(c,8);
	
	FILE* outfp=fopen("D:/new20220212.txt","w");
	for(int i=0;i<8;i++)
	{
		fprintf(outfp,"%s\t%d\t%d\t%d\t%d\n",c[i].name,c[i].goldNum,c[i].silverNum,c[i].bronzeNum,c[i].totalNum);
	}
	fclose(outfp);
	
	return 0;
}

