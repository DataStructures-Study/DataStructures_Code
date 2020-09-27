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
	char letter[20];
	int count =0;
	int a;
	
	pritntf("���� : ");
	scanf("%s", letter);
	printf("��ȣ �� : ");
	for (a=0; a<20; a++){
		if (letter[a] == '('){
			count+=1;
			push(&s, count);
			printf("%d ", count);
		}
		
		else if (letter[a]==')'){
			printf("%d ", pop(&s));
		}
	}
	return 0;
} 


