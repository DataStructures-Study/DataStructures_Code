##### 1. 4번(3,8,4,9,7)

##### 2. 2번(6,7,3,5,9)

##### 3. 1번(3,4,7,9,8)

##### 4. 4번(ㄱ:j>=0&&key<A[j],ㄴ:A[j+1]=A[j])

##### 5. 

(1)

|  3   | 4    | 9    | 6    | 7    | 8    | 7    | 5    |
| :--: | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  3   | 4    | 9    | 6    | 7    | 8    | 7    | 5    |
|  3   | 4    | 5    | 6    | 7    | 8    | 7    | 9    |
|  3   | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
|  3   | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
|  3   | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
|  3   | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
|  3   | 4    | 5    | 6    | 7    | 7    | 8    | 9    |

(2)

| 7    | 4    | 9    |  6   | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | :--: | ---- | ---- | ---- | ---- |
| 4    | 7    | 9    |  6   | 3    | 8    | 7    | 5    |
| 4    | 7    | 9    |  6   | 3    | 8    | 7    | 5    |
| 4    | 6    | 7    |  9   | 3    | 8    | 7    | 5    |
| 3    | 4    | 6    |  7   | 9    | 8    | 7    | 5    |
| 3    | 4    | 6    |  7   | 8    | 9    | 7    | 5    |
| 3    | 4    | 6    |  7   | 7    | 8    | 9    | 5    |
| 3    | 4    | 5    |  6   | 7    | 7    | 8    | 9    |

(3)

| 4    | 7    | 6    | 3    | 8    | 7    | 5    | 9    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 4    | 6    | 3    | 7    | 7    | 5    | 8    | 9    |
| 4    | 3    | 6    | 7    | 5    | 7    | 8    | 9    |
| 3    | 4    | 6    | 5    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |

(4)

| 7    | 4    | 9    | 6    | 3    | 8    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 7    | 4    | 5    | 6    | 3    | 8    | 7    | 9    |
| 6    | 3    | 5    | 7    | 4    | 8    | 7    | 9    |
| 3    | 4    | 5    | 6    | 7    | 7    | 8    | 9    |

##### 6

(1)

| 71   | 49   | 92   | 55   | 38   | 82   | 72   | 53   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 38   | 49   | 53   | 55   | 71   | 82   | 72   | 92   |
| 38   | 49   | 53   | 55   | 71   | 72   | 82   | 92   |
| 38   | 49   | 53   | 55   | 71   | 72   | 82   | 92   |

처음에 pivot은 71이다. low와 high가 이동하며 교환한뒤 최종적으로 38과 피봇인 71이 교환되어 첫번째 정렬이 끝난다. 71을 기준으로 좌우로 나뉘며 또 정렬이 시작되고 두번째는 38과 72과 확정된다.  마지막엔 모두 오름차순으로 정렬된다.

(2),(3)

![6번(2,3)](cjimg/6번(2,3).jpg)

##### 7

(1) 1에서 8까지 하나씩 피봇값으로 정해져서 정렬완료된다.

(2) 

##### 8

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]={ 67,90,57,25,84,32,73,54 };
int n;
void print_status(int list[]);
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
			print_status(list, low, high);
		} while (list[low] < pivot);
		do {
		high--;
		print_status(list, low, high);
		} while (list[high] > pivot);
		
		
		
		if (low < high) SWAP(list[low], list[high], temp);
		
	} while (low < high);
	
	SWAP(list[left], list[high], temp);
	print_status(list, low, high);
	return high;
}
void print_status(int list[],int low, int high) {
	int i;
	for (i = 0;i < MAX_SIZE;i++) {
		printf(" %d   ", list[i]);
	}
	printf("\n");
	//int status[MAX_SIZE] = { 0 };
	for (i = 0;i < MAX_SIZE;i++) {
		if (i == low) printf(" low");
		else if (i == high) printf(" high ");
		else{ printf("      "); }
	}
	printf("\n");
}
void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

//
int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	
	quick_sort(list, 0, n - 1); // 퀵정렬 호출 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
