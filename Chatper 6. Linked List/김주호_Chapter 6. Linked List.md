# Chapter 6. Linked List

-------

## problem 1

(2) 원형 열결 리스트 -> NULL  포인터 없음

## problem 2

(1) 배열 -> 리스트 n번째 요소 바로 찾음

## problem 3

(4) last->link가 마지막노드임. 마지막 노드 -> link == NULL

## problem 4

(c)

## problem 5

p = p->link;

## problem 6

q = p;

## problem 7

D 노드

## problem 8

(4) $x_{n-1}$의 link를 NULL로 바꿔야하는데, $x_{n-1}$에 접근하는 방법은 first를 타고 쭉 가는 수밖에 없다.

## problem 9

```c
#include "LinkedList.h"

Node* insert_last(Node* head, int value) {
	Node* last_node = head;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		return NULL;
	}

	p->data = value;
	p->link = NULL;
	
	if (head == NULL) { // linked list가 비어있으면,
		head = p;
	}
	else { // 그렇지 않으면, link 타고 맨 끝으로 간다.
		while (1) {
			if (last_node->link == NULL) {
				last_node->link = p;
				break;
			}
			else {
				last_node = last_node->link;
			}
		}
	}
	return head;
}

int main() {
	int N, element;
	Node* head = NULL;

	printf("노드의 개수 : ");
	if (scanf("%d", &N) == NULL) {
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		printf("노드 #%d 데이터 : ", i);
		if (scanf("%d", &element) == NULL) {
			return 0;
		}
		head = insert_last(head, element);
	}

	printf("생성된 연결 리스트: ");
	print_list(head);

	return 0;
}
```



## problem 10

```c
#pragma warning(disable:4996)
#include "LinkedList.h"

int size(Node* head) {
	int count = 0;
	Node* p = head;

	while (p->link != NULL) {
		count += 1;
		p = p->link;
	}
	count += 1;
	return count;
}

int main() {
	int N, element;
	Node* head = NULL;

	printf("노드의 개수 : ");
	if (scanf("%d", &N) == NULL) {
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		printf("노드 #%d 데이터 : ", i);
		if (scanf("%d", &element) == NULL) {
			return 0;
		}
		head = insert_first(head, element);
	}

	printf("연결리스트 노드의 개수 = %d", size(head));
}

```



## 

## problem 11

```c
#pragma warning(disable:4996)
#include "LinkedList.h"

int get_sum(Node* head) {
	int sum = 0;
	Node* p = head;

	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}

int main() {
	int N, element;
	Node* head = NULL;

	printf("노드의 개수 : ");
	if (scanf("%d", &N) == NULL) {
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		printf("노드 #%d 데이터 : ", i);
		if (scanf("%d", &element) == NULL) {
			return 0;
		}
		head = insert_first(head, element);
	}

	printf("연결 리스트의 데이터 합: %d", get_sum(head));
}
```



## problem 12

```c
#pragma warning(disable:4996)
#include "LinkedList.h"

int search_element(Node* head, element val) {
	int count = 0;
	Node* p = head;

	while (p != NULL) {
		if (p->data == val) {
			count += 1;
		}
		p = p->link;
	}
	return count;
}

int main() {
	int N, element, num;
	Node* head = NULL;

	printf("노드의 개수 : ");
	if (scanf("%d", &N) == NULL) {
		return 0;
	};

	for (int i = 1; i <= N; i++) {
		printf("노드 #%d 데이터 : ", i);
		if (scanf("%d", &element) == NULL) {
			return 0;
		}
		head = insert_first(head, element);
	}

	printf("탐색할 값을 입력하시오: ");
	if (scanf("%d", &num) == NULL) {
		return 0;
	}

	printf("%d은(는) 연결 리스트에서 %d번 나타납니다.", num, search_element(head, num));
}
```



## 

## problem 13

