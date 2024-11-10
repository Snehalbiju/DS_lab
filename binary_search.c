#include<stdio.h>

int main() {
    int a[10], n, i, item, mid, low, high, flag = 0; // Declare variables

    printf("Program for binary search\n");
    
    // Input array size
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Input sorted array elements
    printf("Enter the array elements in sorted order: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Input the element to search for
    printf("Enter the element to be searched: ");
    scanf("%d", &item);
    
    // Initialize low and high pointers for binary search
    low = 0;
    high = n - 1;
    
    // Binary search algorithm
    while(low <= high) {
        mid = low + (high - low) / 2; // Calculate mid index
        if(item == a[mid]) { // Check if item is at mid
            printf("Item found at position %d\n", mid + 1); // Output 1-based index
            flag = 1; // Set flag to indicate item is found
            break; // Exit loop after finding the item
        } else if(item < a[mid]) { // If item is less than mid element
            high = mid - 1; // Search in the left half
        } else { // If item is greater than mid element
            low = mid + 1; // Search in the right half
        }
    }
    
    // If item was not found, display message
    if(!flag) {
        printf("Item not found\n");
    }

    return 0;
}