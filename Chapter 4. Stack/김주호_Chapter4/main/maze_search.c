#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 6

// ======= 스택 코드의 시작 ========

#define MAX_STACK_SIZE 100

typedef struct{
	short r;
	short c;
}element;

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

element here = {1,0}, entry = {1,0};
char maze[MAX_SIZE][MAX_SIZE] ={
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

//위치를 스택에 삽입
void push_loc(StackType *s, int r, int c){
	if (r<0 || c<0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.'){
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//미로를 화면에 출력한다. 
void maze_print(char maze[MAX_SIZE][MAX_SIZE]){
	int r, c;
	printf("\n");
	for (r=0; r<MAX_SIZE; r++){
		for(c=0; c<MAX_SIZE; c++){
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}

} 

int main(){
	int r, c;
	StackType s;
	
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x'){
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		
		push_loc(&s, r-1, c);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c-1);
		push_loc(&s, r, c+1);
		
		if (is_empty(&s)){
			printf("실패..\n");
			return ;
		}
		else{
			here = pop(&s);
		}
	}
	printf("성공!!\n");
	return 0;
}


