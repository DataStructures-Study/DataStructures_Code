# 05 큐 연습문제



1.

큐는 FIFO 선입 선출의 형태를 갖기 때문에 먼저 들어온 대로 출력된다.

=>(a) A,B,C,D,E



2.

| [0]  | [1]  | [2]  | [3]     | [4]  | [5]        | [6]  | [7]  |
| :--: | :--: | :--: | ------- | ---- | ---------- | ---- | :--: |
|      |      |      | <front> | (a)  | (b) <rear> |      |      |

=>(b) a,b 두개



3.

선입 선출의 형태로 먼저 들어온  10, 20, 30 이 삭제된다.

=>40, 50



4.

front 와 rear의 값이 같으면 원형 큐가 비어있음을 나타낸다.

=>(c) front==rear



5.

원형큐에서는 삽입 시에 rear가 먼저 증가되고, 증가된 위치에 새로운 데이터가 삽입된다. 

=>(2) front는 3, rear은 6



6.



| [0]  | [1]  | [2]  | [3]  | [4]  |
| :--: | :--: | :--: | :--: | :--: |
|      |      |  C   |  A   |  D   |



A가 [3]에 추가, D가 [4]에 추가, [1]의 B가 삭제





7.

큐에는 탐색이 없다. 

자료가 삽입 될 때는 자료의 맨 뒤에 자료가 삽입 되는 연산만 수행,

자료의 삭제 또한 맨 앞의 자료가 삭제되는 연산만 수행되므로 

시간 복잡도는 O(1)



=>(a)



8.

```c
element get_count(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    else
        return (q->rear - q->front);
}
```





9.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 검사 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 검사 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void)
{
	StackType s1, s2;

	init_stack(&s1);
	init_stack(&s2);
	int n = 0, num = 0, i = 0;

	
	printf("입력 개수 = ");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("입력 : ");
		scanf_s("%d", &num);
		push(&s1, num); //입력이 들어오면 스택 1 에 넣음 
	}

	for (int j = 0; j < i; j++)
	{
		push(&s2, pop(&s1)); //스택 1에서 요소 꺼내 스택 2에 넣음
	}

	while (!is_empty(&s2))
	{
		
		printf("출력 : %d\n", pop(&s2)); //스택 2의 요소들 꺼내 출력
	}
	return 0;
}


```





10.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//오류 함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//포화상태 검사
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//공백상태 검사
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
//원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//삽입 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q))
		error("큐가 포화상태.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[(q->rear)] = item;
}
//삭제 함수
int dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//호출 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int main(void)
{
	QueueType queue;
	int element;

	int fib;

	init_queue(&queue);
	

	enqueue(&queue, 0);
	enqueue(&queue, 1);

	printf("%d %d ", queue.data[1], queue.data[2]);

	for(int i=0; i<MAX_QUEUE_SIZE; i++)
	{
		fib = dequeue(&queue) + queue.data[queue.rear]; 
		enqueue(&queue, fib);
		printf("%d ", queue.data[queue.rear]);
	}

	return 0;

}
	


```



11.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

//오류 함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수
void init_queue(DequeType* q)
{
	q->front = q->rear = 0;
}
//포화상태 검사
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//공백상태 검사
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}
//원형큐 출력 함수
void deque_print(DequeType* q)
{
	printf("Deque(front = %d, rear = %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//삽입 함수
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[(q->rear)] = item;
}

//삭제 함수
int delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//삭제 함수
element get_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}




int main(void)
{
	int i;
	int n = 0;
	char string[20];

	DequeType queue;
	init_queue(&queue);

	printf("문자열을 입력하시오 : ");
	scanf_s("%s", string, sizeof(string));
	n = strlen(string); //문자열의 길이

	for (i = 0; i < n; i++)
	{
		if (string[i] == ',' || string == ' ') //구두점이나 스페이스 무시
			continue;

		if (65 <= string[i] && string[i] <= 90) 
			string[i] += 32; //대문자->소문자 바꾸기

		add_rear(&queue, string[i]); //삽입
	}


	for (i = 0; i < n/2 ; i++)
	{
		if (delete_rear(&queue) == delete_front(&queue)) //첫번째, 마지막 삭제 원소가 같다면 
			continue;
		else
			printf("회문이 아닙니다.");
	}
	printf("회문입니다");

	return 0;
}

```



12.

A-Steal 스케줄링

* 멀티 프로세서 환경에서 사용.

* 각 프로세서마다 자신이 먼저 처리해야할 작업들이 들어있는 Deque가 존재

* A 프로세서가 자신에게 할당된 작업을 처리하기 위해 Deque의 선두에서 요소를 얻어옴

* 만약 다른 B프로세서가 자신에게 할당된 작업을담아놓은 Deque에 있는 작업을 모두 처리했다면 

  A 프로세서의 Deque에서 작업을 가져옴. 이를 '훔친다'로 표현

  (이때, B프로세서는 A프로세서의 꼬리쪽에서 작업을 가져오므로 Deque를 사용)

