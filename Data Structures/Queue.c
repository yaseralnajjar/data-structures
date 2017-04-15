#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int value;
	Node* next;
};

void Enqueue(Node** head, Node** tail, int value);
int Dequeue(Node** head, Node** tail);
void QueueTesting();

int main()
{
	QueueTesting();

	return 0;
}

void QueueTesting()
{
	Node* queue = NULL;
	Node* queueTail = NULL;

	Enqueue(&queue, &queueTail, 2);
	Enqueue(&queue, &queueTail, 7);
	Enqueue(&queue, &queueTail, 4);
	Enqueue(&queue, &queueTail, 5);
	Enqueue(&queue, &queueTail, 6);

	printf("%d, ", Dequeue(&queue, &queueTail));
	printf("%d, ", Dequeue(&queue, &queueTail));
	printf("%d, ", Dequeue(&queue, &queueTail));
	printf("%d, ", Dequeue(&queue, &queueTail));
	printf("%d, ", Dequeue(&queue, &queueTail));

	Enqueue(&queue, &queueTail, 100);
	printf("%d, ", Dequeue(&queue, &queueTail));

	getch();
}

void Enqueue(Node** head, Node** tail, int value)
{
	Node* newItem = malloc(sizeof(Node));
	newItem->next = NULL;
	newItem->value = value;

	if (*head == NULL)
	{
		*head = newItem;
		*tail = newItem;
		return;
	}

	(*tail)->next = newItem;
	*tail = newItem;
}

int Dequeue(Node** head, Node** tail)
{
	if (*head == NULL)
	{
		return;
	}

	if ((*head)->next == NULL)
	{
		*tail = NULL;
	}

	Node* temp = *head;

	int value = (*head)->value;
	*head = (*head)->next;

	free(temp);

	return value;
}