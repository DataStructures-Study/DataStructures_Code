// 프로그램 4.3에서 스택 코드 추가
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int eval(char exp[]){
	int op1, op2, value, i=0;
	int len;
	char ch;
	StackType s;
	
	len =  strlen(exp);
	
	init_stack(&s);
	for (i=0; i<len; i++){
		ch = exp[i];
		if (ch!='+' && ch!='-' && ch!='*' && ch!='/'){ // 피연산자 이면, 
			value = ch - '0';
			push(&s, value);
		}
		else{
			op2 = pop(&s);
			op1 = pop(&s);
			switch(ch){
				case '+': push(&s, op1+op2); break;
				case '-': push(&s, op1-op2); break;
				case '*': push(&s, op1*op2); break;
				case '/': push(&s, op1 / op2); break; 
			}
		}
	}
	return pop(&s);
}

int main(){
	int result;

	printf("후위 표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
} 

 
