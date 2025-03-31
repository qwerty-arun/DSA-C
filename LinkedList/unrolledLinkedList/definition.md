# Unrolled Linked List
- An unrolled linked list stores multiple elements in each node (call it block). In each block, a circular linked list is used to connect all nodes
- A variation of a linked list where each node contains an array of elements of just a single element

- List Head

- V 

- BlockHead(10)            BlockHead(70)          BlockHead(91)

-   V                           V                         V

- | 10 <- 1 <- 30 <- 6 |  --> | 70 <- 3 <- 45 <-2 | --> | 91 <- 19 <- 1 <-18 |

-   |----------------^           |--------------^          |---------------^


## Searching for an element in Unrolled Linked lists

- We can find the kth element in O(n^0.5)
- 1) Traverse the list of blocks to the one that contains the kth node, i.e the k/ root(n) th block. It takes O (root(n)) since we may find it by going through no more than root(n) blocks
- 2) Find (k mod (root(n))th node in the circular linked list of this block. It also taks O(root n) since there are no more than root n nodes in a single block.


## Advantages 
- Reduces pointer overhead and improves cache efficiency
