#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CLLNode 
{
	int data;
	struct CLLNode* next;
};

int CircularListLength(struct CLLNode* head)
{
	struct CLLNode* current = head;
	int count = 0;
	if(head == NULL)
		return 0;
	do{
		current = current->next;
		count++;
	}while(current!=head);
	return count;
}

void PrintCircularList(struct CLLNode* head)
{
	struct CLLNode* current = head;
	if(head == NULL)
		return;

	do{
		printf("%d ",current->data);
		current = current->next;
	}while(current!=head);
}

void InsertAtEnd(struct CLLNode** head, int data)
{
	struct CLLNode* current = *head;
	struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
	if(!newNode)
	{
		printf("Memory Error\n");
		return;
	}

	newNode->data = data;

	while(current->next!= *head)
		current = current->next;

	newNode->next = newNode;

	if(*head == NULL)
		*head = newNode;
	else{
		newNode->next = *head;
		current->next = newNode;
	}
}

void InsertAtBegin(struct CLLNode** head, int data)
{
	struct CLLNode* current = *head;
	struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
	if(!newNode)
	{
		printf("Memory Error!\n");
		return;
	}
	newNode->data = data;
	while (current->next!=*head) {
		current = current->next;	
	}
	newNode->next = newNode;
	if(*head == NULL)
		*head = newNode;
	else
	{
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;
	}
	return;
}

void DeleteLastNode(struct CLLNode** head)
{
	struct CLLNode* temp = *head, *current = *head;	
	if(*head == NULL)
	{
		printf("List Empty!\n");
		return;
	}
	while (current->next!=*head) {
		temp = current;	
		current = current->next;
	}
	temp->next = current->next;
	free(current);
	return;
}

void DeleteFrontNode(struct CLLNode** head)
{
	struct CLLNode* temp = *head;
	struct CLLNode* current = *head;
	if(*head == NULL)
	{
		printf("List Empty!\n");
		return;
	}
	while (current->next!=*head) {
		current= current->next;	
	}
	current->next = (*head)->next;
	*head = (*head)->next;

	free(temp);
	return;
}

int main()
{
	struct CLLNode* head = NULL;
	InsertAtBegin(&head, 3);
	InsertAtBegin(&head, 5);
	PrintCircularList(head);
}
