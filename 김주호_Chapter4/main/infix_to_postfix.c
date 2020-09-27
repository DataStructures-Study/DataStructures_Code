#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// 차후에 스택이 필요하면 여기만 복사하여 붙인다.
// ======= 스택 코드의 시작 ========
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

// 연산자의 우선순위를 반환한다.
int prec(char op){
	switch (op){
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
} 

// 중위연산자 -> 후위연산자  
void infix_to_postfix(char exp[]){
	int i = 0;
	char ch, top_op;
	int len=strlen(exp);
	StackType s;
	
	init_stack(&s);
	for (i=0; i<len; i++){
		ch = exp[i];
		switch(ch){
			case '+': case'-': case'*': case'/':
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
				while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))) ){
					printf("%c", pop(&s));				
				}
				push(&s, ch);
				break;
			case '(':
				push(&s, ch);
				break;
			case ')':
				top_op = pop(&s);
				while (top_op != '('){
					printf("%c", top_op);
					top_op = pop(&s);
				}
				break;
			default:    //피연산자
				printf("%c", ch);
				break; 
		}
	}
	while(!is_empty(&s)){
		printf("%c", pop(&s));
	}
}


int main(){
	char *s = "(2+3)*4+9";
	printf("중위표기수식 %s \n", s);
	
	printf("후위표기수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0; 
} 


