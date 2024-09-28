#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
} QueueNode;

QueueNode* createNode(int value){
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void appendNode(QueueNode** head, int value){
    QueueNode* newNode = createNode(value);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    QueueNode* tmp = *head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next = newNode;
}

void popNode(QueueNode** head){
    if(*head==NULL){
        printf("No nodes in the queue, nothing to pop.\n");
        return;
    }
    QueueNode* toPop = *head;
    if(toPop->next==NULL){
        *head=NULL;

    }else{
    *head = toPop->next;
    }
    printf("Popped node with value %d.\n", toPop->data);
    free(toPop);
    return;
}

void printQueue(QueueNode* head){
    if(head==NULL){
        printf("No nodes to print.\n");
        return;
    }
    QueueNode* tmp=head;
    while(tmp){
        printf("%d -> ", tmp->data);
        tmp=tmp->next;
    }
    printf("NULL\n");
}

int main(){
    QueueNode *head = NULL;

    appendNode(&head, 4);
    appendNode(&head, 5);
    printQueue(head);
    popNode(&head);
    printQueue(head);
    popNode(&head);
    printQueue(head);
    return 0;
}