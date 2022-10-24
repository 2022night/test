#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
typedef struct Postion
{
	int row;
	int col;
}PT;
typedef PT STdatetype;
typedef struct Stack
{
	STdatetype* a;
	int top;
	int capacity;
}Stack;
Stack route;
Stack minroute;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STdatetype x);
void StackPop(Stack* ps);
STdatetype StackTop(Stack* ps);
int Stacksize(Stack* ps);
bool StackEmpty(Stack* ps);
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STdatetype*)malloc(sizeof(STdatetype) * 4);
	if (ps->a == NULL)
	{
		printf("mealloc fail\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(Stack* ps, STdatetype x)
{
	assert(ps);
	//�жϿռ��Ƿ����������Ļ�����
	if (ps->top == ps->capacity)
	{
		STdatetype* tmp = (STdatetype*)realloc(ps->a, sizeof(STdatetype) * (ps->capacity) * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}

	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//�ж�ջ�Ƿ�Ϊ�գ�Ϊ��ֱ�ӱ���
	assert(ps->top > 0);
	ps->top--;
}
STdatetype StackTop(Stack* ps)
{
	assert(ps);
	//�ж�ջ�Ƿ�Ϊ��,Ϊ��ֱ�ӱ���
	assert(ps->top > 0);
	return  ps->a[ps->top - 1];

}
int Stacksize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintMaze(int**maze,int N,int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
}
bool IsPass(int** maze, int N, int M,PT next)
{
	if (next.row >= 0 && next.row < N && next.col >= 0 && next.col < M && maze[next.row][next.col]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StackCopy(Stack* pcopy, Stack* ps)
{
	pcopy->a = (STdatetype*)malloc(sizeof(STdatetype) * ps->capacity);
	memcpy(pcopy->a,ps->a,sizeof(STdatetype)*ps->top);
	pcopy->capacity = ps->capacity;
	pcopy->top = ps->top;
}
void GetMazePath(int** maze,int N, int M, PT cur,int P)
{
	StackPush(&route,cur);
	//�ҵ�����
	if (cur.row == 0 && cur.col == M-1)
	{
		if (StackEmpty(&minroute) || Stacksize(&route) < Stacksize(&minroute) && P >= 0)
		{
			StackDestory(&minroute);
			StackCopy(&minroute,&route);
		}
	}
	PT next;
	maze[cur.row][cur.col] =2;
	//��
	next = cur;
	next.row -= 1;
	if (IsPass(maze, N, M, next))
	{
	     GetMazePath(maze, N, M, next,P-3);
	}
	//��
	next = cur;
	next.row += 1;
	if (IsPass(maze, N, M, next))
	{
	    GetMazePath(maze, N, M, next,P);
	}
	//��
	next = cur;
	next.col -= 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next,P-1);
	}
	//��
	next = cur;
	next.col += 1;
	if (IsPass(maze, N, M, next))
	{
		GetMazePath(maze, N, M, next,P-1);
	}
	maze[cur.row][cur.col] = 1;
	StackPop(&route);
	
}

void PrintRoute(Stack* route)
{
	Stack rroute;
	StackInit(&rroute);
		while(!StackEmpty(route))
		{
			StackPush(&rroute, StackTop(route));
			StackPop(route);
		}
	while (!StackEmpty(&rroute))
	{
		PT top = StackTop(&rroute);
		printf("(%d,%d)", StackTop(&rroute).row, StackTop(&rroute).col);
		StackPop(&rroute);
	}
	StackDestory(&rroute);
}
int main()
{
	int n = 0, m = 0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		printf("�������Թ����д�С\n");	
		scanf("%d%d", &n, &m);
		//���ٶ�ά���鴢���Թ�
		int** maze = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
		{
			maze[i] = (int*)malloc(sizeof(int*) * m);
		}
		//�����Թ�
		printf("�������Թ�:\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		//��ӡ�Թ�
		PrintMaze(maze, n, m);
		PT entry = { 0, 0 };
		StackInit(&route);
		StackInit(&minroute);
		//�ж��Ƿ��ҵ����벢��ӡ����
		int P = 100;

		GetMazePath(maze, n, m, entry,P);
		if (!StackEmpty(&minroute))
		{
			//PrintMaze(maze, n, m);
			PrintRoute(&minroute);
		}
		else
		{
			printf("û�г�·\n");
		}
		StackDestory(&route);
		StackDestory(&minroute);
		for (int i = 0; i < m; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze = NULL;
	}
	return 0;
}