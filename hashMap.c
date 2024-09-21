#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[TABLE_SIZE];


int hashFunction(int key){
    return key % TABLE_SIZE;
}

void initHashTable(){
    for (int i = 0; i<TABLE_SIZE; i++){
        hashTable[i]=NULL;
    }
}

HashNode* createHashNode(int key, int value){
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));

    if (!newNode){
        printf("Allocation error.\n");
        exit(1);
    }
    newNode->key=key;
    newNode->value=value;
    newNode->next=NULL;

    return newNode;
}

void insert(int key, int value){
    int newKey = hashFunction(key);
    HashNode* newNode = createHashNode(key, value);
    newNode->next = hashTable[newKey];
    hashTable[newKey]=newNode;
}

int search(int key){
    int hashIndex = hashFunction(key);
    HashNode* temp = hashTable[hashIndex];

    while(temp){
        if(temp->key==key){
            return temp->value;
        }
        temp=temp->next;
    }
    return -1;
}

void delete(int key){
    int hashIndex = hashFunction(key);

    HashNode* temp = hashTable[hashIndex];
    HashNode* prev = NULL;
    while(temp){
        if(temp->key==key){
            if(prev){
                prev->next=temp->next;
            }else{
                hashTable[hashIndex] = temp->next;
            }
            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("No entry at key %d", key);
    return;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp) {
            printf("(Key: %d, Value: %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


main(){
     initHashTable();

    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 40);

    displayHashTable();

    int value = search(21);
    if (value != -1)
        printf("Key 21 found with value %d\n", value);
    else
        printf("Key 21 not found\n");

    delete(11);
    displayHashTable();

    // Free all nodes
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* temp = hashTable[i];
        while (temp) {
            HashNode* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        hashTable[i] = NULL;
    }

    return 0;
}