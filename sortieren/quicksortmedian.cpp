#include <iostream>
#include <stdlib.h>
#include <time.h>

void printarray (long* nums, long size) {

	std::cout << "[ ";
	for (long i = 0; i < size; i++) {

		std::cout << nums [i] << " ";
	}
	std::cout << "]" << std::endl;
}

void randomize (long* nums, long size) {


	for (long i = 0; i < size; i++) {

		nums [i] = rand() % 100;
	}
}

bool checker (long* nums, long size) {


	for (long i = 0; i < size-1; i++) {

		if (nums [i] > nums [i+1]) {
			return false;
		}
	}
	return true;
}


void median (long* nums, long p, long mid, long r) {

	if (nums[p] > nums [mid] ) {
		long temp = nums [p];
		nums [p] = nums [mid];
		nums [mid] = temp;
		//std::cout << "Case 1" << std::endl;
	}
	else {}
	if (nums [mid] > nums [r]) {

		long temp = nums [r];
		nums [r] = nums [mid];
		nums [mid] = temp;
		//std::cout << "Case 2" << std::endl;
	}
	else {}
	if (nums [p] > nums[mid]) {

		long temp = nums [p];
		nums [p] = nums [mid];
		nums [mid] = temp;
		//std::cout << "Case 3" << std::endl;
	}



}



long partition (long* nums, long p, long r) {

	long pivot;
	long mid;

	if (r-p == 3) {
		long mid = (p+r)/2;
		median (nums, p, mid, r);
		pivot = nums [mid];
	}
	
	else {
		pivot = nums [r];
	}


	long i = p-1;
	long j = p;

	for (j=p; j < r; j++) {

		if (nums [j] <= pivot) {
			i++;
			long temp = nums [j];
			nums [j] = nums [i];
			nums [i] = temp;
		}
	}
	
	if (r-p == 3) {
		long temp = nums [mid];
		nums [mid] = nums [i+1];
		nums [i+1] = temp;
	}

	else {
		long temp = nums [r];
		nums [r] = nums [i+1];
		nums [i+1] = temp;
	}
	return i+1;
}



void quecksort (long* nums, long p, long r) {

	if (p < r) {

		long q = partition (nums, p, r);
		quecksort (nums, p, q-1);
		quecksort (nums, q+1, r);

	}
	return;
}




void quicksort (long* nums, long size) {

	quecksort (nums, 0, size-1);
}


int main (void) {


	long size = 100000;
	long* nums = new long [size];

	randomize (nums, size);

	//printarray(nums, size);

	clock_t begin = clock();


	quicksort (nums, size);


	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	std::cout << "Time spent: " << time_spent << std::endl;

	//printarray(nums, size);


	if (checker(nums, size) == true) {
		std::cout << "Es hat funktioniert" << std::endl;
	}

	else {
		std::cout << "Es hat nicht funktioniert" << std::endl;
	}


	return 0;
}