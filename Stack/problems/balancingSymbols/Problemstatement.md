# Discuss how stacks can be used for checking balancing of symbols

## Solution
- This algorithm is very useful in compilers. Each time the parser reads one character at a time. If the character is an opening delimiter such as (, { or [, then it is written to the stack. When the delimiter is encountered like ),} or ], the stack is popped.

- The opening and closing delimiters are then comparted. If they match, the parsing of the string continues. If they do not match, the parser indicates that there is an error on the line. A linear time O(n) algorithm is given below:

## Algorithm
1) Create a stack
2) While(end of inputt is not reached){
    - If the character read is not a symbol to be balanced, ignore it.
    - If the character is an opening symbol like (, [, {, push it onto the stack
    - If it is a closing symbol like ),],}, then if the stack is empty report an error. Otherwise pop the stack.
    - If the symbol popped is not the corresponding opening symbol, report an error.
}
3) At the end of input, if the stack is not empty report an error

- Time Complexity: O(n)
- Space Complexity: O(n)
