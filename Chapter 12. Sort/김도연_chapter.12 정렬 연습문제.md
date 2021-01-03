# 12.정렬



01 (4)



02 (2)



03 (1)



04 (4)



05 

(1) 선택 정렬

입력 배열에서 최소값을 발견하고 이 최소값을 배열의 첫번째 요소와 교환

| 7    | 4    | 9    | 6    | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 3    | 4    | 9    | 6    | 7    | 8    | 7    | 5    |
| 3    | 4    | 9    | 6    | 7    | 8    | 7    | 5    |
| 3    | 4    | 5    | 6    | 7    | 8    | 7    | 9    |
| 3    | 4    | 5    | 6    | 7    | 8    | 7    | 9    |
| 3    | 4    | 5    | 6    | 7    | 8    | 7    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |

(2) 삽입 정렬

정렬되어있는 리스트에 새로운 레코드를 적절한 위치에 삽입

| 7    | 4    | 9    | 6    | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 4    | 7    | 9    | 6    | 3    | 8    | 7    | 5    |
| 4    | 7    | 9    | 6    | 3    | 8    | 7    | 5    |
| 4    | 6    | 7    | 9    | 3    | 8    | 7    | 5    |
| 3    | 4    | 6    | 7    | 9    | 8    | 7    | 5    |
| 3    | 4    | 6    | 7    | 8    | 9    | 7    | 5    |
| 3    | 4    | 6    | 7    | 7    | 8    | 9    | 5    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |



(3) 버블 정렬

인접한 2개의 레코드를 비교해 크기가 순서대로 되어있지 않으면 교환하는 과정을 왼쪽 끝 -오른쪽 끝 진행 

| 7    | 4    | 9    | 6    | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 4    | 7    | 6    | 3    | 8    | 7    | 5    | 9    |
| 4    | 6    | 3    | 7    | 7    | 5    | 8    | 9    |
| 4    | 3    | 6    | 7    | 5    | 7    | 8    | 9    |
| 3    | 4    | 6    | 5    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |



(4) 쉘 정렬

| 7    | 4    | 9    | 6    | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 7    |      |      |      | 3    |      |      |      |
|      | 4    |      |      |      | 8    |      |      |
|      |      | 9    |      |      |      | 7    |      |
|      |      |      | 6    |      |      |      | 5    |
| 3    | 4    | 7    | 5    | 7    | 8    | 9    | 6    |

(간격 4 정렬 후의 전체 배열)

| 3    |      | 7    |      | 7    |      | 9    |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      | 4    |      | 5    |      | 8    |      | 6    |
| 3    | 4    | 7    | 5    | 7    | 6    | 9    | 8    |

(간격 2 정렬 후의 전체 배열)



| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

(간격 1 정렬 후의 전체 배열)



06

(1) 퀵 정렬

| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 38   | 49   | 53   | 55   | 71   | 82   | 72   | 92   |
| 38   | 49   | 53   | 55   | 71   | 72   | 82   | 92   |



(2) 합병 정렬

  --------------------A-------------------------------분할-----------------------B---------------------------

| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| 49   | 71   | 55   | 92   | 38   | 82   | 53   | 72   |
| 49   | 55   | 71   | 92   | 38   | 53   | 72   | 82   |
| 38   | 49   | 53   | 55   | 71   | 72   | 82   | 92   |



(3) 히프 정렬

배열 삽입

| 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |



완전 이진 트리



|      |      |      |      | 71   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 49   |      |      |      | 92   |      |
|      | 55   |      | 38   |      | 82   |      | 72   |
| 33   |      |      |      |      |      |      |      |

|      |      |      |      | 92   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 55   |      |      |      | 82   |      |
|      | 53   |      | 38   |      | 71   |      | 72   |
| 49   |      |      |      |      |      |      |      |

|      |      |      |      | 82   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 53   |      |      |      | 71   |      |
|      | 49   |      | 38   |      | 55   |      | 72   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 72   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 53   |      |      |      | 71   |      |
|      | 49   |      | 38   |      | 55   |      | 82   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 71   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 53   |      |      |      | 55   |      |
|      | 49   |      | 38   |      | 72   |      | 82   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 55   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 49   |      |      |      | 53   |      |
|      | 38   |      | 71   |      | 72   |      | 82   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 53   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 38   |      |      |      | 49   |      |
|      | 55   |      | 71   |      | 72   |      | 82   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 49   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 38   |      |      |      | 53   |      |
|      | 55   |      | 71   |      | 72   |      | 82   |
| 92   |      |      |      |      |      |      |      |

