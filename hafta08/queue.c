#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct  Queue
{
	int front, rear, size;
	unsigned capacity;
	int *array;
};

typedef struct Queue Queue;

int isFull(Queue * queue) {
	return (queue-> size == queue->capacity);
}

int isEmpty(Queue * queue) {
	return (queue->size == 0);
}


Queue *createQueue(unsigned capacity) {

	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; // Rear'in ilk degerini burada veriyoruz.
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}


void enqueue(Queue *queue, int item) {
	
	if (isFull(queue)) {
		return;
	}

	// 45. satirdaki mantik;
	// Dizilerin indisi 0'dan basladigi icin kuyruga ekleme yaptigimiz da ilk eleman dizi[0]'a eklenmesi gerekmektedir.
	// createQueue metodunda dizinin indisini kapasitenin 1 eksigi kadar tanimladigimizdan dolayi burada dizinin
	// 0.indisine ulasmamiz icin kuyrugun indis degerini bir arttirip, kuyruk kapasitesine bolumunden kalani aldigimizda
	// 0. indise ulasmis bulunuyoruz.
	queue->rear = (queue->rear + 1) % queue->capacity; 
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;

	printf("%d kuyruga eklendi... \n",item);
}

int deQueue(Queue *queue) {

	if (isEmpty(queue)) {
		return INT_MIN;
	}

	// 60. satirda dizinin ilk indisin cekiyor ve cekme islemi bittikten sonra front(indisi) bir arttiriyor.
	// yani aslinda (front++) once islem yap sonra arttir gibi bir durum soz konusu.
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(Queue *queue) {

	if (isEmpty(queue)) {
		return INT_MIN;
	}
	return queue->array[queue->front];
}

int rear(Queue *queue) {

	if (isEmpty(queue)) {
		return INT_MIN;
	}
	return queue->array[queue->rear];
}

int main() {

	Queue *queue = createQueue(10);
	enqueue(queue, 5);
	enqueue(queue, 10);
	enqueue(queue, 15);
	enqueue(queue, 20);
	printf("\n");
	printf("%d kuyruktan cekildi...\n" , deQueue(queue));
	printf("%d kuyruktan cekildi...\n", deQueue(queue));

	printf("En ondeki eleman: %d\n", front(queue));
	printf("En sondaki eleman: %d\n", rear(queue));
}


/*

		ORNEK : Boyutu 3 olan bir kuyruga ekleme ve silme islemleri yapalim:
		Kuyruk ilk tanimlandiginda verileri; front = 0 | size = 0 | rear =2 ;

		1.Adim => Kuyruga Eleman Ekleme(1 Verisi):  rear = (2+1)%3 = 0; | size = 1 | front = 0 | Dizinin 0.indisi
		2.Adim => Kuyruga Eleman Ekleme(2 Verisi):  rear = (0+1)%3 = 1; | size = 2 | front = 0 | Dizinin 1.indisi
		3.Adim => Kuyruga Eleman Ekleme(3 Verisi):  rear = (1+1)%3 = 2; | size = 3 | front = 0 | Dizinin 2.indisi

			Kuyruktan Eleman Cekme Islemleri
		4.Adim => 0.indisi cekme => array[queue->front] yani => array[0] | item=1 | front=1 | size = 2
		5.Adim => 1.indisi cekme => array[queue->front] yani => array[1] | item=2 | front=2 | size = 1
	
		Soru => Front degiskeni ne ise yarar?
		Cevap : Front degiskeni siradan eleman cekmek istedigimizde bizim sirada olan ilk elemanimizi tutmamizi saglar.
		Yani front ilk tanimlandiginda deger 0'dýr. Ve Dequeue(Yani veri cekme islemi) yapilmadigi surece front degeri 
		asla arttirilmaz. Ne zaman Dequeue yapilirsa ilk olarak array[queue->front] islemi bir degiskene atilir.( Yani
		dizinin [0]. indisi.) Daha sonra Front islemi arttirilir. Boylelikle 0. indis alindiktan sonra front degerinin
		bir artmasi, yeni siradaki ilk elemani gostermeyi sagliyor.


		6.Adim => Kuyruga Eleman Ekleme(4 verisi): rear = (2+1)%3 = 0 | size = 2 | front = 2 | Dizinin 0.indisi

		7.Adim => 2.indisi cekme => array[queue->front] yani => array[2] | item=1 | front=(2+1)%3=0; | size = 1
		8.Adim => 1.indisi cekme => array[queue->front] yani => array[1] | item=2 | front=1			 | size = 0

*/