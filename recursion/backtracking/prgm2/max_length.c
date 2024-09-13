#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to get value of the cell in the matrix
int getval(int (*A)[5], int i, int j, int L, int H) {
    if (i < 0 || i >= L || j < 0 || j >= H)
        return 0;
    else
        return A[i][j];
}

// Function to find the largest block of connected 1's
void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int *maxsize) {
    if (r < 0 || r >= L || c < 0 || c >= H)
        return;

    if (A[r][c] == 0 || cntarr[r][c] == true)
        return;

    cntarr[r][c] = true;
    size++;

    if (size > *maxsize)
        *maxsize = size;

    // Directions array for 8 possible movements
    int direction[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for (int i = 0; i < 8; i++) {
        int newi = r + direction[i][0];
        int newj = c + direction[i][1];
        findMaxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
    }

    cntarr[r][c] = false;
}

// Function to create a 2D boolean array dynamically
bool **create2darr(int rmax, int colmax) {
    bool **arr = (bool **)malloc(rmax * sizeof(bool *));
    for (int i = 0; i < rmax; i++) {
        arr[i] = (bool *)malloc(colmax * sizeof(bool));
        for (int j = 0; j < colmax; j++) {
            arr[i][j] = false;
        }
    }
    return arr;
}

// Function to find the largest block of connected 1's in the matrix
int getMaxOnes(int (*A)[5], int rmax, int colmax) {
    int maxsize = 0;
    bool **cntarr = create2darr(rmax, colmax);

    for (int i = 0; i < rmax; i++) {
        for (int j = 0; j < colmax; j++) {
            if (A[i][j] == 1) {
                findMaxBlock(A, i, j, rmax, colmax, 0, cntarr, &maxsize);
            }
        }
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rmax; i++) {
        free(cntarr[i]);
    }
    free(cntarr);

    return maxsize;
}

// Main function to demonstrate the code
int main() {
    int A[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 1}
    };

    int rmax = 5, colmax = 5;
    int maxOnesBlock = getMaxOnes(A, rmax, colmax);

    printf("Maximum size of connected 1's block: %d\n", maxOnesBlock);

    return 0;
}