|      |      |      |      | 38   |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|      |      | 49   |      |      |      | 53   |      |
|      | 55   |      | 71   |      | 72   |      | 82   |
| 92   |      |      |      |      |      |      |      |



07

(1)

| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |

(2)

5를 피봇으로

| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |





08

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ((t)=(x), (x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void print_LowHigh(int list[], int high, int low)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", list[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (i == high)
			printf("high\t");
		else if (i == low)
			printf("low\t");
		else
			printf("\t");
	}
	printf("\n");
}

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		print_LowHigh(list, high, low);

		if (low < high) 
			SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	print_LowHigh(list, high, low);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	n = MAX_SIZE;
	int list[] = { 67, 90, 57, 25, 84, 32, 73, 54 };
	
	quick_sort(list, 0, n - 1); //퀵정렬 호출

	
	return 0;
}
```





09

(2), (3)



10

(2)



11

(a)

| 5    | 3    | 4    | 9    | 8    | 5    | 6    | 7    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 5    | 3    | 4    | 5    | 8    | 9    | 6    | 7    |
| 4    | 3    | 5    | 5    | 8    | 9    | 6    | 7    |

(b) 8번

(c) 변경되지 않는다. 고정된 피봇값 위치를 기준으로 왼쪽, 오른쪽 분할해 연산을 진행하기 때문이다.



12

| 123  | 398  | 210  | 409  | 528  | 003  | 513  | 129  | 220  | 294  |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 210  | 220  | 123  | 003  | 513  | 294  | 398  | 528  | 019  | 129  |
| 003  | 210  | 513  | 019  | 220  | 123  | 528  | 129  | 294  | 398  |
| 003  | 129  | 123  | 129  | 210  | 220  | 294  | 398  | 513  | 528  |



13

```c
#define MAX_SIZE 100
#define NAME_SIZE 20

typedef struct {
	int key;
	char name[NAME_SIZE];
} record;
record list[MAX_SIZE];


void insertion_sort(record list[], int n)
{
	int i, j;
	record record1;
	for (i = 1; i < n; i++) {
		record1 = list[i];
		for (j = i - 1; j >= 0 && list[j].key > record1.key; j--)
			list[j + 1] = list[j];
		list[j + 1] = record1;
	}

}
```





14

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 6
#define SWAP(x, y, t) ((t)=(x), (x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;


void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (i = 0; i <= n; i++) {
		//정렬되어있는 숫자들
		printf("( ");
		for (int k = 0; k < i; k++)
			printf("%d ", list[k]);
		printf(")     ");

		//정렬해야할 숫자들
		printf("( ");
		for (int k = i; k < n; k++)
			printf("%d ", list[k]);
		printf(")\n");
		//printf(")      %d삽입\n");


		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;


	}



}



int main(void)
{
	n = MAX_SIZE;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &list[i]);

	insertion_sort(list, n);

	return 0;
}
```







15



```c
typedef struct listNode{
    struct ListNode * link;
    int data;
}ListNode;

void insertion_sort(ListNode *h)
{
  
    
}


```





16

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;

	printf("( )    ");
	printf("(");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf(")\n");

	for (i = 0; i < n; i++) {
		least = i;
		for (j = i + 1; j < n; j++) //최소값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);

		printf("( ");
		for (int k = 0; k <= i; k++)
			printf("%d ", list[k]);
		printf(")     ");

		printf("(");
		for (int k = i + 1; k < n; k++)
			printf("%d ", list[k]);
		printf(")\n");
	}


	
}

int main(void)
{
	n = MAX_SIZE;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &list[i]);

	selection_sort(list, n);

	

	return 0;
}
```





17

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;


int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		printf("quick_sort(%d, %d)\n", left, right);
		quick_sort(list, left, q - 1);
		printf("quick_sort(%d, %d)\n", left, right);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100;

	quick_sort(list, 0, n - 1);          // 퀵정렬 호출 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}


```



18

```c
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high, middle;

	low = left;
	high = right + 1;
	middle = (left + right) / 2;

	if (left < right) { 
		if (right < middle) 
			pivot = list[right];
		else {
			if (left < middle) 	
				pivot = list[middle];
			else 
				pivot = list[left];
		}
	}
	else { // right > left
		if (left < middle)
			pivot = list[left];
		else {
			if (right < middle)
				pivot = list[middle];
			else
				pivot = list[right];
		}
	}

	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
```



19.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE]; //정렬된 결과 배열을 담을 수 있는 공간 필요
//정렬 배열은 반드시 전역 변수로 선언

