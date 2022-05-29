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

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL; //ָ��β��� 

void signIn()
{
	
}

void signUp()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNode (�������) 
	Account * newNode=(Account *)malloc(sizeof(Account));
	
	//��㸳ֵ
    printf("�������˺ţ�\n");
	scanf("%s",newNode->username);
  
	printf("���������룺\n");
	scanf("%s",newNode->password);
  
	printf("������������\n");
	scanf("%s",newNode->name);
	
    printf("���������֤��\n");
	scanf("%s",newNode->idCard);
	
	printf("������绰��\n");
	scanf("%s",newNode->tel);
	
	newNode->money =0.0f; 
	newNode->next=NULL;
	
	//��ӽ�㵽���� 
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

	printf("�����ɹ���\n");
}

void showMenu()
{
	while(1)
	{
		if(language==1)
		{
			printf("��¼���밴1\n");
			printf("�������밴2\n");
			printf("�˳����밴3\n");
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
	FILE* fp=fopen("D:/����/atm1.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//�������
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//����ʼ��
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
			
			//��ӽ�㵽����
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
	FILE* fp=fopen("D:/����/atm1.txt","w");//������bug 
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
	printf("���ķ��񣬰�1\n");
	printf("English Service��Press 2\n");
	printf("һҹ��������3\n");
	
	scanf("%d",&language);
	
	showMenu();
 
  loadData();                 

  saveData();
	
	printLinkedList(); 
	
	return 0;
}

