# Finding the length of connected cells of 1s (regions) in an matrix of Os and 1s:
- Given a matrix, each of which may be 1 or 0. The filled cells that are connected form a region. 
- Two cells are said to be connected if they are adjacent to each other horizontally, vertically or diagonally.
- There may be several regions in the matrix. How do you find the largest region (in terms of number of cells) in the matrix?

Sample input: 
11000
01100
00100
10001
01011

Sample output: 5

Simplest idea: For each location traverse in all 8 directions and in each of those directions, keep track of maximum region found. 
