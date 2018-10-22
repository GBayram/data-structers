#include <stdio.h>
#include <stdlib.h>


struct Node {

	int data;
	struct Node *next;
};


typedef struct Node Node;


void push(Node **head_ref, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node)); // yeni dugumumuzu olusturduk.
	new_node->data = data; 
	new_node->next = (*head_ref); // yeni dugumun nexti artik bas elemani gosteriyor.(Yani kendisini)
	(*head_ref) = new_node; // dugumu head'e atadik.
}

void search(Node *head, int key) {

	Node *temp = head;
	int count = 1;

	while (temp != NULL) {

		if (temp->data == key) {
			printf("\nAradiginiz deger %d. satirda bulundu: %d",count, temp->data);
			return;
		}
		else {
			temp = temp->next;
			count++;
		}
	}
	printf("\nAradiginiz deger bulunamadi...");
}

void printList(Node *node) {

	Node *temp = node;

	while (temp != NULL) {

		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main() {

	Node *head = NULL;
	push(&head, 10);
	push(&head, 5);
	push(&head, 3);
	printList(head);
	search(head,10);
}