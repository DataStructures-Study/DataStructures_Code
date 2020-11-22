# Chap 10. 그래프1

---------

01.

인접 행렬 adj_mat[][]에서 어떤 정점 v의 진출 차수를 알고 싶으면 어떻게 하면 되는가?

(1) 인접 행렬의 v번째 행의 값들을 전부 더한다.



02.

![image-20201122021218038](C:./kjh_img_and_textfile/image-20201122021218038.png)



03.

원하는 vertex의 항을 다 더하면 된다.



04.

정점의 개수를 n, 간선의 개수가 e인 그래프를 인접 리스트로 표현하였을 경우, 인접 리스트 상 총 노드의 개수는?

(2) 2e개 (무방향 그래프라면)



05.

(2) 너비 우선 탐색



06.

![image-20201122021246702](C:./kjh_img_and_textfile/image-20201122021246702.png)



07.

(1) 각 정점의 진입차수와 진출차수

| vertex   | 0    | 1    | 2    | 3    | 4    | 5    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- |
| 진입차수 | 1    | 2    | 3    | 2    | 3    | 0    |
| 진출차수 | 3    | 2    | 1    | 2    | 2    | 1    |

(2) 각 정점에 인접한 정점들의 집합

| vertex      | 0       | 1     | 2    | 3     | 4      | 5    |
| ----------- | ------- | ----- | ---- | ----- | ------ | ---- |
| 인접 vertex | {1,2,3} | {2,3} | {4}  | {0,4} | {1, 2} | {4}  |

(3) 인접 행렬 표현

![image-20201122021307159](C:./kjh_img_and_textfile/image-20201122021307159.png)

(4) 인접 리스트 표현

![image-20201122021319191](C:./kjh_img_and_textfile/image-20201122021319191.png)

(5) 모든 사이클과 그 길이

| 0 1 3 | 0 3 0 | 0 2 4 1 3 0 | 1 3 0 1 | 1 3 4 1 | 1 2 4 1 | 1 3 0 2 4 1 | 2 4 2 | 2 4 1 2 | 2 4 1 3 0 2 | 3 4 1 3 | 3 0 1 3 | 3 0 2 4 1 3 | 4 1 2 4 | 4 2 4 | 4 1 3 0 2 4 | 4 1 3 4 |
| ----- | ----- | ----------- | ------- | ------- | ------- | ----------- | ----- | ------- | ----------- | ------- | ------- | ----------- | ------- | ----- | ----------- | ------- |
| 30    | 30    | 130         | 85      | 50      | 60      | 130         | 65    | 65      | 130         | 50      | 85      | 130         | 60      | 65    | 130         | 50      |





08.

V = {1, 2, 3, 4, 5}

![image-20201122021352049](C:./kjh_img_and_textfile/image-20201122021352049.png)

09.

방향그래프를 인접 행렬로 표현하고 다음의 함수를 작성

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		printf("정점 개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int s, int e) {
	if (s >= g->n || e >= g->n) {
		printf("정점 번호 오류");
		return;
	}
	g->adj_mat[s][e] = 1;
	//g->adj_mat[e][s] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
```

(1)  주어진 정점의 진출차수(out-degree)를 계산하는 함수

```c
#include "adj_mat.h"

int num_of_outdeg(GraphType* g, int v) {
	int outdeg = 0;
	for (int i = 0; i < g->n; i++)
		if (g->adj_mat[v][i] != 0) outdeg++;
	return outdeg;
}

int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	printf("노드 0의 진출 차수는 : %d\n", num_of_outdeg(g, 0));
	printf("노드 3의 진출 차수는 : %d\n", num_of_outdeg(g, 3));

	free(g);
}
```

시간 복잡도는 O(n)



(2) 주어진 정점의 진입차수(in-degree)를 계산하는 함수

```c
#include "adj_mat.h"

int num_indeg(GraphType* g, int v)
{
	int indeg = 0;
	for (int i = 0; i < g->n; i++)
		if (g->adj_mat[i][v] != 0) indeg++;
	return indeg;
}


int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	printf("노드 0의 진입 차수는 : %d\n", num_indeg(g, 0));
	printf("노드 3의 진입 차수는 : %d\n", num_indeg(g, 3));

	free(g);
}
```

시간 복잡도는 O(n)



(3) 그래프 안에 있는 간선들의 개수를 계산하는 함수

```c
#include "adj_mat.h"

int num_of_edges_in_directed_graph(GraphType* g){
	int edges = 0;
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
			if (g->adj_mat[i][j] != 0) edges++;
	return edges;
}


int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	printf("방향그래프 g의 edge 개수는 : %d\n", num_of_edges_in_directed_graph(g));

	free(g);
}
```

시간 복잡도는 O($n^2$)





10.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		printf("그래프 : 정점 개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산, e를 s의 인접리스트에 삽입한다.(s->e 연결)
void insert_edge(GraphType* g, int s, int e) {
	GraphNode* new_node;
	if (s >= g->n || e >= g->n) {
		printf("그래프 : 정점 번호 오류");
		return;
	}

	new_node = (GraphNode*)malloc(sizeof(GraphNode));
	new_node->vertex = e;
	new_node->link = g->adj_list[s];
	g->adj_list[s] = new_node;
}

// 출력
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* ptr = g->adj_list[i];
		printf("정점 %d의 인접리스트 ", i);
		while (ptr != NULL) {
			printf("-> %d", ptr->vertex);
			ptr = ptr->link;
		}
		printf("\n");
	}
}
```

(1) 주어진 정점의 진출차수(out-degree)를 계산하는 함수

