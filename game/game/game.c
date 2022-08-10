#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}printf("\n");
		if(i<row-1)
		for (j = 0; j < col; j++)
		{
			
				printf("---");
			if (j < col - 1)
				printf("|");

		}printf("\n");
	}
}
void  PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走 :>\n");
	while(1)
	{
		printf(" 请输入坐标:>");
        scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用\n");
		}
		else
			printf("输入错误\n");

	}
	
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走 :>\n");
	
	while (1)
	{
	  x = rand() % row;
	  y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
		break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
				return 0;
		}
	}
	return 1;
}

void IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}