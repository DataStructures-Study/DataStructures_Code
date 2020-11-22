# 6장 연습문제



1.

(2) 원형 연결 리스트는 NULL 포인터가 존재하지 않는 구조이다.



2.

연결 리스트는 i번째 데이터를 찾을 때 앞에서부터 순차적으로 접근해야 하지만 배열은 한번에 바로 찾을 수 있어 빠르다.

(1) 배열 



3.

마지막 노드의 link pointer 가 NULL을 가리킨다.

(3) last->link==NULL



4.

p의 link가 다음 노드를 가리킨다.

(c) p=p->link;



5.

p=p->link



6.

q=p



7.

마지막 노드인 D를 가리키게 된다.



8.

처음부터 끝까지 탐색 한 후에 삭제를 해야하기 때문에 O(1)이 될 수 없다.

(4) deleteLast 연산: 덱의 마지막 원소를 삭제



9.단순 연결리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램을 작성하라.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int main(void)
{
	ListNode *head = NULL;
	int num;
	int data;

	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		insert(&head, head, create_node(data));
	}
	printf("생성된 연결 리스트 : ");
	print_list(head);
	return 0;
}
```



10.단순 연결 리스트의 노드들의 개수를 계산하는 프로그램을 작성해보자.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL) 
	{//빈연결리스트인 경우
		new_p->link = NULL;
		*phead = new_p; //new_p를 헤드에 저장
	}
	else
	{
		new_p->link = NULL; //초기화
		ListNode* p = *phead; // 헤드부터 훑기위한 포인터
		while (p->link != NULL) //빈연결리스트 아니면
			p = p->link; //헤드부터 맨 끝 노드까지 이동
		p->link = new_p; //맨끝 노드 뒤로 받아온 노드연결
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int count(ListNode* head)
{
	int count = 0;
	ListNode *p = head;

	while (p != NULL) //리스트 끝까지 탐색하면서 count값 증가
	{
		count++;
		p = p->link;
	}
	return count;
}

int main(void)
{
	ListNode *head = NULL;
	int num;
	int data;

	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		insert(&head, head, create_node(data));
	}
	printf("연결 리스트 노드의 개수 = %d", count(head));
	

	return 0;
}
```





11.단순 연결 리스트에 정수가 저장되어 있다. 연결 리스트에 있는 모든 노드의 데이터 값을 합한 결과를 출력하는 프로그램을 작성하시오.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int cal_sum(ListNode* head)
{
	int sum = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		// 연결리스트의 모든 노드의 데이터
		sum += p->data; //데이터들의 합
	}
	return sum;
}

int main(void)
{
	ListNode *head = NULL;
	int num;
	int data;

	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		insert(&head, head, create_node(data));
	}
	printf("연결 리스트의 데이터 합 = %d", cal_sum(head));


	return 0;
}
```



12.연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수를 작성하라.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int frequency(ListNode* head, element item)
{
	ListNode* p=head;
	int count = 0;

	while (p != NULL) { //다음 노드가 비어있을 때
		if (p->data == item) //노드의 데이터가 일치하면
			count++; //빈도수 증가
		p = p->link; //다음 노드로 이동

	}
	return count;
}

int main(void)
{
	ListNode *head = NULL;
	int num;
	int data;
	int search;

	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		insert(&head, head, create_node(data));
	}
	printf("탐색할 값을 입력하시오: ");
	scanf_s("%d", &search);
	printf("%d는 연결 리스트에서 %d번 나타납니다.",search, frequency(head, search));

	return 0;
}
```



13.단순 연결 리스트에서의 탐색함수를 참고하여 특정한 데이터값을 갖는 노드를 삭제하는 함수를 작성하라.

```c

void delete_node(ListNode** head, element x)
{ //head부터 순회하여 특정 데이터를 찾고 그부분을 remove
    ListNode* p=NULL;
    ListNode* removed= *head; //삭제할 노드를 헤드에
    while(removed->data!=x) //데이터값이 일치하지 않으면
    {
        p=removed; //removed가 가리키던걸 p가 가리키게
        removed=removed->link; //다음으로 한칸씩 이동
    }
    //데이터값이 x값과 일치하면
    if(p==NULL){ //헤드가 지울 데이터를 담고있었다면
        *head=(*head)->link; //헤드의 다음 노드를 새로운 헤드로 만들어 헤드 노드를 지움
    }
    else //지울 노드가 헤드노드가 아니면
        p->link=removed->link; //전노드의 link가 가리키는걸 다음노드(지울 노드의 link로)
    
    free(removed); //삭제할 노드 동적 메모리 반납
    return;
}
```



