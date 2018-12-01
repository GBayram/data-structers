#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {

	int *array; // Gelen verileri tutacak. (Ilk tanimlandiginda boyutunun kac olacagi belli olmadigi icin -
					// pointer seklinde tanimladik.(Fakat dizi mantigi ile calisacak.)
	
	int capacity; // kapasiteyi tutacak.(yani dizinin kac elemanli olacagini belirtir.)
	int top; // icinde kac tane veri oldugunu tutacak.(Dizinin indis degeri)

};

typedef struct Stack Stack;

// Stack ilk olusturuldugunda boyutuna gore yer ayiran fonksiyon.
Stack *createStack(int capacity) {

	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity; // stack'e eklenebilecek max. veri sayisi.
	stack->top = -1; // icinde hic eleman olmadigindan(ici bos oldugundan)dolayi alt satirlarda eleman islemi yaparken
					// dizinin indisini buradan cekecegimiz icin ilk veri eklendiginde dizi indisi 0 olur.(Dizi indisleri 0'dan baslar.)

	// eklenecek verilerin tutuldugu dizinin max. boyutu=int tipinin boyutu x(carpi) eklenebilecek max. veri sayisi
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(Stack *stack) {
	return stack->top == stack->capacity - 1; // Dizinin indis degeri(top), toplam alabilecegi kapasite degererinin -1'ine 
										// esitse geriye 1 donderecek, degilse 0 donderecek..
}


int isEmpty(Stack *stack) {
	return stack->top == -1; // dizi boyutu -1'se(yani eleman eklenmemisse) 1 donderecek, degilse 0 donderecek.
}

// Stack'e ekleme islemi.
void push(Stack *stack, int item) {

	if (isFull(stack)) {// Eger gelen dugum doluysa geriye 1 dondurur. Sadece if blogu calisir.(Stack dolu oldugundan ekleme yapilmaz...)
		return;
	}

	// ++stack->top : Ilk once stack->top'un degerini 1 arttir. Sonra atama islemini gerceklestir demektir.
	// Orn: Ilk eleman eklenecek ise;
	// dizi[-1] oldugu icin, ilk olarak indis degeri arttirilir dizi[0] olur, sonra dizi[0]'a eleman atamasi yapilir. Cunku dizinin indisi 0'dan baslar.
	stack->array[++stack->top] = item;
}

// Stack'ten veri cekme islemi.
int pop(Stack *stack) {

	if (isEmpty(stack)) { // Eger pop etme islemi bittiyse, yani stack'te eleman kalmadiysa geri don.
		return -1;
	}

	return stack->array[stack->top--]; // stack->top-- : ilk once atama islemi yapilir. Daha sonra eksiltme islemi yapilir.(eksiltme isleminden sonra
							// tekrar veri cekmek istersek kaldigi yerdeki veriyi dondurur.(daha sonra eksiltir. Bu boyle stack bosalana kadar devam eder)
}

int main() {

	Stack *stack = createStack(3);
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d ", pop(stack));
	printf("%d ", pop(stack));
	printf("%d ", pop(stack));
}