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
		printf("���������������������\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", (pa->data[pa->size]).name);
		printf("����������:>");
		scanf("%d", &((pa->data[pa->size]).age));
		printf("�������Ա�:>");
		scanf("%s", (pa->data[pa->size]).sex);
		printf("������绰:>");
		scanf("%s", (pa->data[pa->size]).tele);
		printf("�������ַ:>");
		scanf("%s", (pa->data[pa->size]).addr);
		pa->size++;
		printf("��ӳɹ�\n");
	}
	
}
void showconatact(struct contact* pa)
{
	printf("%-12s\t%-4s\t%-5s\t%-20s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������ɾ������:>");
	scanf("%s",name );
	//���Ҷ���
	int i = 0;
	int ret = Findmyname(name, pa,&i);
	if (ret ==-1)
	{
		printf("���󲻴���\n");
	}
	//ɾ����ϵ��
	else
	{
		int j = 0;
		for (j=ret;j<pa->size;j++)
		{
			pa->data[j] = pa->data[j + 1];
		}
		pa->size--;
		printf("ɾ���ɹ�\n");
	}
}
void searchcontact(struct contact* pa)
{
	int i = 0;
	char name[MAX_NAME];
	printf("��������Ҷ���:>");
	scanf("%s", name);
	int ret = Findmyname(name, pa);
		if (ret == -1)
		{
			printf("���󲻴���\n");
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
	printf("�������޸Ķ���:>");
	scanf("%s", name);
	int ret = Findmyname(name, pa);
	if (ret == -1)
	{
		printf("���󲻴���\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", (pa->data[ret]).name);
		printf("����������:>");
		scanf("%d", &((pa->data[ret]).age));
		printf("�������Ա�:>");
		scanf("%s", (pa->data[ret]).sex);
		printf("������绰:>");
		scanf("%s", (pa->data[ret]).tele);
		printf("�������ַ:>");
		scanf("%s", (pa->data[ret]).addr);
		pa->size++;
		printf("�޸ĳɹ�\n");
	}
}
void sortcontact(struct contact* pa)
{
	;
}