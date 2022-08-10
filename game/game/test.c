#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("*********************************\n");
	printf("****     1.play   0.exit     ****\n");
	printf("*********************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	Initboard(board, ROW, COL); //初始化棋盘
	Displayboard(board, ROW, COL);// 打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}		
	}
	if (ret == '*')
		printf("你赢了\n");
	else if (ret == '#')
		printf("你输了\n");
	else
		printf("平局\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	
}
int main()
{
	test();
	return 0;
}