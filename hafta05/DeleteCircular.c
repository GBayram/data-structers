#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node * next;

};

typedef struct Node Node;


void push(Node **head_ref, int data) {

	Node *temp = *head_ref;
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	if (*head_ref == NULL) { // ekledigim dugum ilk dugum ise;

		new_node->next = new_node; // Cevrimsel oldugu icin next'i kendisini gosterir.
		(*head_ref) = new_node;
		return;
	}
	// Ilk eleman degilse, Next'i head_ref olan elemana kadar gitmeli, sonra son dugumun next'ini yeni dugum yapmaliyiz
	else {

		while (temp->next != *head_ref) {
			temp = temp->next;
		}
		
		temp->next = new_node; // son dugumun next'ini yeni dugumle degistir.
		new_node->next = *head_ref; // yeni dugumun next'i headi gostersin.
		*head_ref = new_node; // ve headi yeni dugum olarak degistir.
	}
	
}


// Parametre olarak gonderilen datayi iceren dugumu silme.


void deleteNode(Node **head_ref, int key) {

	// Burada ilk dugumun de silinme ihtimali oldugu icin CALL_BY_REFERENCE yontemini kullaniriz. Cunku head adresi degisebilir ve bunuda
	// bunuda ya geriye yeni dugum dondurerek yada geriye dugumun adresini dondurerek(call by reference) yapabiliriz.

	if (*head_ref == NULL) { // Liste bossa geriye don.
		return;
	}

	Node *temp = *head_ref;
	Node *prew = NULL; // Bu atamayi yapmazsak hata alacagiz.
	

	while (temp->data != key) {

		if (temp->next == *head_ref) {
			printf("Girmis oldugunuz deger bulunamadi... ");
			return;
		}
		prew = temp; // Prew'de bir onceki dugumu tutuyoruz. Cunku silme islemi yaptigimizda silinen dugumden onceki dugum ile silinen dugum
						// den sonraki dugumu birbirine baglamamiz lazim.
		temp = temp->next;
	}
	// burada uc ihtimal olusacaktir.
	// 1-) Silecegimiz veri basta olabilir.
	// 2-) Silecegimiz veri ortada olabilir.
	// 3-) Silecegimiz veri sonda olabilir.
	

	// Silecegimiz dugum BASTA ise...
	if (temp == *head_ref) {

	prew = *head_ref; // prew normalde silinecek dugumden bir onceki dugumu tutuyordu fakat burada yukaridaki while dongusune girmeyerek direk buraya geldi.

	while (prew->next != *head_ref) { // silinecek dugumu son dugum gosterdiginden son dugume gidilir.

		prew = prew->next;
		}
		*head_ref = temp->next; //head dugumunu ikinci dugum yaptik.
		 prew->next = *head_ref; // son dugum yeni dugum oldu.
		 free(temp);
	}
	// Silecegimiz dugum SONDA ise;
	else if (temp->next == *head_ref) {

		prew->next = *head_ref; // silinecek dugumu gosteren dugumun next'ini head'e ata.
		free(temp);
		}

	// Silecegimiz dugum ORTADA ise;

	else {

		prew->next = temp->next; //silinecek dugumden onceki dugum,silinecek dugumden sonraki dugumu gostersin
		free(temp); // Aradaki dugumu sil.
	 }
	}

void goster(Node *head){

	Node *temp = head;

	do {

		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);
}

int main() {

	Node *head = NULL;
	
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	goster(head);
	printf("\n");

	deleteNode(&head, 1);
	deleteNode(&head, 5);
	deleteNode(&head, 8);
	goster(head);
}