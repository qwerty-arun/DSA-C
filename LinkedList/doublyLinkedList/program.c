#include <stdio.h>
#include <stdlib.h>

struct DLLNode
{
	int data;
	struct DLLNode* prev;
	struct DLLNode* next;
};

int ListLength(struct DLLNode* head);
void InsertElement(struct DLLNode** head, int data, int position);
void Display(struct DLLNode* head);
void DeleteLinkedList(struct DLLNode **head);
void DeleteElement(struct DLLNode **head, int position);

int main()
{
	struct DLLNode* head = (struct DLLNode*)malloc(sizeof(struct DLLNode));
	printf("\nSize of each Block: %d\n\n",sizeof(struct DLLNode));
	InsertElement(&head, 5, 1);
	InsertElement(&head, 7, 1);
	InsertElement(&head, 8, 2);

	DeleteElement(&head, 2);

	InsertElement(&head, 10, 3);
	InsertElement(&head, 17, 4);
	printf("List Length: %d\n",ListLength(head));
	return 0;
}

int ListLength(struct DLLNode* head)
{
	struct DLLNode* current = head;
	int count = 0;
	while(current->next!=NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void InsertElement(struct DLLNode** head, int data, int position)
{
	struct DLLNode *newNode= (struct DLLNode*)malloc(sizeof(struct DLLNode));
	struct DLLNode *p,*q;
	int k=1;
	if(!newNode)
	{
		printf("Memory Error!\n");
		return;
	}
	newNode->data = data;
	p=*head;
	if(position == 1) //insert at the beginning
	{
		newNode->next=p;
		p->prev= newNode;
		*head = newNode;
	}
	else
	{
		while((p!=NULL) && (k<position))
		{
			k++;
			q = p;
			p=p->next;
		}
		q->next = newNode;
		newNode->next=p;
		newNode->prev=q;
		p->prev=newNode;
	}
	printf("Array after inserting the element %d at position %d\n",data,position);
	Display(*head);
}
void DeleteElement(struct DLLNode **head, int position)
{
	int k=1;
	struct DLLNode *p,*q;
	if(*head == NULL)
	{
		printf("List Empty\n");
		return;
	}
	if(position>ListLength(*head))
	{
		printf("Position %d Doesn't Exist!\n",position);
		return;
	}
	p = *head;
	if(position==1)
	{
		*head = (*head) -> next;
		free(p);
		return;
	}
	else
	{	
		while((p!=NULL) && (k<position))
		{
			k++;
			q=p;
			p = p->next;
		}
			q->next = p->next;
			p->next->prev = p->prev;
			free(p);
	}
	printf("Array after deleting the element  at position %d\n",position);
	Display(*head);
}

void DeleteLinkedList(struct DLLNode **head)
{
	struct DLLNode *auxilaryNode, *iterator;
	iterator = *head;
	while(iterator!=NULL)
	{
		auxilaryNode = iterator->next;
		free(iterator);
		iterator= auxilaryNode;
	}
	*head = NULL;
}

void Display(struct DLLNode* head)
{
	struct DLLNode *p = head;
	while(p->next!=NULL)
	{
		printf(" %d ->",p->data);
		p = p->next;
	}
	printf("NULL\n\n");
}
