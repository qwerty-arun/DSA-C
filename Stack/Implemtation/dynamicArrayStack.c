#include <stdio.h>
#include <stdlib.h>

# define MAXSIZE 10

struct DynArrayStack{
	int top;
	int capacity;
	int *array;
};

struct DynArrayStack* CreateStack()
{
	struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
	if(!S)
		return NULL;

	S->capacity= MAXSIZE;
	S->top = -1;
	S->array= (int*)malloc(S->capacity*sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}

int IsEmpty(struct DynArrayStack *S)
{
	return (S->top==-1);
}

int IsFullStack(struct DynArrayStack *S)
{
	return(S->top == S->capacity-1);
}

void DoubleStack(struct DynArrayStack* S)
{
	S->capacity*=2;
	S->array = (int*)realloc(S->array, S->capacity*sizeof(int));
}

void Push(struct DynArrayStack* S, int data)
{
	if(IsFullStack(S))
		DoubleStack(S);
	S->array[++S->top] = data;
}

int Pop(struct DynArrayStack* S)
{
	if(IsEmpty(S))
	{
		return -1;
	}
	else
		return (S->array[S->top--]);
}

void DeleteStack(struct DynArrayStack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}

void Display(struct DynArrayStack *S)
{
	struct DynArrayStack* p = S;
	int top = S->top;
	for(int i=top;i>=0;i--)
	{
		printf("| %d |",S->array[i]);
		if(i==top)
			printf("  <- top");
		printf("\n-----\n");
	}
	printf(" | \n");
	printf(" V \n");
	printf("Null\n");
}

int main()
{

	struct DynArrayStack* top = CreateStack();
	Push(top, 1);
	Push(top, 2);
	Push(top, 3);
	Push(top, 4);
	Display(top);
	Pop(top);
	Display(top);
	return 0;
}
