##### 18

```c
ListNode* makeC(ListNode* a, ListNode* b) {
	ListNode* c;
	c = NULL; //c=(ListNode*)malloc(sizeof(ListNode)); 라고 쓰면 하나의 노드가 생성되고 거기에 data 값이 랜덤한 수가 들어가게 됨
	//포인터로만 작동하기때문에 할당받을 필요가 없다.
	ListNode* pa=NULL;
	ListNode* pb = NULL;
	pa = a;
	pb = b;
	while (pa != NULL && pb != NULL) {
		if ((pa->data) > (pb->data)) {
			c=insert_first(c, pa->data);
			pa = pa->link;
		}
		else {
			c=insert_first(c, pb->data);
			pb = pb->link;
		}
	}
	while (pa != NULL) {
		c = insert_first(c, pa->data);
		pa = pa->link;
	}
	while (pb != NULL) {
		c = insert_first(c, pb->data);
		pb = pb->link;
	}
	return c;
}
```





##### 19

```c

```



##### 20

```c
// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, 
// expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  // a의 차수 == b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {					// a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

//
//
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx**%d ", p->coef, p->expon);
		if (p->link != NULL) {
			printf(" + ");
		}
	}
	printf("\n");
}
```



##### 21

```c
void poly_eval(int x, ListType* list3) {
	ListNode* p;
	p = list3->head;
	int sum = 0;
	int temp = 1;
	for (; p; p = p->link) {
		for (int i = 0;i < p->expon;i++) {
			temp *= x;
		}
		sum += p->coef * temp;
	}
	printf("합은 %d", sum);
}
```



##### 22

```c
void SortedList(ArrayListType* L, element value) {
	int i;

	for (i = 0;i < L->size;i++) {
		if (L->array[i] > value) {
			for (int j = L->size;j > i;j--) {
				L->array[j] = L->array[j - 1];
			}
			break;
		}

	}
	L->array[i] = value;
	L->size++;
}
```



##### 23

```c
ListNode* SortedList(ListNode* head, element value) {
	ListNode* newnd = (ListNode*)malloc(sizeof(ListNode));
	newnd->data = value;
	newnd->link = NULL;
	ListNode* p;
	ListNode* pre;
	if (head == NULL) {
		head = newnd;
	}
	else {
		p = head;
		pre = NULL;
		while (p != NULL) {
			if (p->data > newnd->data) {

				if (pre == NULL) {
					/*pre =head;
				while (pre != p) {
				pre = pre->link;
				}*/newnd->link = head;
				p = newnd;

				}//가장 맨끝에 있는 노드보다 새로운 노드값이 더 작을 경우
				else {
					pre->link = newnd;
					newnd->link = p;

				}break;
			}
			/*if ((p->link == NULL) && (p->data < newnd->data)) {
				p->link = newnd;
			}*/
			pre = p;
			p = p->link;
		}

	}
	return head;
}
```



##### 24

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element row;//행
	element column;//렬
	element data;
	struct ListNode* link;
} ListNode;
ListNode* findrc(ListNode* head, int matrix[6][6]) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (matrix[i][j] != 0)
				insert_later(head, i, j, matrix[i][j]);

		}
	}
	return head;
}
void insert_later(ListNode** head, int i, int j, int a[1]) {
	ListNode* newn = (ListNode*)malloc(sizeof(ListNode));
	newn->data = a;
	newn->row = i;
	newn->column = j;
	if (*head == NULL) {
		newn->link = NULL;
		head = newn;
	}
	else {
		newn->link = NULL;
		ListNode* p = head;
		while (p != NULL) {
			p = p->link;
		}
		p->link = newn;
	}
}
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}



ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("행:%d 열:%d 값:%d->", p->row, p->column, p->data);
	printf("NULL \n");
}
```

