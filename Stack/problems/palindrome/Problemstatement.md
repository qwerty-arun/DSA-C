# Palindrome string
- Given an array of characters formed with a's and b's. The string is marked with special character X which represents the middle of the list
- Example: abababXbababa
- Check whether the string is palindrome

## Brute Force
- start with two indices, one at beginning of string and one at the end of the string
- each time compart whether the values at both the indices are same or not 
- If not, then nope

## Stacks
- Traverse the list till we encounter X as input element
- During the traversal push all the elements (until X) onto the stack
- For the second half of the list, compare each element's content with top of the stack. If they are the same then pop the stack and go to the next element in the input list.
- If they are not the same then the given string is not a palindrome.
- Continue this process until the stack is empty of the string is not a palindrome
- Time: O(n)
- Space: O(n/2) = O(n)
