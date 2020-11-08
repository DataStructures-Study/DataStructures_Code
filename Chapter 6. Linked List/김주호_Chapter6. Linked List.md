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



## problem  18

```python
#include "LinkedList.h"

Node* merge(Node* A, Node* B) {
	Node* p = A, * q = B, * merged_list = NULL;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			merged_list = insert_last(merged_list, p->data);
			p = p->link;
		}
		else {
			merged_list = insert_last(merged_list, q->data);
			q = q->link;
		}
	}

	while (p != NULL) {
		merged_list = insert_last(merged_list, p->data);
		p = p->link;
	}
	while (q != NULL) {
		merged_list = insert_last(merged_list, q->data);
		q = q->link;
	}
	return merged_list;
}

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* result;

	head1 = insert_last(head1, 10);
	head1 = insert_last(head1, 20);
	head1 = insert_last(head1, 30);
	print_list(head1);

	head2 = insert_last(head2, 15);
	head2 = insert_last(head2, 25);
	print_list(head2);

	result = merge(head1, head2);
	printf("결과\n");
	print_list(result);

	return 0;
}
```





## problem  19

```python
#include "LinkedList.h"

void split(Node** A, Node** B, Node* C) {
	Node* p = C;
	int flag = 1;
	while (p != NULL) {
		if (flag) {
			*A = insert_last(*A, p->data);
			p = p->link;
			flag = 0;
		}
		else {
			*B = insert_last(*B, p->data);
			p = p->link;
			flag = 1;
		}
	}
	return;
}

int main() {
	Node* C = NULL;
	Node* A = NULL;
	Node* B = NULL;

	C = insert_last(C, 1);
	C = insert_last(C, 2);
	C = insert_last(C, 3);
	C = insert_last(C, 4);
	C = insert_last(C, 5);
	printf("연결리스트 C\n");
	print_list(C);

	split(&A, &B, C);
	printf("\n======A와 B에 split======\n");
	printf("A : ");
	print_list(A);
	printf("B : ");
	print_list(B);

	return 0;
}
```





## problem  20

```python
#include "LinkedList_for_poly.h"

void poly_print(ListType* plist, const char* name){ 
	ListNode* p = plist->head;
	printf("%s = ", name);
	for (; p; p = p->link) {
		if (p->coef < 0) //계수가 0보다 작은경우 '-' 출력
			printf("%dx^%d ", p->coef, p->expon);
		else //그외의 경우 '+' 출력
			printf("+%dx^%d ", p->coef, p->expon);
	}
	printf("\n");
}

int main(void){
	ListType* list1, * list2, * list3;
	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 6); // 첫번째 다항식 입력
	insert_last(list1, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -9, 0);
	insert_last(list2, -2, 6); // 두번째 다항식 입력
	insert_last(list2, -4, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);

	poly_print(list1, "A(x)"); // 출력
	poly_print(list2, "B(x)");
	poly_add(list1, list2, list3); // 입력한 두 다항식을 더하여 list3에 저장
	poly_print(list3, "A(x) + B(x)"); // 더해진 다항식을 출력.

	free(list1);
	free(list2);
	free(list3);
	// 사용이 끝났으므로 제거하여 메모리 공간을 확보한다.
}
```





## problem  21

```python
#include "LinkedList_for_poly.h"

void poly_print(ListType* plist, const char* name) {
	ListNode* p = plist->head;
	printf("%s = ", name);
	for (; p; p = p->link) {
		if (p->coef < 0) //계수가 0보다 작은경우 '-' 출력
			printf("%dx^%d ", p->coef, p->expon);
		else //그외의 경우 '+' 출력
			printf("+%dx^%d ", p->coef, p->expon);
	}
	printf("\n");
}

int eval_poly(ListType* plist, int x) {
	int sum = 0;
	ListNode* term = plist->head;
	while (term) {
		int tmp = 1;
		for (int i = 0; i < term->expon; i++)
			tmp *= x;
		sum += tmp * term->coef;
		term = term->link;
	}
	return sum;
}

int main(void) {
	ListType* poly ;
	// 연결 리스트 헤더 생성
	poly = create();

	insert_last(poly, 1, 3); // 첫번째 다항식 입력
	insert_last(poly, 2, 1);
	insert_last(poly, 6, 0);

	poly_print(poly, "A(x)"); // 출력
	printf("A(2) = %d", eval_poly(poly, 2));

	free(poly);
	// 사용이 끝났으므로 제거하여 메모리 공간을 확보한다.
}


```





