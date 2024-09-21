#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data){
    // create new node
    // newNode->next = previous head
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data){
    // create new node
    // find last node
    // last node->next = newNode
    Node* newNode = createNode(data);
    Node* node = *head;
    while(node->next){
        node = node->next;
    }
    node->next = newNode;
}

void deleteNode(Node** head, int key){
    // loop through nodes until you find the one at 'key-1'
    // make that node's next point to the one after 'key'
    // free the memory for the node previously at 'key'

    Node* temp = *head;
    int counter = 0;
    while(temp->next!=NULL && counter<key-1){
        temp = temp->next;
        counter++;
    }
    if(counter<=key-1){
        printf("Element with key %d doesn't exist.\n", key);
        return;
    }
    Node* toDel = temp->next;

    if(toDel->next!=NULL){
        temp->next = toDel->next;
    }else{
        temp->next=NULL;
    }
    free(toDel);

}

void displayList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int listLen(Node** head){
    if(*head==NULL){
        return 0;
    }
    int counter = 1;
    Node* temp = *head;

    while(temp->next != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}
int main(){
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtBeginning(&head, 1);

    displayList(head);

    deleteNode(&head, 3);
    displayList(head);

    printf("Length = %d\n", listLen(&head));
}