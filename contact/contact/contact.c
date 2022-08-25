#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void initcontact(struct contact* pa)
{
	memset(pa->data,0,sizeof(pa->data));
	pa->size = 0;
}
void addcontact(struct contact* pa)
{
	if (pa->size == MAX)
	{
		printf("人数已满，不可以再添加\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", (pa->data[pa->size]).name);
		printf("请输入年龄:>");
		scanf("%d", &((pa->data[pa->size]).age));
		printf("请输入性别:>");
		scanf("%s", (pa->data[pa->size]).sex);
		printf("请输入电话:>");
		scanf("%s", (pa->data[pa->size]).tele);
		printf("请输入地址:>");
		scanf("%s", (pa->data[pa->size]).addr);
		pa->size++;
		printf("添加成功\n");
	}
	
}
void showconatact(struct contact* pa)
{
	printf("%-12s\t%-4s\t%-5s\t%-20s\t%-20s\n","名字","年龄","性别","电话","地址");
	int i = 0;
	for (i = 0; i < pa->size; i++)
	{
		printf("%-12s\t%-4d\t%-5s\t%-20s\t%-20s\n", pa->data[i].name,
			                                   pa->data[i].age,
			                                   pa->data[i].sex,
			                                   pa->data[i].tele,
			                                   pa->data[i].addr
		);
	}
}
void delcontact(struct contact* pa)
{
	char name[MAX_NAME];
	printf("请输入删除对象:>");
	scanf("%s",name );
	//查找对象
	int i = 0;
	int ret = Findmyname(name, pa,&i);
	if (ret ==-1)
	{
		printf("对象不存在\n");
	}
	//删除联系人
	else
	{
		int j = 0;
		for (j=ret;j<pa->size;j++)
		{
			pa->data[j] = pa->data[j + 1];
		}
		pa->size--;
		printf("删除成功\n");
	}
}
void searchcontact(struct contact* pa)
{
	int i = 0;
	char name[MAX_NAME];
	printf("请输入查找对象:>");
	scanf("%s", name);
	int ret = Findmyname(name, pa);
		if (ret == -1)
		{
			printf("对象不存在\n");
		}
		else
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", pa->data[i].name,
				pa->data[ret].age,
				pa->data[ret].sex,
				pa->data[ret].tele,
				pa->data[ret].addr);
		}

}
  static int Findmyname(char* name,const struct contact* pa)
{
	  int i = 0;
	for (i = 0; i < pa->size; i++)
	{
		if (strcmp(name, pa->data[i].name) == 0)
		{
			return i;
		}
	}
	if (i == pa->size)
	{
		return-1;
	}
}
void modifycontact(struct contact* pa)
{
	char name[MAX_NAME];
	printf("请输入修改对象:>");
	scanf("%s", name);
	int ret = Findmyname(name, pa);
	if (ret == -1)
	{
		printf("对象不存在\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", (pa->data[ret]).name);
		printf("请输入年龄:>");
		scanf("%d", &((pa->data[ret]).age));
		printf("请输入性别:>");
		scanf("%s", (pa->data[ret]).sex);
		printf("请输入电话:>");
		scanf("%s", (pa->data[ret]).tele);
		printf("请输入地址:>");
		scanf("%s", (pa->data[ret]).addr);
		pa->size++;
		printf("修改成功\n");
	}
}
void sortcontact(struct contact* pa)
{
	;
}