#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for characters (operators)
struct CharStack {
    char data[MAX];
    int top;
};

void initCharStack(struct CharStack* stack) {
    stack->top = -1;
}

int isCharStackEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

char peekChar(struct CharStack* stack) {
    return stack->data[stack->top];
}

void pushChar(struct CharStack* stack, char c) {
    stack->data[++stack->top] = c;
}

char popChar(struct CharStack* stack) {
    if (isCharStackEmpty(stack)) return '\0';
    return stack->data[stack->top--];
}

// Stack for integers (operands)
struct IntStack {
    int data[MAX];
    int top;
};

void initIntStack(struct IntStack* stack) {
    stack->top = -1;
}

int isIntStackEmpty(struct IntStack* stack) {
    return stack->top == -1;
}

void pushInt(struct IntStack* stack, int val) {
    stack->data[++stack->top] = val;
}

int popInt(struct IntStack* stack) {
    if (isIntStackEmpty(stack)) return 0;
    return stack->data[stack->top--];
}

// Precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix Conversion
void infixToPostfix(const char* infix, char* postfix) {
    struct CharStack opStack;
    initCharStack(&opStack);

    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char token = infix[i];

        if (isdigit(token)) {
            postfix[k++] = token;
            postfix[k++] = ' ';
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!isCharStackEmpty(&opStack) && precedence(peekChar(&opStack)) >= precedence(token)) {
                postfix[k++] = popChar(&opStack);
                postfix[k++] = ' ';
            }
            pushChar(&opStack, token);
        }
        i++;
    }

    while (!isCharStackEmpty(&opStack)) {
        postfix[k++] = popChar(&opStack);
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}

// Postfix Evaluation
int evaluatePostfix(const char* postfix) {
    struct IntStack operandStack;
    initIntStack(&operandStack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            pushInt(&operandStack, postfix[i] - '0');
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int b = popInt(&operandStack);
            int a = popInt(&operandStack);
            int result;
            switch (postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            pushInt(&operandStack, result);
        }
        i++;
    }

    return popInt(&operandStack);
}

// Main Function
int main() {
    char infix[] = "1*3-7/3+2-9";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

