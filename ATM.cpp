#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char username[100];
	char password[7];
	int money;
	
	struct Account *next;
};
typedef struct Account Account;

Account * head=NULL;//指向头结点的指针
Account * tail=NULL;//指向尾结点的指针 
Account * curAccount=NULL;//指向当前登录账户的指针 

void signUpC()
{
	//申请一块堆内存空间，将其地址赋值给指针newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("请输入姓名:\n");
	scanf("%s",newNodeP->name);
	
	printf("请输入身份证:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("请输入电话:\n");
	scanf("%s",newNodeP->tel);
	
	printf("请输入账号:\n");
	scanf("%s",newNodeP->username);
	
	printf("请输入密码:\n");
	scanf("%s",newNodeP->password);
	
	newNodeP->money=0;
	newNodeP->next=NULL;
	
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("创建成功!\n");
	
}
void signUpE()
{
	//申请一块堆内存空间，将其地址赋值给指针newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("Please enter your name:\n");
	scanf("%s",newNodeP->name);
	
	printf("Please enter your idCard:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("Please enter your tel:\n");
	scanf("%s",newNodeP->tel);
	
	printf("Please enter your username:\n");
	scanf("%s",newNodeP->username);
	
	printf("Please enter your password:\n");
	scanf("%s",newNodeP->password);
	
	newNodeP->money=0;
	newNodeP->next=NULL;
	
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("Created successfully!\n");
	
}


//找到返回1，否则返回0 
int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}

void updatePasswordC()
{
	char formerPassword[100]={'\0'};
	printf("请输入旧密码：");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("请输入新密码：");
		scanf("%s",curAccount->password);
		printf("修改成功！\n");
	}
	else
	{
		printf("密码错误！不能修改！\n");
	}
}

void updatePasswordE()
{
	char formerPassword[100]={'\0'};
	printf("please enter your former password：");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("please enter your new password：");
		scanf("%s",curAccount->password);
		printf("Modified successfully！\n");
	}
	else
	{
		printf("The password is wrong and cannot be modefied！\n");
	}
}


void saveMoneyC()
{
	printf("请输入存款金额：");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("存款成功！\n");
	}
	else
	{
		printf("数额不符，无法存款");
	}
	
}
void saveMoneyE()
{
	printf("please enter the deposit amount：");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("deposit successful！\n");
	}
	else
	{
		printf("the amount does not match,so the deposit cannot be made");
	}
	
}
void drawMoneyC()
{
	printf("请输入取款金额：");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("取款成功！\n");
		curAccount->money-=money;
		
	}
	else
	{
		printf("余额不足!取款失败\n");
	}
	
}
void drawMoneyE()
{
	printf("please enter the withdrawal amount：");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("withdrawal successful！\n");
		curAccount->money-=money;
		
	}
	else
	{
		printf("wiyhdrawal failed due to insufficient balance\n");
	}
	
}

Account *otherAccount=NULL;
int findotherAccount(char otherusername[])
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->username,otherusername)==0)
		{
			otherAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}
void transferC()
{
	printf("请输入转账账户：");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		
		printf("请输入转账金额：");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{
			
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("转账成功");
		}
		else
		{
			printf("余额不足，无法转账！");
		}
	}
	
	else
	{
		printf("账户错误！");
	}
}

void transferE()
{
	printf("please enter the transfer account：");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		
		printf("please enter the transfer amount：");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{
			
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("transfer succeeded!");
		}
		else
		{
			printf("Insufficient balance，unable to transfer！");
		}
	}
	
	else
	{
		printf("Account error！");
	}
}

void homePageC()
{
	system("cls");
	printf("请选择服务：");
	printf("按1修改密码，按2存款，按3取款，按4转账");
	int gn;
	scanf("%d",&gn);
	if(gn==1)
	{
		updatePasswordC();
	}
	else if(gn==2)
	{
        saveMoneyC();
	}
	else if(gn==3)
	{
		drawMoneyC();
	}
	else if(gn==4)
	{
		transferC();
	}
	else
	{
		printf("输入错误");
	}
}

void homePageE()
{
	system("cls");
	printf("please select a service：");
	printf("press 1 to change the password，deposit by 2，withdraw by 3，transfer by 4");
	int gn;
	scanf("%d",&gn);
	if(gn==1)
	{
		updatePasswordE();
	}
	else if(gn==2)
	{
        saveMoneyE();
	}
	else if(gn==3)
	{
		drawMoneyE();
	}
	else if(gn==4)
	{
		transferE();
	}
	else
	{
		printf("Input error");
	}
}
void signInC()
{
	for(int i=0;i<3;i++)
	{
		Account a; 
		printf("欢迎登录\n");
		printf("请输入账号：\n");
		scanf("%s",a.username);
		
		printf("请输入密码：\n");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			homePageC();
			
			return;
		}
		else
		{
			printf("登录失败!\n");
		}
	} 
}
void signInE()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("Please enter your username:");
		scanf("%s",a.username);
		
		printf("Please enter your password:");
		scanf("%s",a.password);
		
		if(findAccount(a)==1)
		{
			homePageE();
			return;
		}
		else
		{
			printf("Login failed！\n");
		}
	}
}

/**
如果数据加载成功返回1
否则返回0 
*/
int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0; 
	}
	else
	{
		while(!feof(fp))
		{
			//创建结点：在堆上申请一块内存空间，将其地址赋值给指针newNodeP
			Account * newNodeP=(Account *)malloc(sizeof(Account)); 
			
			//结点赋值：结点初始化
			newNodeP->next=NULL;
			fscanf(fp,"%s %s %d\n",newNodeP->username,newNodeP->password,&newNodeP->money);
			
			//添加结点到链表
			if(head==NULL)
			{
				head=newNodeP;
				tail=newNodeP;
			}
			else
			{
				tail->next=newNodeP;
				tail=newNodeP;
			}
		}
		return 1;
	}
	fclose(fp);
}
void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %d\n",curP->username,curP->password,curP->money);
			curP=curP->next;
		}
	}
}


void showMenuC()
{
	printf("开户，按1\n");
	printf("登录，按2\n");
	int n;
	scanf("%d",&n);
	
	if(n==1)
	{
		signUpC();
	}
	else if(n==2)
	{
		
		signInC();
	}
	
	
	
	else
	{
		printf("输入错误！");
	}
}

void showMenuE()
{
	printf("signUp，input 1\n");
	printf("signIn，input 2\n");
	int n;
	scanf("%d",&n);
	
	if(n==1)
	{
		signUpE();
	}
	else if(n==2)
	{
		
		signInE();
		
		
	}
	else
	{
		printf("Input error！");
	}
}
int main()
{
	printf("欢迎使用牛马银行\n");
	printf("Welcome to niuma bank\n");
	
	int language;
	printf("中文，按1\n");
	printf("English, input 2\n");
	printf("一夜牛马请按 3\n");
	scanf("%d",&language);
	if(language==1)
	{
		int status=loadData();
		if(status==1)
		{
			printf("加载成功！\n");
			showMenuC();
		               saveData();
		}
		else
		{
			printf("加载失败！\n");
		}
			
	}
	else if(language==2)
	{
		int status=loadData();
		if(status==1)
		{
			printf("Load successful！\n");
			showMenuE();
			saveData();
		}
		else
		{
			printf("failed to load！\n");
		}	
	}
	else
	{
		printf("输入错误！\n");
		printf("Input error");
	}
	
	return 0;
} 
