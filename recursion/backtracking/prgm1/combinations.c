#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate all permutations
void generatePermutations(char *str, int l, int r) {
    // Base case: if left index is equal to right index, print the string
    if (l == r) {
        printf("%s\n", str);
    } else {
        // Iterate over the string and recursively generate permutations
        for (int i = l; i <= r; i++) {
            // Swap the current index with the left index
            swap((str + l), (str + i));

            // Recur with the next part of the string
            generatePermutations(str, l + 1, r);

            // Backtrack by undoing the swap
            swap((str + l), (str + i));
        }
    }
}

int main() {
    char str[10]="abc";
    
    int n = strlen(str);
    
    printf("All permutations of the string are:\n");
    generatePermutations(str, 0, n - 1);
    
    return 0;
}

