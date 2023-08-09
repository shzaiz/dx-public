#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct TreeNode {
    int data;
    int left;
    int right;
};

struct TreeNode tree[MAX_NODES];

int rootNode = -1; // 根节点的索引

// 创建一个新节点
int createNode(int data) {
    if (rootNode == -1) {
        rootNode = 0;
        tree[0].data = data;
        tree[0].left = -1;
        tree[0].right = -1;
        return 0;
    }

    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i].data == 0) {
            tree[i].data = data;
            tree[i].left = -1;
            tree[i].right = -1;
            return i;
        }
    }

    return -1; // 数组已满
}

// 添加左子节点
void addLeft(int parentIdx, int data) {
    if (parentIdx >= 0 && parentIdx < MAX_NODES) {
        int childIdx = createNode(data);
        tree[parentIdx].left = childIdx;
    }
}

// 添加右子节点
void addRight(int parentIdx, int data) {
    if (parentIdx >= 0 && parentIdx < MAX_NODES) {
        int childIdx = createNode(data);
        tree[parentIdx].right = childIdx;
    }
}

// 先序遍历
void preorderTraversal(int idx) {
    if (idx != -1) {
        printf("%d ", tree[idx].data);
        preorderTraversal(tree[idx].left);
        preorderTraversal(tree[idx].right);
    }
}

// 中序遍历
void inorderTraversal(int idx) {
    if (idx != -1) {
        inorderTraversal(tree[idx].left);
        printf("%d ", tree[idx].data);
        inorderTraversal(tree[idx].right);
    }
}

// 后序遍历
void postorderTraversal(int idx) {
    if (idx != -1) {
        postorderTraversal(tree[idx].left);
        postorderTraversal(tree[idx].right);
        printf("%d ", tree[idx].data);
    }
}

int main() {
    int root = createNode(1);
    addLeft(root, 2);
    addRight(root, 3);
    addLeft(tree[root].left, 4);
    addRight(tree[root].left, 5);

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
