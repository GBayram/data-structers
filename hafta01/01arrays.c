// Dizinin elemanlarini 2 basamak sola kaydirma...

#include <stdio.h>

void leftRotatebyOne(int arr[], int n)
{
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;

}

/* Bu metotta iki basamak sola kaydirma islemi yapacagimiz icin leftRotatebyOne metodunu iki kere donguye sokuyor. 
   Farkli bir metot acmak yerine leftRotatebyOne metodu parametrelerine de kac defa donecegini degisken olarak belirtim for'la dondurebiliriz.
*/
void leftRotate(int arr[], int d, int n)
{
	int i;
	for (i = 0; i < d; i++)
		leftRotatebyOne(arr, n);
}

// Dizimizin son halini ekrana yazdirdigimiz Metod.
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; // Dizimizi tanimladik. Boyutunu belirtmedigimiz icin kendisi algýlayacak.
	leftRotate(arr, 2, 7);
	printArray(arr, 7);
	getchar(); // Bu komut ekranda tusa basilmadan ekrani kapatmamak icin kullaniliyor.
	return 0;
}
