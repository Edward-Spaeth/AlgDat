#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10000
#define cycles 15


void randomize (int* a) {
	
	for (int i = 0; i < size; i++) {

		a[i] = rand() % 10000;
	}
}

int checker (int* a) {

	for (int i = 0; i < size-1; i++) {

		if (a[i] > a [i+1] ) {

			return 1;
		}
	}
	return 0;
}

void bubblesort (int* a) {

	for (int i = 0; i < size; i++) {
	int temp;
		for (int j=0; j < size-1-i; j++) {

			if (a[j] > a [j+1]) {
				temp = a [j];
				a [j] = a [j+1];
				a [j+1] = temp;
			}
		}
	}
}

void bubblesortreverse (int* a) {

	for (int i = 0; i < size; i++) {
	int temp;
		for (int j=0; j < size-1-i; j++) {

			if (a[j] < a [j+1]) {
				temp = a [j];
				a [j] = a [j+1];
				a [j+1] = temp;
			}
		}
	}
}


int main (void) {

double gesamt=0;
for (int l = 0; l < cycles; l++) {


	int a[size];
	int diditwork;

	randomize (a);

	//bubblesort(a);
	//bubblesortreverse(a);

	// Messung Start
	clock_t begin = clock();




	bubblesort(a);



	// Messung Stop
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %lf\n", time_spent);
	
	gesamt += time_spent;

	if ((diditwork = checker (a)) == 0) {
		printf("\nIt worked\n");
	}
	else {
		printf("\nIt didn't work\n");
	}

	printf("\n");

	}
	
	printf("Gesamt: %lf\n", gesamt/cycles);
	return 0;

	}