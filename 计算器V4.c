#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
double calc(char *s){
	double a_czs[40],czs;
	char a_ysf[40],ysf;
	int cnt_czs=0,cnt_ysf=0,i;
	a_czs[0]=atof(s);
	while(*s!='\0'){
		while(isdigit(*s)||*s=='.'||(*s)==' ')s++;
		ysf=*s;
		s++;
		czs=atof(s);
		while(isdigit(*s)||*s=='.'||(*s)==' ')s++;
		switch(ysf){
		case '+':
		case '-':a_czs[++cnt_czs]=czs;a_ysf[cnt_ysf++]=ysf;break;
		case '*':a_czs[cnt_czs]*=czs;break;
		case '/':a_czs[cnt_czs]/=czs;break;
		}
	}
	for(i=0;i<cnt_czs;i++){
		printf("%.5lf\t",a_czs[i]);
	}
	printf("\n");
	for(i=0;i<cnt_ysf;i++){
		printf("%c\t",a_ysf[i]);
	}
	for(i=0;i<cnt_ysf;i++){
		switch(a_ysf[i]){
		case '+':a_czs[0]+=a_czs[i+1];break;
		case '-':a_czs[0]-=a_czs[i+1];break;
		}
	}
	return a_czs[0];
}
int main(){
	char s[40];
	double result;
	while(1){
		puts("请输入一个简单的表达式（只含加减乘除的）：");
		gets(s);
		printf("string is\"%s\",it\"double value:%.3lf\n\n",s,atof(s));
		if(strcmp(s,"QUIT")==0)
			return 0;
		else{
			result=calc(s);
			printf("%s=%.3lf\n\n",s,result);
		}
	}
}




