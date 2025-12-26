#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *left;
struct node *right;
};

struct node* createNode(int value) {
struct node* n = (struct node*)malloc(sizeof(struct node));
n->data = value;
n->left = n->right = NULL;
return n;
}

struct queue {
struct node* nodes[100];
int front, rear;
};

void initQueue(struct queue* q) { q->front = q->rear = 0; }
int isEmpty(struct queue* q) { return q->front == q->rear; }
void enqueue(struct queue* q, struct node* n) { q->nodes[q->rear++] = n; }
struct node* dequeue(struct queue* q) { return q->nodes[q->front++]; }

void BFS(struct node* root) {
if (!root) return;
struct queue q; initQueue(&q);
enqueue(&q, root);
while (!isEmpty(&q)) {
struct node* cur = dequeue(&q);
printf("%d ", cur->data);
if (cur->left) enqueue(&q, cur->left);
if (cur->right) enqueue(&q, cur->right);
}
}

struct node* buildTree() {
int n, value;
printf("Enter number of nodes: ");
scanf("%d", &n);
if (n <= 0) return NULL;
struct node* nodes[n];
for (int i = 0; i < n; i++) {
printf("Enter value for node %d: ", i + 1);
scanf("%d", &value);
nodes[i] = createNode(value);
}
for (int i = 0; i < n; i++) {
int left = 2*i + 1;
int right = 2*i + 2;
if (left < n) nodes[i]->left = nodes[left];
if (right < n) nodes[i]->right = nodes[right];
}
return nodes[0];
}

int main() {
system("getmac");
struct node* root = buildTree();
printf("BFS (Level-Order) traversal: ");
BFS(root);
printf("\n");
return 0;
}
