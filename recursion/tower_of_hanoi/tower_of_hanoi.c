#include <stdio.h>

void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg) {
    // Base case: If only 1 disk, make the move and return
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }

    // Move top n-1 disks from 'frompeg' to 'auxpeg' using 'topeg' as auxiliary
    TowersOfHanoi(n - 1, frompeg, auxpeg, topeg);

    // Move remaining disk from 'frompeg' to 'topeg'
    printf("Move disk %d from peg %c to peg %c\n", n, frompeg, topeg);

    // Move n-1 disks from 'auxpeg' to 'topeg' using 'frompeg' as auxiliary
    TowersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}

int main() {
    TowersOfHanoi(3, 'A', 'C', 'B');  // A, B and C are the pegs
    return 0;
}
