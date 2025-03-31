# Problem Statement: Check whether the given linked list is either NULL-terminated or ends in a cycle

## Solution-1 (Brute Force)
- Repetition of next pointers indicates the existence of a loop
- Start with the first node and see whether there is any node whose next pointer is the current node's address.
- If yes, then there is a loop

## Solution-2 (Hashing)
- Traverse the list one by one.
- Check if the address of node is available in the hash table or not
- If yes, it indicates that we are visiting the node that was already visited. This is only possible if there is a loop in it
- If not, insert that node's address into the hash table
- Continue this process until we reach the end of the list, or we find the loop.
- Time: O(n) for scanning
- Space: O(n) for has table

## Solution-3 (Sorting approach)
- This method fails
- Traverse the linked list nodes one by one and take all the next pointers values into an array
- Sort the array
- If there is a loop, definitely two next node pointers will be pointing to the same node
- After sorting if there is a loop in the list, the nodes whose next pointers are the same will end up adjacent in the sorted list.
- If such pair exists in the sorted list then we say the linked list has a loop in it.
- Time: O(n*logn) for sorting 
- Space: O(n) for the next pointers array
- Why fail? The above algorithm works only if we can find the length of the list. But if the list has a loop then we may end up in an infinite loop.

## Solution-4 (Fast and Slow Pointer)
- The solution is named Floyd Cycle algorithm
- Two pointers moving at different speeds. Once they enter the loop they are expected to meet, which denotes that there is a loop.
- Time: O(n)
- Space: O(1)
