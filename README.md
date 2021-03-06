# C-data_structures
Modular Data Structure Implementation in C

Implemented Data structures:
- Linked List
- Stack (Linked List based )
- Queue (Linked List based )
- hashMap 

## How to use

`#include "DS.h"` should get all the data structures included in your program.

### Data Node

```
typedef struct Node{
    int key;
    int val;
    struct Node *next;

}Node;


```

### Linked List

```
typedef struct linkedList{
    Node *head;
    int length;
}linkedList;

```

- `linkedList* create_linked_list()`: Creates a linked list and returns a pointer to the linkedList structure
- `void append(linkedList* list, int value)`: insert item at the end of list. **O(n)**
- `int get(linkedList* list, int index)`: get the value based on index in the list. (returns -234 if not present ) **O(n)**
- `int delete(linkedList* list,int index)`: Delete the element in list given by index. **O(n)**
- `void print_elements(linkedList* list)`: Print all elements of list


### Queue

```
typedef struct queue{
    Node* front;
    Node* back;
    linkedList* list;
}queue;
```
- `queue* create_queue()`: Creates a Queue and returns a pointer to the queue 
- `void append_queue(queue* q,int value)`: Adds an item to the end of the queue. **O(1)**
- `int pop_queue(queue* q)`: removes and returns the item from the front of the queue. (returns -234 if not present ) **O(1)**
- `int get_front(queue* q)` : returns the element at the front of the queue. (returns -234 if not present ) **O(1)**
- `int get_back(queue* q)`: returns the element at the back of the queue. (returns -234 if not present ) **O(1)**
- `void print_queue_elements()`: prints all the elements of the queue.


### Stack

```
typedef struct stack{
    Node* top;
    linkedList* list;
}stack;
```
- `stack* create_stack()`: creates a stack and returns the pointer to the stack.
- `void push_stack(stack* st,int item)`: Adds an item to the top of the stack. **O(1)**
- `int pop_stack(stack* st)`: Removes and returns the item at the top of the stack. (returns -234 if not present ) **O(1)**
- `int get_top(stack* st)`: returns the element from the top of the stack. (returns -234 if not present ) **O(1)**


### HashMap

The structure is pretty much like an array of linkedlists known as `hashMap`

- `hashMap* create_map()`: Creates a hashMap and returns the pointer to the map 
- `void add_item(hashMap* map,int key,int value)`: Adds a (key,value) pair to the hashMap, hashed based on the key **most likely O(1)**
- `int get_item(hashMap* map,int key)`: returns the value of key. (returns -234 if not present ) **most likely O(1)**
- `void remove_item(hashMap* map,int key)`: removes the key value pair from the map  **most likely O(1)**

### Sample Programs

- Bracket Evaluation using Stack [bracketEvaluation.c](https://github.com/gkrishnan724/C-data_structures/blob/master/samples/bracketEvaluation.c)

- Finding pair in an array that sum to a given value using hashMap [sumPair.c](https://github.com/gkrishnan724/C-data_structures/blob/master/samples/sumPair.c)


