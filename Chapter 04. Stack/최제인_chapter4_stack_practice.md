#### 10

```c
상위 코드는 교재 114쪽과 동일

int main(void)
{
	StackType* s;


	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int input;
	printf("정수 배열의 크기: ");
	scanf_s("%d", &input);
	printf("정수를 입력하시오. ");
	int element;
	for (int i = 0;i < input;i++) {
		scanf_s("%d", &element);
		push(s, element);
	}
	for (int j = 0;j < input;j++) {
		printf("%d ", pop(s));
	}
}

```



#### 11

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
상위 코드는 교재 114쪽과 동일
void check_matching(const char* in)
{
	StackType s;
	char ch;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s);			// 스택의 초기화
	int count = 1;
	printf("괄호 수: ");
	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = 다음 문자
		switch (ch) {
		case '(': 
			push(&s, count);
			printf("%d ", count);
			count ++;
			break;
		case ')':  
			if (is_empty(&s))  return 0;
			else {
				printf("%d ", pop(&s));
				break;
			}
		}
	}
	
}

int main(void)
{
	char p[MAX_STACK_SIZE];
	printf("수식: ");
	gets(p);
	check_matching(p);
	
	return 0;
}
```



#### 12

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 



int main(void)
{
	StackType s;
	init_stack(&s);
	StackType sentence;
	init_stack(&sentence);
	//입력
	char str[20];
	printf("문자열을 입력하시오: ");
	gets(str);
	printf("%s", str);
	char count;
	char ch,lowch,ch1,lowch1;
	char find;
	int len = strlen(str);
	for (int i = 0;i < len;i++) {
		push(&s, str[i]);
	}
	
	do{
		ch = peek(&s);
		count = '0';
		if (isupper(ch)) lowch = tolower(ch);
		else lowch = ch;
		while (1) {
			ch1 = peek(&s);
			lowch1 = tolower(ch1);
			if (lowch == lowch1) {
				printf("%c",pop(&s));count++;
			}
			else {
				break;
			}
			if (s.top == -1) {
				break;
				}

		}
		push(&sentence,lowch);
		push(&sentence,count);
	} while (s.top!=-1);
	printf("압축된 문자열: ");
	while(1){
		if (sentence.top == -1) {
			
			break;
		}
		printf("%c", pop(&sentence));
	
		
	}

	return 0;
}
```



#### 13

```c
싱위코드 114쪽
int main(void)
{
	StackType s1;
	init_stack(&s1);
	StackType s2;
	init_stack(&s2);

	char input[MAX_STACK_SIZE];
	printf("정수를 입력하시오.");
	scanf_s("%s", input, sizeof(input));
	//한글자씩 
	
	int i = 0;
	while (input[i] != NULL) {
		if (input[i] != input[i + 1])
			push(&s1, input[i] - '0');
		i++;
	}
	while (!is_empty(&s1)) {
		push(&s2, pop(&s1));
	}
	printf("출력 : ");
	while (!is_empty(&s2)) {
		printf("%d", pop(&s2));
	}
	return 0;
}
```



#### 14

```c
int size(StackType* s){
    if(is_empty(&s)){
    return 0;
    }
    else {
        return (s->top + 1);
    }
}
```



#### 15

```c

```



#### 16

```c
int main(void)
{
	printf("문자열을 입력하시오 : ");
	char input[MAX_STACK_SIZE];
	scanf_s("%s", input, sizeof(input));

	StackType s;
	init_stack(&s);
	int i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z')
			push(&s, input[i]);
		// 대문자는 소문자로 바꿔서 stack에 저장.
		else if ('A' <= input[i] && input[i] <= 'Z')
			push(&s, input[i] - ('A' - 'a'));
		i++;
	}
	int flag = 1;
	i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			if (pop(&s) != input[i]) {
				flag = 0;
				break;
			}
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			if (pop(&s) != (input[i] - ('A' - 'a'))) {
				flag = 0;
				break;
			}
		}
		i++;
	}
	if (flag)
		printf("회문입니다.\n");
	else
		printf("회문이아닙니다.\n");
}

```



