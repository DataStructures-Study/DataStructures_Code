# include <stdio.h>
# include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�.
// ======= ���� �ڵ��� ���� ========

#define MAX_STACK_SIZE 100

typedef int element;
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

int main(){
	StackType s;
	int size;
	int i;
	int tmp;

	printf("���� �迭�� ũ�� : "); 
	scanf("%d", &size);
		
	init_stack(&s);
	
	printf("������ �Է��Ͻÿ� : ");
	for (i=0; i<size; i++){
		scanf("%d", &tmp);
		push(&s, tmp);
	}

	
	printf("������ ���� �迭 : ");
	for (i=0; i<size; i++){
		printf("%d ", pop(&s));
	}
	
	return 0;
} 