```c
#include "adj_list.h"

int num_of_outdeg(GraphType* g, int v)
{
	int outdeg = 0;
	GraphNode* node = g->adj_list[v];
	while (node != NULL)
	{
		outdeg++;
		node = node->link;
	}
	return outdeg;
}

void main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);

	printf("\n");
	printf("노드 0의 진출 차수는 : %d\n", num_of_outdeg(g, 0));
	printf("노드 3의 진출 차수는 : %d\n", num_of_outdeg(g, 3));

	free(g);
}
```

O(e)

(2) 주어진 정점의 진입차수(in-degree)를 계산하는 함수

```c
#include "adj_list.h"

int num_of_indeg(GraphType* g, int v) {
	int indeg = 0;
	GraphNode* ptr;
	for (int k = 0; k < g->n; k++) {
		ptr = g->adj_list[k];
		while (ptr != NULL)
		{
			if (ptr->vertex == v) indeg++;
			ptr = ptr->link;
		}
	}
	return indeg;
}


void main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);

	printf("\n");
	printf("노드 0의 진입 차수는 : %d\n", num_of_indeg(g, 0));
	printf("노드 3의 진입 차수는 : %d\n", num_of_indeg(g, 3));

	free(g);
}
```

O(n+e)

(3)

```c
#include "adj_list.h"

int num_of_edges_in_directed_graph(GraphType* g)
{
	int edges = 0;
	GraphNode* ptr;

	for (int i = 0; i < g->n; i++) {
		ptr = g->adj_list[i];
		while (ptr != NULL) {
			edges++;
			ptr = ptr->link;
		}
	}
	return edges;
}


void main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);

	printf("방향그래프 g의 edge 개수는 : %d\n", num_of_edges_in_directed_graph(g));

	free(g);
}
```

O(n+e)



11.

3개, 4개, 5개의 정점으로 된 무방향 완전 그래프를 그려보라.

![image-20201122021420035](C:./kjh_img_and_textfile/image-20201122021420035.png)



12.

```C
#include "adj_mat.h"

void read_adjmat_textfile(GraphType* g, char* filename) {
	int val;
	int size;
	FILE* fp = fopen(filename, "r");

	if (fp != NULL) {
		init(g);
		fscanf(fp, "%d", &size);

		for (int a = 0; a < size; a++) {
			insert_vertex(g, a);
		}
		
		for (int i = 0; i < g->n; i++) {
			for (int j = 0; j < g->n; j++) {
				fscanf(fp, "%d", &val);
				if (val != 0)
					insert_edge(g, i, j);
				//val이 0이 아니라면 edge 삽입 연산을 실행
			}
		}
		printf("파일 읽기가 성공적으로 이루어졌습니다.\n");
		fclose(fp);
	}
}

void write_adjmat_textfile(GraphType* g, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp != NULL) {
		fprintf(fp, "%d\n", g->n);

		for (int i = 0; i < g->n; i++) {
			for (int j = 0; j < g->n; j++) {
				fprintf(fp, "%d ", g->adj_mat[i][j]);
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
	}
	printf("파일 쓰기가 성공적으로 이루어졌습니다.\n");
}

void main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));

	read_adjmat_textfile(g, "input.txt");
	printf("\n읽어드린 adj_mat\n<<<<<<<<<<<<<<<<<<<<<<<<\n");
	print_adj_mat(g);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>\n\n");

	write_adjmat_textfile(g, "output.txt");

	free(g);
}
```



13.

(1) 정점 3에서 출발하여 dfs 했을 때 방문 순서

3 1 0 2 4 5 6 7 8 9

(2) 정점 6에서 출발하여 dfs 했을 때 방문 순서

6 5 3 1 0 2 4 7 8 9

(3) 정점 3에서 출발하여 bfs 했을 때 방문 순서

3 1 4 5 0 2 6 7 8 9

(4) 정점 6에서 출발하여 bfs 했을 때 방문 순서

6 5 7 3 8 9 1 4 0 2



14.

```c
#include "adj_mat.h"

#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES] = {0,};
int count = 0;

// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
int countNode_begin_at_v(GraphType* g, int v) {
	int w;

	visited[v] = TRUE;
	count++;
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) {
			countNode_begin_at_v(g, w);
		}
	}
	return count;
}

// edge 삭제
void delete_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "오류\n");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}


void find_bridge(GraphType* g)
{
	int num_of_nodes = countNode_begin_at_v(g, 1);
	count = 0;
	for (int k = 0; k < g->n; k++) {
		visited[k] = 0;
	}

	for (int i = 0; i < num_of_nodes; i++)
		for (int j = i; j < num_of_nodes; j++)
		{
			if (g->adj_mat[i][j] == 1) // i와 j가 연결되어 있다면,
			{
				delete_edge(g, i, j); // 간선 {i,j} 삭제
				int num_of_nodes_after_deletion = countNode_begin_at_v(g, 1); // 삭제 후 vertex 개수 세어봄
				count = 0;
				for (int k = 0; k < g->n; k++) {
					visited[k] = 0;
				}

				if (num_of_nodes != num_of_nodes_after_deletion) {
					printf("%d와 %d사이에 브릿지가 있습니다.\n", i, j);
				}	
				insert_edge(g, i, j); // 삭제 간선 복구
			}
			else // i와 j가 연결되어 있지 않다면,
				continue;
		}
}


int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 10; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 6);
	insert_edge(g, 5, 7);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);
	//print_adj_mat(g);

	find_bridge(g);

	free(g);
}
```



15.

A B E G F C D