/*  i는 정렬된 왼쪽 리스트에 대한 인덱스
	j는 정렬된 오른쪽 리스트에 대한 인덱스
	k는 정렬될 리스트에 대한 인덱스  */

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	/* 분할 정렬된 list의 합병 */
	//작은 순서대로 배열에 삽입
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	//남은 데이터도 삽입
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	//배열 sorted[]의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

}

void merge_sort(int list[], int left, int right)
{	//크기가 1 보다 큰 경우
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트의 균등 분할
		merge_sort(list, left, mid); //왼쪽 병합정렬
		printf("merge_sort_left(%d, %d)\n", left, right);
		merge_sort(list, mid + 1, right); //오른쪽 병합 정렬
		printf("merge_sort_right(%d, %d)\n", left, right);
		merge(list, left, mid, right); //합병
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100;

	merge_sort(list, 0, n - 1);          // 퀵정렬 호출 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
```



20.



21.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct { //큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
//오류 함수
void error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}
//공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
//포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백 상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void print_bucket(int list[], int n)
{
	int factor = 1;
	int n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
	int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp6 = 0,
		temp7 = 0, temp8 = 0, temp9 = 0;
	int bucket0[MAX_QUEUE_SIZE], bucket1[MAX_QUEUE_SIZE], bucket2[MAX_QUEUE_SIZE], bucket3[MAX_QUEUE_SIZE],
		bucket4[MAX_QUEUE_SIZE], bucket5[MAX_QUEUE_SIZE], bucket6[MAX_QUEUE_SIZE], bucket7[MAX_QUEUE_SIZE],
		bucket8[MAX_QUEUE_SIZE], bucket9[MAX_QUEUE_SIZE];
	printf("===========================\n");
	for (int i = 0; i < n; i++)
	{
		switch ((list[i]/factor) % 10)
		{
		case 0: bucket0[n0] = list[i]; n0++; temp0 = n0;
			break;
		case 1: bucket1[n1] = list[i]; n1++; temp1 = n1;
			break;
		case 2: bucket2[n2] = list[i]; n2++; temp2 = n2;
			break;
		case 3: bucket3[n3] = list[i]; n3++; temp3 = n3;
			break;
		case 4: bucket4[n4] = list[i]; n4++; temp4 = n4;
			break;
		case 5: bucket5[n5] = list[i]; n5++; temp5 = n5;
			break;
		case 6: bucket6[n6] = list[i]; n6++; temp6 = n6;
			break;
		case 7: bucket7[n7] = list[i]; n7++; temp7 = n7;
			break;
		case 8: bucket8[n8] = list[i]; n8++; temp8 = n8;
			break;
		case 9: bucket9[n9] = list[i]; n9++; temp9 = n9;
			break;
		}
	}

	printf("[0]->  ");
	for (int j = 0; j < temp0; j++)
		printf("  %d", bucket0[j]);
	printf("\n");

	printf("[1]->  ");
	for (int j = 0; j < temp1; j++)
		printf("  %d", bucket1[j]);
	printf("\n");

	printf("[2]->  ");
	for (int j = 0; j < temp2; j++)
		printf("  %d", bucket2[j]);
	printf("\n");

	printf("[3]->  ");
	for (int j = 0; j < temp3; j++)
		printf("  %d", bucket3[j]);
	printf("\n");

	printf("[4]->  ");
	for (int j = 0; j < temp4; j++)
		printf("  %d", bucket4[j]);
	printf("\n");

	printf("[5]->  ");
	for (int j = 0; j < temp5; j++)
		printf("  %d", bucket5[j]);
	printf("\n");

	printf("[6]->  ");
	for (int j = 0; j < temp6; j++)
		printf("  %d", bucket6[j]);
	printf("\n");

	printf("[7]->  ");
	for (int j = 0; j < temp7; j++)
		printf("  %d", bucket7[j]);
	printf("\n");

	printf("[8]->  ");
	for (int j = 0; j < temp8; j++)
		printf("  %d", bucket8[j]);
	printf("\n");

	printf("[9]->  ");
	for (int j = 0; j < temp9; j++)
		printf("  %d", bucket9[j]);
	printf("\n");

	printf("\n");	printf("===========================\n");

}

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]); //큐들의 초기화 

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)   //데이터들을 자리수에 따라 큐에 삽입
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		
		for (b = i = 0; b < BUCKETS; b++) //버킷에서 꺼내어 list로 합친다.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10; //그 다음 자리수로 간다.
	}
	print_bucket(list, n);
}

#define  SIZE 10

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;

	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

```

