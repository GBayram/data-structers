#include <stdio.h>

void referans(int *p, int *q);

int main() {

	int sayi1 = 10;
	int sayi2 = 20;
	printf("Degerler metoda gonderilmeden once: %d , %d \n", sayi1, sayi2);
	referans(&sayi1, &sayi2);
	printf("Degerler metoda gonderildikten sonra: %d , %d \n", sayi1, sayi2);
}

void referans(int *p, int *q) {
	// Burada ise degiskenin kopyasini degil yolunu deger olarak metoda gonderiyoruz. Burada orjinal haliyle islem yaptigi
	// icin asil degerlerde de degisiklik oluyor. Cikti sonucu: 11,21 olur.
	(*p)++;
	(*q)++;
}