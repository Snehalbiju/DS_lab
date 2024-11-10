#include<stdio.h>
#include<stdlib.h>

#define MAX 50 // Define the maximum size of the circular queue

int cq[MAX], front = -1, rear = -1, count = 0; // Circular queue array and pointers for front, rear, and count of elements

// Function to add an element to the circular queue (enqueue)
void enqueue() {
    int elem;
    if (count == MAX) { // Check if the circular queue is full
        printf("Circular queue is full\n");
        return;
    }
    if (front == -1) { // If the queue is initially empty, set front to 0
        front = 0;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &elem);
    rear = (rear + 1) % MAX; // Increment rear in a circular manner
    cq[rear] = elem; // Insert the element at the new rear position
    count++; // Increment the element count
    printf("%d is entered into the queue\n", elem);
}

// Function to remove an element from the circular queue (dequeue)
void dequeue() {
    if (count == 0) { // Check if the circular queue is empty
        printf("Circular queue is empty, No element to be dequeued!\n");
        return;
    }
    printf("%d is dequeued\n", cq[front]); // Display the element at the front being removed
    front = (front + 1) % MAX; // Move the front pointer in a circular manner
    count--; // Decrease the element count
}

// Function to display elements in the circular queue
void display() {
    int i, j;
    if (count == 0) { // Check if the circular queue is empty
        printf("Circular queue is empty\n");
        return;
    }
    j = front;
    printf("Queue elements are: ");
    for (i = 0; i < count; i++) { // Loop through the elements in circular order
        printf("%d ", cq[j]);
        j = (j + 1) % MAX; // Move index in a circular manner
    }
    printf("\n");
}

// Main function
int main() {
    int ch;
    while (1) {
        printf("\n----Circular Queue Menu----\n");
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
                printf("Program ended\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
