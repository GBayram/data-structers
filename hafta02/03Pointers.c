#include <stdio.h>
#include <stdlib.h>

int f(int *);
int g(int);
int main() {

	int a = 10;
	int *p;
	p = &a;
	printf("%d \n", *p);
	*p = 20; // Pointerin gosterdigi yerdeki degeri 20 yapiyoruz. 
	printf("%d \n", a); // Dolayisiyla a'nin degeri de otomatik olarak degismis oluyor.

	int *q = (int *)malloc(sizeof(int)*a); // 20 tane elemanin oldugu bir dizi olusturacak.
	q[3] =70; // Bu bir pointer ama dizi seklinde kullaniyoruz. 
	printf("\n %d", q[3]);

	f(&a); 
	printf("\n %d", a);
	g(a);
	printf("\n %d", a);
		
};

int g(int a) { // Call By Value(Deger ile cagirma)

	// Burada degiskenin kendisini degil bir kopyasini metoda yolladigimiz icin, metot icerisinde yapilan degisiklikler
	// degiskenin degerini etkilemeyecektir...
	a = 90;
};

int f(int * a) { // Call By Reference

	// Burada bir pointer tanimlaniyor. Metota pointerin adresini aliyor. Ve burada yapilan degisiklik degiskenin orjinal 
	// halini de degistirir.
	*a = 80;
};