#include "DateCalFunc.h"

Date* getDate()
{
	struct tm date;
	time_t t = time(NULL); //  ���� �ð� �ޱ�
	Date *currentDate = (Date*)malloc(sizeof(Date));
	memset(currentDate, 0, sizeof(Date));

	localtime_s(&date, &t);

	currentDate->y = date.tm_year + 1900; // �⵵ 1900�⵵ �����̱⿡ 1900 ����
	currentDate->m = date.tm_mon + 1; // ���� 0���� �����̱⿡ 1�� ����
	currentDate->d = date.tm_mday;

	return currentDate;
}
Date* changeInteger(char* date)
{
	Date *newDate = (Date*)malloc(sizeof(Date));
	memset(newDate, 0, sizeof(Date));

	char *context;
	char *tok[3];

	context = date;

	for (int i = 0; i < 3; i++)
	{
		tok[i] = strtok_s(context, "-", &context);
	}

	newDate->y = atoi(tok[0]);
	newDate->m = atoi(tok[1]);

	if (newDate->m == 1 || newDate->m == 3 || newDate->m == 5 || newDate->m == 7 || newDate->m == 8 || newDate->m == 10 || newDate->m == 12)
	{
		newDate->d = 31; // �����ؾ��� �κ�
	}
	else if (newDate->m == 2)
	{
		if (checkLeapYear(newDate->y) == true)
			newDate->d = 29;
		else
			newDate->d = 28;
	}
	else
		newDate->d = 30;

	return newDate;
}

bool checkLeapYear(int year)
{
	/*������ ����
	1. 4�� ������ ��������.
	2. 4�� ������ ��������, 100���ε� ������ ��������.
	3. 400�� ������ ��������.*/

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}

	return false;
}
int monthDateCal(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	else if (month == 2)
	{
		if (checkLeapYear(year) == true)
			return 29;
		else
			return 28;
	}
	else
		return 30;
}
int totalDate(int year, int month, int day)
{
	int sum = 0;

	sum += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400; // �� �⵵���� -1 �� �Ͽ� ���� �⵵������ �� ��¥�� ���ϰ� �ű⼭ ����
																					// ó���� ���� �������� ���� ���� ���� ���� �ذ��Ѵ�

	for (int i = 0; i < month - 1; i++) // ���� ���� ���� �� ���� �����ְ�
	{
		sum += monthDateCal(year, i+1);
	}

	sum += day; // �� ���� ��¥�� �� ���� �� ��¥�� ����Ѵ�.

	return sum;
}																					
//int DateCal(Date Date1, Date date2) // �� ��¥�� ����, ������ �߽����� ���� �� ��
//{
//	int sum = 0; // �������� Ȯ���ϸ鼭 ���ؾ���
//	int y = Date1.y, m = Date1.m, d = Date1.d;
//
//	// ���� �ٸ�������
//
//	if (d != date2.d)
//	{
//		sum = date2.d - d;
//
//		d = date2.d;
//	}
//
//	while (m != date2.m) // ���� �ٸ�������
//	{
//		if (m > date2.m) // ���� ���� �� Ŭ ���
//		{
//			sum -= monthDateCal(Date1.y, m); // �ش� ��� ���� �Ƿ��� �۾�������
//			m--;
//		}
//		else if (m < date2.m)
//		{
//			sum += monthDateCal(Date1.y, m); // �ش� ��� ���� �Ƿ��� Ŀ������
//			m++;
//		}
//		else
//			break;
//	}
//
//	while (y != date2.y)
//	{
//		if (checkLeapYear(y) == false)
//		{
//			if (y < date2.y)
//			{
//				sum += 365;
//				y++;
//			}
//			else if (y > date2.y)
//			{
//				sum -= 365;
//				y--;
//			}
//			else
//				break;
//		}
//		else// ����� ���
//		{
//			if (y < date2.y)
//			{
//				sum += 366; // ������ ����
//				y++;
//			}
//			else if (y > date2.y)
//			{
//				sum -= 366; // ������ ����
//				y--;
//			}
//			else
//				break;
//		}
//	}
//
//	return sum;
//}
int DateCal(Date Date1, Date date2) // ������ ������ ��´�.
{
	int d1 = 0, d2 = 0, dateCal = 0;

	d1 = totalDate(Date1.y, Date1.m, Date1.d);
	d2 = totalDate(date2.y, date2.m, date2.d);

	dateCal = d1 - d2;

	return dateCal;
}

char* changeString(int y, int m, int d)
{
	char *newDate = (char*)malloc(sizeof(char)*12);
	memset(newDate, 0, sizeof(char)*12);
	char year[5], month[3], day[3];

	_itoa_s(y, year, _countof(year), 10);
	_itoa_s(m, month, _countof(month), 10);
	_itoa_s(d, day, _countof(day), 10);

	strcat_s(newDate, sizeof(char)*12, year); strcat_s(newDate, sizeof(char) * 12, "-");
	if (m >= 10)
	{
		strcat_s(newDate, sizeof(char) * 12, month); strcat_s(newDate, sizeof(char) * 12, "-");
	}
	else
	{
		strcat_s(newDate, sizeof(char) * 12, "0");
		strcat_s(newDate, sizeof(char) * 12, month); strcat_s(newDate, sizeof(char) * 12, "-");
	}
	if (d >= 10)
	{
		strcat_s(newDate, sizeof(char) * 12, day);
	}
	else
	{
		strcat_s(newDate, sizeof(char) * 12, "0");
		strcat_s(newDate, sizeof(char) * 12, day);
	}

	return newDate;
}

