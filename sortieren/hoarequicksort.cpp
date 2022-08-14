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


// Ist dazu da um das TEILARRAY zu printen, welches gerade bearbeitet wird
void printpart (long* nums, long a, long b) {

	std::cout << "Für Index " << a << " bis " << b<< std::endl; 
	for (int i = a; i <= b; i++) {

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

void swap (long* nums, long a, long b) {

	long temp = nums [a];
	nums [a] = nums [b];
	nums [b] = temp;


	//std::cout << " swapping" << a << " and " << b << std::endl;
	//std::cout << "Values: " << nums[a] << " and " << nums[b] << std::endl;
}




long hoare_partition (long* nums, long p, long r) {

	long pivot = nums [p];
	
	long i = p-1;
	long j = r+1;

	while (true) {  // while (true) ist eine infinite loop genauso wie "for (;;)"
		

		//std::cout << "Pivot = " << pivot << std::endl;

		do {

			j--;
		}	while (nums [j] > pivot);

		//std::cout << "J = " << j << "	nums [j] = " << nums [j] << std::endl;

		do {

			i++;
		}		while (nums [i] < pivot);

		//std::cout << "I = " << i << "	nums [i] = " << nums [i] << std::endl;

		if (i < j) {

			swap (nums, i, j);

		}

		else {

			//std::cout << "j ist: " << j << std::endl;
			return j;
		}

	}

}







void quecksort (long* nums, long p, long r) {

	if (p < r) {
		long q = hoare_partition (nums, p, r);
		//std::cout << "q ist: " << q << std::endl;
		//printarray (nums, 9);
		//printpart (nums, p, q);
		quecksort (nums, p, q);

		//printpart (nums, q+1, r);
		quecksort (nums, q+1, r);
	}	
	return;
}





void quicksort (long* nums, long size) {

	quecksort (nums, 0, size-1);
}







int main (void) {


	
	long size = 10000000;
	
	long* nums = new long [size];

	//long const size = 9;
	//long nums [size] = {2, 1, 8, 5, 4, 7, 0, 3, 9};



	randomize(nums, size);

	//printarray (nums, size);

	clock_t begin = clock();


	quicksort (nums, size);


	clock_t end = clock();


	//printarray (nums, size);


	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	std::cout << "Time spent: " << time_spent << " Sekunden" << std::endl;

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