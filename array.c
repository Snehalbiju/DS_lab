#include <stdio.h>
#include <stdlib.h>

int n, a[50]; // Global array and its size

// Function to display the array
void display() { 
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n-----------------\n");
}

// Function to insert an element into the array
void insertion() {
    int i, pos, elem;
    if (n >= 50) {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }
    printf("Enter the position (0 to %d) where you want to insert and the value: ", n);
    scanf("%d%d", &pos, &elem);
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    n++; // Increase the array size
    // Shift elements to the right to make space for the new element
    for (i = n - 2; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    // Insert the element at the specified position
    a[pos] = elem;
    printf("Array after insertion:\n");
    display();
}

// Function to delete an element from the array
void deletion() {
    int i, pos;
    if (n == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    printf("Enter the position (0 to %d) of the element to be deleted: ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    // Store the element being deleted
    int elem = a[pos];
    // Shift elements to the left to fill the gap
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--; // Decrease the array size
    printf("Deleted element: %d\n", elem);
    printf("Array after deletion:\n");
    display();
}

int main() {
    int ch, i;
    printf("Create array\n");
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    printf("Enter %d array elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Menu loop
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                display();
                break;
            case 2:
                insertion();
                break;
            case 3:
                deletion();
                break;
            case 4:
                printf("Program exited.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}