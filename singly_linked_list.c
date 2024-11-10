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
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    new_node->data = item; // Set the node's data
    new_node->link = NULL; // Initialize the link to NULL
    return new_node; // Return the new node
}

// Function to insert a node at the head of the list
void insertAtHead() {
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
}

// Function to insert a node at the tail of the list
void insertTail() {
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
}

// Function to delete the head node
void deleteAtHead() {
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
    } else {
        struct Node* ptr = start; // Store the current head
        start = start->link; // Update head to the next node
        free(ptr); // Free the memory of the old head
        printf("Head node deleted successfully.\n");
    }
}

// Function to delete the tail node
void deleteTail() {
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
    } else if (start->link == NULL) {
        // If there's only one node, delete it
        free(start);
        start = NULL;
        printf("Tail node deleted successfully.\n");
    } else {
        struct Node* ptr = start;
        struct Node* prev = NULL;
        // Traverse to the last node
        while (ptr->link != NULL) {
            prev = ptr; // Track the node before the last one
            ptr = ptr->link;
        }
        // Unlink the last node and free its memory
        prev->link = NULL;
        free(ptr);
        printf("Tail node deleted successfully.\n");
    }
}

// Function to traverse and print the list
void traverse() {
    if (start == NULL) {
        printf("List is empty.\n");
    } else {
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
        deleteAtHead(); // Delete the head node until the list is empty
    }
}

// Main function: Menu-driven program
int main() {
    int choice;

    while (1) {
        // Display menu and get user choice
        printf("\n--- Menu ---\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Delete Head\n");
        printf("4. Delete Tail\n");
        printf("5. Traverse List\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtHead(); // Insert new node at head
                printf("Node inserted at head.\n");
                break;

            case 2:
                insertTail(); // Insert new node at tail
                printf("Node inserted at tail.\n");
                break;

            case 3:
                deleteAtHead(); // Delete the head node
                break;

            case 4:
                deleteTail(); // Delete the tail node
                break;

            case 5:
                printf("Current List: ");
                traverse(); // Traverse and print the list
                break;

            case 6:
                printf("Exiting program.\n");
                freeList(); // Free all nodes before exiting
                exit(0); // Exit the program

            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}