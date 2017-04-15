#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int value;
	Node* right;
	Node* left;
};

void Add(Node** currentNode, int value);
Node* Search(Node* currentNode, int key);
void PrintPreOrder(Node* currentNode);
void PrintInOrder(Node* currentNode);
void PrintPostOrder(Node* currentNode);
void TreeTesting();

int main() 
{
	TreeTesting();
	return 0;
}

void TreeTesting()
{
	Node* tree = NULL;

	Add(&tree, 6);
	Add(&tree, 5);
	Add(&tree, 4);
	Add(&tree, 5);
	Add(&tree, 2);
	Add(&tree, 8);
	Add(&tree, 7);
	Add(&tree, 10);
	
	Node* searchPtr = Search(tree, 20);

	//PrintPreOrder(tree);
	//PrintInOrder(tree);

	getch();
}

Node* Search(Node* currentNode, int key)
{
	if (currentNode == NULL)
	{
		return NULL; // Nothing found
	}

	if (currentNode->value == key)
	{
		return currentNode;
	}

	if (key >= currentNode->value)
	{
		Search(currentNode->right, key);
	}
	else 
	{
		Search(currentNode->left, key);
	}
}

void PrintPostOrder(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}

	PrintPostOrder(currentNode->left);
	PrintPostOrder(currentNode->right);
	printf("%d\n", currentNode->value);
}

void PrintInOrder(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}

	PrintInOrder(currentNode->left);
	printf("%d\n", currentNode->value);
	PrintInOrder(currentNode->right);
}

void PrintPreOrder(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}

	printf("%d\n", currentNode->value);
	PrintPreOrder(currentNode->left);
	PrintPreOrder(currentNode->right);
}

void Add(Node** currentNode, int value)
{
	if (*currentNode == NULL)
	{
		*currentNode = malloc(sizeof(Node));
		(*currentNode)->value = value;
		(*currentNode)->left = NULL;
		(*currentNode)->right = NULL;
		return;
	}

	if (value >= (*currentNode)->value)
	{
		Add(&(*currentNode)->right, value);
	}
	else
	{
		Add(&(*currentNode)->left, value);
	}
}