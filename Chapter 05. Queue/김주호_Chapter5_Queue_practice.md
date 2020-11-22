# Chapter 5. Queue

## problem 8

```c
#include "Header_queue.h"

int get_count(QueueType* q) {
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void main() {
	QueueType q;
	init_queue(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	printf("%d", get_count(&q));

	return;
}
```



## problem 9

```c
#include "Header_stack.h"
#pragma warning(disable:4996)

void main(){
    StackType s1, s2; 
    int temp; 
    init_stack(&s1); 
    init_stack(&s2); 

    for (int count = 0; count < 5; count++) // 입력 s1 스택에 넣음
    {
        printf("입력할 %d번째 정수: ", count + 1);
        scanf("%d", &temp);
        push(&s1, temp);
    }

    if (is_empty(&s2) == 1) // s2스택이 비어있다면 s1스택의 모든 요소를 꺼내 s2스택에 넣음
    {
        for (int count2 = 0; count2 < 5; count2++)
            push(&s2, pop(&s1));
    }

    for (int count = 0; count < 5; count++) // s2스택에서 꺼내어 출력
    {
        printf("%d ", pop(&s2));
    }
}
```



## problem 10

```c
#include "Header_queue.h"

int peek_rear(QueueType* q)
{
    if (is_empty(q))
        fprintf(stderr, "오류");
    else
        return q->data[q->rear];
}

main()
{
    QueueType q;
    init_queue(&q);
    int scan, count;

    enqueue(&q, 0); // f(0)=0
    enqueue(&q, 1); // f(1)=1
    
    printf("피보나치 수열 n번째 항의 값 f(n)을 구합니다.\n n을 입력하세요: ");
    scanf("%d", &scan);
    
    if (scan == 0)
        printf("구한 값: %d\n", dequeue(&q));
    else if (scan == 1)
        printf("구한 값: %d\n", peek_rear(&q));
    else
    {
        for (count = 2; count <= scan; count++)
        {
            enqueue(&q, peek_rear(&q) + dequeue(&q));
        }
        printf("구한 값: %d", peek_rear(&q));
    }
}

```



## problem 11

```c
#include "Header_deque.h"

void eliminate(char* str)
{
    for (; *str != '\0'; str++)
    {
        if (*str == '\'' || *str == ' ' || *str == ',')
        {
            strcpy(str, str + 1);
            str--;
        }
    }
}

void main(){
    DequeType dq; 
    init_deque(&dq);

    char input[30];
    printf("문자열을 입력하세요: ");
    scanf("%[^\n]", input);

    strlwr(input);
    eliminate(input); 

    int len = strlen(input);
    for (int count = 0; count < len; count++) 
    {
        add_rear(&dq, input[count]);
    }
    for (int count = 0; count < (len / 2); count++)
    {
        if (delete_front(&dq) != delete_rear(&dq))
        {
            printf("회문이 아닙니다\n");
            exit(1);
        }
        else
            ;
    }
    printf("회문입니다.\n");
}
```



## problem 12

```c

```

