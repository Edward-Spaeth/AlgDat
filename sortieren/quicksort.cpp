#include <iostream>
#include <stdlib.h>
#include <time.h>


void randomize (long* nums, long size) {


	for (long i = 0; i < size; i++) {

		nums [i] = rand() % 100000;
	}
}


void printarray (long* nums, long size) {

	for (long i = 0; i < size; i++) {

		std::cout << nums[i] << " "; 
	}
	std::cout << std::endl;
}


bool checker (long* nums, long size) {

	for (long i = 0; i < size-1; i++) {

		if (nums[i] > nums [i+1] ) {
			return false;
		}

	}
	return true;
}






long partition (long* nums, long p, long r) {

	long pivot = nums [r];
	long i = p-1;
	long j = p;

	for (j=p; j < r; j++) {

		if (nums [j] <= pivot) {
			i++;
			long temp = nums [i];
			nums [i] = nums [j];
			nums [j] = temp;
		}
	}
	long temp = nums [r];
	nums [r] = nums [i+1];
	nums [i+1] = temp;

	return i+1;
}







void quecksort (long* nums, long p, long r) {

	std::cout << "quecksort aufgerufen" << std::endl;
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


	
	long size = 10000000;
	long const smallsize = 9;  
	//std::cin >> size;

	
	long* nums = new long [size];
	
	long smallnums [smallsize] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	randomize(nums, size);

	//printarray (nums, size);
	std::cout << "Test" << std::endl;
	clock_t begin = clock();


	quicksort (smallnums, smallsize);


	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	std::cout << "Time spent: " << time_spent << std::endl;

	//printarray (nums, size);




	if (checker (nums, size) == true) {
		
		std::cout << "Es hat funktioniert. Bool Wert ist: " << checker (nums, size) << std::endl;
	}
	else {

		std::cout << "Es hat nicht funktioniert. Bool Wert ist: " << checker (nums, size) << std::endl;
	}

	delete [] nums;

	return 0;
}
