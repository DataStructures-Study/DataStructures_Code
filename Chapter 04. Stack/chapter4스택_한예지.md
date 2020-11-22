10번

```
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
   element *data;
   int capacity;
   int top;
} StackType;

void init_stack(StackType *s) {
   s->top = -1;
   s->capacity = 1;
   s->data = (element *)(malloc)(s->capacity * sizeof(element));
}

void delete(StackType *s) {
   free(s);
}

int is_empty(StackType *s) {
   return (s->top == -1);
}

int is_full(StackType *s) {
   return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {
   if (is_full(s)) {
      s->capacity *= 2;
      s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
   }
   s->data[++(s->top)] = item;
}

element pop(StackType *s) {
   if (is_empty(s)) {
      fprintf(stderr, "스택공백에러\n");
      exit(1);
   }
   else return s->data[(s->top)--];
}

int main(void) {
   StackType s;
   init_stack(&s);
   int n;
   int i;
   int num;

   for (i = 0; i < n; i++) {
      scanf("%d ", &num);
      push(&s, num);
   }
   printf("반전된 정수 배열 : ");
   for (i = 0; i < n; i++) {
      printf("%d ", pop(&s));
   }
   free(s.data);
   delete(&s);
   return 0;
}
```

11번

```

```

12번

```
#include<stdio.h>
#include<string.h>

int main(void) {
   int arr[26][1] = { 0, };
   int i = 0;
   char str[1000];

   printf("문자열을 입력하시오:");
   scanf("%s", str);
   while (i < strlen(str)) {
      //대문자인경우
      if (65 <= str[i] && str[i] <= 90) {
         arr[str[i] - 65][0]++;
      }
      //소문자인경우
      else if (97 <= str[i] && str[i] <= 122) {
         arr[str[i] - 97][0]++;
      }
      i++;
   }
   for (i = 0; i < 26; i++) {
      if (arr[i][0] > 0) {
         printf("%d%c", arr[i][0], i + 97);
      }
   }
   return 0;
}
```

13번

```
#include<stdio.h>
#include<string.h>

int arrin(char a, char b[]) {
   int j = 0;
   while (b[j] != NULL) {
      if (a == b[j]) {
         return 1;
      }
      j++;
   }
   return 2;
}

int main(void) {
   char arr1[100];
   char arr2[100] = "a";

   printf("정수를 입력하세요:");
   scanf("%s", &arr1);

   int k = 1;
   int i = 0;
   while (arr1[i] != NULL) {
      if (arrin(arr1[i],arr2)==2) {
         arr2[k] = arr1[i];
         k++;
      }
      i++;
   }
   
   printf("출력:");
   i = 1;
   while (arr2[i] != NULL) {
      printf("%c", arr2[i]);
      i++;
   }

   return 0;
}
```

14번

```
int stacksize(StackType *s) {
   return s->top+1;
}
```

15번

```
int mazerun(StackType *s, char maze[MAZE_SIZE][MAZE_SIZE]) {
   int r, c;
   while (maze[here.r][here.c] != 'x') {
      r = here.r;
      c = here.c;
      maze[r][c] = '.';
      push_loc(&s, r + 1, c);
      push_loc(&s, r, c + 1);
      push_loc(&s, r - 1, c);
      push_loc(&s, r, c - 1);

      if (is_empty(&s)) {
         return 1;
      }
      else
         here = pop(&s);
   }
   return 2;
}

int main(void) {
   
   StackType s;
   init_stack(&s);
   here = entry;
   if (mazerun(&s, maze) == 1) {
      printf("실패\n");
   }
   else {
      maze_print(maze);
      printf("성공");
   }
   
   return 0;

}
```

16번

```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;
typedef struct {
   element data[100];
   int top;
} StackType;

void init_stack(StackType *s) {
   s->top = -1;
}

int is_empty(StackType *s) {
   return (s->top == -1);
}

int is_full(StackType *s) {
   return (s->top == 99);
}

void push(StackType *s, element item) {
   if (is_full(&s)) {
      fprintf(stderr, "스택포화에러\n");
      return;
   }
   else s->data[++(s->top)] = item;
}

element pop(StackType *s) {
   if (is_empty(&s)) {
      fprintf(stderr, "스택공백에러\n");
      exit(1);
   }
   else return s->data[(s->top)--];
}

element peek(StackType *s) {
   if (is_empty(&s)) {
      fprintf(stderr, "스택 공백에러\n");
      exit(1);
   }
   else return s->data[s->top];
}

int pal(StackType *s1, StackType *s2) {
   while (is_empty(&s1) != 1) {
      if (pop(&s1) == pop(&s2)) {
         continue;
      }
      else {
         return 2;
      }
   }
   return 1;
}

int main(void) {
   char a[1000];
   int i;
   StackType s1;
   StackType s2;
   StackType s3;
   init_stack(&s1);
   init_stack(&s2);
   init_stack(&s3);
   
   printf("문자열을 입력하시오:");
   scanf("%s", &a);

   i = 0;
   while (a[i] != NULL) {
      if (a[i] == ',' || a[i] == ' ') {
         i++;
         continue;
      }
      else if (65 <= a[i] && a[i] <= 90) {
         a[i] += 32;
      }
      push(&s1, a[i]);
      push(&s2, a[i]);
      i++;
   }

   i = 0;
   while (is_empty(&s1)!=1) {
      push(&s3, pop(&s1));
      i++;
   }

   if (pal(&s2, &s3)==1) {
      printf("회문입니다.");
   }
   else {
      printf("회문이 아닙니다.");
   }

   return 0;
}
```

