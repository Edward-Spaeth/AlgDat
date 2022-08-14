#include <iostream>
#include <time.h>

long fib_array (long* fib_ergebnisse, int n) {
	
	int i = 2;
	while (i <= n) {

		fib_ergebnisse [i] = fib_ergebnisse [i-1] + fib_ergebnisse [i-2];
		i++;
	}

	return fib_ergebnisse [n];
}


long fib_iter (int n) {

	if (n <= 1) {
		
		return n;
	}

	else {
		long a = 0;
		long b = 1;
		long c;

		while (n >= 2) {	// Im Skript steht n > 2. Was Denke ich mal falsch ist

			c = a + b;
			a = b;
			b = c;

			n--;
		}

		return b;
	}
}


int main (void) {

	int n;

	std::cout << "Wievielte Fibonacci Zahl? ";
	std::cin >> n;								// ca. 150 ist längste Eingabe für n

	long* fib_ergebnisse = new long [n];

	fib_ergebnisse [0] = 0;
	fib_ergebnisse [1] = 1;

	for (int i = 2; i < n; i++) {
		fib_ergebnisse [i] = -1;
	}

	double arr_start = clock ();

	std::cout << "Die " << n << ". Fibonacci Zahl ist " <<
	fib_array (fib_ergebnisse, n) << std::endl;

	double arr_end = clock ();

	double arr_time = (arr_end - arr_start) / CLOCKS_PER_SEC;

	std::cout << "Array braucht " << arr_time << " sekunden" << std::endl << std::endl;

	double iter_start = clock ();

	std::cout << "Die " << n << ". Fibonacci Zahl ist " <<
	fib_iter (n) << std::endl;

	double iter_end = clock ();

	double iter_time = (iter_end - iter_start) / CLOCKS_PER_SEC;

	std::cout << "Iterativ braucht " << iter_time << " sekunden" << std::endl;


	/*

	Array braucht ca. 1,7 * 10 ^-5 =  0,000018 Sekunden (n = 150)
	Iterativ braucht ca. 2 * 10 ^-6 = 0,000002 Sekunden (n = 150)

	Unterschied:
	Iterativ ist ca. 10 mal schneller + weniger Speicherverbrauch 
	
	*/


	delete fib_ergebnisse;
	return 0;
}