#### 10번)

```c
#include<stdio.h>

#define max_size 100

typedef struct Stacktype {
	int stack[max_size];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	int n, temp;
	Stacktype s;
	Stack_init(&s);

	printf("정수 배열의 크기 : ");
	scanf_s("%d", &n);
	printf("정수를 입력하시오 : ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		Stack_push(&s, temp);
	}
	printf("반전된 정수 배열 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Stack_pop(&s));
	}
	return 0;
}
```

#### 11번) 

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef struct datas
{
    int ArrayStack[MAX_STACK_SIZE];
    int top;
}StackType;
//initializing stack
void init_stack(StackType *s)
{
    s->top=-1;
}
//스택에 대한 모든 연산은 구조체의 포인터를 받게 된다.(이제는 top값이 전역변수가 아님.)
int is_empty(StackType *s)
{
    return(s->top==-1);
}
int is_full(StackType *s)
{
    return(s->top==MAX_STACK_SIZE-1);
}
//push연산
void push(StackType *s,int item)
{
    if(is_full(s))
        printf("Error, can't push");
    else
        s->ArrayStack[++(s->top)]=item;
}
//pop연산
int pop(StackType *s)
{
    if(is_empty(s))
        printf("Error, can't pop");
    else
        return s->ArrayStack[(s->top)--];
}
//peek function
int peek(StackType *s)
{
    if(is_empty(s))
        printf("Error, can't peek");
    else
        return s->ArrayStack[s->top];
}
int main()
{
    StackType *s;
    char input[100];
    init_stack(s);
    printf("수식: ");
    scanf("%s",input);
    int i=0;
    int num=1;
    while(input[i]!=NULL)
    {
        if(input[i]=='(')
        {
            push(s,num);
            printf("%d ",num);
            num++;
        }
        else if(input[i]==')')
        {
            printf("%d ",pop(s));
        }
        i++;
    }
    return 0;
}
```



#### 12번)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[20];
    int alphabet[26]={0,};
    printf("Enter string :");
    scanf("%s",word);
    for(int i=0;i<strlen(word);i++)
    {
        if('a'<=word[i] && word[i]<='z')
        {
            alphabet[(int)word[i]-97]++;
        }
        else if('A'<=word[i] && word[i]<='Z')
        {
            alphabet[(int)word[i]-65]++;
        }
    }
    printf("run length :");
    for(int i=0;i<26;i++)
    {
        if(alphabet[i]!=0)
        {
            printf("%d",alphabet[i]);
            printf("%c",i+97);
        }
    }
    return 0;
}

```



#### 13번)

```c
#include<stdio.h>
#define MAX_SIZE 100

typedef struct Stacktype {
	int stack[MAX_SIZE];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	printf("정수를 입력하시오. : ");
	char input[MAX_SIZE];
	scanf_s("%s", input, sizeof(input));

	Stacktype s1, s2;
	Stack_init(&s1);
	Stack_init(&s2);

	int i = 0;
	while (input[i] != NULL) {
		if (input[i] != input[i + 1])
			Stack_push(&s1, input[i] - '0');
		i++;
	}
	while (!is_empty(&s1)) {
		Stack_push(&s2, Stack_pop(&s1));
	}
	printf("출력 : ");
	while (!is_empty(&s2)) {
		printf("%d", Stack_pop(&s2));
	}
	return 0;
}
```



#### 14번)

```c
int size(StackType *s){
	return s->top + 1;
}
```



#### 15번)

```

```



#### 16번

```c
#include<stdio.h>

#define MAX_SIZE 100

typedef struct Stacktype {
	char stack[MAX_SIZE];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

char Stack_pop(Stacktype* s) {
	char t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	printf("문자열을 입력하시오 : ");
	char input[MAX_SIZE];
	scanf_s("%s", input, sizeof(input));

	Stacktype s;
	Stack_init(&s);
	int i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z')
			Stack_push(&s, input[i]);
		// 대문자는 소문자로 바꿔서 stack에 저장.
		else if ('A' <= input[i] && input[i] <= 'Z')
			Stack_push(&s, input[i] - ('A' - 'a')); 
		i++;
	}
	bool flag = true;
	i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			if (Stack_pop(&s) != input[i]) {
				flag = false;
				break;
			}
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			if (Stack_pop(&s) != (input[i] - ('A' - 'a'))) {
				flag = false;
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

