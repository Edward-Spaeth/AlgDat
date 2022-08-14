#include <stdio.h>
#include <stdlib.h>



int main (void) {


// COPYPASTED RANDOM ARRAY GENERATOR


int size;
   printf("Enter the size of array: ");
   scanf("%d",&size);
   int randArray[size];
   for(int i=0;i<size;i++)
     randArray[i]=rand()%1000;   //Generate number between 0 to 99


// COPYPASTED



/*

const int size = 10;

int randArray[10] = { 60 , 91 , 54 , 31 , 78, 425 , 4231 , 9 , 4 , 2 };


*/


// Unsorted Preview

printf("\nElements of the presorted array: \n");
  
  printf("[ ");
  
   for(int i=0;i<size;i++)
   {
     printf("%d ",randArray[i]);
   }

 printf("]\n");



// Insertionsort:


	for(int i = 1; i < size; i++) {

		int temp = randArray[i];
		int j = i - 1;
		while (j >= 0 && randArray[j] > temp ) { /* Wenn man "randArray[j] > temp" zu randArray[j] < temp macht,*/
								/* sortiert man absteigend. */		
			randArray[j+1] = randArray[j];
			j--;
			
		
		}
			
		randArray [j+1] = temp;





	}


// Output


printf("\nElements of the sorted array: \n");
  
  printf("[ ");
  
   for(int i=0;i<size;i++)
   {
     printf("%d ",randArray[i]);
   }

 printf("]\n");



return 0;

} 
