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

void ReverseList(struct ListNode* head)
{
	struct ListNode * temp = NULL, *nextNode = NULL;
	while(head->next!=NULL) //Stack implementation
	{
		nextNode = head->next;
		head ->next = temp;
		temp= head;
		head = nextNode;
	}
	while(temp!=NULL)
	{
		printf(" %d ->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

struct ListNode* RecursiveReverse(struct ListNode* head)
{
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;

	struct ListNode *secondElem = head->next;
	// Need to unlink list from the rest or you will get a cycle
	head->next = NULL;
	//reverse everything from the second element on
	struct ListNode* reverseRest = RecursiveReverse(secondElem);
	secondElem->next = head;

	return reverseRest;
}

int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	InsertElement(&head, 5, 1);
	InsertElement(&head, 7, 1);
	InsertElement(&head, 8, 2);
	InsertElement(&head, 0, 2);
	InsertElement(&head, -3, 2);
	Display(head);
	printf("List Length: %d\n",ListLength(head));

	struct ListNode* node= (struct ListNode*)malloc(sizeof(struct ListNode));
	/*ReverseList(head);*/
	struct ListNode* reverseRest = RecursiveReverse(head);
	//printing the elements
	reverseRest = reverseRest->next;
	while(reverseRest!=NULL)
	{
		printf("%d-> ",reverseRest->data);
		reverseRest= reverseRest->next;
	}
	printf("NULL\n");

	/*DeleteLinkedList(&head);*/
	/*Display(head);*/
	/*printf("List Length: %d\n",ListLength(head));*/
	return 0;
}
