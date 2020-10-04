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
#define MAX_SIZE 100
#define MAZE_SIZE 6

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};


```

