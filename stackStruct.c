#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

StackNode* createNode(int value){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

StackNode* getLastNode(StackNode* head){
    if(head==NULL){
        return head;
    }
    StackNode *tmp = head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    return tmp;
}
void addNewNode(StackNode** head, int value){
    StackNode *newNode = createNode(value);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    StackNode *lastNode = getLastNode(*head);

    lastNode->next = newNode;
}

void popNode(StackNode** head){
    if(*head==NULL){
        printf("Stack empty, nothing to pop.\n");
        return;
    }
    StackNode *tmp = *head;
    if(tmp->next==NULL){
        printf("Popped element with value {%d}.\n", tmp->data);
        *head=NULL;
        free(tmp);
        return;
    }
    StackNode *toDelete;
    while(tmp->next!=NULL){
        if(tmp->next->next==NULL){
            toDelete = tmp->next;
            printf("Popped element with value {%d}.\n", toDelete->data);
            tmp->next = NULL;
            free(toDelete);
            return;
        }
        tmp=tmp->next;
    }
}
void printStack(StackNode* head){
    if(head == NULL){
        printf("Stack is empty, nothing to print.\n");
        return;
    }
    StackNode *tmp = head;
    while(tmp!=NULL){
        printf("%d -> ", tmp->data);
        tmp=tmp->next;
    }
    printf("NULL\n");
}

int main(){
    StackNode *head = NULL;

    addNewNode(&head, 5);
    addNewNode(&head, 2);
    addNewNode(&head, 3);
    popNode(&head);
    printStack(head);
    return 0;
}