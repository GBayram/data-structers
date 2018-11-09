#include <stdlib.h>
#include <stdio.h>

struct Node {

	int data;
	struct Node *next;
};

typedef struct Node Node;

void push(Node **head_ref,int new_data) {

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}

void reverse(Node ** head_ref) {  // 2 adet '*' oldugundan dolayi bu metotta yaptigimiz degisiklikler
	// main metodu icerisindeki head dugumunu de etkliyecek. Cunku metoda gelen head_ref dugumu, 'head' dugumu-
	// nun adresini tutuyor. ( Bk: Call_By_Reference)

	/* Parametre olarak gonderilen listenin elemanlarini tersine cevirir.
	Ornek:
		   1,2,3,4 sayisini gonderdigimizde bize cikti olarak
		   4,3,2,1 'i verecek.*/


	Node *prew = NULL;
	Node *current = *head_ref;
	Node *next;

	while (current != NULL) { // 1

		next = current->next; // 2
		current->next = prew; // 3 
		prew = current; // 4 
		current = next; // 5
		
	}
	*head_ref = prew; // 6
	
		/* WHILE Dongusunun Calimasina bakalim.
	
		1. Adim:
				Verdigimiz sarti sagladigi surece while dongusunun icine girip orada islemleri yapacak.

		2. Adim: 
				next(gecici) dugumunde current->next'ini tuttuk. Cunku alttaki kodlarda head dugumundeki bas degeri
				head dugumunden koparip prew dugumune atayacagimiz icin head dugumune tekrar ulasmamiz gerekecek. Elimizde
				islem yapmamiz gereken baska degerler oldugu icin dugumun geri kalan elemanlarini bir yerde tutmamiz gerekiyor.
				Yani ilk adimda next (2->3->4->Null ) olacak.

		3. Adim:
				current ilk adimda 1 degerini tutuyor ve prew dugumude suanda NULL durumdadir. Biz 3. siradaki islemi yaptigimizda
				current su hale gelecektir " 1->NULL " . Dikkat edilirse 1 den sonra NULL geldiginden sonraki dugumleri kaybettik.
				Eger bizim 2.adimdaki gibi bir islemimiz olmasaydi head dugumunun diger elemanlarina ulasamayacaktik.(E isleminde 
				currenti tekrar head dugumune bagliyoruz.)

		4. Adim:
				current'i , prew'e atadik yani prew artik 1->NULL oldu.
		
		5. Adim:
				C isleminde kaybettigimiz dugumleri tekrar currente bagladik ve current:2->3->4->NULL halini aldi (yalniz bagladigimiz dugum
				programin basindaki dugum degildir.Su anda nextte 2->3->4->NULL var fakat prog. basinda dugumumuz 1 den basliyordu.Ama prew'e 
				baktigimizda ise baslangicta sadece NULL iceriyorken simdi 1->NULL iceriyor.Zaten dongunun yaptigi islemde bu.Currentten head 
				dugumunu koparip,prewde head yapmak.currentin tum elemanlarini koparip bir tek NULL kaldigindada current A sartina takilacak 
				ve donguden cikacaktir.

				______________________________________________________________________________________________________________________________
		2.ADIM:
		A-)current 2->3->4->NULL old.dan kontrolden gecer
		B-)next:3->4->NULL tutulur
		C-)current headi tutar.headde 2 old.dan ve prew 1->NULL old.dan current su hali alir:2->1->NULL
		D-)prew:2->1->NULL olur
		E-)current:3->4->NULL olur
		______________________________________________________________________________________________________________________________
		3.ADIM:
		A-)currentin headi 3 old.dan kontrolden gecer
		B-)next:4->NULL
		C-)current:3->2->1->NULL
		D-)prew:3->2->1->NULL
		E-)current:4->NULL
		______________________________________________________________________________________________________________________________
		4.ADIM:
		A-)currentin headi 4 old.dan takilmaz
		B-)next:NULL
		C-)current:4->3->2->1->NULL
		D-)prew:4->3->2->1->NULL
		E-)current:NULL
		______________________________________________________________________________________________________________________________
		5.ADIM:
		A-)currentin headi NULL kontrolden gecemez ve donguden cikar.
		______________________________________________________________________________________________________________________________
		DONGUNUN DISI:
		yeni head_ref prew oldu ve dugumlerimizi terse cevirmis olduk
		*/
	(*head_ref) = prew;
}

void goster(Node *head) { // Ekrana yazdirma metodu

	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
}

main() {
	
	Node *head = NULL;
	push(&head,4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	goster(head);
	printf("\n");

	reverse(&head);
	goster(head);
	return 0;
}