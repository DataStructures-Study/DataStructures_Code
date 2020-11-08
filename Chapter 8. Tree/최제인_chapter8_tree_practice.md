##### 13

```c
int isBalanced(TreeNode* root) {
	//왼쪽 
	if (root == NULL) return 1;
	if (abs(count(root->right) - count(root->left)) < 2 && isBalanced(root->right) && isBalanced(root->left)) {
		return 1;
	}
	else { return 0; }
}//이 함수도 똑같이 순환함수로 서브트리의 서브 트리도 있으니 트리마다 검사해야한다.
int count(TreeNode* root) {
	
	if (root == NULL)
		return 0;
	int result = (count(root->left) > count(root->right)) ? count(root->left) : count(root->right);
	return(1 + result);
}
```



##### 14

```c
int makeSum(TreeNode* root) {
	int left_size, right_size;
	if (root == NULL) return 0;

	left_size = makeSum(root->left);
	right_size = makeSum(root->right);
	return(root->key + left_size + right_size);

}
```



##### 15

```c
void find_smaller_than_value(TreeNode* root, int value) {
	if (root == NULL)
		return;
	if (root->key < value)
		printf("%d보다 작은 노드 :  %d\n", value, root->key);
	find_smaller_than_value(root->left, value);
	find_smaller_than_value(root->right, value);
}
```



##### 16

```c
int numOneNode(TreeNode* root) {

	if (root == NULL)
		return 0;
	int count = 0;
	if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL)) {
		count++;
	}
	return(count + numOneNode(root->left) + numOneNode(root->right));

}
```



##### 17

```c
int findMax(TreeNode* root) {

	int result;
	if (root == NULL) return -999999;
	int maxValue = root->data;
	maxValue = max(maxValue, findMax(root->left));
	maxValue = max(maxValue, findMax(root->right));

	return maxValue;
}
int findMin(TreeNode* root) {
	
	if (root == NULL) return 999999;
	int minValue = root->data;
	minValue = min(minValue, findMin(root->left));
	minValue = min(minValue, findMin(root->right));

	return minValue;

}
```



##### 18

```c
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("[%d] ", root->key);  // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}
int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	int arr[11] = { 11,3,4,1,56,5,6,2,98,32,23 };
	for (int i = 0;i < 11;i++) {
		root = insert_node(root, arr[i]);
	}
	inorder(root);

	return 0;
}
```



##### 19

```c
void inorder2(TreeNode* root) {
	if (root) {
		inorder2(root->right);// 왼쪽서브트리 순회
		printf("[%d] ", root->key);  // 노드 방문
		inorder2(root->left);// 오른쪽서브트리 순회
	}
}
```



##### 20

```c
void plus(TreeNode* root) {
	if (root != NULL) {
		root->data += 1;
		plus(root->right);
		plus(root->left);

	}
}
```



##### 21

```c
TreeNode* max_value_node(TreeNode* node) {
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->right != NULL)
		current = current->right;

	return current;

}
```



##### 22

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct TreeNode {
	char name[10];
	char num[15];
	struct TreeNode* left, * right;
} TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, char name[])
{
	if (node == NULL) return NULL;
	if (strcmp(name, node->name) == 0) return node;
	else if (strcmp(name, node->name) < 0)
		return search(node->left, name);
	else {
		return search(node->right, name);
	}
}
TreeNode* new_node(char name[],char num[])
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(temp->name,name);
	strcpy(temp->num,num);
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, char name[], char num[])
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(name,num);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (strcmp(name,node->name)<0)
		node->left = insert_node(node->left, name ,num);
	else if (strcmp(name, node->name) > 0)
		node->right = insert_node(node->right, name,num);

	// 변경된 루트 포인터를 반환한다. 
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
TreeNode* delete_node(TreeNode* root, char name[], char num[])
{
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (strcmp(name, root->name) <0)
		root->left = delete_node(root->left, name, num);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (strcmp(name, root->name) > 0)
		root->right = delete_node(root->right, name, num);
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
		strcpy(root->name, temp->name);
		strcpy(root->num, temp->num);

		// 중외 순회시 후계 노드를 삭제한다. 
		root->right = delete_node(root->right, temp->name,temp->num);
	}
	return root;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("친구의 이름 : %s \n", root->name);  // 노드 방문
		printf("친구의 전화번호 : %s \n", root->num);  // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	
	char name[10];
	char num[16];
	TreeNode* find = NULL;
	while(1){
		
		printf("삽입(i),탐색(s),삭제(d): ");
		char ans;
		scanf("%c", &ans);
		
		if (ans == 'i') {
			
			printf("친구의 이름 :");
			scanf("%s", name);
			printf("친구의 전화번호 :");
			scanf("%s", num);
			root = insert_node(root, name, num);
		}
		else if (ans == 's') {
			printf("친구의 이름 :");
			scanf("%s", name);
			find = search(root,name);
			if (find != NULL) {
				printf("%s의 전화번호:%s \n", name, find->num);
			}
			else {
				printf("번호가 없습니다.\n");
			}
		}
		else if (ans == 'd') {
			printf("친구의 이름 :");
			scanf("%s", name);
			find = search(root, name);
			if (find != NULL) {
				root = delete_node(find, name, num);
				printf("삭제되었습니다.\n");
			}
			else {
				printf("번호가 없습니다.\n");
			}
			
		}
		else {
			break;
		}
		getchar();
	} 
	return 0;
}
```



##### 



