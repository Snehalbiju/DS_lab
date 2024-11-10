#include<stdio.h>
#include<stdlib.h>

#define MAX 50 // Define the maximum size of the queue

int queue[MAX], front = -1, rear = -1; // Initialize the queue array and pointers for front and rear

// Function to add an element to the queue (enqueue)
void enqueue() {
    int item;
    if (rear == MAX - 1) { // Check if the queue is full
        printf("Queue is full. Cannot enqueue new element\n");
        return;
    }
    if (front == -1) { // If the queue is initially empty, set front to 0
        front = 0;
    }
    printf("Enter the element to be enqueued: ");
    scanf("%d", &item);
    rear = rear + 1; // Increment rear and add the element at rear position
    queue[rear] = item;
    printf("%d is enqueued\n", item);
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (front == -1 || front > rear) { // Check if the queue is empty
        printf("Queue is empty. No element to be dequeued\n");
        return;
    }
    printf("%d is dequeued\n", queue[front]); // Display the element at the front being removed
    front++; // Move the front pointer to the next element
    if (front > rear) { // Reset front and rear if the queue becomes empty
        front = rear = -1;
    }
}

// Function to display elements in the queue
void display() {
    int i;
    if (front == -1) { // Check if the queue is empty
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) { // Print elements from front to rear
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int ch;

    // Display menu and allow user to choose queue operations
    while (1) {
        printf("\n--Start Menu--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        // Perform operation based on user's choice
        switch (ch) {
            case 1:
                enqueue(); // Call enqueue function
                break;
            case 2:
                dequeue(); // Call dequeue function
                break;
            case 3:
                display(); // Call display function
                break;
            case 4:
                printf("Program is terminated!\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}