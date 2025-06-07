#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode* next;
};

struct Queue
{
	struct ListNode* front;
	struct ListNode* rear;
};

struct Queue* createQueue()
{
	struct Queue* Q;
	Q = (struct Queue*)malloc(sizeof(struct Queue));

	if(!Q)
		return NULL;

	Q->front = Q->rear = NULL;
	return Q;
}

int isEmpty(struct Queue* Q)
{
	return Q->front == NULL;
}

void EnQueue(struct Queue* Q, int data)
{
	struct ListNode* newNode;
	newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(!newNode)
		return;
	newNode->data = data;
	newNode->next = NULL;
	if(Q->rear)
	{
		Q->rear->next = newNode;
	}

	Q->rear = newNode;
	if(Q->front == NULL)
		Q->front = Q->rear;
}

int DeQueue(struct Queue* Q)
{
	int data = 0;
	struct ListNode* temp;
	if(isEmpty(Q))
	{
		printf("Queue is empty!\n");
		return 0;
	}
	else
	{
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}

void deleteQueue(struct Queue* Q)
{
	struct ListNode* temp;
	while(Q->front)
	{
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
}

void displayQueue(struct Queue* Q)
{
	struct ListNode* temp = Q->front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main()
{
	struct Queue* Q = createQueue();
	printf("%d\n",isEmpty(Q));
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	DeQueue(Q);
	displayQueue(Q);
	return 0;
}
