#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int value;
	Node* next;
};

void Add(Node** list, int value);
void Sort(Node* list);
void DeleteRepeated(Node* list);
void CopyList(Node* list, Node** newList);
void DisplayList(Node* list);
void LinkedListTesting();

int main()
{
	LinkedListTesting();

	return 0;
}

void LinkedListTesting()
{
	Node* list1 = NULL;

	Add(&list1, 7);
	Add(&list1, 5);
	Add(&list1, 5);
	Add(&list1, 5);
	Add(&list1, 5);
	Add(&list1, 3);
	Add(&list1, 4);
	Add(&list1, 1);

	Node* list2 = NULL;
	CopyList(list1, &list2);
	Sort(list2);

	Node* list3 = NULL;
	CopyList(list2, &list3);
	DeleteRepeated(list3);

	DisplayList(list3);

	getch();
}

void CopyList(Node* list, Node** newList)
{
	Node* current = list;
	while (current != NULL)
	{
		Add(newList, current->value);

		current = current->next;
	}
}

void DeleteRepeated(Node* list)
{
	Node* currentNode = list;
	Node* previousNode = NULL;

	while (currentNode != NULL)
	{
		if (previousNode != NULL)
		{
			if (previousNode->value == currentNode->value)
			{
				Node* temp = currentNode;

				if (currentNode->next == NULL)
				{
					previousNode->next = NULL;
				}
				else
				{
					previousNode->next = currentNode->next;
				}

				free(temp);

				currentNode = previousNode;
			}
		}

		previousNode = currentNode;
		currentNode = currentNode->next;
	}
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