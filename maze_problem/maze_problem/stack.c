#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
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
	//判断空间是否已满，满的话增容
	if (ps->top == ps->capacity)
	{
		int* tmp = (STdatetype*)realloc(ps->a, sizeof(STdatetype) * (ps->capacity) * 2);
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
	//判断栈是否为空，为空直接报错
	assert(ps->top > 0);
	ps->top--;
}
STdatetype StackTop(Stack* ps)
{
	assert(ps);
	//判断栈是否为空,为空直接报错
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
