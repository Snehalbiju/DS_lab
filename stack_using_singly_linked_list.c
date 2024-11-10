#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;              // Data part of the node
    struct Node* link;     // Pointer to the next node
};

// Head pointer for the linked list
struct Node* start = NULL;

// Function to create a new node (getnode)
struct Node* getnode() {
    int item;
    printf("Enter the value to insert: ");
    scanf("%d", &item); // Get the value for the new node
    
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = item; // Set the node's data
    new_node->link = NULL; // Initialize the link to NULL
    return new_node; // Return the new node
}

// Function to insert a node at the head of the list
void push() {
    struct Node* new_node = getnode(); // Create a new node
    if (start == NULL) {
        // If the list is empty, make the new node the head
        start = new_node;
    } else {
        // Link the new node to the current head
        new_node->link = start; 
        // Update head to point to the new node
        start = new_node; 
    }
    printf("%d is pushed\n",new_node->data);
}


// Function to delete the head node
int pop() {
    if (start == NULL) {
        printf("Stack is empty, nothing to delete.\n");
        return 0;
    } else {
        struct Node* ptr = start; // Store the current head
        start = start->link; // Update head to the next node
        free(ptr); // Free the memory of the old head
        return 1;
    }
}

// Function to traverse and print the stack
void traverse() {
    if (start == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        struct Node* ptr = start; // Pointer to traverse the list
        while (ptr != NULL) {
            printf("-> %d", ptr->data); // Print current node data
            ptr = ptr->link; // Move to the next node
        }
    }
}

// Function to free all nodes in the list
void freeList() {
    while (start != NULL) {
        pop(); // Delete the head node until the list is empty
    }
}

// Main function: Menu-driven program
int main() {
    int choice;

    while (1) {
        // Display menu and get user choice
        printf("\n---Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(); // Perform push operation of stack
                break;

            case 2:
                if(pop()){
                    printf("Top element poped.\n"); // Perform pop operation of stack
                }
                break;

            case 3:
                traverse(); // Display elements
                break;

            case 4:
                printf("Exiting program.\n");
                freeList(); // Free all nodes before exiting
                exit(0); // Exit the program

            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}