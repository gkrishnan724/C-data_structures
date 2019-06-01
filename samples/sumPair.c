/*
    Given an array, find two numbers that sum to a particular value
    HashMap implementation
    Complexity: O(n) Most likely
*/
#include <stdio.h>
#include "../DS.h"
int main(){
    int arr[MAX_SIZE];
    printf("Enter length of array: ");
    int n;
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    hashMap* map = create_map();
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        add_item(map,arr[i],1);
    }
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    for(int i=0;i<n;i++){
        int searchval = val - arr[i];
        int result = get_item(map,searchval);
        if(result != -234){
            printf("found: %d %d\n",arr[i],searchval);
        }
    }
    return 0;
    
}