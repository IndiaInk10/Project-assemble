#pragma once
#include <stdio.h> // 기본 함수들 
#include <stdlib.h> // 동적메모리 관리를 위한 함수들 malloc, free
#include <stdbool.h> // bool자료형을 사용하기 위한 헤더파일
#include <string.h> // strcmp함수를 사용하기 위한 헤더파일

#define NAME_SIZE 10 // NODE 안의 데이터 name문자열의 크기
#define PHONE_SIZE 12 // NODE 안의 데이터 phoneNum문자열의 크기
#define EMAIL_SIZE 50 // NODE 안의 데이터 email문자열의 크기

typedef struct node { // 노드의 구조체
	struct node *llink;
	struct node *rlink;

	char n_name[NAME_SIZE];
	char n_phoneNum[PHONE_SIZE];
	char n_email[EMAIL_SIZE];
}NODE;

typedef struct dLinkedList { // 이중연결리스트의 접근 및 관리를 위한 구조체
	NODE *head;
	NODE *tail;

	int count;
}DLINKEDLIST;

typedef struct sortArray { // 버블소팅을 위한 구조체
	char name[NAME_SIZE];
	NODE *sData;
}SA;

void dlInit(DLINKEDLIST *list); // 이중연결리스트 초기화
bool dlIsEmpty(DLINKEDLIST *list); // 이중연결리스트가 비어있는가
int dlCount(DLINKEDLIST *list); // dlCount count값을 리턴하는 함수
SA *dlSort(DLINKEDLIST *list); // 버블소팅을 하기 위한 함수

void dlPrint(DLINKEDLIST *list, SA *Array); // 이중연결리스트를 출력하는 함수
NODE* dlSearchData(DLINKEDLIST *list, char *data); // 검색을 하여 노드의 주소값을 반환하는 함수
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode); // 이중연결리스트에 입력된 자료가 있는 노드를 링크하는 함수
void dlDelete(DLINKEDLIST *list, NODE *search); // 입력된 노드의 주소값을 링크를 풀고 메모리해제하는 함수