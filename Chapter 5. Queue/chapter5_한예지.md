8번

```
int how(QueueType *q) {
   if (q->front <= q->rear)
      return q->rear - q->front;
   else
      return MAX_QUEUE_SIZE - (q->front - q->rear);
}
```

9번

```
int main(void) {
   StackType s1;
   StackType s2;
   init_stack(&s1);
   init_stack(&s2);
   push(&s1, 1);
   push(&s1, 2);
   push(&s1, 3);
   while(!is_empty(&s1)){
      push(&s2, pop(&s1));
   }
   while (!is_empty(&s2)) {
      printf("%d ", pop(&s2));
   }

   return 0;
}
```

10번

```
void fib(QueueType *q) {
   enqueue(&q, q->data[(q->rear) % MAX_QUEUE_SIZE]+ q->data[(q->rear-1) % MAX_QUEUE_SIZE]);
   dequeue(&q);
}
```

11번

```
#include<stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef char element;
typedef struct {
   element data[MAX_QUEUE_SIZE];
   int front, rear;
} QueueType;

void error(char *message) {
   fprintf(stderr, "%s\n", message);
   exit(1);
}

void init_queue(QueueType *q) {
   q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
   return (q->front == q->rear);
}

int is_full(QueueType *q) {
   return((q->rear + 1)*MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q) {
   printf("QUEUE(front=%d rear=%d)=", q->front, q->rear);
   if (!is_empty(q)) {
      int i = q->front;
      do {
         i = (i + 1) % (MAX_QUEUE_SIZE);
         printf("%d | ", q->data[i]);
         if (i == q->rear)
            break;
      } while (i != q->front);
   }
   printf("\n");
}

void add_rear(QueueType *q, element item) {
   if (is_full(q)) {
      error("큐가 포화상태입니다.");
   }
   q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   q->data[q->rear] = item;
}

element delete_front(QueueType *q) {
   if (is_empty(q)) {
      error("큐가 공백상태입니다.");
   }
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->data[q->front];
}

element get_front(QueueType *q) {
   if (is_empty(q)) {
      error("큐가 공백상태입니다.");
   }
   return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(QueueType *q, element item) {
   if (is_full(q)) {
      error("큐가 포화상태입니다.");
   }
   q->data[q->front] = item;
   q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(QueueType *q) {
   int prev = q->rear;
   if (is_empty(q)) {
      error("큐가 공백상태입니다.");
   }
   q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
   return q->data[prev];
}

element get_rear(QueueType *q) {
   if (is_empty(q)) {
      error("큐가 공백상태입니다.");
   }
   return q->data[(q->rear)];
}

int how(QueueType *q) {
   if (q->front <= q->rear)
      return q->rear - q->front;
   else
      return MAX_QUEUE_SIZE - (q->front - q->rear);
}

int pal(QueueType *q) {
   for (int i = how(&q) / 2; i > 0; i--) {
      if (delete_front(&q) == delete_rear(&q)) {
         continue;
      }
      else {
         return 1;
      }
   }
   return 2;
}

int main(void) {
   QueueType q;
   char a[100];
   scanf("%s", &a);
   int i = 0;
   while (a[i] != NULL) {
      if (a[i] == ',' || a[i] == ' ') {
         i++;
         continue;
      }
      else if (65 <= a[i] && a[i] <= 90) {
         a[i] += 32;
      }
      add_rear(&q, a[i]);
      i++;
   }

   if (pal(&q) == 1) {
      printf("회문이 아닙니다.");
   }
   else {
      printf("회문입니다.");
   }
   return 0;
}
```

12번