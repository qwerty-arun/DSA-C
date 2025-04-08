#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack 
{
	int data;
	struct Stack* next;
};

struct AdvancedStack
{
	struct Stack *elementStack;
	struct Stack *minStack;
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
	//Main Stack
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


int GetMin(struct Stack* min)
{
	return Peek(min);
}

void Push_adv(struct AdvancedStack* S, int data)
{
	Push(&S->elementStack, data);
	if(IsEmptyStack(S->minStack) || Peek(S->minStack)>=data)
		Push(&S->minStack, data);
}

int Pop_adv(struct AdvancedStack* S)
{
	if(IsEmptyStack(S->elementStack))
		return -1;
	int temp = Peek(S->elementStack);
	if(Peek(S->minStack) == Peek(S->elementStack))
		Pop(&S->minStack);
	return temp;
}

int GetMinimum(struct AdvancedStack* S)
{
	return Peek(S->minStack);
}

struct AdvancedStack* CreateAdvancedStack(int data)
{
	struct AdvancedStack* S = (struct AdvancedStack*)malloc(sizeof(struct AdvancedStack));
	if(!S)
		return NULL;
	S->elementStack = CreateNode(data);
	S->minStack= CreateNode(data);
	return S;
}
int main()
{
	struct AdvancedStack* adv = CreateAdvancedStack(4);
	Push_adv(adv, 7);
	Push_adv(adv, 9);
	Push_adv(adv, -1);
	Push_adv(adv, 0);
	printf("%d",GetMinimum(adv));
	printf("Element stack: \n");
	DisplayStack(adv->elementStack);
	printf("Min stack: \n");
	DisplayStack(adv->minStack);

	Pop_adv(adv);
	Pop_adv(adv);
	printf("Element stack: \n");
	DisplayStack(adv->elementStack);
	printf("Min stack: \n");
	DisplayStack(adv->minStack);
}
