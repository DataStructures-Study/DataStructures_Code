## Maze problem with Stack

> 출구를 찾는 기본적인 방법은 시행착오 방법으로 하나의 경로를 선택하여 시도해보고 안되면 다시 다른 경로를 시도하는 방법이다. 문제는 현재의 경로가  안 될 경우, 다른 경로를 선택해야 한다는 것으로 다른 경로들이 저장되어 있어야 한다는 것이다. 
>
> 이때, 가장 최근에 저장한 경로가 쉽게 추출되는 자료 구조를 사용하는 것이 좋을 것이며, 따라서 스택을 사용하게 된다. 구체적으로는 현재 위치에서 갈 수 있는 방들의 좌표를 스택에 쌓아두었다가 막다른 길을 만나면 아직 가보지 않은 방 중에서 가장 가까운 방으로 돌아가 새로운 경로를 찾는다. 또한 한 번 지나간 방을 다시 가면 안 되므로, 각 방들을 지날 때마다 방문했다고 표시를 하는 작업이 필요하다.

- 미로는 2차원 배열 maze[][][] [] 를 통해서 표현한다. 배열의 값이 0이면, 갈 수 있는 길이고 1이면 지나갈 수 없는 벽을 의미한다. 출구는 x로 표시되며 현재 생쥐의 위치는 m으로 표시된다. 

- 생쥐의 위치는 (행,열)의 좌푯값으로 표시하므로 스택에 저장되는 data는 (행,열) (=구조체)이 될 것이다. 방문이 끝난 위치는 2차원 배열의 값을 '.'으로 바꾼다.

- 스택이 비었는데도 출구를 찾지 못했다면 미로 탐색을 실패한 것이며, 동일한 좌표값이 중복해서 스택에 저장되어도 문제는 발생하지 않는다. 

```c
//아래 소스코드에서는 미로의 크기를 고정시켰음.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

//.. 스택 코드 추가
// ...

typedef struct maze_location
{
	int x;
    int y;
}element;
//stack 코드 추가 끝

element here={1,0},entry={1,0}; //전역변수로 지정
char maze[MAZE_SIZE][MAZE_SIZE]={
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};
void push_loc(StackType *s,int r, int c)
{
    if(r<0||c<0)
        return; //stack에 push 하지 않는다.
    if(maze[r][c]!='1' && maze[r][c]!='.')
    {
        element tmp;
        tmp.r=r;
        tmp.c=c;
        push(s,tmp);
    }
}
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for(int r=0;r<MAZE_SIZE;r++)
    {
        for(int c=0;c<MAZE_SIZE;c++)
        {
            printf("%c",maze[r][c]);
        }
        printf("\n");
    }
}
int main(void)
{
    int r,c;
    StackType s;
    init_stack(&s);
    
    here=entry; // here은 현재 위치를 의미한다. entry는 입구를 의미.
   	while(maze[here.r][here.c]!='x')
    {
        r=here.r;
        c=here.c;
        maze[r][c]='.';
        maze_print(maze);
        // 스택에 위, 아래, 왼, 오 순으로 쌓아둔다.
        push_loc(&s,r-1,c);
        push_loc(&s,r+1,c);
        push_loc(&s,r,c-1);
        push_loc(&s,r,c+1);
        
        if(is_empty(&s))
        {
            printf("fail\n");
            return;
        }
        else
            here=pop(&s);
    }
    printf("success\n");
    return 0;
}
```

#### Problem 15) 미로 탐색 프로그램에서 탐색 성공 시에 입구부터 출구까지의 경로 출력하기

최단 경로가 아닌 방(2차원 배열의 원소) 또한 '.'으로 변경될 수 있으므로 출력하게 되는 경로는 시행착오를 겪은 경로를 모두 출력하는 것.

```c
typedef struct maze_row_column
{
    int row;
    int col;
}element;
int main(void)
{
    int r,c;
    int i=0;
    //루트를 방의 좌표로 표현하자.
    element Route[20]={0,}; //초기화
    int len_Route; //나중에 출력할시에 출력할 범위를 알기 위해서
    StackType s;
    init_stack(&s);
    
    here=entry; // here은 현재 위치를 의미한다. entry는 입구를 의미.
   	while(maze[here.r][here.c]!='x')
    {
        r=here.r;
        c=here.c;
        maze[r][c]='.';
        Route[i].col=c;
        Route[i].row=r;
        i++;
        maze_print(maze);
        // 스택에 위, 아래, 왼, 오 순으로 쌓아둔다.
        push_loc(&s,r-1,c);
        push_loc(&s,r+1,c);
        push_loc(&s,r,c-1);
        push_loc(&s,r,c+1);
        
        if(is_empty(&s))
        {
            printf("fail\n");
            return;
        }
        else
            here=pop(&s);
    }
    //미로를 통과하는데 지난 방의 개수=i+1
    len_Route=i+1;
    for(int i=0;i<len_Route;i++)
    {
        printf("(%d,%d)->",Route[i].row,Route[i].col);
    }
    printf("Success?!?!?");
    printf("success\n");
    return 0;
}
```











