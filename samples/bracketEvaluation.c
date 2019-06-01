/*
    Program to evaluate if parenthesis order is correct
*/
#include <stdio.h>
#include "../DS.h"
int main(){
    stack* st = create_stack();
    char str[MAX_SIZE];
    printf("Enter brackets: ");
    scanf("%s",str);
    int i = 0;
    char chr;
    while(str[i] != '\0'){
        chr = str[i];
        if(chr == '(' || chr  == '[' || chr == '{'){
            push_stack(st,chr);
        }
        else if((chr == ')' && get_top(st) == '(') ||  (chr == ']' && get_top(st) == '[') || (chr == '}' && get_top(st) == '{')){
            pop_stack(st);
        }
        else{
            printf("Not balanced\n");
            return 0; 
        }
        
        i++;
    }
    if(st->list->length == 0){
        printf("Balanced \n");
        return 0;
    }
}