# chapter6.연결리스트

1. 다음 중 Null포인터가 존재하지 않는 구조는 어느 것인가?

   원형 연결리스트

2. 리스트의 n번째 요소를 가장 빠르게 찾을 수 있는 구현 방법은 무엇인가?

   배열

3. 단순 연결 리스트에서 포인터 last가 마지막 노드를 가리킨다고 할 때 다음 수식 중 참인 것은?

   last->link==null     //last가 마지막노드라서 가리키는 곳이 없음

4. 단순 연결 리스트의 노드들을 포인터 p로 방문하고자 한다. 현재 p가 가리키는 노드에서 다음 노드로 가려면 어떤 코드를 사용해야 하는가?

   p=p->link;

5. 다음과 같이 변수 p가 2를 저장하는 노드를 가리키도록 하는 문장을 작성하라.

   p=p->link;

6. 다음과 같이 변수 q가 1를 저장하는 노드를 가리키도록 하는 문장을 작성하라.

   q=p;

7. 다음과 같은 연결 리스트에 아래와 같은 코드를 실행한다고 하자. 실행이 끝난 후에 포인터 p가 가리키는 노드는 어떤 노드인가?

   D

8. 덱은 삽입과 삭제가 양끝에서 임의로 수행되는 자료구조이다. 다음 그림과 같이 단순 연결 리스트로 덱을 구현한다고 할때 O(1)시간 내에 수행할 수 없는 연산은?

   deleteLast연산 	//deleteLast를 하려면 last가 Xn-1을 가리켜야하기 때문에 DQ~Xn-1까지 탐색하게됨

9. 다음과 같이 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램을 작성하라.

   ```c
   //헤더파일에 추가
   ListNode* reverse(ListNode *head) {
   	ListNode *p, *q, *r;
   	p = head;
   	q = NULL;
   	while (p != NULL) {
   		r = q;
   		q = p;
   		p = p->link;
   		q->link = r;
   	}
   	return q;
   }
   
   void print_list(ListNode *head) {
   	for (ListNode *p = head; p != NULL; p = p->link){
   		if (p->link == NULL) {
   			printf("%d", p->data);
   			break;
   		}
   	printf("%d->", p->data);
   	}
   	//printf("NULL\n");
   }
   //
   //main
   int main(void) {
   	int nodenum, i, node;
   	ListNode *head = NULL;
   	ListNode *reverse_head = NULL;
   
   	printf("노드의 개수 : ");
   	scanf("%d", &nodenum);
   	for (i = 0; i < nodenum; i++) {
   		printf("노드 #%d 데이터 : ",i+1);
   		scanf("%d", &node);
   		head = insert_first(head, node);
   	}
   	reverse_head = reverse(head);
   	print_list(reverse_head);
   	for (i = 0; i < nodenum; i++) {
   		head = delete_first(head);
   	}
   	return 0;
   }
   ```

10. 다음과 같이 단순 연결 리스트의 노드들의 개수를 계산하는 프로그램을 작성해보자.

    ```c
    //헤더파일에 추가
    int node_count(ListNode *head) {
    	int count = 0;
    	while (head != NULL) {
    		head = delete_first(head);
    		count++;
    	}
    	return count;
    }
    //
    //main함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	printf("연결 리스트 노드의 개수 = %d",node_count(head));
    	}
    	return 0;
    }
    ```

11. 단순 연결 리스트에 정수가 저장되어 있다. 연결 리스트에 있는 모든 노드의 데이터 값을 합한 결과를 출력하는 프로그램을 작성하시오.

    ```c
    //헤더파일 추가
    int node_sum(ListNode *head) {
    	int node_sum = 0;
    	for (ListNode *p = head; p != NULL; p = p->link) {
    		node_sum += p->data;
    	}
    	return node_sum;
    }
    //
    //메인함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	printf("연결 리스트 데이터의 합 : %d",node_sum(head));
    	for (i = 0; i < nodenum; i++) {
    		head = delete_first(head);
    	}
    	return 0;
    }
    ```

