#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�.
// ======= ���� �ڵ��� ���� ========
typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s){
	s->top = -1;
} 

// ���� ���� ���� �Լ�
int is_empty(StackType *s){
	return (s->top==-1);
} 

// ��ȭ ���� ���� �Լ�
int is_full(StackType *s){
	return (s->top==(MAX_STACK_SIZE));
} 

// ���� �Լ�
void push(StackType *s, element item){
	if(is_full(s)){
		fprintf(stderr, "���� ��ȭ error!\n");
		return;	
	}
	else{
		s->data[++(s->top)] = item;
	}
}

// ���� �Լ� 
element pop(StackType *s){
	if (is_empty(s)){
		fprintf(stderr, "���� ���� error!\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// peek �Լ�
element peek(StackType *s){
	if (is_empty(s)){
		fprintf(stderr, "���� ���� error!\n");
		exit(1);
	}
	else return s->data[s->top];
} 
// ======== ���� �ڵ� �� ==========

// �������� �켱������ ��ȯ�Ѵ�.
int prec(char op){
	switch (op){
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
} 

// ���������� -> ����������  
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
			//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
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
			default:    //�ǿ�����
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
	printf("����ǥ����� %s \n", s);
	
	printf("����ǥ����� ");
	infix_to_postfix(s);
	printf("\n");
	return 0; 
} 