## problem  22

```python
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef struct {
	int arr[MAX_LIST_SIZE];
	int length;
}SortedList;

void init(SortedList* L) {
	L->length = 0;
}
int is_empty(SortedList* L) {
	return L->length == 0;
}
int is_full(SortedList* L) {
	return L->length == MAX_LIST_SIZE;
}

void add(SortedList* L, int item) {
	if (is_full(L)) {
		printf("이미 배열이 가득찼습니다.\n");
		return;
	}
	int i = 0;
	for (i = 0; i < L->length; i++) {
		if (item < L->arr[i]) {
			for (int j = L->length; j > i; j--)
				L->arr[j] = L->arr[j - 1];
			break;
		}
	}
	L->arr[i] = item;
	L->length++;
}

void delete_item(SortedList* L, int item) {
	int i;
	for (i = 0; i < L->length; i++) {
		if (item == L->arr[i]) {
			for (int j = i; j < L->length; j++) {
				L->arr[j] = L->arr[j + 1];
			}
		}
	}
	L->length--;
}

void clear(SortedList* L, int item) {
	L->length = 0;
}

int is_in_list(SortedList* L, int item) {
	for (int i = 0; i < L->length; i++)
		if (L->arr[i] == item)
			return 1;
	return 0;
}

int get_length(SortedList* L) {
	return L->length;
}

void display(SortedList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->arr[i]);
	printf("\n");
}

int main() {
	SortedList* L = (SortedList*)malloc(sizeof(SortedList));
	init(L);

	add(L, 4);
	add(L, 2);
	add(L, 3);
	add(L, 1);

	display(L);

	return 0;
}
```





## problem  23

```python
#include<stdio.h>
#include<stdlib.h>


typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* create_node(element item) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = item;
	new_node->link = NULL;
	return new_node;
}

void add_element(ListNode** head, element item) {
	ListNode* tmp = create_node(item);
	if (*head == NULL) {
		*head = tmp;
	}
	else {
		ListNode* pre = NULL;
		ListNode* ptr = *head;
		while (ptr != NULL) {
			if (item < ptr->data) {
				if (ptr == *head) {
					*head = tmp;
					tmp->link = ptr;
				}
				else {
					pre->link = tmp;
					tmp->link = ptr;
				}
				break;
			}
			pre = ptr;
			ptr = ptr->link;
		}
	}
}

void delete_element(ListNode** head, element item) {
	ListNode* pre = NULL, * removed = *head;
	while (removed->data != item) {
		pre = removed;
		removed = removed->link;
		if (removed == NULL) {
			printf("삭제를 원하는 원소가 리스트 안에 없습니다.\n");
			return;
		}
	}
	if (pre == NULL)
		*head = (*head)->link;
	else
		pre->link = removed->link;
	return;
}

void clear(ListNode** head) {
	(*head)->link = NULL;
}

int is_in_list(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item)
			return 1;
		p = p->link;
	}
	return 0;
}

int get_length(ListNode* head) {
	int count = 0;
	ListNode* p = head;
	while (p != NULL) {
		count++;
		p = p->link;
	}
	return count;
}

int is_empty(ListNode* head) {
	return head->link == NULL;
}

int is_full(ListNode* head) {
	// 노드가 더이상 만들어지지 않는다면 메모리가 가득찬상태.
	ListNode* N = create_node(0);
	if (N == NULL)
		return 1;
	return 0;
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

int main() {
	ListNode* L = NULL;

	printf("4 삽입\n"); add_element(&L, 4);
	printf("2 삽입\n"); add_element(&L, 2);
	printf("3 삽입\n"); add_element(&L, 3);
	printf("1 삽입\n"); add_element(&L, 1);

	printf("\n=====연결리스트에 담긴 형태=====\n");
	display(L); printf("\n");

	printf("4 삭제\n"); delete_element(&L, 4);
	display(L); printf("\n");
	printf("5 삭제\n"); delete_element(&L, 5);
	display(L);

	return 0;
}
```



