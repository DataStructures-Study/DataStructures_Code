# Chapter 7. LinkedList2

----------

01.

(3) (ㄴ)에서 자료 c를 가져오려면 pop 3번 해야함

02.

(1) 배열로 구현된 리스트.

삽입, 삭제가 비효율적

03.

- Circular_LinkedList.h

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

// 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<- |%d| ->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

```



```c
#include "Circular_LinkedList.h"

ListNode* search(ListNode* tail, element data)
{
	ListNode* n = NULL;
	if (tail->link == NULL) return NULL;

	for (n = tail->link;; n = n->link) {
		//L이 가리키는 값(data, link)를 n에 복사, 그리고 한 반복이 끝나면 n을 다음으로 이동
		if (data == n->data)
			return n;
		if (n == tail)
			//for 문에 넣는경우 n과 L이 일치하면 먼저 종료되기에 이를 막기위해서 끝에 넣는다
			break;
	}

	return NULL;
}

void print(ListNode* tail)
{
	ListNode* node;
	if (tail->link == NULL)
		printf("아무것도 없습니다");
	for (node = tail->link;; node = node->link) {
		printf("%d ", node->data);
		if (node == tail)
			//for 문에 넣는경우 n과 L이 일치하면 먼저 종료되버림
			break;
	}

}
void main() {
	int scan;
	ListNode* tail = NULL;
	tail = insert_first(tail, 10);
	tail = insert_first(tail, 30);
	tail = insert_first(tail, 40);
	tail = insert_first(tail, 60); 

	printf("현재 입력된 값 : ");
	print(tail); // 출력
	printf("\n찾는 값을 입력하시오 : ");
	scanf("%d", &scan); // 찾을 목표값 입력
	if (search(tail, scan) != NULL)
		printf("값 %d는 리스트 안에 있습니다\n", scan);
	else
		printf("값 %d는 리스트 안에 없습니다\n", scan);
}
```



04.

```c
#include "Circular_LinkedList.h"

int get_size(ListNode* L)
{
	ListNode* n;
	int count = 0;
	if (L->link == NULL) return 0;
    
	for (n = L->link;; n = n->link) {
		// L이 가리키는 값(data, link)를 n에 복사, 그리고 한 반복이 끝나면 n을 다음으로 이동
		count++;
		if (n == L)
			//for 문에 넣는경우 n과 L이 일치하면 먼저 종료되버림
			break;
	}
	return count;
}

void main() {
	int scan;
	ListNode* tail = NULL;
	tail = insert_first(tail, 10);
	tail = insert_first(tail, 30);
	tail = insert_first(tail, 40);
	tail = insert_first(tail, 60); //값 입력

	printf("원형 연결리스트에 들어 있는 원소의 개수 : %d", get_size(tail));
}
```

05.

- 장점
    - 선행노드에 대한 접근이 쉬워짐
- 단점
    - size가 커짐
    - link 연결 관리 및 구현이 복잡해짐.

06.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

// 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<- |%d| ->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

```



```c
#include "Double_LinkedList.h"

void print_reverse(DListNode* d) //출력함수-반대
{
	DListNode* node;
	for (node = d->llink; node != d; node = node->llink)
		//이전 노드 방향으로 진행한다
		printf(" %d ", node->data);
	printf("\n");
}

void main() {
	DListNode* n = (DListNode*)malloc(sizeof(DListNode));

	init(n);
	//n을 초기화
	int scan;
	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &scan);
	for (int a = 0; a < scan; a++)
	{
		int temp;
		printf("노드 #%d의 데이터를 입력하시오 : ", a + 1);
		scanf("%d", &temp);
		dinsert(n, temp); 
	}
	print_dlist(n);
	printf("\n");

	printf("\n데이터를 역순으로 출력 :\n");
	print_reverse(n); // 출력
}

```

07.

```c
#include "Double_LinkedList.h"

DListNode* search(DListNode* L, element data)
{
	for (DListNode* p = L->rlink; p != L; p = p->rlink) {
		if (p->data == data)
			return p; //찾는 값이 존재하면 p 반환
	}
	return NULL; //찾는 값이 없다면 NULL 반환
}

main()
{
	DListNode* n = (DListNode*)malloc(sizeof(DListNode));

	init(n);
	//n을 초기화
	int num, target;
	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &num);
	for (int a = 0; a < num; a++)
	{
		int temp;
		printf("노드 #%d의 데이터를 입력하시오 : ", a + 1);
		scanf("%d", &temp);
		dinsert(n, temp); 
	}
	print_dlist(n); printf("\n");

	printf("찾을 값을 입력하시오 : ");
	scanf("%d", &target);
	if (search(n, target) != NULL) // 만약 search 함수의 결과가 NULL이 아니면
		printf("값 %d는 리스트 내부에 존재합니다\n", target);
	else 
		printf("값 %d는 리스트 내부에 없습니다\n", target);
}

```

