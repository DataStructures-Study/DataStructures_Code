# 08트리 연습문제





9> 

이진 탐색 트리는 탐색, 삽입, 삭제연산의 시간 복잡도가 O(h)이다. 

즉 트리의 높이(height)에 따라 수행시간이 결정된다.

n개의 노드를 가지는 이진트리의 높이는 최대 n, 최소 log2(n+2)이므로

평균의 시간복잡도는 logn, 최악의 시간복잡도는 O(n)이다.

or

처음 입력된 개수가 N이라 했을때, 탐색할 자료의 개수는 k번의 시행후 (1/2)k승 N개가 되고

마지막에 남은 자료가 1개 남게 된다.  ( (1/2)k승N =1)

이를 풀면 k=log(2)N 

즉 자료의 개수 N에 따른 시행횟수는 log(2)N이므로 시간 복잡도는 O(logN)이 된다.



13>

균형트리: 모든 노드에 대해 왼쪽 부분트리 높이와 오른쪽 부분트리 높이 차이가 최대 1차이 나는 트리.

왼쪽/오른쪽 서브트리 높이 구하기-> 높이 차 구해 1 이상일 경우 false, 아니면 균형트리

```c
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
} TreeNode;
//		 15
//	 4		 20
// 	1	 	16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;


int get_height(TreeNode* node) //트리의 높이 구하기 
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int isBalanced(TreeNode* node)
{
	int left_height = 0, right_height = 0;

	left_height = get_height(node->left);
	right_height = get_height(node->right);

	if ((left_height - right_height <= 1) && (left_height - right_height >= -1))
		return 1;
	else return 0;
}

int main(void)
{
	if (isBalanced(root) == 1)
		printf("균형 트리입니다.");
	else
		printf("균형 트리가 아닙니다.");

	return 0;
}


```



14>주어진 이진트리에서 노드가 가지고 있는 값의 합을 계산하는 프로그램을 작성해보자. 

8.6참조 (이진탐색트리에서 노드 개수 구하는 알고리즘)

```c
int get_sum(TreeNode* root)
{
    int sum=0;
    
    if(node!=NULL){
        int num=root->data;
        sum=num+get_sum(root->left)+get_sum(root->right);
        
    return sum;
        
    }
}
```



15>주어진 이진트리에서 노드가 가지고 있는 값이 주어진 value보다 작으면 노드의 값을 출력하는 프로그램을 작성해보자.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;

//		 15
//	 4		 20
// 	1	 	16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void smaller_node(TreeNode* root, int value)
{
	if (root == NULL)
		return;
	if (root->data < value)
		printf("%d보다 작은 노드: %d\n", value, root->data);
	smaller_node(root->left, value);
	smaller_node(root->right, value);
}

int main(void)
{
	int value = 0;
	printf("value의 값을 입력하시오 : ");
	scanf_s("%d", &value);
	smaller_node(root, value);
	return 0;
}
```





16>주어진 이진트리에서 자식이 하나만 있는 노드의 개수를 반환하는 함수를 작성하라.

```c
int alone_node_count(TreeNode* node)
{
    int count=0;
    
    if(node!=NULL){
        if(node->left==NULL&&node->right!=NULL)||(node->left!=NULL&&node->right==NULL)
            return 1;
    
        count=alone_node_count(node->left)+alone_node_count(node->right);
     
    }
    return count;
}
```





17>일반 이진트리에서 최대값과 최소값을 탐색하기 위한 함수를 작성하라. 

이진 탐색 트리가 아니다.



```c
#include <stdio.h>
#include <stdlib.h>
#define Max -9999999
#define Min 9999999

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;
//		 15
//	 4		 20
// 	1	 	16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int MAX(int a, int b)
{
	return (a > b ? a : b);
}

int MIN(int a, int b)
{
	return (a > b ? b : a);
}

int find_MaxValue(TreeNode* root)
{

	if (root == NULL)
		return Max;

	int MaxValue = root->data;

	MaxValue = MAX(MaxValue, find_MaxValue(root->left));
	MaxValue = MAX(MaxValue, find_MaxValue(root->right));

	return MaxValue;
}

int find_MinValue(TreeNode* root)
{
	if (root == NULL)
		return Min;

	int MinValue = root->data;

	MinValue = MIN(MinValue, find_MinValue(root->left));
	MinValue = MIN(MinValue, find_MinValue(root->right));

	return MinValue;
}

