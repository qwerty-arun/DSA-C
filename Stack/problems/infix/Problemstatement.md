# Discuss the infix expression with stacks in one pass?

## Infix Expression
- (A+B) + (C-D)

## Infix Expression Evaluation
- 1) Create an empty operator stack
- 2) Create an empty operand stack
- 3) For each token in the input string
-   a) Get the next token in the infix string
-   b) If the next token is an operand, place it on the operand stack
-   c) If next token is an operator
-       i) Evaluate the operator (next op)
- 4) While operator stack is not empty, pop operator and operands (left and right), evaluate left operator right and push result onto operand stack
- 5) Pop result from operator stack
