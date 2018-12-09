#include <stdio.h>


void towerOfHanoi(int n, char S,char D, char A) {

	if (n == 1) {
		printf("\n Move disk 1 from rod %c to rod %c", S, D);
		return;
	}

	towerOfHanoi(n - 1, S, A, D);
	printf("\n Move disk %d from rod %c to rod %c",n, S, D);
	towerOfHanoi(n - 1, A, D, S);
}

int main() {

	int n = 4;
	towerOfHanoi(n, 'A', 'C', 'B');
	getche();
	return 0;
}