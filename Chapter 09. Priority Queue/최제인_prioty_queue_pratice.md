##### 1

(1) 루트 : 루트노드에 있는 값을 반환한다.



##### 2

(1) 완전 이진 트리이기 때문에 => 안정적이고 규칙이 있어서 배열의 빈자리가 거의 없다.



##### 3

(2) 트리의 높이에 비례한다.  (노드의 개수와 헷갈림..)



##### 4

(1) 항상 가장 큰 값이 루트에 있기때문에 오름차순으로 뽑기 유용하다.



##### 5

(2) 첫번째 노드



##### 6

두번째나 세번째 노드이다.



##### 7

$$
log_210 = 3.xxx
$$

3.xxx에서 올림하면 4다. 그러므로 10개의 데이터를 저장하는 히프트리의 높이는 4다.



##### 8

![KakaoTalk_20201120_165648409](C:\Users\Janie\Desktop\KakaoTalk_20201120_165648409.jpg)

##### 9

![KakaoTalk_20201120_165413848](C:\Users\Janie\Documents\카카오톡 받은 파일\KakaoTalk_20201120_165413848.jpg)

##### 10 , 12 ,13

![KakaoTalk_20201120_165419093](C:\Users\Janie\Documents\카카오톡 받은 파일\KakaoTalk_20201120_165419093.jpg)



##### 11

```c
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_ELEMENT 200
typedef struct {
	char todo[20];
	int lank;

} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 삭제 함수
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].lank) > h->heap[child + 1].lank)
			child++;
		if (temp.lank >= h->heap[child].lank) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	HeapType* heap;

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화
	char ans;
	char todo[20];
	int lank;
	element e;
	element d;
	while (1) {
	
		printf("삽입(i), 삭제(d): ");
		scanf("%c", &ans);
		switch (ans) {
		case 'i':
			getchar();
			printf("할일: ");
			scanf("%[^\n]", todo);
			strcpy(e.todo, todo);
			getchar();
			printf("우선순위: ");
			scanf("%d", &lank); //삽입
			e.lank = lank;
			
			insert_min_heap(heap,e);
			getchar();
			break;
		case 'd':
			d = delete_min_heap(heap);
			//삭제
			printf("제일 우선 순위가 높은 일은 \"%s\"\n", d.todo);
			getchar();
		}
	}

	free(heap);
	return 0;
}

	

```



##### 14

```c
#include<stdio.h>
#define MAX 100
typedef struct{
	int key;
}element;
typedef struct {
	element arr[MAX];
	int arr_size;
}arrType;
void init(arrType* array) {
	array->arr_size = 0;
}
arrType* create() {
	return (arrType*)malloc(sizeof(arrType));

}
void insert_max_array(arrType* array,int key) {
	array->arr[array->arr_size].key = key;
	array->arr_size++;
}
int delete_max_array(arrType* array) {
	int min = -9999;
	for (int i = 0;i < array->arr_size;i++) {
		if (array->arr[i].key > min)
			min = array->arr[i].key;
	}
	return min;
}
int main() {
	
	int arr[10] = { 29,1,2,9,30,56,75,8,3,4 };
	arrType *array;

	array = create();
	init(array);
	for (int i = 0;i < 10;i++) {
		insert_max_array(array, arr[i]);
	}
	insert_max_array(array, 37);//마지막 자리에 삽입 하면됨.
	for (int i = 0;i < array->arr_size;i++) {
		printf("%d ", array->arr[i].key);
	}
	
	printf("\n %d",delete_max_array(array));//가장 큰 수를 탐색해서 반환해야함 그리고 앞으로 이동시켜야함. 
	//삽입, 삭제 함수 
}
```



##### 15

```c
//무작위로 삽입하고 삭제할때 가장 큰 노드를 찾아서 삭제함. 
typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_biggest(ListNode* head)
{
	int m = -99999;
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	ListNode* temp1 = NULL, * temp2 = head, *p = NULL;
	while (removed != NULL) {
		if (removed->data > m) {
			m = removed->data;
			temp1 = p;
			temp2 = removed;
		}
		p = removed;
		removed = removed->link;
	}
	if (temp1 == NULL)
		head = head->link;
	else
		temp1->link = temp2->link;
	printf("가장 큰 수 %d 삭제", m);
	head = removed->link;	// (2)
	free(temp2);		// (3)
	return head;		// (4)
}
```



##### 16

```c
element find_some(HeapType* h, int key) {
	int parent, child;
	for (int i = 1;i <= h->heap_size;i++) {
		if (h->heap[i]== key) {
			parent = i;
			child = 2 * i;
			break;
		}
	}
	int item = h->heap[parent], temp = h->heap[(h->heap_size)--];
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;
		if (temp >= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent]= temp;
	return item;
	
}
```





##### 17![KakaoTalk_20201120_165422669](C:\Users\Janie\Documents\카카오톡 받은 파일\KakaoTalk_20201120_165422669.jpg)