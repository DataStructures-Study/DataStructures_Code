// ���α׷� 4.3���� ���� �ڵ� �߰�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�.
// ======= ���� �ڵ��� ���� ========

#define MAX_STACK_SIZE 100

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

int eval(char exp[]){
	int op1, op2, value, i=0;
	int len;
	char ch;
	StackType s;
	
	len =  strlen(exp);
	
	init_stack(&s);
	for (i=0; i<len; i++){
		ch = exp[i];
		if (ch!='+' && ch!='-' && ch!='*' && ch!='/'){ // �ǿ����� �̸�, 
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

	printf("���� ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
} 

 
