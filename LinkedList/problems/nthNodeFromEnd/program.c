#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
	int data;
	struct ListNode* next;
};

int ListLength(struct ListNode* head)
{
	struct ListNode* current = head;
	int count = 0;
	while(current->next!=NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}


void InsertElement(struct ListNode** head, int data, int position)
{
	struct ListNode *newNode= (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p,*q;
	int k=1;
	if(!newNode)
	{
		printf("Memory Error!\n");
		return;
	}
	newNode->data = data;
	p=*head;
	if(position == 1)
	{
		newNode->next=p;
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
	}
}
void DeleteElement(struct ListNode **head, int position)
{
	int k=1;
	struct ListNode *p,*q;
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
			free(p);
	}
}

void DeleteLinkedList(struct ListNode **head)
{
	struct ListNode *auxilaryNode, *iterator;
	iterator = *head;
	while(iterator!=NULL)
	{
		auxilaryNode = iterator->next;
		free(iterator);
		iterator= auxilaryNode;
	}
	*head = NULL;
}

void Display(struct ListNode* head)
{
	struct ListNode *p = head;
	while(p->next!=NULL)
	{
		printf(" %d ->",p->data);
		p = p->next;
	}
	printf("NULL\n\n");
}

void NthNodeFromEnd(struct ListNode** head, int n)
{
	int length = ListLength(*head);
	if(n>length)
	{
		printf("Invalid term from end!\n");
		return;
	}
	int term = length - n ; //M-n+1th term needs to be calculated
	struct ListNode* p = *head;
	int k = 0;
	while(p->next!= NULL && k<term)
	{
		p=p->next;
		k++;
	}
	printf("%dth term from the end is: %d\n",n,p->data);
}

void nth(struct ListNode* head,int n)
{
	struct ListNode *pNthNode = NULL, *pTemp = head;
	for(int count = 0;count <n; count++)
	{
		if(pTemp)
			pTemp = pTemp -> next;
	}

	while(pTemp)
	{
		if(pNthNode == NULL)
			pNthNode = head;
		else
			pNthNode = pNthNode->next;
		pTemp = pTemp -> next;
	}

	if(pNthNode)
		printf("%dth term from end: %d\n",n,pNthNode->data);
	else
		printf("Noooooo\n");

}
int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	InsertElement(&head, 5, 1);
	InsertElement(&head, 7, 1);
	InsertElement(&head, 8, 2);
	InsertElement(&head, 0, 2);
	Display(head);
	NthNodeFromEnd(&head, 3);
	nth(head, 3);
	InsertElement(&head, 9, 2);
	NthNodeFromEnd(&head, 2);
	nth(head, 2);
	/*printf("List Length: %d\n",ListLength(head));*/
	/*DeleteElement(&head, 3);*/
	/*Display(head);*/
	/*printf("List Length: %d\n",ListLength(head));*/
	/*DeleteElement(&head, 3);*/
	/*Display(head);*/
	/*printf("List Length: %d\n",ListLength(head));*/
	/*DeleteLinkedList(&head);*/
	/*Display(head);*/
	/*printf("List Length: %d\n",ListLength(head));*/
	return 0;
}
