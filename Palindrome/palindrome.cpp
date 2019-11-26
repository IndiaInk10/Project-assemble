#include "Stack.h"
#define MAX_NUM 50

bool checkStringNum(int num)
{
	if (num == 1) return false; // 1�����Ͻ� �Ұ���
	else
		return true;
}

int riddleSave(StackType* s, char* string)
{
	int count = 0; // ���ڼ� ī��Ʈ�ϴ� ����
	for (int i = 0; i < strlen(string) + 1; i++)
	{
		if (string[i] >= 'A' && string[i] <= 'Z') // �빮�ڸ� �ҹ��ڷ� �ٲ㼭 push
		{
			push(s, tolower(string[i]));
			count++;
		}
		else if (string[i] >= 'a' && string[i] <= 'z') // �ҹ��ڸ� �ٷ� push
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

	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf_s("%[^\n]s", string, sizeof(string));
	printf("%s", string);
	count = riddleSave(&stringStack, string);
	//riddleSave(&stringStack, string);
	if (checkStringNum(count))
	{
		if (checkPalindrome(&stringStack, string, count))
		{
			printf("\nȸ���Դϴ�.\n");
		}

		else
			printf("\nȸ���� �ƴմϴ�.\n");
	}
	else
		printf("\nȸ�� �� �� �����ϴ�.\n");
}