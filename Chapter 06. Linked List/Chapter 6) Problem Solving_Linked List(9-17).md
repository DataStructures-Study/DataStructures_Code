## Chapter 6) Problem Solving_Linked List

#### 9번 ) 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램 작성하기

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode* next;
}Node;
//추가하는 함수 이외에 첫 노드를 생성하는 함수를 분리시키자.
Node* CreateNode(int item)
{
    Node* NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=item;
    NewNode->next=NULL;
    return NewNode;
}
Node* insert_head(Node* head,int item)
{
    Node* New=(Node*)malloc(sizeof(Node));
    New->data=item;
    New->next=head;
    head=New;
    return head;
}
Node* insert_tail(Node* head, int item)
{
    Node* New=(Node*)malloc(sizeof(Node));
    Node* pres=head;
    while(pres->next!=NULL)
    {
        pres=pres->next;
    }
    pres->next=New;
    New->data=item;
    New->next=NULL;
    return head;
}
void print_list(Node* head)
{
    Node* pres=head;
    while(pres!=NULL)
    {
        printf("%d->",pres->data);
        pres=pres->next;
    }
    printf("NULL\n");
}
int main(void)
{
    int node_num,item;
    Node* list=NULL;
    printf("Enter a number of nodes: ");
    scanf("%d",&node_num);
    for(int i=1;i<=node_num;i++)
    {
        printf("node #%d data : ",i);
        scanf("%d",&item);
        if(list==NULL)
            list=CreateNode(item);
        else
            list=insert_tail(list,item);
    }
    printf("final linked list : ");
    print_list(list);

    return 0;
}

```



#### 10번) 단순 연결 리스트의 노드 개수를 계산하는 프로그램을 작성하기

```c
int CountNode(Node* head)
{
    Node* pres;
    int cnt=0;
    for(pres=head;pres!=NULL;pres=pres->next)
    {
        cnt++;
    }
    return cnt;
}
```



#### 11번) 단순연결리스트에 있는 모든 노드의 데이터 값을 합한 결과를 출력하는 프로그램 작성하기 

```c
int SumNode(Node* head)
{
    Node* pres;
    int sum=0;
    for(pres=head;pres!=NULL;pres=pres->next)
    {
        sum+=pres->data;
    }
    return sum;
}
```



#### 12번) 연결 리스트에 특정한 데이터 값을 갖는 노드 개수를 계산하는 함수 작성하기

```c
int Counting_Values(Node* head, int value)
{
    Node* pres=head;
    int cnt=0;
    while(pres!=NULL)
    {
        if(pres->data==value)
            cnt++;
        pres=pres->next;
    }
    return cnt;
}
```



#### 13번) 탐색함수를 참고하여 특정 데이터 값을 갖는 노드를 삭제하는 함수 작성하기

```c
Node* Remove_Value(Node* head,int value)
{
    Node* cur=head;
    Node* prev=NULL;

    while(cur!=NULL && cur->data!=value)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
        return head; // value was not found
    if(prev==NULL)
        head=head->next; //value was in the first node
    else
        prev->next=cur->next;
    return head;
}
```

-------------------------

13 번까지 실행한 코드

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode* next;
}Node;
Node* CreateNode(int item)
{
    Node* NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=item;
    NewNode->next=NULL;
    return NewNode;
}
Node* insert_head(Node* head,int item)
{
    Node* New=(Node*)malloc(sizeof(Node));
    New->data=item;
    New->next=head;
    head=New;
    return head;
}
Node* insert_tail(Node* head, int item)
{
    Node* New=(Node*)malloc(sizeof(Node));
    Node* pres=head;
    while(pres->next!=NULL)
    {
        pres=pres->next;
    }
    pres->next=New;
    New->data=item;
    New->next=NULL;
    return head;
}
void print_list(Node* head)
{
    Node* pres=head;
    while(pres!=NULL)
    {
        printf("%d->",pres->data);
        pres=pres->next;
    }
    printf("NULL\n");
}
int CountNode(Node* head)
{
    Node* pres;
    int cnt=0;
    for(pres=head;pres!=NULL;pres=pres->next)
    {
        cnt++;
    }
    return cnt;
}
int SumNode(Node* head)
{
    Node* pres;
    int sum=0;
    for(pres=head;pres!=NULL;pres=pres->next)
    {
        sum+=pres->data;
    }
    return sum;
}
int search_Node(Node* head, int value)
{
    Node* pres=head;
    int cnt=0;
    while(pres!=NULL)
    {
        if(pres->data==value)
            cnt++;
        pres=pres->next;
    }
    return cnt;
}
Node* Remove_Value(Node* head,int value)
{
    Node* cur=head;
    Node* prev=NULL;

    while(cur!=NULL && cur->data!=value)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
        return head; // value was not found
    if(prev==NULL)
        head=head->next; //value was in the first node
    else
        prev->next=cur->next;
    return head;
}
int main(void)
{
    int node_num,item;
    Node* list=NULL;
    printf("Enter a number of nodes: ");
    scanf("%d",&node_num);
    for(int i=1;i<=node_num;i++)
    {
        printf("node #%d data : ",i);
        scanf("%d",&item);
        if(list==NULL)
            list=CreateNode(item);
        else
            list=insert_tail(list,item);
    }
    printf("final linked list : ");
    print_list(list);
    printf("Counting Nodes : %d\n",CountNode(list));
    printf("Sum of Nodes : %d\n",SumNode(list));
    printf("Counting values : %d\n",search_Node(list,2));
    list=Remove_Value(list,2);
    print_list(list);
    return 0;
}

```



