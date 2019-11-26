#pragma once
#include "DoubleLinkedList.h"

void Menu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //메뉴
void rentMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // rent메뉴
void endMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 종료메뉴

void insertData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 추가
void printCanRent(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //출력
void searchData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //검색
void rentVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 대여
void returnVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 반납
void modifyData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 수정
void deleteData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // 삭제