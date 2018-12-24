#include <stdio.h>
#include <stdlib.h>

// basic binary tree
struct Node {

	int data; // veriyi tutacagimiz yapi.
	struct Node *left; // solu gosterecegimiz pointer.
	struct Node *right; // sagi gosterecegimiz pointer.
};

typedef struct Node Node;

struct Node* newNode(int data) {

	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data; // gelen data n dugumumuzun datasina esit olsun.
	n->left = n->right = NULL;
	return n;
}

int main() {
	Node *root = newNode(1); // kok dugumumuzu olusturduk.
	root->left = newNode(3); // kok dugumuzun soluna 3 degerini koyduk.
	root->right = newNode(4); // kok dugumuzun sagina 4 degerini koyduk.
	root->left->left = newNode(5); 

	return 0;
}