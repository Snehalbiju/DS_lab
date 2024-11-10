#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the disjoint-set
struct node {
    struct node *rep;  // Pointer to the representative of the set
    struct node *next; // Pointer to the next element in the set
    int data;          // The value of the node
};

struct node *heads[50], *tails[50]; // Arrays to hold the heads and tails of each set
static int countRoot = 0; // Number of root nodes (sets)

// Function to create a new set with the element x
void makeSet(int x) {
    // Allocate memory for a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
    newNode->rep = newNode; // Set the representative to itself
    newNode->next = NULL; // Initialize the next pointer to NULL
    newNode->data = x; // Set the data of the node
    heads[countRoot] = newNode; // Add the new set to heads
    tails[countRoot++] = newNode; // Update tails and increment count
}

// Function to find the representative of the set containing element a
struct node* find(int a) {
    for (int i = 0; i < countRoot; i++) { // Loop through all sets
        struct node *tmp = heads[i]; // Start with the head of the current set
        while (tmp) { // Traverse the current set
            if (tmp->data == a) // If the element is found
                return tmp->rep; // Return its representative
            tmp = tmp->next; // Move to the next node
        }
    }
    return NULL; // Return NULL if not found
}

// Function to perform union of two sets containing elements a and b
void unionSets(int a, int b) {
    struct node *rep1 = find(a); // Find representative of the first set
    struct node *rep2 = find(b); // Find representative of the second set

    // If either element is not in the set, return
    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement not present in the DS\n");
        return;
    }

    // If they are in different sets, merge them
    if (rep1 != rep2) {
        // Update the representative of all nodes in the second set (rep2)
        struct node *temp = rep2;
        while (temp) {
            temp->rep = rep1; // Update representative to rep1 for all nodes in set with rep2
            temp = temp->next;
        }

        // Find the index of the set containing rep2
        int index = -1;
        for (int i = 0; i < countRoot; i++) {
            if (heads[i] == rep2) { // Directly compare heads to find rep2
                index = i;
                break;
            }
        }

        // If the set containing rep2 was found, merge it with the set of rep1
        if (index != -1) {
            for (int i = 0; i < countRoot; i++) {
                if (heads[i] == rep1) { // Find the set containing rep1
                    tails[i]->next = rep2; // Link the second set (rep2) to the first set (rep1)
                    tails[i] = tails[index]; // Update the tail to the tail of the merged set
                    break;
                }
            }

            // Remove the second set from the heads and tails arrays
            for (int i = index; i < countRoot - 1; i++) {
                heads[i] = heads[i + 1];
                tails[i] = tails[i + 1];
            }
            countRoot--; // Decrease the set count after merging
        }
    } else {
        printf("\nElements are already in the same set\n");
    }
}

// Function to check if an element x exists in any set
int search(int x) {
    for (int i = 0; i < countRoot; i++) { // Loop through all sets
        struct node *tmp = heads[i];
        while (tmp) { // Traverse the set
            if (tmp->data == x) // If the element is found
                return 1;
            tmp = tmp->next; // Move to the next node
        }
    }
    return 0; // Return 0 if not found
}

// Main function
int main() {
    int choice, x, y;

    printf("Disjoint Set Operations Using Linked Lists\n");
    do {
        // Display menu options
        printf("\n.......MENU.......\n");
        printf("1. Make Set\n");
        printf("2. Display Set Representatives\n");
        printf("3. Union\n");
        printf("4. Find Set\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1: // Make a new set
                printf("\nEnter new element: ");
                scanf("%d", &x); // Input new element
                if (search(x))
                    printf("\nElement already present in the disjoint set DS\n");
                else
                    makeSet(x); // Create new set
                break;
            case 2: // Display representatives
                printf("\nRepresentatives of the sets: ");
                for (int i = 0; i < countRoot; i++)
                    printf("%d ", heads[i]->data); // Print each representative
                printf("\n");
                break;
            case 3: // Union of two sets
                printf("\nEnter first element: ");
                scanf("%d", &x);
                printf("\nEnter second element: ");
                scanf("%d", &y);
                unionSets(x, y); // Perform union operation
                break;
            case 4: // Find representative of an element
                printf("\nEnter the element: ");
                scanf("%d", &x);
                struct node *rep = find(x); // Find representative
                if (rep == NULL)
                    printf("\nElement not present in the DS\n");
                else
                    // Print representative
                    printf("\nThe representative of %d is %d\n", x, rep->data); 
                break;
            case 5: // Exit
                exit(0);
            default:
                printf("\nWrong choice\n");
                break;
        }
    } while (1); // Keep looping until exit
}
