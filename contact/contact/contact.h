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
	int size;//元素个数
};
// 初始化通讯录
void initcontact(struct contact* pa);
//添加通讯录联系人
void addcontact(struct contact* pa);
//查看通讯录
void showconatact(const struct contact* pa);
//删除联系人
void delcontact(struct contact* pa);
//查找联系人
void searchcontact(struct contact* pa);
//修改联系人信息
void modifycontact(struct contact* pa);
//分类，排序
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