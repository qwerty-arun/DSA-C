# Problem Statement: Find nth node from the end of a Linked List

## Brute Force Method (Solution-1)
- Start with the first node and count the number of nodes present after that node. If the number of nodes is < n-1 then return saying "fewer number of nodes in the list". If the number of nodes is > n-1 then go to next node. Continue this until the numbers of nodes after current node are n-1
- Time complexity: O(n^2)
- Space complexity: O(1)

## Hash Table (Solution-2)
- Create a hash table whose entries are <position of node, node address>. That means, key is the position of the node in the list and value is the address of that node.
- By the time we traverse the complete list, we can find the list length. Let us say the list length is M. To find nth from the end of linked list, we can convert this to MM-n+1 th from the beginning. Since we already know the length of the list, it is just a matter of returning M-n+1th key value from the has table.
- Time Complexity: Time for creating the hash table, O(m).
- Space Complexity: We need to create a has table of size m, O(m).

## Improvement: NO hash table (Solution-3)
- After finding length M, just compute the M-n+1th node from the beginning
- The solution needs two scans: one for finding the length of the list and the other for finding M-n+1th node from the beginning
- Time: O(n)
- Space: O(1) since we don't need to create the hash table.

## Just One Scan? (Solution-4)
- Use two pointers pNthNode and pTemp. Initially, both point to head node of the list.
- pNthNode starts moving only after pTemp has made n moves. 
- From there move forward until pTemp reaches the end of the list. As a result pNthNode points to nth node from the end of the linked list.
- Both the pointers move one node at a time.
