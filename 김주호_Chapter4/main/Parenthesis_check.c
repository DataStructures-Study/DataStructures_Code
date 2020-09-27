#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// 차후에 스택이 필요하면 여기만 복사하여 붙인다.
// ======= 스택 코드의 시작 ========

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수
void init_stack(StackType *s){
	s->top = -1;
} 

// 공백 상태 검출 함수
int is_empty(StackType *s){
	return (s->top==-1);
} 

// 포화 상태 검출 함수
int is_full(StackType *s){
	return (s->top==(MAX_STACK_SIZE));
} 

// 삽입 함수
void push(StackType *s, element item){
	if(is_full(s)){
		fprintf(stderr, "스택 포화 error!\n");
		return;	
	}
	else{
		s->data[++(s->top)] = item;
	}
}

// 삭제 함수 
element pop(StackType *s){
	if (is_empty(s)){
		fprintf(stderr, "스택 공백 error!\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// peek 함수
element peek(StackType *s){
	if (is_empty(s)){
		fprintf(stderr, "스택 공백 error!\n");
		exit(1);
	}
	else return s->data[s->top];
} 
// ======== 스택 코드 끝 ==========

int check_matching(const char *in){
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n =  문자열의 길이 
	init_stack(&s);
	
	for (i=0; i<n; i++){
		ch = in[i];
		switch(ch){
			case '(': case '[': case '{':
				push(&s, ch);
				break;
			case ')': case ']': case '}':
				if (is_empty(&s)){
					return 0;
				}
				else{
					open_ch = pop(&s);
					if ((open_ch == '(' && ch!=')') || (open_ch == '[' && ch!=']') || (open_ch == '{' && ch!='}')){
						return 0;
					}
				}
				break;
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}


int main(){
	char *p = "{ A[(i+1)]=0; }";
	if (check_matching(p)==1){
		printf("%s 괄호검사성공\n", p);
	}
	else printf("%s 괄호검사실패\n", p);
	return 0;
} 

