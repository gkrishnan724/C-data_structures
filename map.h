
//Structure Declaration
#define MAX_SIZE 10000

//Uses Chaining for collision

typedef linkedList hashMap;

//Function prototype
hashMap* init_map();
int hash_function(int);
int get_item(hashMap*,int);
void add_item(hashMap*,int,int);
void remove_item(hashMap*,int);

//Function definitions
int hash_function(int key){
    return key%MAX_SIZE;
}

hashMap* init_map(){
    hashMap* map = (hashMap*)malloc(MAX_SIZE*sizeof(linkedList));
    return map;
}

void add_item(hashMap* map,int key,int value){
    int index = hash_function(key);
    append_map(&map[index],key,value);
}

int get_item(hashMap* map,int key){
    int index = hash_function(key);
    int item = get_from_key(&map[index],key);
    return item;
}

void remove_item(hashMap* map,int key){
    int index = hash_function(key);
    delete_from_key(&map[index],key);
}