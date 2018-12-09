// Linked List'te REVERSE islemi...
// Ayrica POP VE PUSH metodlari Linked List'lerde Stack'e veri ekleme ve veri cekme islemleridir...
#include <stdio.h>
#include <stdlib.h>
#define bool int

struct sNode {

	char data;
	struct sNode *next;
};

typedef struct sNode sNode;

bool isEmpty(struct sNode* top);

// Stack'e veri ekleme islemi yaparken bagli list'lerde basa eleman ekleme gibi metodumuzu yaziyoruz.
void push(sNode **top_ref, int new_data) {

	sNode *new_node = (sNode *)malloc(sizeof(sNode));

	if (new_node == NULL) {
		printf("Stack overflow \n");
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int pop(sNode **top_ref) {

	char res;
	sNode *top;


	if (top_ref == NULL) {
		printf("Stack overflow \n");
	}
	else {

		top = *top_ref; // top_ref'in gosterdigi adresteki head degerini top dugumune ata.
		res = top->data; // bas dugumun datasini, res degiskenine ata.
		(*top_ref) = top->next; // top->next'i bas dugum yap.
		free(top); // top dugumunu sil.
		return res;
	}

}

void insertAtBottom(struct sNode** top_ref, int item)
{
	if (isEmpty(*top_ref))
		push(top_ref, item);
	else
	{
		int temp = pop(top_ref);
		insertAtBottom(top_ref, item);
		push(top_ref, temp);
	}
}

void reverse(struct sNode** top_ref)
{
	if (!isEmpty(*top_ref))
	{
		int temp = pop(top_ref);
		reverse(top_ref);
		insertAtBottom(top_ref, temp);
	}
}

void print(struct sNode* top)
{
	printf("\n");
	while (top != NULL)
	{
		printf(" %d ", top->data);
		top = top->next;
	}
}

int main() {

	sNode *head_Ref=NULL;

	push(&head_Ref, 30);
	push(&head_Ref, 20);
	push(&head_Ref, 10);

	printf("\n Original Stack ");
	print(head_Ref);
	reverse(&head_Ref);
	printf("\n Reversed Stack ");
	print(head_Ref);
	return 0;
}

bool isEmpty(struct sNode* top)
{
	return (top == NULL) ? 1 : 0;
}