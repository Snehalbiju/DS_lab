#include <stdio.h>

// Declare global arrays and variables for the super set, set A, set B, and their bit strings
int superSet[20], superSetSize = 0,             // Array and size for the super set
setA[20], setASize = 0,                         // Array and size for set A
setB[20], setBSize = 0,                         // Array and size for set B
bitStringA[20], bitStringB[20],                 // Bit strings representing set A and set B
bitStringUnion[20], bitStringIntersection[20];  // Union and intersection bit string results
int isBitStringReady = 0;                       // Flag to check if bit strings are ready

// Function to find the position of an element in the super set
// Returns the index if found, otherwise -1
int search(int arr[], int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) return i;
    }
    return -1;
}

// Function to input a set from the user
// arr[]: The array to store the set elements
// size: The number of elements in the set
void getSet(int arr[], int size) {
    printf("Enter set elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  // Input each element of the set
    }
}

// Function to print the elements of a set
// arr[]: The array storing the set elements
// size: The number of elements in the set
void printSet(int arr[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);  // Print each element
        // Add a comma between elements, except for the last element
        if (i < size - 1) printf(", ");  
    }
    printf(" }\n");
}

// Function to print a bit string
// bitString[]: The array storing the bit string
void printBitString(int bitString[]) {
    printf("{ ");
    for (int i = 0; i < superSetSize; i++) {
        printf("%d", bitString[i]);  // Print each bit (0 or 1)
        if (i < superSetSize - 1) printf(", ");
    }
    printf(" }\n");
}

// Function to generate a bit string for a given set
// set[]: The array representing the set
// setSize: The size of the set
// bitString[]: The array to store the resulting bit string
void generateBitString(int set[], int setSize, int bitString[]) {
    // Initialize the bit string to all 0s
    for (int i = 0; i < superSetSize; i++) bitString[i] = 0;

    // Set the corresponding positions to 1 where the element exists in the super set
    for (int i = 0; i < setSize; i++) {
        // Find the index of the element in the super set
        int pos = search(superSet, superSetSize, set[i]);  
        if (pos >= 0) bitString[pos] = 1;  // Set bit to 1 if the element is found
    }
}

// Function to generate bit strings for both sets A and B
void generateBitStrings() {
    generateBitString(setA, setASize, bitStringA);  // Generate bit string for set A
    generateBitString(setB, setBSize, bitStringB);  // Generate bit string for set B

    // Print the generated bit strings for set A and set B
    printf("\nSet A Bit String: ");
    printBitString(bitStringA);

    printf("Set B Bit String: ");
    printBitString(bitStringB);

    isBitStringReady = 1;  // Set the flag indicating bit strings are ready
}

// Function to compute the union of two bit strings (A and B)
// The result is stored in bitStringUnion[]
void setUnion() {
    for (int i = 0; i < superSetSize; i++) {
        // Perform bitwise OR for each position
        bitStringUnion[i] = bitStringA[i] | bitStringB[i];  
    }
}

// Function to compute the intersection of two bit strings (A and B)
// The result is stored in bitStringIntersection[]
void setIntersection() {
    for (int i = 0; i < superSetSize; i++) {
        // Perform bitwise AND for each position
        bitStringIntersection[i] = bitStringA[i] & bitStringB[i];  
    }
}

// Function to print the result of a set operation based on a bit string
// bitString[]: The array representing the bit string
void printResultAsSet(int bitString[]) {
    printf("{ ");
    int first = 1;  // Flag to avoid printing an extra comma before the first element
    for (int i = 0; i < superSetSize; i++) {
        if (bitString[i]) {  // If the bit is 1, the corresponding element is part of the set
            if (!first) printf(", ");  // Print a comma between elements
            printf("%d", superSet[i]);
            first = 0;  // After printing the first element, set flag to 0
        }
    }
    printf(" }\n");
}

int main() {
    printf("Set Operations Using Bit Strings : Union and Intersection\n");
    // Input the super set from the user
    printf("Enter Super Set Size: ");
    scanf("%d", &superSetSize);
    getSet(superSet, superSetSize);  // Get the elements of the super set

    // Input set A from the user
    printf("Enter Set A Size: ");
    scanf("%d", &setASize);
    getSet(setA, setASize);  // Get the elements of set A

    // Input set B from the user
    printf("Enter Set B Size: ");
    scanf("%d", &setBSize);
    getSet(setB, setBSize);  // Get the elements of set B

    // Generate and print bit strings for set A and set B
    generateBitStrings();

    // Perform and print union and intersection results
    if (isBitStringReady) {
        // Compute and print the union of sets A and B
        printf("\nSet Union: ");
        setUnion();
        printBitString(bitStringUnion);  // Print union as bit string
        printf("Print union as set: ");
        printResultAsSet(bitStringUnion);  // Print union as set

        // Compute and print the intersection of sets A and B
        printf("\nSet Intersection: ");
        setIntersection();
        printBitString(bitStringIntersection);  // Print intersection as bit string
        printf("Print intersection as set: ");
        printResultAsSet(bitStringIntersection);  // Print intersection as set
    } else {
        printf("\nBit strings not generated!");  // Error message if bit strings are not ready
    }
    return 0;
}
