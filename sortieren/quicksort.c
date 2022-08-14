#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define size 500000

void randomize(int* nums, int size) {
	
	for (int i = 0; i < size; i++) {

		nums [i] = rand() % 100000;
	}
}

void printarray (int* nums, int size) {

	printf("[ ");
	for (int i = 0; i < size; i++) {

		printf("%d ", nums[i]);
	}
	printf("]\n");
}

int checker (int* nums, int size) {

	for (int i = 0; i < size-1; i++) {

		if (nums[i] > nums [i+1]) {
			return 1;
		}
	}
	return 0;
}



// Quicksort

int partition (int* nums, int p, int r) {


		int pivot = nums [r];

		int i = p-1;
		int j = p;

		for (j; j < r; j++) {


			if (nums [j] <= pivot) {
				
				i++;

				int temp = nums [j];
				nums [j] = nums [i];
				nums [i] = temp;
			}
		}

				int temp = nums [i+1];
				nums [i+1] = nums [r];
				nums [r] = temp;

				return i+1;
	


}


void quecksort (int* nums, int p, int r) {

	if (p < r) {

	int q = partition (nums, p, r);
	quecksort(nums, p, q-1);
	quecksort(nums, q+1, r);
	}

	return;
}


void quicksort (int* nums, int size) {


	quecksort (nums, 0, size-1);
}













int main (void) {


int* nums;
int n = 10000000;

nums = malloc (n*sizeof(int));

if ((nums = (int*) malloc (n*sizeof(int))) == NULL ) {printf("Malloc Failed!\n"); return 1;}
randomize (nums, n);
//printf("Array vor Sortierung:\n"); printarray (nums);


clock_t begin = clock();

quicksort(nums, n);

clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %lf\n", time_spent);

if (checker(nums, n) == 0) {printf("It worked\n"); }
else {printf("It did not work\n");}


//printf("Array nach Sortierung:\n"); printarray (nums);


free (nums);
nums = NULL;

return 0;
}
