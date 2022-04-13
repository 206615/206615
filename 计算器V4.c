#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isNumber(char *ch);//声明判断一个字符是否是数字函数 返回值 1 是数字  0不是数字函数
int isArithmeticSymbol(char *ch);//声明判断一个字符是否是算术运算符函数 返回值 1 是算术运算符  0不是算术运算符函数原型
int checkValid(char *str);//声明判断一个字符串是否是合法的算术表达式函数 返回值 1 是数字  0不是函数
double strToDouble(char *buf);//声明一个将数字字符串转换为小数函数原型
int  strToInt(char *str);//声明一个将数字字符串转换为整数函数原型
int  getOperateValue(char *caclStr,double * num);//声明获取操作数函数原型
double compute(const double *operandValues,char *caclSymbol);//声明计算算术表达式结果函数原型 
double caculate(char *caclStr);//声明计算计算器表达式结果函数原型
int main()
{
	char caclStr[100]={'\0'};
	double result=0.0;
	while(1)
	{
	    //2输入计算器表达式

		system("color 1f");
		//system("cls");
		printf("请输入四则混合运算表达式[quit-结束]：");
		gets(caclStr);
		if(strcmp(caclStr,"quit")==0) 
		{
			printf("谢谢您使用四则混合运算计算器程序，再见！！！\n");
				exit(0);
		}
		//验证表达式是否合法 如果不合法 重新输入
		if (!checkValid(caclStr)) continue;
		//3调用计算器计算函数返回计算结果
		result=caculate(caclStr);
		//4在主函数输出计算结果
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
int isNumber(char *ch)//判断一个字符是否是数字函数 返回值 1 是数字  0不是数字
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
	int validFlag=1;// 1 合法 0 非法
	while(*str !='\0')
	{
      //如果表达式是算术表达式的操作数 0-9.和运算符 +-*/ 就是合法的算术表达式
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
	double result=0.0;//保存计算结果
	double tempNum=0.0;//保存临时操作数
	i=0;
	//处理
	//思路：计算多位整数四则运算表达式的值四则运算表达式  "100+200/30-40*50"
	//123=('1'-'0')*100+('2'-'0')*10+('1'-'0')*3
    while(*caclStr != '\0')//字符串遍历 
	{
		if(isNumber(caclStr))
		{

			//调用获取操作数函数返回当前操作数
			i=getOperateValue(caclStr,&tempNum);
			caclValues[j]=tempNum;
			j++;
			caclStr=caclStr+i;
		}
		//分解运算符
		if(isArithmeticSymbol(caclStr))
		{
			//如果是'*' 将当前操作数和下一个操作数相乘的放回当前操作数消除 '*' 符号
			if(*caclStr=='*')
			{
                caclStr++;
				i=getOperateValue(caclStr,&tempNum);
				j--;
			    caclValues[j]=caclValues[j] * tempNum;
				j++;
				caclStr=caclStr+i;
			}
			//如果是'/' 将当前操作数和下一个操作数相除的放回当前操作数消除 '/' 符号
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

	//caclOperates[k]运算符数字要变为字符串
	caclOperates[k]='\0';
	return compute(caclValues,caclOperates);
}
double compute(const double * caclValues1,char * caclOperates)
{
	int i=0;
	double result=0.0;//保存计算结果
	i=0;
	result=caclValues1[0] ;//用第一个操作数作为结果的初始值
	while(caclOperates[i] != '\0')//遍历操作符数组
	{
        //判断操作符数组的字符是否是+ - * /
		switch(caclOperates[i])
		{
			case '+':
				//将当前结算结果加上下一个操作数再赋值给计算结果变量
				result =result + caclValues1[i+1];
				break;
			case '-':
				//将当前结算结果减上下一个操作数再赋值给计算结果变量
				result =result - caclValues1[i+1];
				break;
			case '*':
				//将当前结算结果乘上下一个操作数再赋值给计算结果变量
				result =result * caclValues1[i+1];
				break;
			case '/':
				//将当前结算结果除上下一个操作数再赋值给计算结果变量
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
	t=0;//临时操作数字符数组下标 
	while(*caclStr>='0' && *caclStr<='9')//获取整数部分数字字符串
	{
		buf[t]=*caclStr;
		i++;
		caclStr++;
		t++;
	}
	buf[t]='\0';//添加临时操作数字符串的结束标记 
	*num=strToInt(buf);//整数部分数字字符串转换为整数
	if(*caclStr=='.'){//如果有小数点
		i++;
		caclStr++;
		t=0;//临时操作数字符数组下标 
		while(*caclStr>='0' && *caclStr<='9')//获取小数部分数字字符串
			{
			buf[t]=*caclStr;
			i++;
			caclStr++;
			t++;
		}
		buf[t]='\0';//添加临时操作数字符串的结束标记 
		*num=*num+strToDouble(buf);//将小数部分数字字符串转换为小数后累加到该操作数
	}
	return i;
}





