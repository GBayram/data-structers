#include <stdio.h>
#include <stdlib.h>


struct Node{

	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node Node;

void push(Node **head_ref, int new_data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL; // bas dugum olacagi icin prev'i NULL'i gosterecek.

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node; // Bas eleman new_node olacagi icin, eski head_ref'in previ
										// kendindne onceki dugumu gostermek zorundadir.

	(*head_ref) = new_node; // bas dugum new_node oldu.
}

// EKRANA YAZDIRMA
void printList(Node *head) {

	Node *temp = head;

	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main() {

	Node *head = NULL;
	push(&head, 10);
	push(&head, 15);
	printList(head);
}