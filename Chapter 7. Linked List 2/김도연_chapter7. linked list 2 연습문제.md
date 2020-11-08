# 7장 연결리스트 2 연습문제



1>

pop 연산 1회 수행 시-자료 a, 2회시 자료 b, 3회시 자료 c를 가져올수 있다.

(3)



2>

배열로 구현된 리스트는 삽입과 삭제작업시 다른 자료들을 이동시켜야 하기 때문에 실행 시간이 많이 소요 된다.

(1)



3>

원형 연결 리스트에서 특정한 값을 탐색하는 함수 search()

```c
//원형 연결 리스트 L에서 data를 가지고 있는 노드를 찾아서 반환한다.
ListNode *search(ListType* L, element data)
{
    ListType* p=L; 
    do{
        if(p->data==data) return p;
        p=p->link;
    }while(p!=L);
    return NULL;
}
```



4>

원형 연결 리스트에서 저장된 데이터의 개수를 반환하는 함수 get_size()



```c
//원형 연결 리스트 L에 저장된 데이터의 개수를 반환한다.
int get_size(ListNode *L);
{
    ListType* p=L; 
    int count=0;
    do{
        count++;
        p=p->link;
    }while(p!=L);
    
    return count;
    
}
```



5>

이중 연결리스트의 장점은 링크가 양방향이므로 양방향으로 검색이 가능하다는 점이고 단점으로는 공간을 많이 차지하고 코드가 복잡해진다는 것이다.



6>

이중 연결리스트를 역순으로 순회하면서 저장된 데이터 값을 출력하는 프로그램

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}


// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

int main(void)
{
    
}
```



7> 이중 연결 리스트에서 특정 값을 탐색하는 함수 search() 

```c
//이중 연결 리스트 L에서 data를 가지고 있는 노드를 찾아서 반환한다.
DListNode *search(DListNode *L, element data);
{
    DListNode* p;
    for(p=L->rlink; p!=L; p=p->rlink)
    {
        if(p->data==data)
            return p;
    }
    return NULL;
}
```

