#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isNumber(char *ch);//�����ж�һ���ַ��Ƿ������ֺ��� ����ֵ 1 ������  0�������ֺ���
int isArithmeticSymbol(char *ch);//�����ж�һ���ַ��Ƿ���������������� ����ֵ 1 �����������  0�����������������ԭ��
int checkValid(char *str);//�����ж�һ���ַ����Ƿ��ǺϷ����������ʽ���� ����ֵ 1 ������  0���Ǻ���
double strToDouble(char *buf);//����һ���������ַ���ת��ΪС������ԭ��
int  strToInt(char *str);//����һ���������ַ���ת��Ϊ��������ԭ��
int  getOperateValue(char *caclStr,double * num);//������ȡ����������ԭ��
double compute(const double *operandValues,char *caclSymbol);//���������������ʽ�������ԭ�� 
double caculate(char *caclStr);//����������������ʽ�������ԭ��
int main()
{
	char caclStr[100]={'\0'};
	double result=0.0;
	while(1)
	{
	    //2������������ʽ

		system("color 1f");
		//system("cls");
		printf("������������������ʽ[quit-����]��");
		gets(caclStr);
		if(strcmp(caclStr,"quit")==0) 
		{
			printf("лл��ʹ����������������������ټ�������\n");
				exit(0);
		}
		//��֤���ʽ�Ƿ�Ϸ� ������Ϸ� ��������
		if (!checkValid(caclStr)) continue;
		//3���ü��������㺯�����ؼ�����
		result=caculate(caclStr);
		//4�����������������
 		printf("%s=%.2f\n",caclStr,result);
	}
	return 0;
}
int isArithmeticSymbol(char *ch)
{
   int flag=0;
   if(*ch=='+' || *ch=='-' || *ch=='*' || *ch=='/')
   {
	   flag=1;
   }
   return flag;

}
int isNumber(char *ch)//�ж�һ���ַ��Ƿ������ֺ��� ����ֵ 1 ������  0��������
{
   int flag=0;
   if(*ch>='0' && *ch<='9')
   {
	   flag=1;
   }
   return flag;

}
int checkValid(char *str)
{
	//1+2
	int i=0;
	int count_num=0,count_symbol=0;
	int validFlag=1;// 1 �Ϸ� 0 �Ƿ�
	while(*str !='\0')
	{
      //������ʽ���������ʽ�Ĳ����� 0-9.������� +-*/ ���ǺϷ����������ʽ
		if(isNumber(str)==0)
			if(!(*str=='+' || *str=='-' || *str=='*' || *str=='/'|| *str=='.'))
			{
				validFlag=0;
				break;
			}
		if(*str>='0' && *str<='9' || *str=='.' ) 
		{
			count_num++;
		}
		if(*str=='+' || *str=='-' || *str=='*' || *str=='/') 
		{
			count_symbol++;
		}

		//i=i+1;
		str++;
	}
	if(count_num<2 ||count_symbol<1)
	{
        validFlag=0;
	}
	return validFlag;
}
double caculate(char *caclStr)
{
	double  caclValues[10]={0};
	char    caclOperates[10]={'\0'};
	char    buf[10]={'\0'};
	int     i=0,j=0,k=0,t=0;
	double result=0.0;//���������
	double tempNum=0.0;//������ʱ������
	i=0;
	//����
	//˼·�������λ��������������ʽ��ֵ����������ʽ  "100+200/30-40*50"
	//123=('1'-'0')*100+('2'-'0')*10+('1'-'0')*3
    while(*caclStr != '\0')//�ַ������� 
	{
		if(isNumber(caclStr))
		{

			//���û�ȡ�������������ص�ǰ������
			i=getOperateValue(caclStr,&tempNum);
			caclValues[j]=tempNum;
			j++;
			caclStr=caclStr+i;
		}
		//�ֽ������
		if(isArithmeticSymbol(caclStr))
		{
			//�����'*' ����ǰ����������һ����������˵ķŻص�ǰ���������� '*' ����
			if(*caclStr=='*')
			{
                caclStr++;
				i=getOperateValue(caclStr,&tempNum);
				j--;
			    caclValues[j]=caclValues[j] * tempNum;
				j++;
				caclStr=caclStr+i;
			}
			//�����'/' ����ǰ����������һ������������ķŻص�ǰ���������� '/' ����
			if(*caclStr=='/')
			{
                caclStr++;
				i=getOperateValue(caclStr,&tempNum);
				j--;
			    caclValues[j]=caclValues[j] / tempNum;
				j++;
				caclStr=caclStr+i;
			}
			if(*caclStr=='+' || *caclStr=='-')
			{
				caclOperates[k++]=*caclStr;
			
			}
		
		}

		caclStr++;
	}

	//caclOperates[k]���������Ҫ��Ϊ�ַ���
	caclOperates[k]='\0';
	return compute(caclValues,caclOperates);
}
double compute(const double * caclValues1,char * caclOperates)
{
	int i=0;
	double result=0.0;//���������
	i=0;
	result=caclValues1[0] ;//�õ�һ����������Ϊ����ĳ�ʼֵ
	while(caclOperates[i] != '\0')//��������������
	{
        //�жϲ�����������ַ��Ƿ���+ - * /
		switch(caclOperates[i])
		{
			case '+':
				//����ǰ������������һ���������ٸ�ֵ������������
				result =result + caclValues1[i+1];
				break;
			case '-':
				//����ǰ������������һ���������ٸ�ֵ������������
				result =result - caclValues1[i+1];
				break;
			case '*':
				//����ǰ������������һ���������ٸ�ֵ������������
				result =result * caclValues1[i+1];
				break;
			case '/':
				//����ǰ������������һ���������ٸ�ֵ������������
				result =result / caclValues1[i+1];
				break;
		}
		i++;
	}
	return result;
}
int strToInt(char str[])
{
	int i,num=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]>='0'&&str[i]<='9')
			num=num*10+str[i]-'0';
	return (num);

}
double strToDouble(char buf1[])
{

	int i;
	double num=0.0;
	i=strlen(buf1);
	for(;i>=0;i--)
	{
		if(buf1[i]>='0'&&buf1[i]<='9')
			num=num/10+buf1[i]-'0';
	}
	return (num/10);

}
int getOperateValue(char *caclStr,double * num)
{
    char buf[10]={'\0'};
	int i=0;
	int t=0;
	t=0;//��ʱ�������ַ������±� 
	while(*caclStr>='0' && *caclStr<='9')//��ȡ�������������ַ���
	{
		buf[t]=*caclStr;
		i++;
		caclStr++;
		t++;
	}
	buf[t]='\0';//�����ʱ�������ַ����Ľ������ 
	*num=strToInt(buf);//�������������ַ���ת��Ϊ����
	if(*caclStr=='.'){//�����С����
		i++;
		caclStr++;
		t=0;//��ʱ�������ַ������±� 
		while(*caclStr>='0' && *caclStr<='9')//��ȡС�����������ַ���
			{
			buf[t]=*caclStr;
			i++;
			caclStr++;
			t++;
		}
		buf[t]='\0';//�����ʱ�������ַ����Ľ������ 
		*num=*num+strToDouble(buf);//��С�����������ַ���ת��ΪС�����ۼӵ��ò�����
	}
	return i;
}





