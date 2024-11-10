#include<stdio.h>

// Function to perform bubble sort on an array
void bubbleSort(int a[], int n) {
    int temp, swapped, i, j;
    
    // Outer loop for each pass
    for(i = 0; i < n; i++) {
        swapped = 0; // Track if any swapping occurs in the current pass
        
        // Inner loop for comparing adjacent elements
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) { // If the current element is greater than the next
                // Swap elements
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1; // Set swapped to 1 to indicate a swap occurred
            }
        }
        
        // If no elements were swapped, the array is already sorted
        if(!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[10], n, i;
    
    printf("Program for bubble sort\n");
    
    // Input the size of the array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Call bubbleSort function to sort the array
    bubbleSort(a, n);
    
    // Display the sorted array
    printf("Sorted array: ");
    printArray(a, n);
    
    return 0;
}