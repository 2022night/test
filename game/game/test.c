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
	Initboard(board, ROW, COL); //��ʼ������
	Displayboard(board, ROW, COL);// ��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}		
	}
	if (ret == '*')
		printf("��Ӯ��\n");
	else if (ret == '#')
		printf("������\n");
	else
		printf("ƽ��\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
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
	} while (input);
	
}
int main()
{
	test();
	return 0;
}