12. 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수를 작성하라

    ```c
    //헤더파일추가
    int node_search(ListNode *head, int what_search) {
    	int count = 0;
    	for (ListNode *p = head; p != NULL; p = p->link) {
    		if (what_search == p->data) {
    			count++;
    		}
    	}
    	return count;
    }
    //
    //메인함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    	int what;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	printf("탐색할 값을 입력하시오 : ");
    	scanf("%d", &what);
    	printf("%d는 연결 리스트 %d번 나타납니다.", what, node_search(head, what));
    	for (i = 0; i < nodenum; i++) {
    		head = delete_first(head);
    	}
    	return 0;
    }
    ```

13. 단순 연결 리스트에서의 탐색함수를 참고하여 특정한 데이터값을 갖는 노드를 삭제하는 함수를 작성하라.

    ```c
    //헤더파일추가
    ListNode* search_list_delete(ListNode *head, element x) {
    	ListNode *removed=NULL;
    	while (head != NULL) {
    		if (head->data == x) {
    			head = head->link;
    			continue;
    			}
    		else{
    			removed=insert_first(removed, head->data);
    			head = head->link;
    		}
    	}
    	return removed;
    }
    //
    //메인함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    	int what;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	printf("탐색할 값을 입력하시오 : ");
    	scanf("%d", &what);
    	printf("삭제된 리스트 : ");
    	print_list(search_list_delete(head, what));
    	for (i = 0; i < nodenum; i++) {
    		head = delete_first(head);
    	}
    	return 0;
    }
    ```

14.  다음 그림과 같은 데이터를 저장할 수 있는 단순 연결 리스트를 생성하는 프로그램을 작성해보자.

    ```c
    typedef struct ListNode {
    	element data;
    	struct ListNode *link;
    	char Name[10];
    	int age;
    	double height;
    }ListNode;
    ```

15. 단순 연결 리스트가 정렬되지 않은 정수들의 리스트를 저장하고 있다. 리스트에서 최대값과 최소값을 찾는 프로그램을 작성하라.

    ```c
    //헤더파일추가
    int search_min(ListNode *head) {
    	int min = 1000000;
    	while (head != NULL) {
    		if (head->data < min) {
    			min = head->data;
    		}
    		head = head->link;
    	}
    	return min;
    }
    int search_max(ListNode *head) {
    	int max = 0;
    	while (head != NULL) {
    		if (head->data > max) {
    			max = head->data;
    		}
    		head = head->link;
    	}
    	return max;
    }
    //
    //메인함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	printf("최대값:%d 최소값:%d", search_max(head), search_min(head));
    	for (i = 0; i < nodenum; i++) {
    		head = delete_first(head);
    	}
    	return 0;
    }
    ```

16. 단순 연결 리스트의 헤드 포인터가 주어져있을때 첫번째노드에서부터 하나씩 건너서 있는 노드를 전부 삭제하는 함수를 작성하라. 즉 홀수번째 있는 노드들이 전부 삭제된다.

    ```c
    //헤더파일추가
    ListNode* delete_odd(ListNode *head) {
    	ListNode *removed = NULL;
    	while (head != NULL) {
    		head=delete_first(head);
    		if (head == NULL) {
    			break;
    		}
    		else {
    			removed = insert_first(removed, head->data);
    			head = delete_first(head);
    		}
    	}
    	return removed;
    }
    //
    //메인함수
    int main(void) {
    	int nodenum, i, node;
    	ListNode *head = NULL;
    
    	printf("노드의 개수 : ");
    	scanf("%d", &nodenum);
    	for (i = 0; i < nodenum; i++) {
    		printf("노드 #%d 데이터 : ",i+1);
    		scanf("%d", &node);
    		head = insert_first(head, node);
    	}
    	print_list(delete_odd(head));
    	for (i = 0; i < nodenum; i++) {
    		head = delete_first(head);
    	}
    	return 0;
    }
    ```

17. 두 개의 단순연결 리스트 A,B가 주어져 있을 경우,  alternate함수를 작성하라. alternate함수는 A와 B로부터 노드를 번갈아 가져와서 새로운 리스트 C를 만드는 연산이다. 만약 입력리스트중에서 하나가 끝나게 되면 나머지 노드들을 전부 C로 옮긴다. 함수를 구현하여 올바르게 동작하는 지 테스트하라. 작성된 함수의 시간 복잡도를 구하라.

    ```
    ???
    ```

    

