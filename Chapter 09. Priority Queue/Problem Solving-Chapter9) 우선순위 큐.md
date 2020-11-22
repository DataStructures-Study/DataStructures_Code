### Problem Solving-Chapter9) 우선순위 큐

#### 11번) 자신의 할일에 우선순위를 매겨서 힙에 저장했다가 우선순위 순으로 꺼내서 출력하는 프로그램을 작성하자.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    char stuff[50];
    int key // 우선순위
}element;
//-----------------------------------------------
typedef struct
{
    element heap[10];
    int size;
}HeapType;
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}
//insert_function
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i=++(h->size);
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i!=1)&&(item.key > h->heap[i/2].key))
    {
        h->heap[i]=h->heap[i/2];
        i=i/2;
    }
    h->heap[i]=item;
}
//delete_function
element delete_max_heap(HeapType* h)
{
    int parent,child;
    element item, tmp;

    item=h->heap[1];
    tmp=h->heap[(h->size)--]; //루트 노드를 삭제했으므로 사이즈가 1 감소
    parent=1;
    child=2; //루트 노드의 왼쪽 자식의 index
    while(child<=h->size) //힙 트리를 벗어나지 않는 범위 내에서
    {
        //현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다.
        if((child<h->size) && (h->heap[child].key)<(h->heap[child+1].key))
            child++;
        if(tmp.key >= h->heap[child].key)
            break;
        h->heap[parent]=h->heap[child];
        parent=child;
        child=child*2;
    }
    h->heap[parent]=tmp;
    return item;
}
void init(HeapType* heap)
{
    heap->size=0;
}
//=========================================================================
int main(void)
{
    char input;
   	HeapType* newheap;
    newheap=create();
    init(newheap);

    int i=0; // 반복문의 range=5
    while(i<5)
    {
        i++;
        printf("삽입(i), 삭제(d) : ");
    	scanf(" %c",&input);
        if(input=='i')
        {
            printf("할일 : ");
            scanf("%s",newheap->heap[i].stuff);
            printf("우선순위 : ");
            scanf("%d",&newheap->heap[i].key);
        }
        if(input=='d')
        {
            element tmp=delete_max_heap(newheap);
            printf("제일 우선 순위가 높은 일은 %s",tmp.stuff);
        }

    }
    return 0;
}
```

##### 14번) 정렬되지 않은 배열을 이용해 우선순위 큐 추상자료형의 각종 연산들을 구현하여라

정렬되어있지 않은 배열의 경우,  삽입과정은 그냥 배열의 맨 끝에 새로운 요소를 추가하면 된다.

삭제 연산의 경우, 가장 우선 순위가 높은 요소를 찾아 삭제한 뒤, 뒤에 있는 요소들을 다시 앞으로 이동시켜야 한다.요소를 반환하는 것 또한  필요하다.

```c
// 연산 : create,init,insert,delete,find,is_empty,is_full
#define MAX_SIZE 100
typedef struct ArrayHeap{
    int size;
    int heap[MAX_SIZE]; //원소들이 구조체가 정수라고 가정
}HeapType;

void init(HeapType* h)
{
    h->size=0;
}

int is_empty(HeapType* h)
{
    return (h->size==0);
}

int is_full(HeapType* h)
{
    return (h->size==MAX_SIZE);
}
//insert function
void insert_max_heap(HeapType* h, int item)
{
    h->heap[h->size]=item;
    (h->size)++;
}

//delete function
//우선 요소를 반환해야 하므로 반환형은 int
//우선순위가 가장 높은 요소를 삭제하기
/*우선순위의 기준은 heap이라는 배열의 data값으로 비교해야 한다.
즉, 삭제되어야 할 값은 배열의 원소 중 가장 큰 값이 되어야 한다. */
int delete_max_heap(HeapType* h)
{
    int max=0; // 우선순위 값들이 모두 양수라고 가정하자.
    int start;
    for(int i=1;i<h->size;i++)
    {
        if(h->heap[i]>max)
        {
            max=h->heap[i];
            start=i;
        }
    }
    for(int i=index;i<= h->size;i++)
        h->heap[i]=h->heap[i+1]; //앞으로 요소들을 한 칸씩 옮기기
    (h->size)--;
    return max; //삭제된 값을 반환
}
//search function
/*여기서 반환해야 할 값은 우선순위가 가장 높은 요소, 즉 우선순위 값이 가장 큰 요소이다.*/
int fin_max_heap(HeapType* h)
{
    int max=0; //우선순위 값들이 모두 양수라고 가정하자
    for(int i=0;i<size;i++)
    {
        if(h->heap[i]>max)
            max=h->heap[i];
    }
    return max;
}
```



##### 15번) 연결리스트를 이용해 우선순위 큐 추상자료형의 각종 연산들을 구현하라

정렬이 되어 있는 리스트일 경우, 우선 순위가 높은 요소가 앞에 위치하는 것이 유리하다(탐색할 필요가 사라지므로) 삽입시에는 우선 순위값을 기준으로 삽입 위치를 찾아야 한다.

정렬되지 않은 리스트라면 삽입 시에 첫 번째 노드로 삽입시키는 것이 유리하다. 삭제 시에는 포인터를 따라서 모든 노드를 뒤져봐야 한다.

```c
typedef struct HeapType
{
    int data;
    struct HeapType* next;
}HeapNode;

