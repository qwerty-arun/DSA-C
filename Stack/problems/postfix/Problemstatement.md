# Discuss the infix to postfix conversion algorithm using stack

## Infix Expression
- (A+B) + (C-D)

## Prefix Expression
- ++AB-CD

## Postfix Expression
- AB+CD-+

## Important Properties
- Consider the infix expression A + B*C and its postfix equivalent ABC*+
- We notice that the order of alphabets remain unchanged
- But the order of operators * and + is affected in the two expressions
- Actually, only one stack is enough to convert an infix expression to postfix expression.
- The stack that we use in the algorithm will be used to change the order of operators from infix to postfix. 
- The stack we use will only contain operators and the open parentheses symbol '('.

## Algorithm
- Create a Stack
- For each character 't' in the input stream
```
if(t is an operand)
    output t
else if(t is a right paranthesis){
    pop and output tokens until a left paranthesis is popped (but not output)
}

else //t is an operator or left parenthesis
{
    pop and output tokens until one of lower priority than t is encountered or a left parenthesis is encountered or the stack is empty
    push t
}
```
- Pop and output tokens until the stack is empty

## Postfix Evaluation 
- Scan the postfix string from left to right
- Initialize an empty stack
- Repeat steps 4 and 5 till all characters are scanned
- If the scanned character is an operand, push it onto the stack
- If the scanned character is an operator, and if the operator is a unary operator, then pop an element from the stack. After popping the elements, apply the operator to those popped elements. Let the result of this operation be
- After all characters are scanned, we will have only one element in the stack
- Return top of the stack as result.

