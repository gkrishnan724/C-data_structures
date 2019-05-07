#include <stdlib.h>

//Struct declarations
typedef struct Node{
    int key;
    int val;
    struct Node *next;

}Node;

typedef struct linkedList{
    Node *head;
    int length;
}linkedList;

//Function prototypes
linkedList* create_linked_list();
Node* append(linkedList*,int);
void print_elements(linkedList*);
void append_map(linkedList*,int,int);
int get(linkedList*,int);
int get_from_key(linkedList*,int);
void delete_from_key(linkedList*,int);
void delete(linkedList*,int);

//Function definition
linkedList* create_linked_list(){
    linkedList* list = (linkedList*)malloc(sizeof(linkedList));
    list->length = 0;
    list->head = NULL;
    return list;
}

Node* append(linkedList* list,int value){
    if(list->length == 0){
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->val = value;
        newnode->next = NULL;
        list->length += 1;
        list->head = newnode;
        return list->head;
    }

    Node* head = list->head;
    Node* curr = head;
    while(curr->next != NULL){
        curr  = curr->next;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = value;
    newnode->next = NULL;
    curr->next = newnode;
    list->length += 1;
    return newnode;
}

void append_map(linkedList* list,int key,int value){
    if(list->length == 0){
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->val = value;
        newnode->key = key;
        newnode->next = NULL;
        list->length += 1;
        list->head = newnode;
    }

    Node* head = list->head;
    Node* curr = head;
    while(curr->next != NULL){
        curr  = curr->next;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->val = value;
    newnode->next = NULL;
    curr->next = newnode;
    list->length += 1;
    
}

void print_elements(linkedList* list){
    Node* head = list->head;
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}

int get(linkedList* list,int index){
    int cnt = 0;
    Node *head = list->head;
    while(cnt < index && head != NULL){
        head = head->next;
        cnt += 1;
    }
    if(head == NULL){
        return -234;
    }
    else{
        return head->val;
    }
}

void delete(linkedList * list,int index){
    int cnt = 0;
    Node *head = list->head;
    Node *prev = head;
    while(cnt < index && head != NULL){
        prev = head;
        head = head->next;
        cnt += 1;
    }
    if(head == NULL){
        return;
    }
    else{
        prev->next = head->next;
        head->next = NULL;
        free(head);
        list->length -= 1;
    }
}


int get_from_key(linkedList* list,int key){
    Node* head = list->head;
    while(head != NULL && head->key != key){
        head = head->next;
    }
    if(head == NULL){
        return -234;
    }
    else{
        return head->val;
    }
}

void delete_from_key(linkedList* list,int key){
    Node *head = list->head;
    Node *prev = head;
    while(head != NULL && head->key != key){
        prev = head;
        head = head->next;
    }
    if(head == NULL){
        return;
    }
    else{
        prev->next = head->next;
        head->next = NULL;
        free(head);
        list->length -= 1;

    }
}