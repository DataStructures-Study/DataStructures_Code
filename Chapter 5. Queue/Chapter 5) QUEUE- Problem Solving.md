## Chapter 5) QUEUE- Problem Solving

#### 1번~7번은 풀이 생략

-----------

##### 8번) 원형큐에 존재하는 요소의 개수를 반환하는 get_count 함수를 구현하라

```c
//sol) 본문에 나온 do-while 문을 활용한 방법
int get_count(QueueType* q)
{
    int count=0;
    int i=q->front;
    if(is_empty(q))
        return 0;
    do{
        i=(i+1)%MAX_QUEUE_SIZE;
        count++;
        if(i==q->rear)
            break;
    }while(i!=q->front);
    return count;
}
//sol2) 단순히 front와 rear값만으로 요소 개수 구하는 방법
int get_count(QueueType* q)
{
    if(q->rear > q->front)
        return (q->rear)-(q->front);
    else
        return (q->rear)+MAX_QUEUE_SIZE-(q->rear);
}
```

##### 9번) 스택 2개로 큐 구현하기

입력이 들어오면 스택1에 넣고, 출력 요청이 들어오면 스택2에서 요소를 꺼낸다.

`생각의 흐름`

> keypoint : 우선 main함수 내에서 어떤 연산을 수행할 것인지부터 생각해보자
>
> 결론적으로 구현해야하는 것은 큐와 큐의 연산들이다. 처음에  큐를 초기화하는 함수가 올텐데, 이때 각각의 스택을 따로 구현하는 것보단 한 번에 초기화할 수 있도록 하자. 
>
> 그럼 한 번에 초기화 하려면 ? > 두 개의 스택을 멤버변수로 갖는 구조체를 생성하고 이를 큐로 생각하자.

-------

> 큐에 원소를 삽입하는 함수는 실제로는 큐의 멤버변수인 스택에 원소를 삽입한다. 따라서 스택에 원소를 삽입하는 과정을 따로 함수로 만들면, 연산자 우선 순위를 따지지 않아도 된다.

```c
#include <stdio.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 요소 개수

//스택을 나타내는 구조체
typedef struct ArrayStack
{
    int data[MAX_STACK_SIZE];
    int top=-1;
}StackType;
//스택의 공백상태 확인 함수(스택1에서 스택2로 요소들을 옮길때 사용)
int is_empty(StackType* s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
//큐 초기화 함수
//연산자 우선 순위에 따르면, '->'와 '.' 연산자는 우선 순위가 같으며 결합 법칙은 왼쪽에서 오른쪽 방향이다.
init(QueueType *q)
{
    q->s1.top=-1; // q->s1->top=-1; 도 가능하다.
    q->s2.top=-1; // q->s2->top=-1;
}
//큐 삽입 함수(version1) > s1에 삽입한다.
void q_push(QueueType* q, int item)
{
    (q->s1->top)++;
    q->s1->data[q->s1->top]=item;
}

//큐 삽입 함수(version2) -- 스택에 원소를 넣는 과정을 따로 함수로 분리한다.
void s_push(StackType* s, int item)
{
    s->data[++(s->top)]=item;
}
void q_push(QueueType *q, int item)
{
    s_push(q->s1,item);
}

//큐 삭제 함수(version2만 게시)
int s_pop(StackType* s)
{
    int item=s->data[s->top];
    s->data[s->top]=0;
    (s->top)--;
    return item;
}
int q_pop(QueueType* q) // 스택2가 비어있을때만 스택1의 요소를 모두 스택2로 옮긴다.
{
    if(is_empty(q->s2))
    {
        while(!is_empty(q->s1))
        {
            s_push(q->s2,s_pop(q->s1));
        }
    }
    return s_pop(q->s2);
}

//큐 구조체의 멤버로 두 개의 스택을 쓰자
//큐 구조체 내에서 스택 구조체의 포인터 변수들을 선언하자.
typedef struct Stack_Queue
{
    StackType* s1,s2;
}QueueType;

int main(void)
{
    QueueType q1; 
    init(&q1); 
    q_push(&q1,10);
    q_push(&q1,20);
    q_push(&q1,40);
    
    printf("%d",q_pop());
    
    return 0;
}
```

##### 10번) 큐를 이용한 피보나치 수열 계산 프로그램

F(n)값을 구할때, F(n-1)과 F(n-2) 값이 큐에 들어가 있으며, F(n)을 계산할때 F(n-2)를 우선적으로  제거하고, 계산한 다음 F(n)을 넣는다. (f(0)=f(1)=1)

int형은 4byte(=32비트)로, -2^31~2^31-1(21474836)까지 표현가능하다. 따라서 피보나치 수열의 항을 표현하는데에는 한계가 있다.

