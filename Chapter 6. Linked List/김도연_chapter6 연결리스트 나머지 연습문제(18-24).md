# 6장 연결리스트 연습문제2



18>

2개의 단순 연결 리스트를 병합하는 함수를 조금 변경하여 보자. 두개의 연결리스트 a,b가 데이터값의 오름차순으로 노드들이 정렬되어 있는 경우, 이러한 정렬상태를 유지하면서 합병을 하여 새로운 연결리스트를 만드는 알고리즘 merge를 작성하라. a와 b에 있는 노드들은 전부 새로운 연결리스트로 옮겨진다. 



연결리스트 A,B 의 노드들의 데이터 크기를 비교하면서 작은거부터 앞에다 새로운 연결 리스트에 옮긴다.

알고리즘의 시간 복잡도: A의 노드 개수+B의 노드 개수

```c
ListNode* merge(ListNode* A, ListNode* B)
{
    ListNode* p=A, * q=B, * t=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            insert_node_back(&t, create_node(p->data));
            p=p->link;
        }
        else
        {
            insert_node_back(&t, create_node(q->data));
            q=q->link;
        }
    }
    while(p!=NULL)
    {
        insert_node_back(&t, create_node(p->data));
        p=p->link;
    }
    while(q!=NULL)
    {
        insert_node_back(&t, create_node(q->data));
        q=q->link;
    }
    return t;
}
```



19>단순 연결리스트 C를 두개의 단순 연결 리스트 A와 B로 분리하는 함수 split를 작성하여 보자.

C의 홀수번째 노드들은 A로 이동되고

C의 짝수번째 노드들은 B로 이동된다.

이 함수가 C를 변경하여서는 안된다. 

작성된 알고리즘의 시간 복잡도를 구하고 구현하여 수행하여 보라.



```c
void split(ListNode** A, ListNode** B, ListNode* C)
{
    ListNode* p=C;
    
    while(p!=NULL)
    { 
        insert_node_back(A, create_node(p->data)); //홀수번째 노드들은 A로 이동
        p=p->link;
        if(p==NULL) break;
        
        insert_node_back(B, create_node(p->data)); //짝수번째 노드들은 B로 이동
        p=p->link;
    }
    return;
}

```

시간 복잡도: 연결리스트 C의 노드 개수 n개에 따라 n번 이동되므로 O(n)





20.

두개의 다항식을 연결 리스트를 이용하여 나타내고 본문의 프로그램을 이용하여 두 다항식의 합을 구해보시오.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{//노드타입
	int coef; //계수
	int expon; //지수
	struct ListNode *link;
}ListNode;

