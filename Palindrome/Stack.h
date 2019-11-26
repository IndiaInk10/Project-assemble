#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

// Stack code start
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else memcpy(&s->data[++(s->top)], &item, sizeof(item)); // 문자값을 입력하기 위해 memcpy 사용
}

element* pop(StackType* s) // strcmp를 사용하기 위해 포인터로 변경
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return &(s->data[(s->top)--]);
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// Stack code end