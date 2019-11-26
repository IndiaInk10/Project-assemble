//#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct Date {
	int y;
	int m;
	int d;
}Date;

Date* getDate(); // 현재 날짜 받아오기
Date* changeInteger(char *date);

bool checkLeapYear(int year);

int monthDateCal(int year, int month);
int totalDate(int year, int month, int day);
int DateCal(Date Data1, Date data2);

char* changeString(int y, int m, int d); 