// DIZIDE VERILEN IKI SAYI DEGERI ARASINDAKI FARKI BULMA...

#include <stdio.h>
#include <stdlib.h> // Matematik fonksiyonlarina ulasmak icin kullanilan kutuphane. (Orn: abs)
#include <limits.h> // Matematik fonksiyonlarinda int turunda max sayiyi bulmak icin kullaniliyor(INT_MAX)

int minDist(int arr[], int n, int x, int y) {

	int i, j;
	int min_dist = INT_MAX; // int turunde max sayiyi min_dist degiskenine atadik.

	for (i = 0; i < n ; i++)
	{
		for ( j = i+1 ;  j < n ;  j++)
		{	// Karsilastirma kosullarini sagladik.
			if ((x == arr[i] && y == arr[j] || y == arr[i] && x == arr[j]) && min_dist > abs(i - j)) {
				min_dist = abs(i - j);
			}
		}
	}

	return min_dist;
}



int main() {

	int arr[] = { 3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3 }; // Dizimizi tanimladik.
	int n = sizeof(arr) / sizeof(arr[0]); /* Dizimizin toplam boyutunu, herhangi bir tane elemanin boyutuna
	 bolersek dizinin toplam adedini buluruz. */

	// 3 ve 2 arasindaki mesafeyi bul.
	int x = 3; 
	int y = 2;
	
	printf("Minimum distance between %d and %d is %d\n", x, y, minDist(arr, n, x, y));
	return 0;


}