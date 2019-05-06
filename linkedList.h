#include <stdio.h>
#include <stdlib.h>

//Struct declarations
typedef struct Node{
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







