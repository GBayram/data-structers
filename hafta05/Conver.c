#include <stdio.h>
#include <stdlib.h>

// ###### Listeyi, Dairesel(Cevrimsel) List'e cevirme.
struct Node {

	int data;
	struct node* next;
};

typedef struct Node Node;

// Liste icin basa ekleme fonksiyonu.
void push(Node **head_ref, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


// Parametre olarak gonderilen bagli listeyi, dairesel liste yapipi geriye donderir.
struct Node *circular(Node *head) {
	
	Node *temp = head;
	while (temp->next != NULL) { // temp'in next'i NULL olana kadar gez.
		temp = temp->next;
	}

	temp->next = head; // temp'in next'i NULL oldugunda, next'ine head'i ata. Boylelikle Dairesel bagli listi elde etmis oluyoruz.
	return head; // Geriye, parametre olarak gonderilen dugumu gonder.
}

// Dairesel Listi yazdirma metodu.
void goster(Node *head) {

	Node *temp = head;

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("/n");

}

int main() {

	Node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	head = circular(head); // burada dairesel list yapiyor.
	goster(head);
}