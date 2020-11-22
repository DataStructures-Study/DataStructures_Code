#### 8

```c
int get_count(QueueType* q) {
   
   int count = q->rear - q->front;
   if (count < 0) count += MAX_QUEUE_SIZE;
   return count;
}
```



#### 9

```c
int main(void)
{
	StackType s1;
	init_stack(&s1);
	StackType s2;
	init_stack(&s2);

	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);
	push(&s2, pop(&s1));
	push(&s2, pop(&s1));
	push(&s2, pop(&s1));
	for (int i = 0;i < 3;i++) {
		printf("%d", pop(&s2));
	}
	
}

```



#### 10

```c
int fibonachi(Queuetype* q, int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	for (int i = 2; i <= n; i++) {
		int d = pop(q);
		push(q, d + q->Queue[q->rear]);
	}
	return q->Queue[q->rear];
}

int main(void) {
	Queuetype q;
	init(&q);
	push(&q, 0);
	push(&q, 1);
	int n = 4;
	printf("%d", fibonachi(&q, n));
}
```



#### 11

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef char element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType* q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%c | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element get_front(DequeType* q)
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

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}
int count_qu(DequeType* q) {
	int count;
	count = (q->rear - q->front + MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
	return count;
}

int main(void)
{
	DequeType queue;

	init_deque(&queue);
	char input[MAX_QUEUE_SIZE];
	gets(input);
	for (int i = 0; i < strlen(input); i++) {
		add_front(&queue, input[i]);
		deque_print(&queue);
	}

		int r1, r2;
		for (int j = 0;j < strlen(input) / 2;j++) {
			r1 = (delete_front(&queue) == delete_rear(&queue));
			r2 = (delete_front(&queue) == delete_rear(&queue));
			if (r1 && r2) {
				printf("회문이다.\n");
			}
		}
	
	
	return 0;
}
```



#### 12

```

```