14.



```c
typedef struct ListNode{ //노드 타입을 구조체로 정의
    char name[20]={};
    ing age={};
    struct ListNode* link; //ListNode를 가리키는 포인터
}ListNode;
```



15.단순 연결 리스트가 정렬되지 않은 정수들의 리스트를 저장하고 있다. 

리스트에서 최대값과 최소값을 찾는 프로그램을 작성하라.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int find_max(ListNode* head) //리스트에서 최대값 구하기
{
	ListNode* p = head;
	int max = head->data; //max를 head data로 설정
	
	while (p != NULL) { //다음 노드가 비어있지 않다면
		if (max < p->data) //data가 max보다 크면 max로 두기
			max = p->data;
		p = p->link; //다음 노드로 계속 순회
	}
	return max;
}

int find_min(ListNode* head) //
{
	ListNode* p = head;
	int min = head->data;

	while (p != NULL) {
		if (min > p->data)
			min = p->data;
		p = p->link;
	}
	return min;
}

int main(void)
{
	ListNode *head = NULL;
	int num;
	int data;
	

	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		insert(&head, head, create_node(data));
	}
	printf("최대값: %d, 최소값: %d",find_max(head),find_min(head));
		
	return 0;
}
```





16.단순 연결 리스트의 헤드 포인터가 주어져 있을 때 첫번째 노드에서부터 하나씩 건너서 있는 노드를 전부 삭제하는 함수를 작성하라.즉 홀수번째 있는 노드들이 전부 삭제된다.



```c
void remove_odd_node(ListNode** head) {
	*head = (*head)->link; ////헤드의 다음 노드를 새로운 헤드로 만들어 헤드 노드를 지움
	ListNode* p = NULL, 
    *removed = *head; //삭제할 노드를 head에
	while (removed->link != NULL) { //removed가 마지막 노드가 아니라면
		p = removed;
		removed = removed->link; //한칸씩 이동
		p->link = removed->link; //전노드의 link가 가리키는걸 다음노드(지울 노드의 link로)해 removed위치에 있는 노드 삭제
        
		if (removed->link != NULL) //removed가 마지막 노드가 아니면
			removed = removed->link; //removed한칸 옮기기
		else
			break;
	}
	return;
}

```



17.두개의 단순 연결 리스트 A,B가 주어져 있을 경우, alternate 함수를 작성하라. alternate함수는 A와 B로부터 노드를 번갈아 가져와서 새로운 리스트 C를 만드는 연산이다. 만약 입력리스트 중에서 하나가 끝나게 되면 나머지 노드들을 전부 C로 옮긴다. 작성된 함수의 시간복잡도를 구하라.



```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

ListNode* alternate(ListNode* A, ListNode* B)
{
	ListNode* p = A;
	ListNode* q = B;
	ListNode* r = NULL;

	while (p != NULL || q != NULL) {
		if (p != NULL) { //비어있지 않으면 r에 p 데이터 노드 삽입
			insert(&r, r, create_node(p->data));
			p = p->link;
		}
		if (q != NULL) { //비어있지 않으면 r에 q 데이터 노드 삽입
			insert(&r, r, create_node(q->data));
			q = q->link;
		}
	}
	return r;
}



int main(void)
{
	int count;
	int num;

	ListNode* A = NULL;
	ListNode* B = NULL;
	ListNode* result = NULL;

	printf("리스트 A 데이터 개수: ");
	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) 
	{
		printf("a%d 노드 데이터: ",i+1);
		scanf_s("%d", &num);
		insert(&A, A, create_node(num));
	}

	printf("리스트 B 데이터 개수: ");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++)
	{
		printf("b%d 노드 데이터: ",i+1);
		scanf_s("%d", &num);
		insert(&B, B, create_node(num));
	}
	
	printf("리스트 C : ");
	print_list(alternate(A, B));

	return 0;
}
```

