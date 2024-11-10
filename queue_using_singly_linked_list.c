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

// Function to insert a node at the tail of the list
void enqueue() {
    struct Node* new_node = getnode(); // Create a new node
    if (start == NULL) {
        // If the list is empty, the new node becomes the head
        start = new_node;
    } else {
        struct Node* ptr = start; // Start from the head
        // Traverse to the last node
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        // Link the last node to the new node
        ptr->link = new_node;
    }
    printf("%d is enqueued\n",new_node->data);
}


// Function to delete the head node
int dequeue() {
    if (start == NULL) {
        printf("Queue is empty, nothing to delete.\n");
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
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
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
        dequeue(); // Delete the head node until the list is empty
    }
}

// Main function: Menu-driven program
int main() {
    int choice;

    while (1) {
        // Display menu and get user choice
        printf("\n---Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(); // Perform push operation of stack
                break;

            case 2:
                if(dequeue()){
                    printf("Item dequeued.\n"); // Perform pop operation of stack
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