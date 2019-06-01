

//Structure Declaration

typedef struct queue{
    Node* front;
    Node* back;
    linkedList* list;
}queue;

//Function prototypes
queue* create_queue();
void append_queue(queue*,int);
int pop_queue(queue*);
int get_front(queue *);
int get_back(queue *);
void print_queue_elements();

//Function definitions

queue* create_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->list = create_linked_list();
    q->front = q->list->head;
    q->back = NULL;
}

void append_queue(queue* q,int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;
    if(q->back == NULL){
        q->list->head = newnode;
        q->back = newnode;
    }
    else{
        q->back->next = newnode;
        q->back = newnode;
    }
    q->front = q->list->head;
}

int pop_queue(queue *q){
    if(q->list->length == 0){
        return -234;
    }
    else{
        int val = q->front->val;
        q->list->head = q->list->head->next;
        q->list->length -= 1;
        q->front = q->list->head;
        if(q->list->length == 0){
            q->back = q->front;
        }

        return val;
    }
}

int get_front(queue *q){
    if(q->front != NULL){
        return q->front->val;
    }
    else{
        return -234;
    }
}

int get_back(queue *q){
    if(q->back != NULL){
        return q->back->val;
    }
    else{
        return -234;
    }
}

void print_queue_elements(queue *q){
    print_elements(q->list);
}