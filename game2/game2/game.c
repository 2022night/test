#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	int x = 0;
	int y = 0;
	for (x = 0; x <rows;x++)
	{
		for (y = 0; y < cols; y++)
		{
			board[x][y] = ret;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("  ");
	for (y = 1; y <= col; y++)
	{
		
		printf("%d ", y);
	}
	printf("\n");
	for (x = 1; x <= row; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= col; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
}
void SetMIne(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while(count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}

   }
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = row*col;
	while( win>EASY_COUNT)
	{
		win = 0;
	printf("ÇëÊäÈë×ø±ê:>");
	scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]=='*')
		{
			if (mine[x][y] == '1')
			{
				printf("ÓÎÏ·Ê§°Ü\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				
				saolei(x,y,show,mine,row,col);
				displayboard(mine, row, col);
				displayboard(show, row, col);
				for (x=1;x<=row;x++)
				{
					for (y = 1; y <= col; y++)
					{
						if (show[x][y] == '*')
						{
							win++;
						}
					}
				}
			}
		}
		else
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë\n");
	}
	if ( win== EASY_COUNT)
	{
		printf("ÄãÓ®ÁË\n");
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y] - 8 * '0';

}
void saolei(int x,int y, char show[ROWS][COLS], char mine[ROWS][COLS],int row,int col)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		int i = 0;
		int j = 0;
		if (get_mine_count(mine, x, y) == 0)
		{
			show[x][y] = '_';
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (show[x + i][y + j] == '*')
					{
						saolei(x + i, y + j, show, mine, row, col);
					}
				}
			}
		}
		else
		{
			show[x][y] = get_mine_count(mine, x, y) + '0';
		}
	}
	else
	{
		return 0;
	}
}