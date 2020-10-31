#### 3

```c
ListNode* search(ListNode* head,element find) {
	ListNode* p;p = head;
	while (p != NULL) {
		if (p->data == find) {
			return p;
		}
		p = p->link;
	}

}
```



#### 4

```c
int get_size(ListNode* head) {
	ListNode* p;
	p = head;
	int nsize = 0;
	while (p != NULL) {
		nsize++;
		p = p->link;
	}
	return nsize;
}
```



#### 6

```c
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
```



#### 7

```c
DListNode* search(DListNode* phead,element data) {
	DListNode* p;
	p = phead;
	for (p = phead->rlink;p != phead;p = p->rlink) {
		if (p->data == data) {
			return p;
		}
	}

}
```

