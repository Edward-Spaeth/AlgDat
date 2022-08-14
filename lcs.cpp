#include <iostream>
//#include <string>
#define WE 0
#define NW 1
#define NO 2

#define g_m 4+1
#define g_n 5+1

struct Cell {

	int direction;
	int len;

	Cell ();

};

	Cell::Cell () {

		direction = 5;
		len = 0;
	}

Cell chart [g_m] [g_n];

void print_lcs (std::string X, int i, int j) {

	if (i == 0 || j == 0) {
		return;
	}

	if (chart [i] [j].direction == NW) {
		print_lcs (X, i-1, j-1);
		std::cout << X [i-1] << " ";
	}

	else
		if (chart [i] [j].direction == NO) {
			print_lcs (X, i-1, j);
		}

		else {
			print_lcs (X, i, j-1);
		}
}



void print_table (int m, int n) {

	std::cout << std::endl << std::endl;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {


			std::cout << chart [i] [j].len << " ";

		}

		std::cout << std::endl;
	}		

	std::cout << std::endl;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			if (chart [i] [j].direction == 5) {

				std::cout << "  ";
			}
			else

			if (chart [i] [j].direction == 0) {
				std::cout << "\u2190" << " ";
				//std::cout << "←" << " ";
			}
			else {
				if (chart [i] [j].direction == 1) {
					std::cout << "\u2196" << " ";
					//std::cout << "⬉" << " ";
				}

				else {
					std::cout << "\u2191" << " ";
					//std::cout << "↑" << " ";
				}
			}
		

		}

		std::cout << std::endl;
	}		


}


int main (void) {

	// X: von unten nach oben
	// Y: von links nach rechts
	
//	std::string X = "TGCGTCCAT";	// 9+1
//	std::string Y = "TACGTGCGCT";	// 10+1

	std::string X = "ACGT";
	std::string Y = "AGCTA";



	int m = g_m;
	int n = g_n;



	std::cout << "X Size: " << X.length () << "   Y Size: " << Y.length () << std::endl;



	for (int i = 1; i < m; i++) {

		for (int j = 1; j < n; j++) {

			if (X [i-1] == Y [j-1]) {	// Neuer Teil des Substring. Also Länge = alte Länge + 1

				chart [i] [j].len = chart [i-1] [j-1].len + 1;
				chart [i] [j].direction = NW;
			}

			else
				if (chart [i-1] [j].len >= chart [i] [j-1].len) {

					chart [i] [j].len = chart [i-1] [j].len;
					chart [i] [j].direction = NO;
				}

				else {

					chart [i] [j].len = chart [i] [j-1].len;
					chart [i] [j].direction = WE;
				}

		}
	}


	//////////////////// Print Result /////////////////////////

	std::cout << std::endl << "LCS:" << std::endl;

	print_lcs (X, m-1, n-1);


	print_table (m, n);



	return 0;
}



/* 
1. LCS von ACGT und AGCT
= ACT

2. ACAC und GTGT
= gibt es nicht

3. ACGT und TGCA
= A (oder G oder T)

4. AACCGGTT und ACGTACGT

= AACGT (oder ACGGT)

5. GATTGACCT und CGTCTC

= GTTC (oder GTCT)

Die jeweils erste Antwort durch Programm berechnet
die Antworten der Form (oder ...) durch Nachdenken
*/