int is_empty(HeapNode* h)
{
    return (h==NULL);
}

int is_full(HeapNode* h)
{
    //full의 경우,동적 메모리 할당이 불가능한 경우를 의미한다.
    HeapNode* NewNode=(HeapNode*)malloc(sizeof(NewNode));
    return (NewNode==NULL);
}

HeapNode* CreateNode(int item)
{
    HeapNode* NewNode=(HeapNode*)malloc(sizeof(HeapNode));
    NewNode->next=NULL;
    NewNode->data=item;
    return NewNode;
}
//새로운 노드를 테일 노드로 삽입시킨다.
//insert연산의 경우 우선 순위 큐에 요소 x를 추가한다.(여기서는 노드 추가하기)
void AppendNode_heap(HeapNode** Head, Node* NewNode)
{
    if((*Head)==NULL)
        *Head=NewNode;
    else
    {
        Node* Tail=(*Head);
        while(Tail->next!=NULL)
            Tail=Tail->next;
        Tail->next=NewNode;
    }
}
//delete 연산의 경우 우선 순위 큐로부터 가장 우선순위가 높은 요소를 삭제후 이 요소를 반환
//return type=int
/*기존에 연결리스트에서 구현했던 노드 삭제 함수의 경우, 두 번째 매개변수가 삭제할 대상(노드)였지만 힙에서는 함수 내에서 우선순위를 통해 삭제할 것을 판단해야 한다.*/
int DeleteNode_heap(HeapNode** head)
{
	int max=0; //데이터 셋이 양수의 집합
    HeapNode* curr=*head; //연결리스트를 순환할 포인터
    HeapNode* Removed=NULL; //삭제할 노드를 가리킬 포인터
    HeapNode* prev=NULL;
    HeapNode* prev2;
    //삭제할 노드를 찾기(최댓값 찾기)
    while(curr!=NULL)
    {
        if(curr->data > max)
        {
            max=curr->data;
            Removed=curr;
            prev2=prev;
        }
        prev=curr;
        curr=curr->next;
       
    }
    //삭제할 노드 앞 뒤 노드 연결관계 정리
    if(prev==NULL)//삭제할 노드가 헤드 노드의 다음 노드인 경우
        *head=*head->next;
    else
    	prev2->next=Removed->next;
    return max;
}
//search function
int find_max_heap(HeapNode* head)
{
    int max=0; //데이터 셋이 양수의 집합이라고 가정
    HeapNode* curr=head;
    while(curr!=NULL)
    {
        if((curr->data)>max)
            max=curr->data;
        curr=curr->next;
    }
    return curr;
}
 
```



##### 16번) 최소 힙에서 임의의 요소를 삭제하는 C함수를 작성하라

루트 노드를 삭제하는 것이 아닌 임의의 요소를 삭제하는 것!

임의의 요소를 찾은뒤 임의의 요소를 지닌 노드를 루트 노드로 생각하고, 거기서부터 노드의 재구성을 하면 된다.

```c
typedef struct Heap
{
    int num_array[50];
    int size;
}HeapType;
// num_array의 원소는 구조체가 아닌 int

element delete_min_heap(HeapType* h,int data)
{
    int parent,child;
    //반복문을 돌아야 함(인덱스가 1부터 size까지 존재)
    for(int i=1;i<=h->size;i++)
    {
        if(h->heap[i]==data)
        {
            parent=i;
            child=parent*2;
            break;
        }
    }
    int item=h->num_array[parent];
    int tmp=h->num_array[h->size];
    (h->size)--;
    while(child<=h->size) //힙 트리를 벗어나지 않는 범위 내에서
    {
        //현재 노드의 자식 노드 중 더 작은 자식 노드를 찾는다.
        if((child<h->size) && 
           (h->num_array[child].key)>(h->num_array[child+1].key))
            child++;
        if(tmp.key <= h->num_array[child].key)
            break;
        h->num_array[parent]=h->num_array[child];
        parent=child;
        child=child*2;
    }
    h->num_array[parent]=tmp;
    return item;
}
```

