#include "Stack.h" // include <stdio.h>, <stdlib.h>
#include <string.h>
#define MAX_SIZE 6

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAX_SIZE][MAX_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' }
};

void push_loc(StackType* s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAX_SIZE][MAX_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAX_SIZE; r++)
	{
		for (int c = 0; c < MAX_SIZE; c++)
		{
			//printf("%c", maze[r][c]);
			if (maze[r][c] == '1')
				printf("■");
			else if (maze[r][c] == 'x')
				printf("＆");
			else if (maze[r][c] == '0')
				printf("□");
			else
				printf("→");
		}
		printf("\n");
	}
}

void print_Stack(StackType* s)
{
	printf("| ");
	for (int i = 0; i < s->top + 1; i++)
	{
		printf("[%d][%d] | ", s->data[i].r , s->data[i].c);
	}
	printf("\n");
}

int main(void)
{
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';

		maze_print(maze);

		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		print_Stack(&s);
		if (is_empty(&s))
		{
			printf("실패\n");
			return 0;
		}
		else
			here = pop(&s);
	}
	printf("\n성공\n");
	maze_print(maze);
	return 0;
}