> 문제 조건에 의하면 , 큐의 원소 개수가 2개로 일정하다. 

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 
//============== 원형 큐 소스 코드 시작 ================
//....
//============== 원형 큐 소스 코드 끝 ==================
int fibonachi(QueueType* q, int num)
{
    for(int i=2;i<=n;i++)
    {
        int out=dequeue(q);
        push(q,out+q->data[q->rear]);
    }
}
int main(void)
{
    QueueType q;
    q_init(&q);
    
    //덱에 f(0)과 f(1)값을 넣어둔다.
    push(&q,0);
    push(&q,1);
    int number;
    scanf("%d",&number);
    if(number==0 || number==1)
        printf("%dth fibonachi number is 1");
    else
    	printf("%dth fibonachi number is %d",number,fibonachi(&q,number));
    return 0;
}
```

##### 11번) 덱을 이용하여 주어진 문자열이 회문인지 아닌지를 결정하는 프로그램

`생각의 흐름`

> 우선 문자열을 매개변수로 받고, 함수 내에서 문자열이 회문인지 아닌지 판단해서 출력까지 하는 함수를 설계하는 것이 목표이다.
>
> -----------
>
> 함수 내에서 덱을 생성하고, 반복문을 통해 add_rear함수로 문자열을 이루는 문자들을 모두 덱에 삽입한다. 이후 덱의 rear와 front 부분에서 각각 문자를 빼내서 같은지 비교한다.
>
> 문자열의 길이가 짝수/홀수 일때 모두 회문 구조가 가능한데, 두 경우의 조건을 하나로 합치는게 가능하므로 문제될 것은 없다.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
//================= 원형 큐(덱) 함수들 =================
typedef struct ArraryDeque
{
    char data[MAX_SIZE];
    int front,rear; // 덱에서도 두 개의 변수를 사용한다.
}DequeType;
//초기화 함수
void dq_init(DequeType * dq)
{
    dq->front=dq->rear=0;
}
//에러 표시 함수
void error(char * message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}
//덱 공백상태 검출 함수
int is_empty(DequeType *dq)
{
	if(dq->front==dq->rear)
        return 1;
    else
        return 0;
}
//덱 포화상태 검출 함수
int is_full(DequeType *dq)
{
    if(dq->front==(dq->rear+1)%MAX_SIZE)
        return 1;
    else
        return 0;
}
//덱 전단 삽입 함수
void add_front(DequeType *dq,char item)
{
    if(is_full(dq))
        error("덱이 포화상태입니다.");
    dq->front=(dq->front-1+MAX_SIZE)%MAX_SIZE;
    dq->data[dq->front]=item;
}
//덱 후단 삽입 함수
void add_rear(DequeType *dq, char item)
{
    if(is_full(dq))
        error("덱이 포화상태입니다.");
    dq->rear=(dq->rear+1)%MAX_SIZE;
    dq->data[dq->rear]=item;
}
//덱 전단 삭제 함수
int delete_front(DequeType *dq)
{
    if(is_empty(dq))
        error("덱이 공백상태입니다.");
     dq->front=(dq->front+1)%MAX_SIZE;
    return dq->data[dq->front];
}
//덱 후단 삭제 함수
int delete_rear(DequeType *dq)
{
    if(is_empty(dq))
        error("덱이 공백상태입니다.");
    dq->rear=(dq->rear-1+MAX_SIZE)%MAX_SIZE;
    return dq->data[dq->rear];
}
//회문 검사 함수
void is_pelindrome(char word[])
{
    int i=0; //반복문을 돌릴때 index값으로 쓰이는 변수
    int count=0; //회문을 판단할때 쓰이는 변수 = 문자열의 길이(단, 영어 대소문자만 취급)
    DequeType dq;
    dq_init(&dq);
    
    while(word[i]!=NULL)
    {
        if('a'<=word[i] && word[i]<='z')
            add_rear(&dq,word[i]);
        	count++;
        else if('A'<=word[i] && word[i]<='Z')
            add_rear(&dq,word[i]);
        	count++;
        i++;
    }
    //count변수에서 2씩 감소시킴(전단과 후단에서 동시에 삭제하므로)
    while(count!=0 && count!=1)
    {
        if(delete_front(dq)!=delete_rear(dq))
        {
            printf("회문 구조가 아닙니다.\n");
            break; //while문을 빠져나간다.
        }
        count=count-2;
    }
     printf("회문 구조입니다.\n");
}
//main 함수
int main(void)
{
    char word1[20]="eye";
    char word2[20]="apple";
    char word3[20]="madam";
    char word4[20]="ma!!#$dam";
    char word5[20]="radar;;;";
    
    is_pelindrome(word1); //배열(문자열)은 변수 이름 자체가 주소를 담고 있기 때문에 포인터로 사용가능
    is_pelindrome(word2);
    is_pelindrome(word3);
    is_pelindrome(word4);
    is_pelindrome(word5);
    return 0;
}
```



##### 12번) 태스크 스케줄링 알고리즘(A-Steal algorithm) 구현

A-steal 알고리즘에서 각각의 cpu는 자신이 실행할 태스크가 저장된 덱을 갖고 있다. 하나의 cpu가 자신의 태스크를 종료했다면 cpu가 실행할 태스크를 훔쳐서 실행가능하다. 이때 다른 cpu의 덱의 끝에 있는 요소를 가져온다.

`문제를 간략화하기 위한 몇 가지 가정들`

> - 특정 cpu의 태스크가 종료되었는지 판단하는 변수를 flag라 두면 flag=0일때 작업이 끝난 상태이며, flag=1일때는 작업이 끝나지 않는 상태라고 판단하자.
>
> - cpu의 index 값은 1부터 10(혹은 사용자 입력에 의존)까지 존재하며, 작업을 단순히 정수 형의 data를 index가 1인 cpu부터 덱에 넣는 과정으로 생각하자
> - 다음 index의 cpu가 실행할 태스크를 훔칠때, 훔칠 cpu의 index를 srand(),rand()함수를 이용해서 랜덤하게 가져오자(난수 생성)
> - 앞의 cpu의 작업이 완료되면, delete_rear함수에 의해 두 번째 cpu가 랜덤하게 큐 요소를 가져오게 된다.(처음 작업에서는 두 번째 cpu가 index값이 1인 cpu를 고르지 않을 수도 있으므로, 큐들이 비어있을 수 도 있다. 이 경우, 랜덤하게 선택된 index의 cpu에 훔칠 태스크(요소)가 없는 경우, is_empty()함수를 써서 다시 난수를 생성할 수 있도록 하자.)