#include<stdio.h>
#include<stdlib.h>

typedef struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
} binaryTreeNode;

binaryTreeNode* createNode(int value){
    binaryTreeNode* newNode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void insertLeft(binaryTreeNode* node, int value){
    binaryTreeNode* newNode = createNode(value);
    node->left = newNode;
}

void insertRight(binaryTreeNode* node, int value){
    binaryTreeNode* newNode = createNode(value);
    node->right= newNode;
}

binaryTreeNode* findPlaceToInsert(binaryTreeNode* root, int value){
    if(root==NULL){
        return root;
    }
    binaryTreeNode* tmp = root;
    while(tmp!=NULL){
        if(tmp->data <= value){
            if(tmp->right!=NULL){
                tmp=tmp->right;
            }else{
                return tmp;
            }
        }else if(tmp->data > value){
            if(tmp->left!= NULL){
            tmp=tmp->left;
            }else{
                return tmp;
            }
        }
    }
    return tmp;
}

void insert(binaryTreeNode* root, int value){
    binaryTreeNode *nodeToInsertAt = findPlaceToInsert(root, value);
    binaryTreeNode *newNode = createNode(value);
    if(nodeToInsertAt->data>value){
        nodeToInsertAt->left = newNode;
    }else{
        nodeToInsertAt->right = newNode;
    }
}

void preorderTraversal(struct binaryTreeNode* root) {
  if (root == NULL) return;
  printf("%d -> ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
  printf("NULL\n");
}

int main(){
    binaryTreeNode *root = createNode(5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 3);
    insert(root, 4);
    preorderTraversal(root);
    printf("%d", root->right->data);
    return 0;
}