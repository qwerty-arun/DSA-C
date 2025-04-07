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
    node->data = data;
    node->next = NULL;
    return node;
}

void Push(struct Stack** top, char data)
{
    struct Stack* temp = CreateNode(data);
    if (!temp)
    {
        printf("Memory allocation failed!\n");
        return;
    }
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

void DisplayStack(struct Stack* top)
{
    struct Stack* p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int IsMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main()
{
    struct Stack* top = NULL;
    char A[] = "((A+B)+(C-D))";  // Fixed array size issue
    int i;

    for (i = 0; A[i] != '\0'; i++) // Iterate until null character
    {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            Push(&top, A[i]);
        }
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            if (IsEmptyStack(top) || !IsMatchingPair(Peek(top), A[i]))
            {
                printf("The symbols aren't balanced!\n");
                return 0; // Exit if unmatched closing symbol found
            }
            Pop(&top);
        }
    }

    if (IsEmptyStack(top))
    {
        printf("The symbols are balanced!\n");
    }
    else
    {
        printf("The symbols aren't balanced!\n");
    }

    return 0;
}
