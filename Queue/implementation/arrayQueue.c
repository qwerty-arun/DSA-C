#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue{
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue* Queue(int size)
{
	struct ArrayQueue *Q = (struct ArrayQueue*)malloc(sizeof(struct ArrayQueue*));
	if(!Q)
	{
		return NULL;
	}

	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if(!Q->array)
	{
		return NULL;
	}
	return Q;
}

int isEmpty(struct ArrayQueue* Q)
{
	return Q->front = -1;
}

int isFull(struct ArrayQueue* Q)
{
	return ((Q->rear+1)%Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue* Q)
{
	return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(struct ArrayQueue* Q, int data)
{
	if(isFull(Q))
		printf("Queue Overflow\n");
	else
	{
		Q->rear = (Q->rear+1) % Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front==-1)
			Q->front = Q->rear;
	}
}

int DeQueue(struct ArrayQueue* Q)
{
	int data = 0;
	if(isEmpty(Q))
	{
		printf("Queue is Empty!");
		return 0;
	}
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else Q->front = (Q->front+1)%Q->capacity;
	}
	return data;
}


void DeleteQueue(struct ArrayQueue* Q)
{
	if(Q)
	{
		if(Q->array)
			free(Q->array);

		free(Q);
	}
}

int main()
{
	struct ArrayQueue* Q = Queue(4);
	printf("Check if empty: %d\n",isEmpty(Q));
	EnQueue(Q, 1);
	EnQueue(Q, 4);
	printf("Check if empty: %d\n",isEmpty(Q));
	for(int i = Q->front+1; i<=Q->rear; i++)
	{
		printf("%d ",Q->array[i]);
	}
	printf("\n");
}
