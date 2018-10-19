#include <stdio.h>

void value(int a, int b);

int main() {

	int sayi1 = 10;
	int sayi2 = 20;
	printf("Sayilarin Metoda gonderilmeden onceki degeri: %d , %d\n", sayi1, sayi2);
	value(sayi1, sayi2);
	printf("Sayilarin metoda gonderildikten sonraki degeri: %d , %d", sayi1, sayi2);
}

void value(a,b) { // Pass By Value(Degiskenin kopyasini gonderme)
	/* Main icerisinde tanimladigimiz sayi1 ve sayi2 degiskenlerini metota gonderip islem yaptirdiktan sonra 
	tekrar ekrana yazdirirsak bu degiskenlerde herhangi bir deger degisikligi olmayacaktir. Cunku biz metoda
	Pass By value olarak deger gonderiyoruz. Yani degisken olarak deger gonderdigimiz icin sayi1,sayi2 degiskenlerinin
	bir kopyasi value metoduna gonderiliyor. O sebepten dolayý metot icerisinde bir islem yapsak asli orjinalligini
	koruyacaktir...*/

	a++;
	b++;

}
