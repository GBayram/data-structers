#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node *next;

};


int main() {

	/* uc tane Pointerimizi olusturduk. Bunlari olusturmadan next ile de islem yapabilirdik. Mesela sadece head(baslangic
		 pointeri)'i olusturup geri kalani " haed->next = (Node*)malloc(sizeof(Node)); " olarakta olusturabilirdik. */
		 // NOT: Tum listeyi temsil eden muhakkak bir tane baslangic pointeri olmalidir(head gibi)	
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node)); // Bir tane Node'un hafizada kapladigi kadar yeri bana ayir. 
	second = (struct Node*)malloc(sizeof(struct Node));		// Ben bu alani bir node olarak kullanayim. 
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 5;
	head->next = second;
	second->data = 6;
	second->next = third;
	third->data = 7;
	third->next = NULL;
	printf("%d \n", &(head->next)); // second'in hafizadaki yerini gosterir.
	printf("%d", head->data); // Head'in data degerini ekrana yazdirir
	getche(); // tusa basmadan ekrani kapatma.
	return 0;
}