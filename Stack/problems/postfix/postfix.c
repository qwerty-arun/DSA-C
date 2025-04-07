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

void Postfix(char* expression)
{
    struct Stack* opStack = NULL;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char c = expression[i];

        // If the character is an operand, print it
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            printf("%c", c);
        }
        // If the character is '(', push to stack
        else if (c == '(')
        {
            Push(&opStack, c);
        }
        // If the character is ')', pop and print until '(' is found
        else if (c == ')')
        {
            while (!IsEmptyStack(opStack) && Peek(opStack) != '(')
            {
                printf("%c", Pop(&opStack));
            }
            Pop(&opStack); // Remove '('
        }
        // If operator, pop from stack based on precedence
        else
        {
            while (!IsEmptyStack(opStack) && Precedence(Peek(opStack)) >= Precedence(c))
            {
                printf("%c", Pop(&opStack));
            }
            Push(&opStack, c);
        }
    }

    // Pop all remaining operators
    while (!IsEmptyStack(opStack))
    {
        printf("%c", Pop(&opStack));
    }
    printf("\n");
}

int main()
{
    char expression[] = "(A+C)-(D-B)+(E-F)";
    printf("Postfix Expression: ");
    Postfix(expression);
    return 0;
}
