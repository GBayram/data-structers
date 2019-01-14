#include <stdio.h>

int main() {

	int *pointer;
	int **ciftpoint;
	int num = 20;
	pointer = &num;
	ciftpoint = &pointer;
	printf("%d", **ciftpoint); 
	/* 
	10. satirda ekrana bastirmak istedigimiz bilgi;
		
		ciftpoint adli pointerin tuttugu adres alanina git. Daha sonrasinda gitmis oldugu alanin icerisinde gosteri-
	  len adres bilgisine git ve gittigi adres bilgisinin degerini ekrana yazdir. Yani ciktimizin sonucu 
	  " 20 " olacaktir...
	  */
} 