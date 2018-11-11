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
void insertAfter(Node **head, int data, int key) {

	Node *temp = *head;
	Node *new_node = (Node*)malloc(sizeof(Node*));
	new_node->data = data;

	if (*head == NULL) // bas dugum bossa(hic dugum yoksa)
		return; // geri dondur.

	// Gelen key degeri, head(bas dugume) esitse;
	if (temp->data == key) {
		new_node->next = temp->next;
		temp->next = new_node;
	}
	// degilse;
	else {
		while (temp->data != key) { // key degeri, temp'in datasindan farkli oldugu surece temp'in nextine git.
			temp = temp->next;
		}
		// Sona eleman ekleme.
		if (temp->next == *head) { // Eger temp'in nexti, bas dugum ise;
			new_node->next = *head; // new_node'un nexti bas dugumu gostersin.
			temp->next = new_node; // temp'in nexti de, new_nodu gostersin.
		}
		// Araya eleman ekleme.
		else {
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}
}
// ########### PARAMETRE OLARAK GONDERILEN DEGERDEN SONRASINA EKLEME YAPMA ###########



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