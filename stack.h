

//Struct declaration

typedef struct stack{
    Node* top;
    linkedList* list;
}stack;

//Function prototypes

stack* create_stack();
void push_stack(stack*,int);
int pop_stack(stack*);
int get_top(stack*);

//Function definitons

stack* create_stack(){
    stack* st = (stack*)malloc(sizeof(stack));
    st->list = create_linked_list();
    st->top = NULL;
    return st;
}

void push_stack(stack* st,int val){
    if(st->list->length == 0){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->val = val;
        temp->next = st->top;
        st->top = temp;
        st->list->head = temp;
        st->list->length += 1;
    }
    else{
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->val = val;
        temp->next = st->top;
        st->top = temp;
        st->list->length += 1;
    }
     
}

int pop_stack(stack* st){
    if(st->list->length == 0){
        return -234;
    }
    else{
        int val = st->top->val;
        st->top = st->top->next;
        st->list->length -= 1;
        return val;
    }
}

int get_top(stack* st){
    if(st->list->length == 0){
        return -234;
    }
    else{
        return st->top->val;
    }
}