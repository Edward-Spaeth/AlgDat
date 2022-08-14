#include <iostream>
#include <stdlib.h>
#include <time.h>

void randomize (int* nums, int size) {

	for (int i = 0; i < size; i++) {

		nums [i] = rand() % 20;
	}
}


void printarray (int* nums, int size) {

	std::cout << "[ ";
	for (int i = 0; i < size; i++) {

		std::cout << nums [i] << " ";
	}
	std::cout << "]" << std::endl;
}

bool checker (int* nums, int size) {

	for (int i = 0; i < size-1; i++) {

		if (nums [i] > nums [i+1]) {
			return false;
		}
	}
	return true;
}

void printblank (int a) {

	while (a > 0) {
			std::cout << " "; 
			a--;

	}
}






void printtree (int* nums, int size, int height) {


	for (int i = 0; i < size; i++) {

		printblank (5);
		std::cout << nums [i] << " ";
		printblank (2*i);
	}
}


void swap (int* nums ,int a, int b) {

	int temp = nums [a];
	nums [a] = nums [b];
	nums [b] = temp;
}




	void heapify (int* nums, int heapsize, int i) {

			int max;

			int l = 2 * i + 1;
			int r = 2 * i + 2;

			if ( (l < heapsize) && (nums [i] < nums [l]) ) {
				max = l;
			}

			else {
				max = i;
			}
		
			if ( (r < heapsize) && (nums[max] < nums [r]) ) {
				max = r;
			}

			
			if (max != i) {
				
				swap (nums, i , max);

				heapify (nums, heapsize, max);
			}


	}

	



	void build_max_heap (int* nums, int size) {

		for (int i = size/2; i >= 1; i--) {

			heapify (nums, size, i-1);
		}
	}





	void heapsort (int* nums, int size) {

		for (int i = size-1; i >= 1; i--) {

			swap (nums, 0, i);

			heapify (nums, i, 0);
		}
	}



int main (void) {

	int size = 15;
	int height = 5;

	int* nums = new int [size];

	randomize (nums, size);

	printarray (nums, size);


	build_max_heap(nums, size);
	heapsort (nums, size);

	printarray (nums, size);
	
	std::cout << std::endl << std::endl << std::endl;

	printtree (nums, size, height);



	if (checker(nums, size) == true) {
		std::cout << "Es hat geklappt" << std::endl;
	}

	else {
		std::cout << "Es hat nicht geklappt" << std::endl;
	}


	delete [] nums;

	return 0;
}