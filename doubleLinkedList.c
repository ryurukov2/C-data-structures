#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode
{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

// createNode
DLLNode *createNode(int value)
{
    DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insert at start
void insertAtStart(DLLNode **head, int value)
{
    DLLNode *newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// insert at end
void insertAtEnd(DLLNode **head, int value)
{
    DLLNode *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    DLLNode *tmp = *head;

    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
// delete
void deleteNode(DLLNode **head, int key)
{
    int counter = 0;
    DLLNode *tmp = *head;
    while (tmp)
    {
        if (counter == key)
        {
            if (tmp->next)
            {
                tmp->next->prev = tmp->prev;
            }
            if (tmp->prev)
            {
                tmp->prev->next = tmp->next;
            } else {
                *head = tmp->next;
            }
            free(tmp);
            return;
        }
        tmp = tmp->next;
        counter++;
    }
    printf("Item with key %d not found\n", key);
}
// display
void displayDLL(DLLNode *head)
{
    DLLNode *tmp = head;
    while (tmp)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

int main()
{
    DLLNode *head = NULL;

    insertAtStart(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 25);
    deleteNode(&head, 5);
    displayDLL(head);

    return 0;
}