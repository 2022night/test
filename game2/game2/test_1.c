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
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}while (input);
}
int main()
{
	test();
	return 0;
 }