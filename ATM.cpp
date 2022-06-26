#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

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

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %s %d\n",curP->name,curP->username,curP->password,curP->money);
			curP=curP->next;
		}
	}
	fclose(fp);
}
Account *haveAccount=NULL;
int findhaveAccount(char haveusername[])
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->username,haveusername)==0)
		{
			haveAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}


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
	for(int m=4;m>0;m--)
	{
		printf("请输入账号:\n");
		scanf("%s",newNodeP->username);
		if(findhaveAccount(newNodeP->username))
		{
			printf("账户已存在！\n");
			printf("请重新输入：");
		}
		else
		{
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
			saveData();
			printf("创建成功!\n");
			
			break;
		}
	}
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
    for( int m=4;m>0;m--)
	{
		printf("Please enter your username:\n");
		scanf("%s",newNodeP->username);
		if(findhaveAccount(newNodeP->username))
		{
			printf("Account already exists\n");
			printf("please re-enter：");
		}
		else
		{
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
			saveData();
			printf("Created successfully!\n");
			break;
		}
	}
	
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
		printf("数额不符，无法存款\n");
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
			printf("转账成功\n");
		}
		else if(money>curAccount->money)
		{
			printf("余额不足，无法转账！\n");
		}
		else if(money%100!=0)
		{
			printf("转账金额不符合规则！\n");
		}
	}
	
	else
	{
		printf("账户错误！\n");
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
		printf("Account error！\n");
	}
}
void printLinkedListC()
{
	
	printf("姓名：%s\t账户：%s\t 余额：%d\n",curAccount->name,curAccount->username,curAccount->money);
	
	
}

void printLinkedListE()
{
	printf("name:%s\tUsername：%s\t balance：%d\n",curAccount->name,curAccount->username,curAccount->money);
	
}

void homePageC()
{
	while(1)
	{
		system("cls");
		printf("请选择服务：");
		printf("按1修改密码，按2存款，按3取款，按4转账,按5查询，按0返回");
		
		int gn;
		scanf("%d",&gn);
		if(gn==1)
		{
			updatePasswordC();
			system("pause");
		}
		else if(gn==2)
		{
			saveMoneyC();
			system("pause");
		}
		else if(gn==3)
		{
			drawMoneyC();
			system("pause");
		}
		else if(gn==4)
		{
			transferC();
			system("pause");
		}
		else if(gn==5)
		{
			printLinkedListC();
			system("pause");
		}
		else if(gn==0)
		{
			break;
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

void homePageE()
{
	while(1)
	{
		system("cls");
		printf("please select a service：");
		printf("press 1 to change the password,\n deposit by 2,\n withdraw by 3,\n transfer by 4,\n press 5 query,\n press 0 return");
		int gn;
		scanf("%d",&gn);
		if(gn==1)
		{
			updatePasswordE();
			system("pause");
		}
		else if(gn==2)
		{
			saveMoneyE();
			system("pause");
		}
		else if(gn==3)
		{
			drawMoneyE();
			system("pause");
		}
		else if(gn==4)
		{
			transferE();
			system("pause");
		}
		else if(gn==5)
		{
			void printLinkedListE();
			system("pause");
			
		}
		else if(gn==0)
		{
			break;
		}
		else
		{
			printf("Input error\n");
		}
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
			fscanf(fp,"%s %s %s %d\n",newNodeP->name,newNodeP->username,newNodeP->password,&newNodeP->money);
			
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

void showMenuC()
{
	while(1)
	{
		system("cls");
		printf("开户，按1\n");
		printf("登录，按2\n");
		printf("返回，按0\n");
		
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpC();
			system("pause");
		}
		else if(n==2)
		{
			
			signInC();
			saveData();
			system("pause");
		}
		else if(n==0)
		{
			break;
		}
		
		
		else
		{
			printf("输入错误！\n");
			Sleep(1200);
		}
	}
}

void showMenuE()
{
	while(1)
	{
		printf("signUp，input 1\n");
		printf("signIn，input 2\n");
		printf("return,input 0\n");
		int n;
		scanf("%d",&n);
		
		if(n==1)
		{
			signUpE();
			system("pause");
		}
		else if(n==2)
		{
			
			signInE();
			saveData();
			system("pause");
			
		}
		else if(n==0)
		{
			break;
		}
		else
		{
			printf("Input error！\n");
			Sleep(1200);
			
		}
	}
}
int main()
{
	
	while(1)
	{	
		system("cls");	
		printf("欢迎使用暴富银行\n");
		printf("Welcome to Baofu bank\n");
		
		int language;
		printf("请选择语言\n");
		printf("please select a language\n");
		printf("中文，按1\n");
		printf("English, input 2\n");
		printf("退出按0\n");
		printf("sign out,input 0");
		scanf("%d",&language);
		if(language==1)
		{
			int status=loadData();
			if(status==1)
			{
				printf("加载成功！\n");
				showMenuC();
				
				
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
				
			}
			else
			{
				printf("failed to load！\n");
			}
			
		}
		else if(language==0)
		{
			break;
		}
		else
		{
			printf("输入错误！\n");
			printf("Input error");
			Sleep(1200);
		}
	}
				saveData();
				return 0;
} 
