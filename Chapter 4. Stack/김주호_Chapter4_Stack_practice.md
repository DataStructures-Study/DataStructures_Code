# Chapter 4. Stack

## problem 10

```c
#include "Header.h"

int main() {
	StackType s;
	int size;
	int i;
	int tmp;

	init_stack(&s);

	printf("정수 배열의 크기 : ");
	scanf("%d", &size);

	printf("정수를 입력하시오 : ");
	for (i = 0; i < size; i++) {
		scanf("%d", &tmp);
		push(&s, tmp);
	}

	printf("반전된 정수 배열 : ");
	for (i = 0; i < size; i++) {
		printf("%d ", pop(&s));
	}

	return 0;
}
```

## problem 11

```c
#include "Header.h"

int main() {
	StackType s;
	char letter[20];
	int count = 0;
	int i;

	init_stack(&s);

	printf("수식 : ");
	scanf("%s", letter);
	printf("괄호 수 : ");

	// 괄호에 맞게 숫자를 stack에 집어넣고, 꺼낸다.
	for (i = 0; i < 20; i++) {
		if (letter[i] == '(') {
			count += 1;
			push(&s, count);
			printf("%d ", count);
		}

		else if (letter[i] == ')') {
			printf("%d ", pop(&s));
		}
	}
	return 0;
}
```

## problem 12

```c
#include "Header.h"

int main()
{
	int len;
	int count = 1;
	char letter[20];
	StackType s;
	init_stack(&s);

	printf("문자열을 입력하시오: ");
	scanf("%s", letter);

	strlwr(letter); // 모두 소문자로
	len = strlen(letter);

	printf("압축된 문자열: ");
	for (int i = 0; i < len; i++)
	{
		if (i == 0) // 첫 문자 바로 stack에 저장
		{
			push(&s, letter[0]);
		}

		else if (i != len - 1 && letter[i] == peek(&s)) // 이전 문자와 같다면
		{
			count++;
		}

		else if (i != len - 1 && letter[i] != peek(&s)) // 이전 문자와 다르다면
		{
			printf("%d", count); // count 출력 
			printf("%c", pop(&s)); // stack에 담긴 문자 출력

			count = 1; // 카운터 1로 초기화
			push(&s, letter[i]); // 새로운 숫자 stack에 밀어 넣음
		}

		else if (i == len - 1) // 끝 지점 처리
		{
			if (letter[i] == peek(&s)) // stack에 저장된 문자와 같다면
			{
				printf("%d", count + 1); // 카운트를 하나 늘리고 출력
				printf("%c", pop(&s)); // stack에 저장된 문자 출력
			}
			else // 다르다면
			{
				printf("%d", count); // count 출력
				printf("%c", pop(&s)); // 이전 문자 출력
				printf("1%c", letter[i]); // 마지막 문자 출력
			}
		}
	}
}

```

## problem 13

```c
#include "Header.h"

int main(void){
	char num[20];
	StackType s;
	init_stack(&s);

	printf("정수를 입력하시오: ");
	scanf("%s", num);

	for (int i = 0; num[i] !=0 ; i++)
	{
		if (i == 0) {
			push(&s, num[i]);
			printf("%c", num[i]);
		}

		else if (num[i-1] != num[i])
		{
			pop(&s);
			push(&s, num[i]);
			printf("%c", num[i]);
		}
	}
}

```

## problem 14

```c
#include "Header.h"

int stack_size(StackType* s) {
	if (is_empty(s)) {
		return 0;
	}
	else {
		return s->top + 1;
	}
}

int main(void){
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	printf("%d", stack_size(&s));

	return;
}
```

## problem 15

