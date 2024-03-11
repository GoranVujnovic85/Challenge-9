/*
 ============================================================================
 Name        : Challenge_23.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description : zadatak 4:
               funkcija insert  dodaje element na kraj ako je index 0, ili na pocetak liste ako je index 1
               u slucaju loseg indeksa funkcija vraca gresku 1 - ERR
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ERR 1

typedef struct Node
{
    int element;
    struct Node* next;
} Node;

Node* head = NULL;

void insert_end(Node** root, int element)
{
	Node* new_node = malloc(sizeof(Node));

	if(new_node == NULL)
	{
		printf("Neuspela alokacija memorije\n");
	}

	new_node->next = NULL;
	new_node->element = element;

	if(*root == NULL)
	{
		*root = new_node;

		return;
	}

	Node* curr = *root;

	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;

}

void insert_begin(Node** root, int element)
{
	Node* new_node = malloc(sizeof(Node));

	if(new_node == NULL)
	{
		printf("Neuspela alokacija memorije\n");
	}

	new_node->next = *root;
	new_node->element = element;

	*root = new_node;
}

int insert(Node** root, int element, int index)
{
	if(index != 0 && index != 1)
	{
		return ERR;
	}
	if(index == 0)
	{
		insert_end(root, element);
	}
	if(index == 1)
	{
		insert_begin(root, element);
	}
	return 0;
}

void deallocate(Node** root)
{
	Node* curr = *root;
	while(curr != NULL)
	{
		Node* aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

int main(void)
{
	Node* root = head;

	insert(&root, 1, 0);
	insert(&root, 10, 0);
	insert(&root, 100, 0);
	insert(&root, 1000, 1);
	insert(&root, 10000, 1);
	insert(&root, 100000, 1);

	Node* curr = root;
	while(curr != NULL)
	{
		printf("%d\n", curr->element);

		curr = curr->next;
	}

    deallocate(&root);

    return 0;
}
