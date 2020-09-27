# include <stdio.h>
# include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�.
// ======= ���� �ڵ��� ���� ========

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element *data;
	int capacity; // data ũ��
	int top; 
}StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s){
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity*sizeof(element));
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
//		fprintf(stderr, "���� ��ȭ error!\n");
//		return;	
		s -> capacity *= 2;
		s -> data = (element*)realloc(s->data, s->capacity*sizeof(element));
	}
	s->data[++(s->top)] = item;
//	else{
//		s->data[++(s->top)] = item;
//	}
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

int main(){
	StackType s;
	
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
} 

