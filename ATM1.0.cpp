#include<stdio.h>
#include<stdlib.h>

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

void signIn()
{
	
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

void loadData()
{
	FILE* fp=fopen("D:/桌面/atm1.txt","r");
	if(fp!=NULL)
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
		fclose(fp);
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

