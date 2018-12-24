#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack *createStack(unsigned capacity) {

	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	
	if (!stack)
		return NULL;

	stack->top = -1; // indis degerimiz.
	stack->capacity = capacity; 
	stack->array = (int *)malloc(stack->capacity * sizeof(int)); // eklenecek verilerin tutuldugu dizinin max. boyutu=int tipinin boyutu x(carpi) eklenebilecek max. veri sayisi
	return stack;

}

int isFull(struct Stack *stack) {
	return stack->top == stack->capacity - 1; // Dizinin indis degeri(top), toplam alabilecegi kapasite degererinin -1'ine 
										// esitse geriye 1 donderecek, degilse 0 donderecek..
}

int isEmpty(struct Stack *stack) {
	return stack->top == -1; // dizi boyutu -1'se(yani eleman eklenmemisse) 1 donderecek, degilse 0 donderecek.

}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

void push(struct Stack *stack, char item) {
	
	stack->array[++stack->top] = item;		
}


char pop(struct Stack *stack) {

	if (!isEmpty(stack)) { // stack bos degilse.
		return stack->array[stack->top--]; // bulundugu indis degerini cek.
	}
	return '$';
}

int evaluatePostfix(char *exp) {

	// Operator => + - * /
	// Operand => 3,5,A,B ...

	/*				####    CALISMA MANTIGI    ####
		Postfix islemi yaparken ilk olarak operandlar,operatorlerden once gelmektedir.
		Bastan sona okuma islemi yapilir. Eger postfix'te gelen ifade sayi ise stackte, degil ise
		iki sayi arasinda okunan operatore gore islem yapilir.

		Orn;
			Mesela stackta x ve y degerleri olsun. Biz x ve y degerlerine islem yaptirirken postfix olarak 
			karsiligini xy- seklinde almaliyiz. Eger postfix ifadenin sonucunu x-y seklinde alirsak hata yapmis oluruz.
			xy- islemi yaptiktan sonra burdan cikan sonuc tekrar stack'e atilir.
	*/

	struct Stack* stack = createStack(strlen(exp)); //exp dizisinin uzunlugu kadar bir stack alani olustur.

	for (int i = 0; i < exp[i]; i++) {

		if (isdigit(exp[i])) {
			push(stack, exp[i]-'0'); // ascii karakterlerinde 0->48,1->49,..... 9->57 ye karsilik gelir.char tipindeki bir rakam  48 ile 57 arasinda rakamlar 
			// alabieceginden,karakteri int'e cevirmek icin etkisiz eleman olan 0 in karsiligi olan 48 den cikaririz.Ornek: 3->51 ,'3'-'0' = 51-48=3
			//not:bu cevirme islemi sadece tek rakamli sayilar icin gecerlidir
		}
		else {
			int value1 = pop(stack);
			int value2 = pop(stack);

			switch (exp[i]) {

			case '+': push(stack, value2 + value1); break;
			case '-': push(stack, value2 - value1); break;
			case '*': push(stack, value2 * value1); break;
			case '/': push(stack, value2 / value1); break;
			}
		}
	}
	return pop(stack);
}
int main()
{

	char exp[] = "231*+4-";
	printf("Postfix ifade : %s \ndegeri= %d", exp, evaluatePostfix(exp));
	return 0;
}