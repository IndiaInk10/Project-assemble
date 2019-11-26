#include "Stack.h"
#define MAX_NUM 50

bool checkStringNum(int num)
{
	if (num == 1) return false; // 1글자일시 불가능
	else
		return true;
}

int riddleSave(StackType* s, char* string)
{
	int count = 0; // 글자수 카운트하는 변수
	for (int i = 0; i < strlen(string) + 1; i++)
	{
		if (string[i] >= 'A' && string[i] <= 'Z') // 대문자면 소문자로 바꿔서 push
		{
			push(s, tolower(string[i]));
			count++;
		}
		else if (string[i] >= 'a' && string[i] <= 'z') // 소문자면 바로 push
		{
			push(s, string[i]);
			count++;
		}
		else
			continue;
	}
	printf("\n%d\n", count);
	return count;
}

bool checkPalindrome(StackType* s, char* string, int count)
{
	char* popS = NULL;
	for(int i = 0; i < count; i++)
	{
		popS = pop(s);
		for (int j = 0; j < strlen(string) + 1; j++)
		{
			if (strcmp(&string[i], popS) == 0)
				break;
			else if (j == strlen(string) && strcmp(&string[i], popS) != 0)
				return false;				
		}
	}
	if (is_empty(s))
		return true;
}

int main(void)
{
	
	char string[MAX_NUM] = { 0, };
	StackType stringStack;
	int count = 0;
	init_stack(&stringStack);

	printf("문자열을 입력하시오: ");
	scanf_s("%[^\n]s", string, sizeof(string));
	printf("%s", string);
	count = riddleSave(&stringStack, string);
	//riddleSave(&stringStack, string);
	if (checkStringNum(count))
	{
		if (checkPalindrome(&stringStack, string, count))
		{
			printf("\n회문입니다.\n");
		}

		else
			printf("\n회문이 아닙니다.\n");
	}
	else
		printf("\n회문 일 수 없습니다.\n");
}