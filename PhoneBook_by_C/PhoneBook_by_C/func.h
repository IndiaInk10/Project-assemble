#pragma once // #ifndef __헤더파일이름(대문자)_H_ #endif
#include <stdio.h>
#include <windows.h> // 창사이즈 조절되게 하는 헤더파일
#include "phoneInfo.h" // 이중연결리스트 구현하기 위한 함수

void menu(DLINKEDLIST *DLL); //메뉴
void endOrMenu(DLINKEDLIST *DLL); // 종료

void printPhoneBook(DLINKEDLIST *DLL); //출력
void searchInfo(DLINKEDLIST *DLL); //검색
void insertInfo(DLINKEDLIST *DLL); // 추가
void modifyInfo(DLINKEDLIST *DLL); // 수정
void deleteInfo(DLINKEDLIST *DLL); // 삭제