int main(void)
{
	printf("최소값= %d\n", find_MinValue(root));
	printf("최대값= %d\n", find_MaxValue(root));

	return 0;
}

```





18> 숫자들이 들어있는 이진 탐색 트리를 중위 순회하면 정렬된 숫자가 얻어진다. 이를 이용하여 다음 배열에 들어있는 숫자들을 정렬시키는 함수를 작성하여 보라. 배열에 들어있는 숫자들을 이진 탐색 트리에 추가한 후에 트리를 중위 순회하면서 숫자들을 출력한다. 단 숫자들은 중복되지 않는다고 가정하자.

(8.18 이진탐색트리)

```c

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
} TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	//트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL)
		return new_node(key);

	//그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	//변경된 루트 포인터를 반환한다.
	return node;
}

//중위 순회 오름차순
void inorder(TreeNode* root) {
	if (root) {
	inorder(root->left); //왼쪽 서브트리 순회
	printf("%d ", root->key); //노드 방문
	inorder(root->right); //오른쪽 서브트리 순회
	}
}

	int main(void)
	{
		TreeNode * root = NULL;
		TreeNode * tmp = NULL;

		int list[11] = { 11,3,4,1,56,5,6,2,98,32,23 };
		
		

		for (int i = 0; i < 11; i++) {
			root=insert_node(root, list[i]);
		}

		inorder(root);
		
		return 0;
	}

```



19> 18번은 오름차순으로 정렬시키는 경우이다. 이진 탐색 트리를 이용하여 배열에 저장된 숫자들을 내림차순으로 정렬시키는 함수를 작성하여 보라.

```c
void decreasing_order(TreeNode* root) {
   if (root == NULL)
      return;

   decreasing_order(root->right);
   printf("%d ", root->data);
   decreasing_order(root->left);
}
```





20>이진 탐색 트리의 모든 노드의 값을 1씩 증가시키는 함수를 작성하여 보라.

```c
void increase_one(TreeNode* root)
{
   if(root!=NULL){
      root->data++;
       increase_one(root->right);
       increase_one(root->left);
   }
}
```







21>이진 탐색 트리를 사용하여 우선순위 큐를 구현할 수도 있다. 우선순위 큐란 항목들이 우선순위를 가지고 있고 우선순위가 가장 큰 항목이 먼저 삭제되는 큐이다. 이진 탐색 트리에서 가장 큰 값을 찾으려면 어떻게 해야 하는가?



트리의 오른쪽 자식노드를 계속 따라 내려가 가장 오른쪽 아래에 있는 단말노드를 찾는다. 





22>이진 탐색 트리의 가장 큰 용도가 map이라는 자료구조를 구현하는 것이다. 본문에서 우리는 단어장을 구현해 보았다. 여기서는 이진 탐색 트리를 이용하여 친구들의 연락처 를 저장하고 탐색하는 프로그램을 작성해보자.



```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_NAME_SIZE	 100
#define MAX_PHONE_NUMBER_SIZE 200

// 데이터 형식
typedef struct {
	char name[MAX_NAME_SIZE]; // 키필드
	char phone_number[MAX_PHONE_NUMBER_SIZE];
} element;
// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.name, e2.name);
}
// 이진 탐색 트리 출력 함수
void display(TreeNode* p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.name, p->key.phone_number);
		display(p->right);
		printf(")");
	}
}
// 이진 탐색 트리 탐색 함수
TreeNode* search(TreeNode* root, element key)
{
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; 	// 탐색에 실패했을 경우 NULL 반환
}
TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	// 루트 포인터를 반환한다. 
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		TreeNode* temp = min_value_node(root->right);

		// 중외 순회시 후계 노드를 복사한다. 
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다. 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//
void help()
{
	printf("\n*** i: 저장, d: 삭제, s: 탐색, p: 출력, q:종료 ***: ");
}

int main(void)
{
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		getchar();	// 엔터키 제거
		switch (command) {
		case 'i':
			printf("친구의 이름:");
			 gets(e.name);
			
			printf("친구의 전화번호: ");
			 gets(e.phone_number);
			
			root = insert_node(root, e);
			break;
		case 'd':
			printf("이름:");
			gets(e.name);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("이름:");
			 gets(e.name);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("%s의 전화번호: %s\n", e.name, tmp->key.phone_number);
			else
				printf("%s은(는) 없습니다. \n", e.name);
			break;
		}

	} while (command != 'q');
	return 0;
}

```

