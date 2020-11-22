#### 9

```c
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = NULL;		//(3)	
	while (pre->link != NULL) {
		pre = pre->link;
	}//pre->link가 아무것도 없으면 while문을 빠져나옴
	
	pre->link = p;		//그럼 그 링크를 가지고 p를 가리킴	
	return head;		//(5)	
}
for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &data);
		if (i == 0) {
			head = insert_first(head, data);

		}
		else {
			pre = head;
			head = insert(head, pre, data);
		}
	}
```



#### 10

```c
int length(ListNode* head) {
	int num = 0;
	for (ListNode* p = head;p != NULL; p = p->link) {
		num++;
	}
	return num;
}
```



#### 11

```c
int count_list(ListNode* head) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = head;
	int sum= 0;
	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}
```



#### 12

```c
void find_list(ListNode* head,int find) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	int count = 0;
	p = head;
	while (p != NULL) {
		if (p->data == find) {
			count++;
		}
		p = p->link;

	}
	printf("%d는 연결리스트에서 %d번 나타납니다.", find, count);
}
```



#### 13

```c
ListNode* find_list(ListNode* head, int find) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	int count = 0;
	p = head;
	ListNode* pre;
	pre = head;
	while (p != NULL) {
		if (p->data == find) {
			break;
		}
		pre = p;
		p = p->link;
	}
	if (p == NULL) {
		printf("삭제할 노드가 존재하지 않는다.");
	}
	else {
		pre->link = p->link;
		free(p);
	}

	return head;
}
```



#### 14

```c
typedef struct ListNode {
	char name[20];
	int age;
	double heigh;
	struct ListNode* link;
}ListNode;
```



#### 15

```c
void find_min_max(ListNode* head) {
	int min = head->data;
	int max = 0;
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data > max) {
			max = p->data;
		}
		if (p->data < min) {
			min = p->data;
		}
		p = p->link;
	}
	printf("min = %d max = %d", min, max);
}
```



#### 16

```c
void remove_odd_node(ListNode* head) {
	head = head->link;
	ListNode* p = NULL,  removed = head;
	while (removed->link != NULL) {
		p = removed;
		removed = removed->link;
		p->link = removed->link;
		if (removed->link != NULL)
			removed = removed->link;
		else
			break;
	}
	
}
```



#### 17

```c
ListNode* alternate(ListNode* a,ListNode* b){
    ListNode* ap,bp,c;
    ap = a;bp = b;
    while(ap!=NULL || bp!=NULL){
        if(ap!=NULL){
        	insert(c,a,ap->data)
            ap=ap->link;}
        if(bp!=NULL){
        	insert(c,b,bp->data)
            bp=bp->link;
        }
    }
    return c;
}
```

