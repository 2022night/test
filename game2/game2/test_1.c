#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("**** 1.play      0.exit ****\n");
	printf("****************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	/*displayboard(mine, ROW, COL);*/
	displayboard(show, ROW, COL);
	SetMIne(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	FindMine(mine,show,ROW,COL);

}
void test()
{
	srand((unsigned int)time(NULL));
int input = 0;
	do
	{
		menu();
		printf("请输入:>");
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
			printf("输入错误请重新输入\n");
			break;
		}
	}while (input);
}
int main()
{
	test();
	return 0;
 }