#### 14번) 다음과 같은 데이터(이름, 나이, 키)를 저장가능한 단순연결리스트 생성하는 프로그램 작성하기

```c
typedef struct ListNode2{
    char name[20];
    int age;
    double Heigh;
    struct ListNode2* link;
    
}Node2;
```



#### 15번) 단순 연결리스트에서 최대, 최솟값 찾는 프로그램 작성하기

```c
//최댓값 구하는 함수
int find_max(Node* head)
{
    int max=head->data;
    for(Node* pres=head;pres!=NULL;pres=pres->next)
    {
        if(max<pres->data)
            max=pres->data;
    }
    return max;
}
//최솟값 구하는 함수
int find_min(Node* head)
{
    int min=head->data;
    for(Node* pres=head;pres!=NULL;pres=pres->next)
    {
        if(min>pres->data)
            min=pres->data;
    }
    return min;
}
```



#### 16번) 단순 연결리스트의 헤드 포인터가 주어질때, 홀수 번째 노드를 전부 삭제하는 프로그램 작성하기

```c
void Remove_Odd(Node** head)
{
    *head=(*head)->next;
    Node* pres=NULL;
    Node* remove=*head;
    while(remove->link!=NULL)
    {
        pres=remove;
        remove=remove->next;
        pres->next=remove->next;
        if(remove->next!=NULL)
            remove=remove->next;
        else
            break;
    }
}
```

#### 17번) alternate 함수의 시간 복잡도 구하기

```c
Node* CreateNode(int Newdata)
{
    Node* NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=Newdata;
    NewNode->next=NULL;
    return NewNode;
}
//insert_tail을 이중 포인터로 표현
void AppendNode(Node** head, Node* NewNode)
{
    if(*head==NULL)
        *head=NewNode;
    else
    {
        Node* pres=(*head);
        while(pres->next!=NULL)
        {
            pres=pres->next;
        }
        pres->next=NewNode;
    }
}
//alternate 함수
//교재에 소개된 방식처럼 while문과 for문을 모두 써서 구현이 가능하나 코드가 쓸데없이 길어지는 경향이 있음
Node* alternate(Node* head1,Node* head2)
{
    Node *Anode=head1,*Bnode=head2;
    Node* NewList=NULL;
    while(Anode||Bnode)
    {
        if(Anode!=NULL)
        {
            AppendNode(&NewList,CreateNode(Anode->data));
            Anode=Anode->next;
        }
        if(Bnode!=NULL)
        {
            AppendNode(&NewList,CreateNode(Bnode->data));
            Bnode=Bnode->next;
        }
    }
    return NewList;
}
```



