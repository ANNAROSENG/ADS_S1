#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    int numNodes, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter %d values to insert into the BST:\n", numNodes);
    for (int i = 0; i < numNodes; ++i) {
        printf("Node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}

OUTPUT:
Enter the number of nodes: 4
Enter 4 values to insert into the BST:
Node 1: 2
Node 2: 5
Node 3: 7
Node 4: 3
In-order traversal of the BST: 2 3 5 7
RESULT: Result is generated and CO1 is attained.


Enter the number of nodes: 5
Enter 5 values to insert into the BST:
Node 1: 21
Node 2: 1
Node 3: 0
Node 4: 11
Node 5: 25
In-order traversal of the BST: 0 1 11 21 25 














