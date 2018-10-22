#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node * next;

};

typedef struct Node Node;


int basaEkle(Node **head_ref, int data) {

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	Node *temp = *head_ref;
	new_node->next = *head_ref; // next'i bas dugumu gostersin.

	if (*head_ref != NULL) {

		while (temp->next != *head_ref) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
	else {
		new_node->next = new_node; // hic eleman yoksa kendine dondur.
	}
	*head_ref = new_node; // bas dugume ata.
		
}

// ########### PARAMETRE OLARAK GONDERILEN DEGERDEN SONRASINA EKLEME YAPMA ###########
void insertAfter(Node *head, int data, int key) {

	while (head == NULL)
		return;

	Node *temp = head;
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	while (temp->data != key) {
		temp = temp->next;
	} 
	new_node->next = temp->next;
	temp->next = new_node;

}// ########### PARAMETRE OLARAK GONDERILEN DEGERDEN SONRASINA EKLEME YAPMA ###########



void printList(Node *head) {

	Node *temp = head;

	do{
		printf("%d ", temp->data);
		temp = temp->next;

	}while (temp != head);
}

int main() {

	Node *head = (Node *)malloc(sizeof(Node));
	Node *second = (Node *)malloc(sizeof(Node));
	Node *third = (Node *)malloc(sizeof(Node));

	head->data = 5;
	second->data = 10;
	third->data = 15;

	head->next = second;
	second->next = third;
	third->next = head;

	basaEkle(&head, 3);
	insertAfter(head, 7, 15);
	printList(head);
}