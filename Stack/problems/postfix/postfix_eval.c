#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack 
{
    char data;
    struct Stack* next;
};

struct Stack* CreateNode(char data)
{
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
    if (!node)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void Push(struct Stack** top, char data)
{
    struct Stack* temp = CreateNode(data);
    temp->next = *top;
    *top = temp;
}

int IsEmptyStack(struct Stack* top)
{
    return top == NULL;
}

char Pop(struct Stack** top)
{
    if (IsEmptyStack(*top))
    {
        return '\0'; // Return null character if stack is empty
    }
    struct Stack* temp = *top;
    char poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

char Peek(struct Stack* top)
{
    return top ? top->data : '\0';
}

int Precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

char* Postfix(char* expression)
{
    struct Stack* opStack = NULL;
    int length = strlen(expression);
    char* result = (char*)malloc(length + 1); // Allocate memory for postfix expression
    int index = 0;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char c = expression[i];

        // If the character is an operand (digit), add it to the result
        if (c >= '0' && c <= '9')
        {
            result[index++] = c;
        }
        // If the character is '(', push to stack
        else if (c == '(')
        {
            Push(&opStack, c);
        }
        // If the character is ')', pop and add to result until '(' is found
        else if (c == ')')
        {
            while (!IsEmptyStack(opStack) && Peek(opStack) != '(')
            {
                result[index++] = Pop(&opStack);
            }
            Pop(&opStack); // Remove '('
        }
        // If operator, pop from stack based on precedence
        else
        {
            while (!IsEmptyStack(opStack) && Precedence(Peek(opStack)) >= Precedence(c))
            {
                result[index++] = Pop(&opStack);
            }
            Push(&opStack, c);
        }
    }

    // Pop all remaining operators
    while (!IsEmptyStack(opStack))
    {
        result[index++] = Pop(&opStack);
    }
    result[index] = '\0'; // Null-terminate the string

    return result;
}

void PostfixEval(char *postfixExp)
{
    struct Stack* opStack = NULL;
    for (int i = 0; postfixExp[i] != '\0'; i++)
    {
        // If operand (digit), push to stack
        if (postfixExp[i] >= '0' && postfixExp[i] <= '9')
        {
            Push(&opStack, postfixExp[i]); // Push character digit
        }
        // If operator, pop two values and perform operation
        else
        {
            int pop1 = Pop(&opStack) - '0'; // Convert to int
            int pop2 = Pop(&opStack) - '0'; // Convert to int
            int result = 0;

            if (postfixExp[i] == '+')
            {
                result = pop2 + pop1;
            }
            else if (postfixExp[i] == '-')
            {
                result = pop2 - pop1;
            }
            else if (postfixExp[i] == '*')
            {
                result = pop2 * pop1;
            }
            else if (postfixExp[i] == '/')
            {
                result = pop2 / pop1;
            }
            
            Push(&opStack, result + '0'); // Convert result back to char and push
        }
    }

    // Final result
    printf("%d\n", Pop(&opStack) - '0'); // Convert char to int and print
}

int main()
{
    char expression[] = "1+(2*3)-5";
    char* postfixExpression = Postfix(expression);
    
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Postfix Evaluation: ");
    PostfixEval(postfixExpression);
    
    free(postfixExpression); // Free allocated memory
    return 0;
}
