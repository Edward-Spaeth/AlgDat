#include <iostream>
#include <stack>
#include <time.h>

void hanoi (int i, std::stack <int> *from, std::stack <int> *to, std::stack <int> *help) {

	if (i > 0) {
		
		hanoi (i-1, from, help, to);
		
		// move from "from" to "to"
		to->push (from->top ());
		from->pop ();
		
		hanoi (i-1, help, to, from);
	}
}


void hanoi_steps (int i, char from, char to, char help) {

	if (i > 0) {
		

		hanoi_steps (i-1, from, help, to);
		
		// move from "from" to "to"
		std::cout << "Move " << i << " from " << from << " to " << to << std::endl;

		hanoi_steps (i-1, help, to, from);
	}


}

void printstack (std::stack <int> *s) {

	if (s->empty ()) {

		std::cout << "Empty" << std::endl;
	}

	else {


		std::stack <int> helper;

		while (!s->empty ()) {
			std::cout << s->top () << " ";
			helper.push (s->top () );
			s->pop ();
		}

		while (!helper.empty ()) {

			s->push (helper.top ());
			helper.pop ();
		}

		std::cout << std::endl;

	}

	
}

int main (void) {

	std::stack <int> A;
	std::stack <int> B;
	std::stack <int> C;

	// A = Start
	// n = 25, 26, 27 ist gut um die Komplexität zu sehen
	int n = 4;

	for (int i = 0; i < n; i++) {

		A.push (n-i);
	}

	std::cout << "Vor Hanoi:" << std::endl << std::endl;

	std::cout << "A: ";
	printstack (&A);

	std::cout << "B: ";
	printstack (&B);

	std::cout << "C: ";
	printstack (&C);

		double hanoi_start = clock ();

	// n Scheiben, from A to B using C as help
	hanoi (n, &A, &B, &C);

		double hanoi_end = clock ();

		double hanoi_time = (hanoi_end - hanoi_start) / CLOCKS_PER_SEC;


	hanoi_steps (n, 'A', 'B', 'C');

std::cout << std::endl << "Nach Hanoi:" << std::endl << std::endl;

	std::cout << "A: ";
	printstack (&A);

	std::cout << "B: ";
	printstack (&B);

	std::cout << "C: ";
	printstack (&C);


	std::cout << std::endl << "Hanoi hat " << hanoi_time << " sekunden gebraucht" << std::endl; 

	// Braucht ungefähr 2 Sekunden für n = 25
	// Braucht ungefähr 62 Sekunden für n = 30


	/* 

	Hinweise zu Hanoi:
		Das kleinste Element wandert bei jedem zweiten Schritt um 1 nach links (Von A nach C,
		von C nach B, von B nach A)
		
		Bei jedem anderen Schritt gibt es nur einen legalen Zug WENN MAN das kleinste Element
		nicht bei seinem Zyklus stört!!! (Nicht Zielführend)

	*/

}