```



##### 9 안정적인 정렬은 삽입,버블,합병 정렬이다.



##### 10   (2) 어느정도 정렬이 되어 있다.



##### 11   

(1)  4,3,5,5,8,9,6,7

(2)  10번

(3) 피봇값은 high값과 위치가 교환된다. 그 분할이 한번 끝난 후에 피봇값의 위치는 변경이 안된다 . 다음 분할 단계를 진행할 때 이 중간에 있는 피봇값을 제외하고 진행하기 때문이다. 

(4) 리턴된 high 위치를 기준으로 왼쪽과 오른쪽 범위를 나눠 또 분할을 한다.

##### 12

![12번](cjimg/12번.jpg)

##### 13

```c
void insertion_sort(record list[], int n)
{
	record key;
	int i, j, keyValue;
	for (i = 1; i < n; i++) {
		key = list[i];
		keyValue = list[i].key;
		for (j = i - 1; j >= 0 && list[j].key > keyValue; j--)
			list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
		list[j + 1] = key;
	}
}
```



##### 14

```c
#include<stdio.h>
#define MAX_SIZE 6
void print_status(int list[], int i, int key);
void insertion_sort(int list[], int n)
{
	int i, j,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
		list[j + 1] = key;
		print_status(list,i,key);
	}
}
void print_status(int list[], int i, int key) {
	printf("(");
	int k;
	for (k = 0;k <= i;k++) {
		printf("%d ", list[k]);
		if (i>=1 && k<i) printf(",");
	}
	printf(")    (");
	for (k = i+1;k < MAX_SIZE;k++) {
		printf("%d ", list[k]);
		if (k < MAX_SIZE-1) printf(",");
	}
	printf(")     %d 삽입",key);
	printf("\n");
}
int main() {
	int list[MAX_SIZE] = {17,9,21,6,3,12};
	printf("()      (");
	for (int i = 0;i < MAX_SIZE;i++) {
		printf("%d ", list[i]);
		if (i < MAX_SIZE - 1) printf(",");

	}
	printf(")\n");
	printf("(%d)      (",list[0]);
	for (int i = 1;i < MAX_SIZE;i++) {
		printf("%d ", list[i]);
		if (i < MAX_SIZE - 1) printf(",");

	}
	printf(")     %d 삽입\n",list[0]);
	insertion_sort(list, MAX_SIZE);
}
```



##### 15

```c

```



##### 16

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
void print_condition(int list[], int n, int i,int least) {
	int j;
	printf("(");
	if (i >= 0) {
		for (j = 0;j <= i;j++) {
			printf("%d ", list[j]);
		}
	}
	printf(")  (");
	for (j = i + 1;j < n;j++) {
		printf("%d ", list[j]);
	}
	if (i < 0) {
		printf(")    초기상태");
	}
	else {
		printf(")    %d선택 후 %d과 교환",list[i], list[least]);
	}
	printf(" \n");
}
void selection_sort(int list[], int n)
{
	int i=-1, j, least=0, temp;
	print_condition(list, n, i,least);
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// 최소값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		print_condition(list, n, i,least);
	}
	print_condition(list, n, i,i);
}

```



##### 17

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]={ 71,49,92,55,38,82,72,53 };
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
		printf("quick_sort(%d,%d)\n",left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
		
	}
}

//
int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	//for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		//list[i] = rand() % 100;
	
	quick_sort(list, 0, n - 1); // 퀵정렬 호출 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
```



##### 18



##### 19

```c
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		printf("merge_sort(%d,%d)\n", left, right);
		mid = (left + right) / 2;     /* 리스트의 균등 분할 */
		merge_sort(list, left, mid);    /* 부분 리스트 정렬 */
		merge_sort(list, mid + 1, right); /* 부분 리스트 정렬 */
		merge(list, left, mid, right);    /* 합병 */
	}
}
```



##### 20

```c
void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
		for (int j = 1;j <= i;j++)
			printf("%d ", h->heap[j].key);
		printf("[");
		for(int k=i ; k<n;k++)
			printf("%d ", a[k].key);
		printf("]");
		printf("\n");
	}
	printf("\n정렬된 배열 :\n");
	for (i = 0;i < n;i++) {
		printf("%d ", a[i].key);
	}
	free(h);
}
```



##### 21

```c
void print_bucket(set nums[]) {
	int j = 0;
	printf("==============\n");
	for (int i = 0;i < BUCKETS;i++) {
		printf("[%d] -> ", i);
		while (nums[j].loc == i){
			printf("%d ", nums[j].num);
			j++;
		}
		
		printf("\n");
	}
	
}
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	int temp;set nums[50];
	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);  // 큐들의 초기화
	
	for (d = 0; d < DIGITS; d++) {
		int j=0;
		for (i = 0; i < n; i++)			// 데이터들을 자리수에 따라 큐에 삽입
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		for (b = i = 0; b < BUCKETS; b++) { // 버킷에서 꺼내어 list로 합친다.
			while (!is_empty(&queues[b])) {
				temp = dequeue(&queues[b]);
				list[i++] = temp;
				nums[j].loc = b;
				nums[j].num = temp; j++;
			}
		}
		print_bucket(nums);
		factor *= 10;					// 그 다음 자리수로 간다.
		
	}
}
```

