# include <stdio.h>
# include <stdlib.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다.
// ======= 스택 코드의 시작 ========

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element *data;
	int capacity; // data 크기
	int top; 
}StackType;

// 스택 초기화 함수
void init_stack(StackType *s){
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity*sizeof(element));
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
//		fprintf(stderr, "스택 포화 error!\n");
//		return;	
		s -> capacity *= 2;
		s -> data = (element*)realloc(s->data, s->capacity*sizeof(element));
	}
	s->data[++(s->top)] = item;
//	else{
//		s->data[++(s->top)] = item;
//	}
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

