#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char map[9][12]={
"*A*********",
"***AAA*AAA*",
"AAA**A****A",
"*A**AAA*AA*",
"***********",
"AAAAA*AA*AA",
"**A****AA*A",
"***A*AA***A",
"*A*****A*P",
};

int curX=0,curY=0;
void printPerson()
{
	COORD pos;
	pos.X=curX;
	pos.Y=curY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	printf("K");
}
void printMap()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<12;j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
void Move(char dir)
{
	switch(dir)
	{
	    case 'W':
			curY--;
			if(curY<0)curY=0;
			if(map[curY][curX]=='A')curY++;
			break;
		case 'S':
			curY++;
			if(curY>=9)curY=9-1;
			if(map[curY][curX]=='A')curY--;
			break;
		case 'a':
			curX--;
			if(curX<0)curX=0;
			if(map[curY][curX]=='A')curX++;
			break;
		case 'd':
			curX++;
			if(curX>=12)curX=12-1;
			if(map[curY][curX]=='A')curX--;
			break;
	}
}
void main()
{
	char dir;
	while(1)
	{
		system("cls");
		printMap();
		printPerson();
		dir=getch();
		Move(dir);
		if(map[curY][curX]=='p')
		{
			printf("恭喜，成功通过!");
			break;
		}
	}
}