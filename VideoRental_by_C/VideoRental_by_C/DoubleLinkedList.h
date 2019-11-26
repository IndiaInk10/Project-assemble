#pragma once
#include <stdio.h> // 기본 함수들 
#include <stdlib.h> // 동적메모리 관리를 위한 함수들 malloc, free
#include <stdbool.h> // bool자료형을 사용하기 위한 헤더파일
#include <string.h> // strcmp함수를 사용하기 위한 헤더파일
#include <Windows.h>

#include "dataStruct.h"
#include "DateCalFunc.h"

typedef struct node { // 노드의 구조체
	struct node *llink;
	struct node *rlink;

	subs_or_videos sOrV;
}NODE;

typedef struct dLinkedList { // 이중연결리스트의 접근 및 관리를 위한 구조체
	NODE *head;
	NODE *tail;

	int count;
}DLINKEDLIST;

typedef struct sortArray { // 버블소팅을 위한 구조체
	char name[SRENTNAME_SIZE];
	int count;

	NODE* data;
}SA;

NODE* createSNode(); // sube데이터를 가진 노드값 초기화
NODE* createVNode(); // video데이터를 가진 노드값 초기화

void dlSInit(DLINKEDLIST *list); // 이중연결리스트 초기화
void dlVInit(DLINKEDLIST *list);

bool dlIsEmpty(DLINKEDLIST *list); // 이중연결리스트가 비어있는가
int dlCount(DLINKEDLIST *list); // dlCount count값을 리턴하는 함수
SA *dlSort(DLINKEDLIST *list); // 버블소팅을 하기 위한 함수 - 바꿔야 할 듯함

void dlInputFile(DLINKEDLIST *list, char *fileName); // 이중연결리스트에 파일 입력
void dlOutputFile(DLINKEDLIST *list, char *fileName); // 이중연결리스트의 값을 파일로 출력
void dlPrint(SA *Array); // 이중연결리스트를 출력하는 함수
void dlSearchData(DLINKEDLIST *list, char *dataName, char *data); // 검색을 하여 노드의 주소값을 반환하는 함수
SA* dlModifyData(DLINKEDLIST *list, char *dataName, char *data);
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode); // 이중연결리스트에 입력된 자료가 있는 노드를 링크하는 함수
void dlDelete(DLINKEDLIST *list, NODE *search); // 입력된 노드의 주소값을 링크를 풀고 메모리해제하는 함수