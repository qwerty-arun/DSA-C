
#include <stdio.h>
#include <stdlib.h>

#define NODE_CAPACITY 4 // Maximum elements per node

// Structure for a node in the unrolled linked list
typedef struct UnrolledNode {
    int elements[NODE_CAPACITY]; // Array to store elements
    int count; // Number of elements stored in the node
    struct UnrolledNode* next; // Pointer to next node
} UnrolledNode;

// Structure for the unrolled linked list
typedef struct UnrolledLinkedList {
    UnrolledNode* head;
} UnrolledLinkedList;

// Function to create a new node
UnrolledNode* createNode() {
    UnrolledNode* node = (UnrolledNode*)malloc(sizeof(UnrolledNode));
    node->count = 0;
    node->next = NULL;
    return node;
}

// Function to initialize an unrolled linked list
UnrolledLinkedList* createList() {
    UnrolledLinkedList* list = (UnrolledLinkedList*)malloc(sizeof(UnrolledLinkedList));
    list->head = createNode();
    return list;
}

// Function to insert an element into the unrolled linked list
void insert(UnrolledLinkedList* list, int value) {
    UnrolledNode* current = list->head;
    
    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // If there is space, insert the element
    if (current->count < NODE_CAPACITY) {
        current->elements[current->count++] = value;
    } else {
        // Create a new node
        UnrolledNode* newNode = createNode();
        
        // Move half elements to the new node (splitting the array)
        int half = NODE_CAPACITY / 2;
        for (int i = half; i < NODE_CAPACITY; i++) {
            newNode->elements[newNode->count++] = current->elements[i];
        }
        current->count = half; // Adjust count for current node

        // Insert new value into the correct node
        if (value < newNode->elements[0]) {
            current->elements[current->count++] = value;
        } else {
            newNode->elements[newNode->count++] = value;
        }

        // Link the new node
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the unrolled linked list
void printList(UnrolledLinkedList* list) {
    UnrolledNode* current = list->head;
    while (current != NULL) {
        printf("[ ");
        for (int i = 0; i < current->count; i++) {
            printf("%d ", current->elements[i]);
        }
        printf("] -> ");
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete an element from the unrolled linked list
void delete(UnrolledLinkedList* list, int value) {
    UnrolledNode* current = list->head;
    UnrolledNode* prev = NULL;

    while (current != NULL) {
        int i;
        // Search for the value in the current node
        for (i = 0; i < current->count; i++) {
            if (current->elements[i] == value) {
                break;
            }
        }

        // If the value was found
        if (i < current->count) {
            // Shift elements left to fill the gap
            for (int j = i; j < current->count - 1; j++) {
                current->elements[j] = current->elements[j + 1];
            }
            current->count--;

            // If the node is empty and not the head, remove it
            if (current->count == 0 && prev != NULL) {
                prev->next = current->next;
                free(current);
            }
            return;
        }

        // Move to the next node
        prev = current;
        current = current->next;
    }
}

// Function to free the memory of the unrolled linked list
void freeList(UnrolledLinkedList* list) {
    UnrolledNode* current = list->head;
    while (current != NULL) {
        UnrolledNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// Main function to demonstrate unrolled linked list operations
int main() {
    UnrolledLinkedList* list = createList();

    insert(list, 10);
    printList(list);
    insert(list, 20);
    printList(list);
    insert(list, 30);
    printList(list);
    insert(list, 40);
    printList(list);
    insert(list, 50);
    printList(list);
    insert(list, 60);
    printList(list);
    insert(list, 70);

    printf("\nUnrolled Linked List:\n");
    printList(list);

    printf("\nDeleting 30...\n");
    delete(list, 30);
    printList(list);
    printf("Deleting 10...\n");
    delete(list, 10);
    printList(list);
    printf("Deleting 20...\n");
    delete(list, 20);
    printList(list);
    printf("Deleting 40...\n");
    delete(list, 40);
    printList(list);

    freeList(list);
    return 0;
}

