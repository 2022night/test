#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

void Initboard(char board[ROWS][COLS],int rows, int cols, char ret);
void displayboard(char board[ROWS][COLS], int row, int col);
void SetMIne(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col);
void saolei(int x, int y, char show[ROWS][COLS], char mine[ROWS][COLS]);