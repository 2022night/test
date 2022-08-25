#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h";


void menu()
{
	printf("************************************************\n");
    printf("******     1. add               2. del    ******\n");
    printf("******     3.search             4. modify ******\n");
    printf("******     5. show              6. sort   ******\n");
    printf("******     0. exit                        ******\n");
    printf("************************************************\n");
}
int main()
{
	int input = 0;
	struct contact con;//  创建通讯录
	//初始化
	initcontact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			addcontact(&con);//添加通讯录
			break;
		case DEL:
			delcontact(&con);
			break;
		case SEARCH:
			searchcontact(&con);
			break;
		case MODIFY:
			modifycontact(&con);
			break;
		case SHOW:
			showconatact(&con);//查看通讯录
			break;
		case SORT:
			sortcontact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}