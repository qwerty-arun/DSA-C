#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack 
{
	int data;
	struct Stack* next;
};

struct Stack* CreateNode(int data)
{
	struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
	node->data = data;
	node->next= NULL;
	return node;
}

void Push(struct Stack** top, int data)
{
	struct Stack* temp = CreateNode(data);
	if(!temp)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	temp->next=*top;
	*top=temp;
}

int IsEmptyStack(struct Stack* top)
{
	return top==NULL;
}

void Pop(struct Stack**top)
{
	struct Stack* temp;
	if(IsEmptyStack(*top))
	{
		printf("Stack is empty!\n");
		return;
	}
	temp = *top;
	*top = (*top)->next;
	free(temp);
}

int Peek(struct Stack* top)
{
	return top->data;
}

void DeleteStack(struct Stack** top)
{
	struct Stack* temp, *p;
	p = *top;
	while(p->next!=NULL)
	{
		temp=p;
		p=p->next;
		free(temp);
	}
	free(p);
}

void DisplayStack(struct Stack* top)
{
	if(top==NULL)
	{
		printf("List is empty!\n");
		return;
	}
	struct Stack* p = top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	struct Stack* top = NULL;
	Push(&top, 1);
	Push(&top, 2);
	Push(&top, 3);
	DisplayStack(top);
	Pop(&top);
	DisplayStack(top);
}
