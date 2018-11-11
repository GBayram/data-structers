// ####  Cift Bagli Liste ile alakali karisik ornekler ####

#include <stdlib.h>
#include <stdio.h>

struct  Node {

	int data;
	struct Node *next;
	struct Node *prev; // Cift bagli liste'de kendinden onceki dugumu de gosterecegi icin prev dugumunu tanimladik. 
};

typedef struct Node Node;

// BASA EKLEME
void push(Node **head_ref, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*head_ref);
	new_node->prev = NULL; // Basa eklendigi icin prev'i NULL olacaktir.

	if (*head_ref != NULL) {
		(*head_ref)->prev = new_node; // Eger head_ref NULL gelmezse "prev"i yeni olusacak head'i gostermelidir.
	}

	*head_ref = new_node; // yeni dugumu head yap.
}

// Head'den sonraki dugume(Araya) eleman ekleme.
void insertAfter(Node *head, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->prev = head; // new_node 'un prev'i bas dugumu(head) gosteriyor.
	new_node->next = head->next; // new_node'un next'i parametre olarak gelen(head'in) dugumun nextini gosteriyor.
	new_node->next->prev = new_node;// parametre olarak verilen dugumun nextinin previ yeni dugum olsun
	head->next = new_node;// //parametre olarak verilen dugumun nexti yeni dugum olsun

}

// SONA EKLEME...
void append(Node **head_ref, int data) {

	Node *temp = *head_ref;
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL; // Son dugum olacagi icin next'i NULL'ý gosteriyor.
	
	while (temp->next != NULL){		
		temp = temp->next; // Next'i NULL'dan farkli olana kadar donecek.
	}

	temp->next = new_node; // Son dugumun nextine yeni dugumu ekle.
	new_node->prev = temp; // yeni dugumun previ, eski dugum olsun.
}


void deleteNode(Node **head_ref, Node *del) {

	if (*head_ref == NULL || del == NULL) // Dugum bos ise.
		return;

	if (*head_ref == del) { // Bastaki dugum silinecek ise
		*head_ref = del->next; // Bas dugumu, silinecek olan dugumun next'i yap.
	}

	if (del->next != NULL) { // silinecek dugum sonda degilse
		del->next->prev = del->prev;
	}

	if (del->prev != NULL) { // silinecek dugum basta degilse
		del->prev->next = del->next;
	}

	// next ve prev degistikten sonra dugum silinecek.
	free(del);

}

void deleteKeyNode(Node **head_ref, int key) {

	Node *temp = *head_ref;

	// silinecek eleman ilk eleman ise;
	if (temp->data == key) {

		*head_ref = temp->next; // temp'in nextini head_ref yaptik.(Cunku bas dugum silineceginden dugumlerde diger 
								// elemanlara ulasmamiz icin silinecek bas dugumden bir sonraki dugumu bas dugum olarak atadik.)
		(*head_ref)->prev = NULL; // yeni bas dugumun prev'ini NULL yap.
		free(temp); // eski bas dugumu sil.	
	}
	else {

		while (temp->data != key) {
			temp = temp->next;
		}
		// yani son eleman silinecek ise;
		if (temp->next == NULL) {
			temp->prev->next = NULL;
			free(temp);
		}
		else { // arada bir eleman ise;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
	}

}

//dugumlerin sirasini degistirme:(son dugum ilk,sondan bir oncki 2.,.......ilk dugum son dugum olur)
void reverse(struct Node** head_ref) {
	struct Node* temp = NULL;
	struct Node* current = *head_ref;
	while (current != NULL) { // reverse islemleri:currenttekileri tersten preve tasidik
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL) { //yeni headi tempin previ yap
		*head_ref = temp->prev;
	}
}

void print(Node *head) {

	Node* temp = head;
	
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main() {

	Node *head = NULL;
	push(&head, 6);
	push(&head, 5);
	push(&head, 3);
	insertAfter(head, 4);
	append(&head, 7);
	print(head);
	printf("\n");
//	deleteNode(&head, head->next);
//  deleteKeyNode(&head,5);
	reverse(&head);
	print(head);
	return 0;
}