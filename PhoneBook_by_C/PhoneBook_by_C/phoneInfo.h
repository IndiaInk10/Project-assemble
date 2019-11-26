#pragma once
#include <stdio.h> // �⺻ �Լ��� 
#include <stdlib.h> // �����޸� ������ ���� �Լ��� malloc, free
#include <stdbool.h> // bool�ڷ����� ����ϱ� ���� �������
#include <string.h> // strcmp�Լ��� ����ϱ� ���� �������

#define NAME_SIZE 10 // NODE ���� ������ name���ڿ��� ũ��
#define PHONE_SIZE 12 // NODE ���� ������ phoneNum���ڿ��� ũ��
#define EMAIL_SIZE 50 // NODE ���� ������ email���ڿ��� ũ��

typedef struct node { // ����� ����ü
	struct node *llink;
	struct node *rlink;

	char n_name[NAME_SIZE];
	char n_phoneNum[PHONE_SIZE];
	char n_email[EMAIL_SIZE];
}NODE;

typedef struct dLinkedList { // ���߿��Ḯ��Ʈ�� ���� �� ������ ���� ����ü
	NODE *head;
	NODE *tail;

	int count;
}DLINKEDLIST;

typedef struct sortArray { // ��������� ���� ����ü
	char name[NAME_SIZE];
	NODE *sData;
}SA;

void dlInit(DLINKEDLIST *list); // ���߿��Ḯ��Ʈ �ʱ�ȭ
bool dlIsEmpty(DLINKEDLIST *list); // ���߿��Ḯ��Ʈ�� ����ִ°�
int dlCount(DLINKEDLIST *list); // dlCount count���� �����ϴ� �Լ�
SA *dlSort(DLINKEDLIST *list); // ��������� �ϱ� ���� �Լ�

void dlPrint(DLINKEDLIST *list, SA *Array); // ���߿��Ḯ��Ʈ�� ����ϴ� �Լ�
NODE* dlSearchData(DLINKEDLIST *list, char *data); // �˻��� �Ͽ� ����� �ּҰ��� ��ȯ�ϴ� �Լ�
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode); // ���߿��Ḯ��Ʈ�� �Էµ� �ڷᰡ �ִ� ��带 ��ũ�ϴ� �Լ�
void dlDelete(DLINKEDLIST *list, NODE *search); // �Էµ� ����� �ּҰ��� ��ũ�� Ǯ�� �޸������ϴ� �Լ