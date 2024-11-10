#include<stdio.h>
#include<stdlib.h>

#define MAX 50 // Define the maximum size of the stack

int stack[MAX], top = -1; // stack array and top variable initialized to -1 (empty stack)

// Function to push an element onto the stack
void push() {
    int item = 0;
    if (top == MAX - 1) { // Check if the stack is full
        printf("Stack overflow. The stack is full\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    top++; // Increment the top index
    stack[top] = item; // Insert the item at the top position
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
void pop() {
    if (top < 0) { // Check if the stack is empty
        printf("Stack underflow. No element in stack to be popped\n");
        return;
    }
	// Display the top element to be removed
    printf("%d is popped from stack\n", stack[top]); 
    top--; // Decrement the top index to remove the element
}

// Function to display elements in the stack
void display() {
    int i = 0;
    if (top < 0) { // Check if the stack is empty
        printf("The stack is empty\n");
        return;
    }
    printf("Stack elements are\n");
    for (i = top; i >= 0; i--) { // Print elements from top to bottom
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int ch;

    // Display menu and allow user to choose stack operations
    while (1) {
        printf("\n--Start Menu--\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        // Perform operation based on user's choice
        switch (ch) {
            case 1:
                push(); // Call push function
                break;
            case 2:
                pop(); // Call pop function
                break;
            case 3:
                display(); // Call display function
                break;
            case 4:
                printf("Program completed\n");
                exit(0); // Exit the program
            default:
                printf("Please enter a valid choice!\n");
        }
    }
    return 0;
}