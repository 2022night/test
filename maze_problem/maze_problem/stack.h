#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STdatetype;
typedef struct Stack
{
	STdatetype* a;
	int top;
	int capacity;
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STdatetype x);
void StackPop(Stack* ps);
STdatetype StackTop(Stack* ps);
int Stacksize(Stack* ps);
bool StackEmpty(Stack* ps);