//연결 리스트 헤더 
typedef struct ListType { //리스트 헤더 타입
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()//헤더 노드 동적 생성하고 초기화
{ 
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_last(ListType* plist, int coef, int expon)
{//새로운 노드를 만들어 다항식의 마지막에 추가
 //헤더 노드를 가리키는 포인터가 함수의 매개변수로 전달
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
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

//list3=list1+list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a&&b)
	{
		if (a->expon == b->expon)
		{ //a의차수=b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon)
		{
			//a의 차수> b의 차수
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else
		{	//a의 차수<b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	//a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	//결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);

}

void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d+ ", p->coef, p->expon);
	}
	printf("\n");
}

int main(void)
{
	ListType *list1, *list2, *list3;

	//연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	//다항식 A(x)를 생성
	insert_last(list1, 3, 6);
	insert_last(list1, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -9, 0);

	//다항식 B(x)를 생성
	insert_last(list2, -2, 6);
	insert_last(list2, -4, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);



	//다항식 B(x)를 생성

	poly_print(list1);
	poly_print(list2);

	//다항식 3=다항식 A(x)+B(x)
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);
}





```





21.

다항식을 연결 리스트로 표현할 수 있음을 보였다. 다항식이 연결 리스트로 표현되어 있고, p를 다항식을 가리키는 포인터라고 할 때, 어떤 실수 x 에 대하여 이 다항식의 값을 계산하는 함수 poly_eval을 작성하라. 



```c
int poly_eval(ListType* plist, int x)
{
	ListNode* p = plist->head;
	int result, eval = 0;
	
	for (; p; p = p->link)
	{
		result = 1;
		for (int i = 0; i < p->expon; i++){ //지수번만큼 x를 곱하기
			result *= x;
        }
		result = p->coef*result; //계수 곱하기
		eval += result; 
	}
	return eval;

}
```





<full>

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()
{
	ListType* plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;

}

void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));

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

void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d*x^%d + ", p->coef, p->expon);
	}
	printf("\n");
}


int poly_eval(ListType* plist, int x)
{
	ListNode* p = plist->head;
	int result, eval = 0;
	
	for (; p; p = p->link)
	{
		result = 1;
		for (int i = 0; i < p->expon; i++){
			result *= x;
        }
		result = p->coef*result; 
		eval += result; 
	}
	return eval;

}

int main(void)
{
	ListType* list;
	int x = 0;
	list = create();

	insert_last(list, 1, 3);
	insert_last(list, 2, 1);
	insert_last(list, 6, 0);

	poly_print(list);

	printf("실수 x의 값 : ");
	scanf_s("%d", &x);

	printf("다항식의 값 = %d", poly_eval(list, x));
	free(list);
}


```





22.배열을 이용하여 숫자들을 입력받아 항상 오름차순으로 정렬된 상태로 유지하는 리스트 Sort-edList를 구현하여보라. 다음의 연산들을 구현하면 된다.



```c
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100
typedef int bool;
#define true 1
#define false 0

typedef struct
{
	int list[MAX_LIST_SIZE];
	int length; //길이
} ArrayListType;

void init(ArrayListType* L) //초기화
{
	L->length = 0;
}

void is_empty(ArrayListType* L) //리스트가 비었는지 검사
{
	return L->length == 0;
}

void is_full(ArrayListType* L) //리스트가 꽉찼는지 검사
{
	return L->length == MAX_LIST_SIZE;
}

void add_item(ArrayListType* L, int item) 
//정렬된 리스트에 요소를 추가
{
	if (is_full)
	{
		printf("이미 배열이 가득찼습니다.\n");
		return;
	}
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		if (item < L->list[i])
		{
			for (int j = L->length; j > i; j--)
				L->list[j] = L->list[j - 1];
			break;
		}
	}
	L->list[i] = item;
	L->length++;
}

void delete_item(ArrayListType* L, int item)
//정렬된 리스트에서 item을 제거
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		if (item == L->list[i])
		{
			for (int j = i; j < L->length; j++)
			{
				L->list[j] = L->list[j + 1];
			}
		}
	}
	L->length--;
}

void clear_list(ArrayListType* L, int item)
{//리스트의 모든 요소를 제거

	L->length = 0;
}

bool is_in_list(ArrayListType* L, int item)
{//item이 리스트 안에 있는지를 검사
	for (int i = 0; i < L->length; i++)
		if (L->list[i] == item)
			return true;
	return false;
}

int get_length(ArrayListType* L)
{//리스트의 길이를 구함
	return L->length;
}

void display(ArrayListType* L)
{//리스트의 모든 요소를 표시
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->list[i]);
	printf("\n");
}

```







23. 단순 연결 리스트를 이용하여 숫자들을 항상 오름차순으로 정렬된 상태로 유지하는 리스트 SortedList를 구현하여 보라. 앞의 문제의 연산들을 구현하면 된다.



```c
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int bool;


typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void add_element(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		ListNode* c = NULL;
		ListNode* p = *phead;
		while (p != NULL) {
			if (new_node->data < p->data) {
				if (c == NULL) {
					new_node->link = *phead;
					*phead = new_node;
				}
				else {
					c->link = new_node;
					new_node->link = p;
				}
				break;
			}
			c = p;
			p = p->link;
		}
	}
}

void delete_element(ListNode** head, element item) {
	ListNode* p = NULL, *removed = *head;
	while (removed->data != item) {
		p = removed;
		removed = removed->link;
	}
	if (p == NULL)
		*head = (*head)->link;
	else
		p->link = removed->link;
	return;
}

void clear(ListNode** head) {
	(*head)->link = NULL;
}

bool is_in_list(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item)
			return true;
		p = p->link;
	}
	return false;
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

bool is_empty(ListNode* head) {
	return head->link == NULL;
}

ListNode* create_node(element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

bool is_full(ListNode* head) {
	ListNode* N = create_node(0);
	if (N == NULL)
		return true;
	return false;
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

```



24.

행렬은 숫자나 문자를 정사각형 또는 직사각형으로 배열하여 그 양끝을 괄호로 묶은 것으로 많은 문제를 수학적으로 해결하는 도구이다. 희소 행렬은 많은 항들이 0인 행렬이다. 연결리스트를 이용하여 희소 행렬을 표현하는 방법을 생각하여 보고 구현하라. 



* 연결리스트는 가변크기의 구조를 효율적으로 나타낼 수 있으며 희소행렬에 대해서도 장점.

  http://blog.naver.com/PostView.nhn?blogId=tjdowl123&logNo=220671112208

```c
typedef struct element{
    int row;
    int col;
    int value;
};
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
```

```c


```

