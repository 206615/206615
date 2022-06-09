#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Account
{
	char name[100];
	char password[100];
	char username[100];
	char idCard[100];
	char tel[100];
	float money;
	
	struct Account * next;	
};
typedef struct Account Account;

int language;//1-Chinese,2-English,3-Rich

Account * head=NULL;//指向头结点的指针
Account * tail=NULL; //指向尾结点 
Account *curAccount=NULL;//记录当前账户 


//找到返回1，否则返回0 
int findAccount(Account a)
{
	Account *curp=head;
	while(curp!=NULL)
	{
		if((strcmp(curp->username,a.username)==0)&&(strcmp(curp->password,a.password)==0))
		{
			curAccount=curp; 
			return 1;
		}
		curp=curp->next;
	}
	return 0;
}

void updatePassword()
{
	printf("请输入旧密码：");
	char oldPassword[100];
	scanf("%s",oldPassword);
	for(;1;){
			if(strcmp(oldPassword,curAccount->password)==0)
		{
			printf("请输入新密码：");
			scanf("%s",curAccount->password);
			if(strcmp(curAccount->password,oldPassword)!=0){
				printf("OK");
				break;
			}
			else{
				printf("NO");
			}
		}
		else
		{
			printf("密码错误！不能修改！\n");
		}
	}
}

void signIn()
{
	int i;
	Account a;
	for(i=0;i<3;i++)
	{ 
		printf("请输入账号：");
		scanf("%s",a.username);
		
		printf("请输入密码：");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			printf("登录成功！\n");
			updatePassword();
			break;
		}
		else
		{
			printf("登录失败！\n");
		}
	}
}

//加载成功返回1，否则返回0 
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
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password);
			
			//添加结点到链表 
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		return 1;
	}
}
void signUp()
{
	//申请一块堆内存空间，将其地址赋值给指针newNode (创建结点) 
	Account * newNode=(Account *)malloc(sizeof(Account));
	
	//结点赋值
    printf("请输入账号：\n");
	scanf("%s",newNode->username);
  
	printf("请输入密码：\n");
	scanf("%s",newNode->password);
  
	printf("请输入姓名：\n");
	scanf("%s",newNode->name);
	
    printf("请输入身份证：\n");
	scanf("%s",newNode->idCard);
	
	printf("请输入电话：\n");
	scanf("%s",newNode->tel);
	
	newNode->money =0.0f; 
	newNode->next=NULL;
	
	//添加结点到链表 
	if(head==NULL)
	{
		head=newNode;
		tail=newNode;	
	} 
	else
	{
		tail->next=newNode;
		tail=newNode;
	}

	printf("创建成功！\n");
}

void showMenu()
{
	while(1)
	{
		if(language==1)
		{
			printf("登录，请按1\n");
			printf("开户，请按2\n");
			printf("退出，请按3\n");
		}
		else if(language==2)
		{
			printf("Sign in, press 1\n");
			printf("Sign up, press 2\n");
			printf("Sign out, press 3\n");
		}
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signIn();
			updatePassword();
		}
		else if(n==2)
		{
			signUp();
		}
		else if(n==3)
		{
			return;
		}
	}
}



void saveData()
{
	Account * curP=head;
	FILE* fp=fopen("D:/桌面/atm1.txt","w");//埋下了bug 
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s\t%s\n",curP->username,curP->password);
			curP=curP->next;
		}
		fclose(fp);
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s %s\n",curP->name,curP->username);
		curP=curP->next;
	}
}

int main()
{
	printf("中文服务，按1\n");
	printf("English Service，Press 2\n");
	printf("一夜暴富，按3\n");
	
	scanf("%d",&language);
	
	showMenu();
 
  loadData();                 

  saveData();
	
	printLinkedList(); 
	
	return 0;
}
