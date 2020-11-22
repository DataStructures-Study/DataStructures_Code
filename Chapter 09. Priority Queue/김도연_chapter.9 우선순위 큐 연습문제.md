# 9 우선순위 큐 연습문제



11> 

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
	int rank;
	char* work;
}element;
//히프는 1차원 배열로 표현될 수 있기 때문에 히프의 각 요소들을 구조체 elemeht로 정의

typedef struct {
	element heap[MAX_ELEMENT]; //element의 1차원 배열
	int heap_size; //현재 히프 안에 저장된 요소의 개수
	char work;
} HeapType;

//생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

//초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size); //히프 크기 하나 증가

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		//i가 루트 노드가 아니고 i번째 노드가 i의 부모 노드보다 크면
		h->heap[i] = h->heap[i / 2];
		i /= 2;
		//i번째 노드와 부모 노드를 교환
	}
	h->heap[i] = item; //새로운 노드를 삽입
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; //루트 노드값 반환 위해 item 변수로 옮김
	temp = h->heap[(h->heap_size)--]; //히프 크키 하나 줄이고 말단 노드를 temp 변수로
	parent = 1;
	child = 2;

	while (child <= h->heap_size) { //히프 트리의 크기보다 작으면
		//현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key) < h
			->heap[child + 1].key)
			child++;

		if (temp.key >= h->heap[child].key) break;
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;


}


int main(void)
{
	HeapType* heap;

	heap = create(); //히프 생성
	init(heap); //초기화

	char select[10];
	char works[50];
	int rank = 0;

	while (select != 'd')
	{
		printf("삽입(i), 삭제(d) : ");
		scanf("%c", &select);
		if (select == 'i')
		{
			printf("할일: ");
			scanf("%s", works);
			printf("우선순위: ");
			scanf("%d", &rank);

			element a;
			a.rank = rank;
			a.work = works;
			insert_max_heap(heap, a);

		}
		else
		{
			element c = delete_max_heap(heap);
			printf("제일 우선 순위가 높은 일은 %s", c.work);
		}


	}

	free(heap);

	return 0;



}
```



14> 정렬되지 않는 배열을 이용한 우선순위 큐 추상자료형의 연산 구현

```c
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
#define MAX 999999
#define MIN -999999
typedef int bool;
#define true 1
#define false 0

typedef struct
{
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, int item)
{
	h->heap[h->heap_size] = item; //그냥 배열의 맨 끝에 새로운 요소 추가-시간복잡도O(1)
	h->heap_size++;
}

int delete_max_heap(HeapType* h)
 //정렬 안되어 있으므로 처음부터 끝까지 모든 요소들 스캔
{
	int m = MIN, index;
	for (int i = 0; i < h->heap_size; i++)
	{
		if (h->heap[i] > m)
		{
			m = h->heap[i];
			index = i;
		}
	}
	for (int i = index; i < h->heap_size; i++) //뒤에 있는 요소들을 앞으로 이동시키는 부담
		h->heap[i] = h->heap[i + 1];
	h->heap_size--;

	return m;
}

bool is_empty(HeapType* h) 
{
	return h->heap_size == 0;
}

bool is_full(HeapType* h)
{
	return h->heap_size == MAX_ELEMENT;
}

int find(HeapType* h)
{
	int m = MIN;
	for (int i = 0; i < h->heap_size; i++)
	{
		if (h->heap[i] > m)
			m = h->heap[i];
	}
	return m;
}


```



15> 연결리스트를 이용한 우선순위 큐 추상자료형의 연산 구현

```c
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
#define MIN -999999

typedef struct HeapType
{
	int data;
	struct HeapType* link;
}HeapType;

HeapType* create_node(int data)
{
	HeapType* new_node;
	new_node = (HeapType*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void is_empty(HeapType* h)
{
	return h == NULL;
}

void is_full(HeapType* h)
{
	HeapType* n;
	n = (HeapType*)malloc(sizeof(n));
	return n == NULL;
}

void insert_heap(HeapType** phead, HeapType* new_node)
{
	if (*phead == NULL)
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else
	{
		new_node->link = NULL;
		HeapType* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
}

int delete_heap(HeapType* head)
{
	int min = MIN;
	HeapType* h = NULL;
	HeapType* removed = head;
	HeapType* temp1 = NULL;
	HeadType* temp2 = head;

	while (removed != NULL)
	{
		if (removed->data > min)
		{
			min = removed->data;
			temp1 = h;
			temp2 = removed;
		}
		h = removed;
		removed = removed->link;
	}

	if (temp1 == NULL)
		head = head->link;
	else
		temp1->link = temp2->link;

	return min;
}

int find_heap(HeapType* h)
{
	int m = MIN;
	HeapType* p = h;
	while (p != NULL)
	{
		if (p->data > m)
			m = p->data;
		p = p->link;
	}
	return m;
}

```



16>

```c
int delete_random_heap(HeapType* h, int key)
{
    int parent, child, item, temp;
    for(int i=0; i<h->heap_size; i++)
    {
        if(h->heap[i]==key) //특정 임의의 요소를 찾는다. 
        {
            parent=i;
            child=2*i;
            break;
        }
        item=h->heap[parent];
        temp=h->heap[(h->heap_size)--];
        while(child <= h->heap_size)
            //현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        {
            if ((child < h->heap_size) && (h->heap[child].key < h->heap[child 					+ 1].key))
			child++;
		if (temp >= h->heap[child].key) //한단계 아래로 이동 
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
        }
        h->heap[parent]=temp;
        return item;
    }
}
```



