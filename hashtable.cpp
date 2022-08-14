#include <iostream>
#include <string.h>
#include <math.h>

#include "hashtablelinkedlist.cpp"

#define MODULOR 13

// WICHTIG !!!
// Nicht vergessen, hashtablelinkedlist.cpp im gleichen Directory zu haben!


int asciifier (char* input, int start=0, int end=-1) {

	if (end == -1) {
		
		end = strlen (input);
	}	
	
	int gesamt = 0;

	for (int i = start; i < end; i++) {

		gesamt+= input [i];
	}


	return gesamt % MODULOR;
}


// Unterteilt den langen String mit den Ländernamen in Worte, indem er Start- und End-index herausfindet

void wortefinder (char* laender, int wort_anfang_ende[] [2]) {

	int size = strlen (laender);
	int k = 0;

	wort_anfang_ende[0] [0] = 0;

	for (int i = 1; i < size; i++) {

		if ( laender [i] == '.') {
			wort_anfang_ende[k] [1] = i;

			k++;

			wort_anfang_ende[k] [0] = i+1;
		}

		
	}
}


void printblank (int blanks) {

	for (int i = 0; i < blanks; i++) {

		std::cout << " ";
	}
}




int main (void) {


	char laender [] = "Baden-Wuerttemberg.Bayern.Berlin.Brandenburg.Bremen.Hamburg.Hessen.Mecklenburg-Vorpommern.Niedersachsen.Nordrhein-Westfalen.Rheinland-Pfalz.Saarland.Sachsen.Sachsen-Anhalt.Schleswig-Holstein.Thueringen.";

	int wort_anfang_ende [strlen (laender)] [2];	// wort_anfang_ende [Start-Index] [End-Index]

	int moduloerg [16];

	wortefinder (laender, wort_anfang_ende);

/*
	for (int i = 0; i < 16; i++) {

		std::cout << "Land mit Index " << i << " startet bei " << wort_anfang_ende[i] [0] << " und endet bei " << wort_anfang_ende[i] [1] 
		<< std::endl; 
	}
*/

	std::cout << "Die Bundesländer: " << std::endl << std::endl;

	for (int i = 0; i < 16; i++) {

		int start = wort_anfang_ende[i] [0];
		int end = wort_anfang_ende[i] [1]; 

		moduloerg [i] = asciifier (laender, wort_anfang_ende[i] [0], wort_anfang_ende[i] [1]);
		moduloerg [i] = asciifier (laender, start, end);

	}


	for (int i = 0; i < 16; i++) {

		int start = wort_anfang_ende[i] [0];
		int end = wort_anfang_ende[i] [1];

		for (int j = start; j <	end; j++) {
		
			std::cout << laender [j];
		}

	

		printblank ( 30 - (end - start));

		std::cout << "Mod " << MODULOR << " = " << moduloerg [i];

		std::cout << std::endl;	
	}

	std::cout << std::endl;


	// Baden-Würtemberg und Thüringen sind nicht wie im Skript, da ich Umlaute entfernt hab, damit es
	// ASCII Kompatibel ist

	int elemente_in_hash [MODULOR];

	for (int i = 0; i < MODULOR; i++) {

		elemente_in_hash [i] = 0;
	}



	LinkedList list [MODULOR];	// Array von Verketten Listen, soviele wie es Restklassen gibt

	for (int i = 0; i < 16; i++) {


		int start = wort_anfang_ende [i] [0];
		int end = wort_anfang_ende [i] [1];

		int hash = asciifier (laender, start, end);

		// Inserted das Element in der LinkedList des Hashes
		list [hash].insert_at_head (laender, start, end);

		// Erhöht den Zähler für Anzahl der Elemente in LinkedList des Hashes		
		elemente_in_hash [hash]++;	
	}



	int maximalekollision = elemente_in_hash [0];
	int maximalekollision_vorkommen = 0;

	for (int i = 1; i < MODULOR; i++) {
		if (elemente_in_hash [i] > maximalekollision) {
			maximalekollision = elemente_in_hash [i];
		}
	}

	for (int i = 0; i < MODULOR; i++) {

		if (elemente_in_hash [i] == maximalekollision) {
			maximalekollision_vorkommen++;
		}
	}

	std::cout << "Die maximale Kollision ist: " << maximalekollision 
	<< " und kommt " << maximalekollision_vorkommen << " mal vor (Modulo " << MODULOR << ")" 
	<< std::endl << std::endl;


/*
	std::cout << std::endl << "Ausgabe der Kollisionen in jeder Restklasse: " << std::endl;
	for (int i = 0; i < 13; i++) {

		std::cout << i << ": " << elemente_in_hash [i] << std::endl;
	}
*/

	char eingabe [32];

	std::cout << "Eingabe eines Bundeslands: " << std::endl;
	std::cin >> eingabe;

	// Hasht den Input des Users, um danach zu bestimmen, in welchem Container gesucht werden soll
	int eingabe_hash = asciifier (eingabe);


	std::cout << std::endl << "Eingabe Hash ist: " << eingabe_hash << " und es gibt in diesem Bucket " 
	<< elemente_in_hash [eingabe_hash] << " Key(s)" << std::endl;


			// Wenn LinkedList mit diesem Hash leer, gibt es nichts mit dem Hash
			if (list [eingabe_hash].isEmpty () ) {

				std::cout << eingabe << " ist kein Bundesland!" << std::endl;
			}


			else {
				
				// Man weiß in welcher LinkedList gesucht wird, man fängt an sie zu durchqueren
				Node* temp = list [eingabe_hash].getHead ();


				// strcmp gibt 0 zurück, wenn true !!!
				// durchqueren bis Eingabe == gesuchter Key oder bis temp == NULL

				while (temp != NULL) {
					if (strcmp ( temp->getLand (), eingabe ) == 0) {
						
						std::cout << std::endl << eingabe << " ist ein Bundesland!" << std::endl;
						break;
					}
					else {

						temp = temp->getNext ();
					}	


				} 

				if (temp == NULL ) {

					std::cout << eingabe << " ist kein Bundesland!" << std::endl; 
				}
			}
	

	int anweisung;

	while (true) {
		
		do {
			std::cout << std::endl << "Welche Restklasse wollen Sie printen? (Maximal " << MODULOR-1 
			<< ", Zahl < 0 für Quit)" << std::endl << "Input: ";
			std::cin >> anweisung;
		} while (anweisung > MODULOR-1);	 

		if (anweisung < 0) {
			std::cout << "Programm beendet. " << std::endl;
			break;
		}

		else {

			list [anweisung].print ();
		}
	}



	return 0;
}