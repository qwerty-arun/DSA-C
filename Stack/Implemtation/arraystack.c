#include <stdio.h>
#include <stdlib.h>

# define MAXSIZE 10

struct ArrayStack{
	int top;
	int capacity;
	int *array;
};

struct ArrayStack* CreateStack()
{
	struct ArrayStack* S = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));
	if(!S)
		return NULL;

	S->capacity= MAXSIZE;
	S->top = -1;
	S->array= (int*)malloc(S->capacity*sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}

int IsEmpty(struct ArrayStack *S)
{
	return (S->top==-1);
}

int IsFullStack(struct ArrayStack *S)
{
	return(S->top == S->capacity-1);
}

void Push(struct ArrayStack* S, int data)
{
	if(IsFullStack(S))
		printf("Stack Overflow\n");
	else
			S->array[++S->top] = data;
}

int Pop(struct ArrayStack* S)
{
	if(IsEmpty(S))
	{
		printf("Stack is Empty\n");
		return -1;
	}
	else
		return (S->array[S->top--]);
}

void DeleteStack(struct ArrayStack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}

void Display(struct ArrayStack *S)
{
	struct ArrayStack* p = S;
	int top = S->top;
	for(int i=0;i<top;i++)
		printf("%d ->",S->array[i]);
	printf("\n");
}

int main()
{

	struct ArrayStack* top = CreateStack();
	Push(top, 1);
	Push(top, 2);
	Push(top, 2);
	Display(top);
	return 0;
}
