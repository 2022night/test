#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
struct PeoInfo
{
	char name[MAX_NAME];
	int  age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct contact
{
	struct PeoInfo data[MAX];
	int size;//Ԫ�ظ���
};
// ��ʼ��ͨѶ¼
void initcontact(struct contact* pa);
//���ͨѶ¼��ϵ��
void addcontact(struct contact* pa);
//�鿴ͨѶ¼
void showconatact(const struct contact* pa);
//ɾ����ϵ��
void delcontact(struct contact* pa);
//������ϵ��
void searchcontact(struct contact* pa);
//�޸���ϵ����Ϣ
void modifycontact(struct contact* pa);
//���࣬����
void sortcontact(struct contact* pa);
enum Fun
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};