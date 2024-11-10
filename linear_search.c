#include<stdio.h>

int main() {
    int a[10], n, i, item, flag = 0; // Declare variables

    printf("Program for linear search\n");
    
    // Input array size
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Input the element to search for
    printf("Enter the element to be searched: ");
    scanf("%d", &item);
    
    // Linear search algorithm
    for(i = 0; i < n; i++) {
        if(a[i] == item) { // Check if current element matches the search item
            printf("Item found at position %d\n", i + 1); // Output 1-based index
            flag = 1; // Set flag to indicate the item is found
            break; // Exit loop after finding the item
        }
    }
    
    // If item was not found, display message
    if(!flag) {
        printf("Item not found\n");
    }

    return 0;
}