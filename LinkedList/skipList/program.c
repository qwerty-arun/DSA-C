#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 4  // Maximum level for the skip list
#define P 0.5        // Probability of creating a higher level node

// Node structure
typedef struct SkipListNode {
    int key;
    struct SkipListNode* forward[MAX_LEVEL]; // Array of forward pointers
} SkipListNode;

// Skip List structure
typedef struct SkipList {
    int level; // Current max level in the list
    SkipListNode* header; // Header node (dummy node)
} SkipList;

// Function to create a new node
SkipListNode* createNode(int key, int level) {
    SkipListNode* node = (SkipListNode*)malloc(sizeof(SkipListNode));
    node->key = key;
    for (int i = 0; i < MAX_LEVEL; i++) {
        node->forward[i] = NULL;
    }
    return node;
}

// Function to create a skip list
SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(INT_MIN, MAX_LEVEL); // Header node with min value
    return list;
}

// Randomly determine node level
int randomLevel() {
    int level = 1;
    while ((rand() / (double)RAND_MAX) < P && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Insert a key into the skip list
void insert(SkipList* list, int key) {
    SkipListNode* update[MAX_LEVEL];  // Track nodes to update
    SkipListNode* current = list->header;

    // Traverse list to find insert position
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    int newLevel = randomLevel(); // Generate random level for new node

    if (newLevel > list->level) {
        for (int i = list->level + 1; i < newLevel; i++) {
            update[i] = list->header;
        }
        list->level = newLevel - 1;
    }

    SkipListNode* newNode = createNode(key, newLevel);

    // Insert the new node and adjust pointers
    for (int i = 0; i < newLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

// Search for a key in the skip list
int search(SkipList* list, int key) {
    SkipListNode* current = list->header;
    
    // Traverse through the levels
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0]; // Move to the next node

    // Check if the key matches
    return (current != NULL && current->key == key);
}

// Delete a key from the skip list
void delete(SkipList* list, int key) {
    SkipListNode* update[MAX_LEVEL];
    SkipListNode* current = list->header;

    // Traverse to find the node
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    // If key is found, adjust pointers
    if (current != NULL && current->key == key) {
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];
        }

        free(current);

        // Reduce the level of the skip list if needed
        while (list->level > 0 && list->header->forward[list->level] == NULL) {
            list->level--;
        }
    }
}

// Print the skip list
void printList(SkipList* list) {
    printf("Skip List Levels:\n");
    for (int i = list->level; i >= 0; i--) {
        SkipListNode* node = list->header->forward[i];
        printf("Level %d: ", i);
        while (node) {
            printf("%d -> ", node->key);
            node = node->forward[i];
        }
        printf("NULL\n");
    }
}

// Free memory used by the skip list
void freeList(SkipList* list) {
    SkipListNode* current = list->header;
    SkipListNode* next;
    
    while (current) {
        next = current->forward[0];
        free(current);
        current = next;
    }

    free(list);
}

// Main function for demonstration
int main() {
    SkipList* list = createSkipList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 30);
    insert(list, 40);
    insert(list, 50);

    printf("Skip List After Insertions:\n");
    printList(list);

    printf("Searching for 30: %s\n", search(list, 30) ? "Found" : "Not Found");
    printf("Searching for 25: %s\n", search(list, 25) ? "Found" : "Not Found");

    printf("Deleting 30...\n");
    delete(list, 30);
    printList(list);

    freeList(list);
    return 0;
}

