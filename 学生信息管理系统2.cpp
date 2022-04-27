#include<stdio.h>
#include<string.h>

struct Student
{
	int stuId;
	int stuAge;
	char stuName[100];

	struct Student* next; 
};
void printStudent(struct Student* curP)
{
	printf("学号:%d 年龄:%d 姓名:%s \n",curP->stuId,curP->stuAge,curP->stuName);
}

void printLinkedList(struct Student* headP)
{
	while(headP!=NULL)
	{
		printStudent(headP);
		headP=headP->next;
	}
}

int main()
{
	struct Student s1,s2,s3;
	s1.stuId=2002;
	s1.stuAge=18;
	strcpy(s1.stuName,"李华");

	s2.stuId=2005;
	s2.stuAge=18;
	strcpy(s2.stuName,"陈士");

	s3.stuId=2006;
	s3.stuAge=19;
	strcpy(s3.stuName,"王二");

	struct Student s4={2008,18,"李龙"};

	//s1->s2->s3->s4
	s1.next=&s2;
	s2.next=&s3;
	s3.next=&s4;
	s4.next=NULL;

	struct Student* curP=&s1;
	printLinkedList(curP);

	printf("请输入你想要查询学生的学号：");
	int id;
	int flag=0;
	scanf("%d",&id);
	curP=&s1;
	while(curP!=NULL)
	{
		if(curP->stuId==id)
		{
			printStudent(curP);
			flag=1;
			break;
		}
		else 
		{
			curP=curP->next;
		}

	}
	if(flag==0)
	{
		printf("对不起，该学生找不到\n");
	}

	printf("接下来要删除s2\n");
	s1.next=&s3;
	s2.next=NULL;

	curP=&s1;
	printLinkedList(curP);
	return 0;
}
