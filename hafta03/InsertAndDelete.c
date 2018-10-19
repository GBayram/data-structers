#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node *next;
};

typedef struct Node Node;

// Burada PASS_BY_REFERANCE YONTEMI KULLANDIK. CUNKU PUSH() METODU ICERISINDEKI YAPTIGIMIZ DEGISIKLIKLERIN MAIN FONKSIYO
// NU ICINDE DE GECERLI KILMASINI SAGLAMAKIR...
void push(Node **head_ref, int data) { // PASS_BY_REFERENCE ISLEMI OLDUGU ICIN IKI TANE(**) KOYDUK.

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*head_ref); // Yeni dugumumuzun nextini, ilk dugumumuze bagladik.
	(*head_ref) = new_node; // ilk olusturdugumuz head dugumunu de, yeni olusturdugumuz dugum ile guncelledik. Boyle-
	// likle head dugumu hala ilk dugumu gosteriyor.
}

/* push() fonksiyonunda yaptigimiz seyler.
1 - ) Yeni dugum icin bellekten yer ayir.
2 - ) Yeni dugumun nextine ilk dugumu ver.
3 - ) Yeni dugumu head yap.

SORU = > Eger 1 adimindan sonra 2 degilde 3 adimi yapilirsa ne olur ?
CEVAP = > head listedeki 2. dugumun, 2.dugum 3.dugumun.....adresini tuttugu icin yeni dugumu head yaparsak,
onceki head dugumunun gosterdigi 2. dugumu dolayisiylada tum listeyi kaybederiz. */

// ---------------------------------------------------------------------------------------------

// ###### ARAYA EKLEME YAPMA ISLEMI ######
void insertAfter(Node *prev_node, int data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = prev_node->next; // head'imizin next'ini, yeni olusturdugumuz dugumun nextine atadik.
	prev_node->next = new_node; // head'in nexti artik yeni ekledigimiz dugumu gosteriyor.
}
// ###### ARAYA EKLEME YAPMA ISLEMI ######

// ---------------------------------------------------------------------------------------------

// ###### SONA EKLEME YAPMA ISLEMI ######
void append(Node **head_ref, int data) {

	Node *temp = *head_ref;
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL; // dugum listenin son elemanina eklenecegi icin son elemandan sonrasini NULL yaptik.
	

	while (temp == NULL) { // tek elemanli ise.
		(*head_ref) = new_node;
	}

	while (temp->next != NULL) { // dugumun sonuna kadar git.

		temp = temp->next;
	}

	temp->next = new_node;
}
// ###### SONA EKLEME YAPMA ISLEMI ######

// ---------------------------------------------------------------------------------------------

// ###### PARAMETRE OLARAK GONDERILEN DEGERDEN SONRAKI LIST'E ELEMAN EKLEME ######
void parInsert(Node **head_ref, int data, int after) {

	Node *temp = *head_ref;
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	while (temp -> data != after) {
		
		temp = temp->next;
		new_node->next = temp->next;	
	}
	
	temp->next = new_node;
}
// ###### PARAMETRE OLARAK GONDERILEN DEGERDEN SONRAKI LIST'E ELEMAN EKLEME ######


// ---------------------------------------------------------------------------------------------


// ###### PARAMETRE OLARAK VERILEN SAYISI ICEREN DUGUMU SILER ########
void deleteRotate(Node **head_ref, int poisition) {

	if (*head_ref == NULL) // Bas dugum bossa geri don
		return;

	Node *temp = *head_ref; // temp ile head ayni yeri gosteriyor.

	// eger key degeri 0 ise bas dugumu siler.
	if (poisition == 0) {

		*head_ref = temp->next;
		free(temp);
		return;
	}

	//listenin sonuna gelinceye kadar veya aranan pozisyonun bir eksigine kadar ilerle
	for (int i = 0; temp != NULL && i < poisition - 1; i++) {
		temp = temp->next;
	}
	if (temp == NULL || temp->next == NULL) {//sona geldi ise geri don
		return;
	}

	Node *next_node = temp->next->next;
	free(temp->next);
	temp->next= next_node;

	/* Burada dikkat edilmesi gereken husus;
		Silinecek olan List'in next'i ile bir onceki List'nin baglantisi yapmaktir.*/
}
// ###### PARAMETRE OLARAK VERILEN SAYISI ICEREN DUGUMU SILER ########

// ---------------------------------------------------------------------------------------------

// ###### PARAMETRE OLARAK VERILEN SAYIYI ICEREN DUGUMU SILER ########

void deleteNode(Node** head_ref, int key) {

	Node *temp = *head_ref, *prew;

	// Eger gelen deger ilk eleman ise, silme islemi.
	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next;
		free(temp);
	}

	while (temp != NULL && temp->data != key) {
	    prew = temp;
		temp = temp->next;

		/*
		parametre olarak verilen sayiyi iceren dugum,listenin basinda,sonunda veya ortasinda olabilir.eger basinda ise yukaridaki if blogu gerceklesir.eger ortasinda ise
		silinecek olan dugumun oncesindekinede ihtiyacimiz vardir.cunku dugumu silmeden once,silinecek dugumun oncesindeki dugumu silinecek dugumden sonraki dugume
		baglamaliyiz ki dugumleri kaybetmeyelim.yukaridaki while dongusundede silinecek dugum bulunmaya calisiliyor ayni zamandada silinecek dugumden onceki dugumude elimizde
		tutmaya calisiyoruz(temp silinecek dugum,prew ise silinecek dugumden onceki dugumu ifade ediyor)
		*/
			
	}
	// Yani aradigimizi bulamadik.
	if (temp == NULL) {
		return;
	}

	//yukaridaki if gerceklesmedi ise aradigimiz datayi bulduk demektir.
	prew->next = temp->next->next; // Silinecek dugumun bir onceki dugumunun nextini, bir sonraki dugumun nextine atadik.
	free(temp); // dugumu sildik
	
}
// ###### PARAMETRE OLARAK VERILEN SAYIYI ICEREN DUGUMU SILER ########


// ---------------------------------------------------------------------------------------------

void printList(Node *node) {

	while (node != NULL) {

		printf("%d ", node->data);
		node = node->next;
	}
}


int main() {

	Node *head = NULL; // head isimli bas dugumumuz olusturduk.
	push(&head, 20);
	push(&head, 10);
	insertAfter(head, 15);
	parInsert(&head, 23, 20);
	append(&head, 25);
	deleteRotate(&head, 3);
	printList(head);


}