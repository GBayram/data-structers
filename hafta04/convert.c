#include <stdlib.h>
#include <stdio.h>

 // ############## BAGLI LISTEYI, DAIRESEL LISTEYE CEVIRME #################
struct  Node {

	int data;
	struct Node *next;
};

typedef struct Node Node;

// Linked List basa eleman ekleme.
void push(Node **head_ref, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Parametre olarak gonderilen bagli listeyi, dairesel liste yapipi geriye donderir.	
struct Node *convert(Node *head) {

	Node *temp = head;
	while (temp->next != NULL) {// temp'in next'i NULL olana kadar gez.	
		temp = temp->next;
	}
	temp->next = head; // temp'in next'i NULL oldugunda, next'ine head'i ata. Boylelikle Dairesel bagli listi elde etmis oluyoruz.
	return head;  // Geriye, parametre olarak gonderilen dugumu gonder.
}



void printList(Node *head) {

	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
}

int main() {

	Node *head = NULL;
	push(&head, 15);
	push(&head, 10);
	push(&head, 5);
	head = circular(head); // burada dairesel list yapiyor.
	printList(head);
}