# Chap 14. Hashing

---------

01.

(2)



02.

(C)



03.





04.

27번

05.

(3)

06.

2-3 트리가 가장 효율적으로 탐색을 수행한다.



07.



08.

```c
#include<stdio.h>

#define KEY_SIZE 20
#define TABLE_SIZE 11

typedef struct element{
	int value;
	int used;
	int full;
}element;

typedef struct HashTable{
	element table[TABLE_SIZE];
}HashTable;

void initTable(HashTable *ht){
	for(int i=0; i<TABLE_SIZE; i++){
		ht->table[i].value = -1;
		ht->table[i].used = ht->table[i].full = 0;
	}
}

void display(HashTable ht){
	for(int i=0; i<TABLE_SIZE; i++){
		printf("%d ", ht.table[i].value);
	}
	printf("\n");
}

int isEmpty(HashTable ht){
	int count=0;
	for(int i=0; i<TABLE_SIZE; i++){
		if(ht.table[i].full){
			count++;
		}
	}
	return count == 0;
}

int isFull(HashTable ht){
	int count = 0;

	for(int i=0; i<TABLE_SIZE; i++){
		if(ht.table[i].full){
			count++;
		}
	}
	return count==TABLE_SIZE;
}

void inputHashTable(HashTable *ht, element data){
	int step, hashKey;
	step = hashKey = data.value % 11;

	if(isFull(*ht)){
		printf("Table is Full.\n");
		return;
	}else{
		while(1){
			if (!ht->table[step].full){
				ht->table[step].value = data.value;
				ht->table[step].full = 1;
				ht->table[step].used = 1;
				break;
			} else {
				step =  ++step % TABLE_SIZE;
				if (step == hashKey) {
					printf("Table is Full.\n");
					return;
				}
			}
		}
		display(*ht);
	}
}

void deleteHashTable(HashTable *ht, element data){
	int step, hashKey;
	step = hashKey = data.value % 11;

	if(isEmpty(*ht)){
		printf("Table is Empty.\n");
		return;
	}else{
		while(1){
			if(ht->table[step].full && ht->table[step].value == data.value){
				ht->table[step].value = -1;
				ht->table[step].full = 0;
				printf("delete success : %d\n", data.value);
				break;
			}else{
				step = ++step % TABLE_SIZE;
				if (step == hashKey || !ht->table[step].used){
					printf("Data you want to delete is not exist in hashtable.\n");
					return;
				}
			}
		}
	}
}

int find(HashTable ht, int data){
	int step, hashKey, result = -1;
	step = hashKey = data % 11;

	while(1){
		if(ht.table[step].used && ht.table[step].value == data){
			result = step;
			break;
		}else{
			step = ++step % TABLE_SIZE;
			if (step == hashKey){
				return -1;
			}
		}
	}

	return result;
}

void search(HashTable ht, element data){
	if(isEmpty(ht)){
		printf("Table is Empty.\n");
	} else{
		int result = find(ht, data.value);
		if(result == -1) {
			printf("Data you are looking for is not exist in hashtable.\n");
		}else{
			printf("search success : %d\n", result);
		}
	}
}

void main(){
	int op;
	element temp;
	HashTable test1;
	initTable(&test1);

	do{
		printf("Enter the desired operation.(0=input, 1=delete, 2=search, 3=display, 4=exit.) ");
		scanf("%d", &op);
		switch (op){
		case 0:
			printf("Enter the key ");
			scanf("%d", &temp.value);
			inputHashTable(&test1, temp);
			break;
		case 1:
			printf("Enter the key ");
			scanf("%d", &temp.value);
			deleteHashTable(&test1, temp);
			break;
		case 2:
			printf("Enter the key ");
			scanf("%d", &temp.value);
			search(test1, temp);
			break;
		case 3:
			display(test1);
		}

	}while(op != 4);
}
```

09.

```c
#include<Stdio.h>
#include<malloc.h>

#define TABLE_SIZE 11

typedef struct ListNode{
	int data;
	struct LinkNode *link;
}ListNode;


void init(ListNode *ht[]){
	for(int i=0; i<TABLE_SIZE; i++){
		ht[i]=NULL;
	}
}

void display(ListNode *ht[]){
	for(int i=0; i<TABLE_SIZE; i++){
		ListNode *p = ht[i];
		printf("%d : ", i);
		while(p != NULL){
			printf("%d ", p->data);
			p = p->link;
		}
		printf("\n");
	}
}

ListNode *createNode(int data){
	ListNode *new = (ListNode *)malloc(sizeof(ListNode));

	if(new == NULL){
		printf("Allocation Failed.\n");
	}else{
		new->data = data;
		new->link = NULL;
	}

	return new;
}

void addHashTable(ListNode *ht[], ListNode *newNode){
	if (newNode == NULL){
		return;
	}else{
		int hashVlaue = newNode->data % TABLE_SIZE;

		if (ht[hashVlaue] == NULL){
			ht[hashVlaue] = newNode;
		}else{
			newNode->link = ht[hashVlaue];
			ht[hashVlaue] = newNode;
		}
	}
}

void deleteHashTable(ListNode *ht[], int data){
	int hashValue = data % TABLE_SIZE;
	ListNode *n = ht[hashValue], *p = NULL, *removed = NULL;

	while(n != NULL){
		if(n->data == data){
			if (p == NULL){
				removed = ht[hashValue];
				ht[hashValue] = n->link;
			}else{
				removed = n;
				p->link = removed->link;
			}
			free(removed);
			return;
		}
		p=n;
		n=n->link;
	}
	printf("Data you want to delete is not exist in hashtable.\n");
}

void search(ListNode *ht[], int data){
	int hashValue = data % TABLE_SIZE;
	ListNode *p = ht[hashValue];

	while(p != NULL){
		if(p->data == data){
			printf("Find the value.\n");
			return;
		}
		p=p->link;
	}
	printf("Data you want to find is not exist.\n");
}

void main(){
	ListNode *test1[TABLE_SIZE];
	init(test1);
	addHashTable(test1, createNode(12));
	addHashTable(test1, createNode(44));
	addHashTable(test1, createNode(13));
	addHashTable(test1, createNode(88));
	addHashTable(test1, createNode(23));
	addHashTable(test1, createNode(16));
	addHashTable(test1, createNode(5));
	display(test1);

	printf("find data 11 in hashtable. ");
	search(test1, 11);
	printf("find data 77 in hashtable. ");
	search(test1, 77);

	printf("\n");
	printf("delete data 5 in hashtable.\n");
	deleteHashTable(test1, 5);
	display(test1);

	printf("\n");
	printf("delete data 7 in hashtable.\n");
	deleteHashTable(test1, 7);

	printf("\n");
	printf("delete data 88 in hashtable.\n");
	deleteHashTable(test1, 88);
	display(test1);
}
```

