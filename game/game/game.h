#pragma once
#include<stdio.h>
#define ROW 3
#define COL 3
#include <time.h>
#include<stdlib.h>
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void  PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);