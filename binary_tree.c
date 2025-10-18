#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* Build_BT(char** arr, int len) {
    if (len == 0 || strcmp(arr[0], "N") == 0) {
        return NULL;
    }
    
    struct Node* root = createNode(atoi(arr[0]));
    struct Node** q = (struct Node**)malloc(len * sizeof(struct Node*));
    int front = 0, rear = 0;
    
    q[rear++] = root;
    
    int ptr = 1;
    while (front < rear && ptr < len) {
        struct Node* node = q[front++];
        
        if (ptr < len && strcmp(arr[ptr], "N") != 0) {
            node->left = createNode(atoi(arr[ptr]));
            q[rear++] = node->left;
        }
        ptr++;
        
        if (ptr < len && strcmp(arr[ptr], "N") != 0) {
            node->right = createNode(atoi(arr[ptr]));
            q[rear++] = node->right;
        }
        ptr++;
    }
    
    free(q);
    return root;
}

void BFS_levelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    struct Node** q = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    
    q[rear++] = root;
    
    while (front < rear) {
        struct Node* node = q[front++];
        printf("%d ", node->data);
        
        if (node->left != NULL) {
            q[rear++] = node->left;
        }
        if (node->right != NULL) {
            q[rear++] = node->right;
        }
    }
    
    printf("\n");
    free(q);
}

int MaxHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int lh = MaxHeight(root->left);
    int rh = MaxHeight(root->right);
    
    return 1 + (lh > rh ? lh : rh);
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    
    char** arr = (char**)malloc(100 * sizeof(char*));
    int count = 0;
    
    char* token = strtok(input, " \n");
    while (token != NULL) {
        arr[count] = (char*)malloc(strlen(token) + 1);
        strcpy(arr[count], token);
        count++;
        token = strtok(NULL, " \n");
    }
    
    struct Node* root = Build_BT(arr, count);
    BFS_levelOrder(root);
    
    int height = MaxHeight(root);
    printf("Maximum Height = %d\n", height);
    
    freeTree(root);
    for (int i = 0; i < count; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
