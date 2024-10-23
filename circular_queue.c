#include <stdio.h>
#include <stdlib.h>
#define MAX 50 // Maximum size of the queue

int queue[MAX], front = -1, rear = -1, count = 0; // Initialize queue and pointers

// Enqueue operation
void enqueue() {
    int elem;
    // Check if the queue is full
    if (count == MAX) {
        printf("Circular queue is full!\n");
        return;
    }
    // Read the element to be enqueued
    printf("Enter the element to be enqueued: ");
    scanf("%d", &elem);
    if (front == -1) {
        front = 0; // Set front to 0 if queue was initially empty
    }
    // Move rear to the next position in a circular manner
    rear = (rear + 1) % MAX;
    queue[rear] = elem; // Insert element at the new rear
    count++; // Increment count
    printf("%d enqueued to the queue.\n", elem);
}

// Dequeue operation
void dequeue() {
    // Check if the queue is empty
    if (count == 0) {
        printf("Circular queue is empty! No elements to dequeue.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    // Move front to the next position in a circular manner
    front = (front + 1) % MAX;
    count--; // Decrease count
}

// Display operation
void display() {
    if (count == 0) {
        printf("Circular queue is empty.\n");
        return;
    }
    int j = front;
    printf("Queue elements are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[j]);
        j = (j + 1) % MAX; // Move to next position in a circular manner
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