```c
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 8

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element location[MAX_STACK_SIZE];
	int top;
} StackType;

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = { // 미로의 형태를 0과 1로 구현
{ '1', '1', '1', '1', '1', '1', '1', '1'},
{ 'e', '0', '0', '0', '0', '1', '0', '1'},
{ '1', '1', '0', '1', '0', '1', '0', '1'},
{ '1', '1', '1', '1', '0', '1', '0', '1'},
{ '1', '1', '1', '1', '0', '0', '0', '1'},
{ '1', '1', '1', '1', '0', '1', '1', '1'},
{ '1', '1', '1', '1', '0', '0', '0', 'x'},
{ '1', '1', '1', '1', '1', '1', '1', '1'}
};

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 공백 에러\n" );
		exit(1);
	}
	else s->location[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->location[(s->top)--];
}

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) {
		return;
	}
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r; tmp.c = c;
		push(s, tmp); 
	}
}

void maze_print(StackType* s) { // 현재 미로 상태 출력
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			if (maze[i][j] == '1') { // 벽
				printf("■"); 
			}	
			else if (maze[i][j] == '0') { // 통로
				printf("  ");
			}
			else if (maze[i][j] == 'x') { // 종착지 End
				printf("E");
			}
			else // 지나온 길 . 표시
				printf("★");
		}
		printf("\n");
	}
}
void main()
{
	int r, c;
	StackType s, route;
	init(&s);      
	init(&route);   // 지나온 location을 route 스택에 기록

	here = entry;
	while (maze[here.r][here.c] != 'x') { // 종착지에 도달하지 않았다면
		r = here.r; c = here.c;
		maze[r][c] = '.';
		push_loc(&s, r - 1, c); // 아래
		push_loc(&s, r + 1, c); // 위
		push_loc(&s, r, c - 1); // 좌
		push_loc(&s, r, c + 1); // 우

		maze_print(&s);

		if (is_empty(&s)) {
			// 더 이상 갈 경로가 없으면,
			printf("실패\n");
			return;
		}
		else
		{
			// 다음 갈 경로를 스택에서 pop
			here = pop(&s);
			// 경로를 stack에 push
			push(&route, here);

			printf("\n===== 경로 출력 ====\n");
			printf("(%d, %d)", entry.r, entry.c);
			for (int i = 0; i < route.top; i++) {
				if (i%4 == 3) {
					printf("\n");
				}
				// 경로 출력
				printf("->(%d, %d)", route.location[i].r, route.location[i].c); 
			}
			printf("\n\n");
		}
		system("pause"); // 잠시 정지
		system("cls");   // clean screen	
	}
	printf("성공!!!\n\n" );
}

```

## problem 16

```c
#include "Header.h"
#include <stdlib.h>

void eliminate(char* str) // 불필요한 특수문자 제거해주는 함수
{
	for (; *str != '\0'; str++)
	{
		if (*str == '\'' || *str == ' ' || *str == ',')
		{
			strcpy(str, str + 1); // 다음문자를 가져와서 덮어씀
			str--; // str 가리키는 곳 조정
		}
	}
}
int main()
{
	char letter[30];
	char temp;
	printf("문자열을 입력하시오: ");
	scanf("%[^\n]", letter); // \n 이 나오기 전 모든 문자를 다 입력받음

	strlwr(letter); // 대소문자 변환
	eliminate(letter); // 구두점 제거

	int len = strlen(letter); 
	int center = len / 2 + 1;

	StackType s;
	init_stack(&s);

	if (len % 2 == 1) //  길이가 홀수
	{
		for (int a = 0; a < center - 1; a++)
		{
			push(&s, letter[a]);
		}
		for (int a = center; a < len; a++)
		{
			temp = pop(&s); 
			if (temp != letter[a]) 
			{
				printf("회문이 아닙니다.");
				exit(1);
			}
		}
		printf("회문입니다.");
	}
	else // 길이가 짝수
	{
		for (int a = 0; a <= center - 1; a++)
		{
			push(&s, letter[a]);
		}
		for (int a = center; a <= len - 1; a++)
		{
			temp = pop(&s); 
			if (temp != letter[a]) 
			{
				printf("회문이 아닙니다.");
				exit(1); 
			}
		}
		printf("회문입니다.");
	}
}
```

