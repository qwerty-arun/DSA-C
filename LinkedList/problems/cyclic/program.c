#include <endian.h>
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

void makeLoop(struct ListNode** head)
{
	struct ListNode* p = *head;
	int length = ListLength(p);
	int k =0;
	while(p->next!=NULL && k<length)
	{
		p=p->next;
		k++;
	}
	p->next = (*head)->next->next;
}

int DoesListHasLoop(struct ListNode* head)
{
	struct ListNode* slowPtr = head, *fastPtr = head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr)
			return 1;
	}
	return 0;
}


void detectLoop(struct ListNode* head) //This doesn't work because we don't know the start of the loop, therefore it ends in an infinite loop
{

	struct ListNode* p = head;
	while (p->next!=NULL) {
		struct ListNode* q = p;
		struct ListNode* temp = q;
		while(q->next!=NULL)
		{
			if(q->next == NULL)
			{
				printf("The list DOESN'T have any loop!\n");
				return;
			}
			if(q->next == temp)
			{
				printf("The list does have a loop!\n");
				return;
			}
			q = q->next;
		}
		p=p->next;
	}
}

struct ListNode* FindBeginofLoop(struct ListNode* head)
{
    struct ListNode *slowPtr = head, *fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next)  // Detect loop
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)  // Cycle detected
        {
            slowPtr = head;  // Reset slowPtr to head

            while (slowPtr != fastPtr)  // Find loop start
            {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return slowPtr;  // This is the loop start node
        }
    }
    return NULL;  // No loop found
}

int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	InsertElement(&head, 5, 1);
	InsertElement(&head, 7, 1);
	InsertElement(&head, 8, 2);
	InsertElement(&head, 0, 2);
	InsertElement(&head, 2, 1);
	Display(head);
	makeLoop(&head);
	int ans = DoesListHasLoop(head);
	if(ans==1)
	{
		printf("The list does have a loop!\n");
	}
	else
	{
		printf("The list DOESN'T have a loop!\n");
	}
	/*detectLoop(head);*/
	struct ListNode* startLoop = FindBeginofLoop(head);
	if(startLoop == NULL)
	{
		printf("There is no loop!\n");
	}
	else
		printf("The Beginning of the loop: %d",startLoop->data);
	return 0;
}
