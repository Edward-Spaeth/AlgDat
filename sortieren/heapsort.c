#include <stdio.h>
#include <stdlib.h>

int size = 8;
int a[8] = {5,6,4,2,1,7,8,3};


void printarray(int *a) {

	printf("[ ");
 	for (int i=0; i < size; i++) {

 		printf("%d ", a[i]);
 	}
 	printf("]\n");
}








void heapify (int *a , int heapsize , int i ) {
 	int temp;
 	int maximum;

 	int l = 2 * i +1; 
 	int r = 2 * i +2; 
 	if ( (l < heapsize) && (a[l] > a [i]) ) {
 		maximum = l;
 	}
 	
 	else {
 		maximum = i;
 	}
 	
 	if ( (r < heapsize) && (a[r] > a[maximum]) ) {
 		maximum = r;
 	}
 	
 	if (maximum != i) {
 		
 		temp = a[i];
 		a[i] = a[maximum];
 		a[maximum] = temp;

		heapify (a , heapsize , maximum );
 	}
 	
 	
}





 void build_heap (int *a) {
 	int i=0;
 	for (i = size/2; i >= 1; i--) {

	heapify (a , size , i-1 );

	}
 }



 
 	
int main (void) {
	 	
			// Array Output
			printf("Presorted Array:\n");
			printarray(a);

	build_heap(a);
 	int temp;
 	int i = 0;
 	
 	for (i = size - 1; i >= 1; i--) {
		
		temp = a [0];
		a [0] = a[i];
		a [i] = temp;

 		heapify (a , i , 0);
 	}

 			// Array Output
 			printf("\nPostsorted Array:\n");
 			printarray(a);

 	return 0;
}



