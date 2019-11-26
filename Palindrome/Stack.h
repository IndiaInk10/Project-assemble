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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else memcpy(&s->data[++(s->top)], &item, sizeof(item)); // ���ڰ��� �Է��ϱ� ���� memcpy ���
}

element* pop(StackType* s) // strcmp�� ����ϱ� ���� �����ͷ� ����
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return &(s->data[(s->top)--]);
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// Stack code end