```c
#pragma warning(disable:4996)
#include "LinkedList.h"

Node* remove_particular_node(Node* head, element item) {
	Node* pre = head;
	Node* removed = NULL;

	if (pre == NULL) {
		printf("연결리스트가 비어있습니다.");
		exit(1);
	}
	if (pre->data == item) { // 첫 번째 node가 삭제 대상이면
		head = head->link;
		free(pre);
		return head;
	}

	// removed가 삭제 대상인 node, pre가 removed 앞 노드를 가리키게 함
	removed = pre->link; 

	while (removed->data != item) {
		pre = removed;
		removed = removed->link;
		if (removed == NULL) { // 끝 node에도 item이 없으면
			return head;
		}
	}
	head = delete_node(head, pre);

	return head;
}

int main() {
	Node* head = NULL;
	element num;

	printf("===linked list에 원소 1, 2, 3, 4를 삽입===\n");
	for (int i = 1; i <= 4; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	printf("삭제할 노드의 data를 입력하세요 : ");
	if (scanf("%d", &num) == NULL) {
		return 0;
	}
	
	printf("\n===linked list에서 data가 %d인 node를 제거===\n", num);
	head = remove_particular_node(head, num);
	print_list(head);

	return 0;
}
```



## 

## problem 14

```c
#include "LinkedList.h"

typedef struct Node {
	char name[20];
	int age;
	float heigh;
	Node* link;
}Node;
```



## 

## problem 15

```c
#include "LinkedList.h"
#include <time.h>

void find_min_and_max(Node* head) {
	int min = 100000;
	int max = -1;
	Node* p = head;

	if (head == NULL) {
		printf("연결리스트에 원소가 없습니다.");
		exit(1);
	}

	while (p != NULL) {
		if (p->data < min) {
			min = p->data;
		}
		else if (p->data > max) {
			max = p->data;
		}
		p = p->link;
	}

	printf("최솟값은 %d, 최댓값은 %d", min, max);
	return;
}


int main() {
	int random;
	Node* head = NULL;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 7; i++){
		random = rand() % 20;
		head = insert_first(head, random);
		print_list(head);
	}

	find_min_and_max(head);

	return 0;
}
```



## 

## problem 16

```c
#include "LinkedList.h"
#include <time.h>

Node* remove_odd_node(Node* head) {
	Node* pre = head;
	Node* p;

	if (pre == NULL) {
		printf("연결리스트가 비어있습니다.");
		exit(1);
	}

	// 첫 번째 node 삭제
	head = delete_first(head);
	p = head;

	while (p != NULL && p->link != NULL) {
		p = delete_node(p, p);      // p 다음 node를 삭제하고,
		p = p->link;                // p->link(네 번째)로 p를 업뎃
	}
	return head;
}

int main() {
	Node* head = NULL;
	int random;

	printf("===15개의 random number를 linked list에 삽입===\n");
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 15; i++) {
		random = rand() % 20;
		head = insert_first(head, random);
		print_list(head);
	}

	printf("===홀수번째 node를 제거===\n");
	head = remove_odd_node(head);
	print_list(head);

	return 0;
}
```



## 

## problem 17

```c
#include "LinkedList.h"
#include <time.h>
// 시간 복잡도는 O(size(A)+size(B))

Node* insert_last(Node* head, int value) {
	Node* last_node = head;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		return NULL;
	}

	p->data = value;
	p->link = NULL;

	if (head == NULL) { // linked list가 비어있으면,
		head = p;
	}
	else { // 그렇지 않으면, link 타고 맨 끝으로 간다.
		while (1) {
			if (last_node->link == NULL) {
				last_node->link = p;
				break;
			}
			else {
				last_node = last_node->link;
			}
		}
	}
	return head;
}

Node* alternate(Node* A, Node* B) {
	Node* p = A, * q = B, * new = NULL;

	while (p != NULL || q != NULL) {
		if (p != NULL) {
			new = insert_last(new, p->data);
			p = p->link;
		}
		if (q != NULL) {
			new = insert_last(new, q->data);
			q = q->link;
		}
	}
	return new;
}

int main() {
	Node* A = NULL;
	Node* B = NULL;
	Node* new = NULL;
	int random;

	srand((unsigned)time(NULL));

	printf("===4개의 random number로 구성된 A===\n");

	for (int i = 0; i < 4; i++) {
		random = rand() % 20;
		A = insert_first(A, random);
	}
	print_list(A);

	printf("===7개의 random number로 구성된 B===\n");
	for (int i = 0; i < 7; i++) {
		random = rand() % 20;
		B = insert_first(B, random);
	}
	print_list(B);

	printf("\n===A와 B로 만든 alternate 연결리스트 C===\n");
	new = alternate(A, B);
	print_list(new);
}
```



## 



