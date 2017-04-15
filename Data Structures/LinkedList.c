#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int value;
	Node* next;
};

void Add(Node** list, int value);
void Delete(Node** list, int keyValue);
void Sort(Node* list);
void DisplayList(Node* list);
void LinkedListTesting();

int main()
{
	LinkedListTesting();

	return 0;
}

void LinkedListTesting()
{
	Node* list = NULL;

	Add(&list, 5);
	Add(&list, 3);
	Add(&list, 4);
	Add(&list, 1);

	//Delete(&list, 5);

	Sort(list);

	DisplayList(list);

	getch();
}

void Sort(Node* list)
{
	Node* currentNode = list;

	int count = 0;
	for (count; currentNode != NULL; currentNode = currentNode->next)
	{
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		currentNode = list;
		while (currentNode->next != NULL)
		{
			if (currentNode->value > currentNode->next->value)
			{
				int temp = currentNode->value;
				currentNode->value = currentNode->next->value;
				currentNode->next->value = temp;
			}

			currentNode = currentNode->next;
		}
	}
}

void Delete(Node** list, int keyValue)
{
	Node* current = *list;
	int count = 0;
	while (current != NULL)
	{
		if (current->value == keyValue && count == 0)
		{
			Node* temp = current;

			*list = (*list)->next;

			free(temp);
			return;
		}

		if (current->next->value == keyValue)
		{
			Node* temp = current->next;

			current->next = current->next->next;

			free(temp);
			return;
		}

		current = current->next;
		count++;
	}
}

void DisplayList(Node* list)
{
	Node* current = list;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

void Add(Node** list, int value)
{
	Node* temp = malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;

	if (*list == NULL)
	{
		*list = temp;
		return;
	}

	Node* current = *list;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = temp;
}