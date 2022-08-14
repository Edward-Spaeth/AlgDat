#include <iostream>
#include <string.h>


#include "hashtable_direkt_stack2.cpp"


// WICHTIG !!!
// hashtable_direkt_stack2.cpp muss nicht mitkompiliert werden!
// Nicht vergessen, hashtable_direkt_stack2.cpp im gleichen Directory zu haben!

#define MODULOR 23


Stack s;

void printblank (int blanks) {

	for (int i = 0; i < blanks; i++) {

		std::cout << " ";
	}
}


int asciifier (char* input) {

	int end = strlen (input);	
	
	int gesamt = 0;

	for (int i = 0; i < end; i++) {

		gesamt+= input [i];
	}


	return gesamt % MODULOR;
}


void tryToAdd (char* buckets, char* laender) {

	


		int hash = asciifier (laender);

	

		if (strcmp (buckets , "NULL") == 0) {


			strcpy (buckets, laender);

		}

		else {

			s.push ( laender);
		}
	
}

bool linearprobing (char buckets [] [32]) {

	

	bool placefound = true;
	
	while (s.isEmpty () == false && placefound == true) {

		char* gepopptes_land = s.pop ();
		char temp [strlen (gepopptes_land)];

		strcpy (temp, gepopptes_land);

		// "linear probing" der Einträge aus dem Stack
		
		int hash_value = asciifier (gepopptes_land);
		int j = 0;


		for (int i=hash_value; j < MODULOR; i= (i+1) % MODULOR) {
			
			placefound = false;
			j++;

			if (strcmp (buckets [i], "NULL") == 0) {
				strcpy (buckets [i], gepopptes_land);
				placefound = true;
				break;
			}

		}
	}
	return placefound;
}
/*
bool quadraticprobing (char buckets [] [32]) {

	

	bool placefound = true;
	
	while (s.isEmpty () == false && placefound == true) {

		char* gepopptes_land = s.pop ();
		char temp [strlen (gepopptes_land)];

		strcpy (temp, gepopptes_land);

		// "linear probing" der Einträge aus dem Stack
		int j = 0;

		for (int i=0; j < 30; i= (i*i) % MODULOR) {
			
			placefound = false;
			j++;

			if (strcmp (buckets [i], "NULL") == 0 || strcmp (buckets [i], "DELETED") == 0) {
				strcpy (buckets [i], gepopptes_land);
				placefound = true;
				break;
			}

		}
	}
	return placefound;
}
*/

int main (void) {

	

	int probing_mode = 0;	//probing mode 0 = linear, 1 = quadratic




	char laender  [16] [32] = { "Baden-Wuerttemberg", "Bayern", "Berlin", "Brandenburg", "Bremen", "Hamburg", "Hessen", "Mecklenburg-Vorpommern", "Niedersachsen", "Nordrhein-Westfalen", "Rheinland-Pfalz", "Saarland", "Sachsen", "Sachsen-Anhalt", "Schleswig-Holstein", "Thueringen"};
	int laender_hash [16];


	std::cout << "Die Bundesländer: " << std::endl << std::endl;
	for (int i = 0; i < 16; i++) {

		std::cout << laender [i];

		laender_hash [i] = asciifier (laender [i]);

		
		// fürs schön printen
		printblank ( 30 - (strlen (laender [i]) ) );
		std::cout << "Mod " << MODULOR << " = " << laender_hash [i];
		std::cout << std::endl;	
	}

	std::cout << std::endl << std::endl << std::endl;


	// Buckets werden mit dem String "NULL" aufgefüllt, damit man sie als leer erkennen kann

	char buckets [MODULOR] [32];

	for (int i = 0; i < MODULOR; i++) {

		strcpy (buckets [i], "NULL");
	}






	for (int i = 0; i < 16; i++) {


		int hash = asciifier (laender [i]);

		tryToAdd (buckets [hash], laender [i]);

	}



	s.print ();

	int max_stack_size = s.getSize ();


	// placefound guckt wieso die for Schleife verlassen wurde:
	// platz gefunden und break, oder alles durchgelaufen und keinen Platz gefunden? --> Gibt an ob Overflow
	
	
/*
	bool placefound = true;
	
	while (s.isEmpty () == false && placefound == true) {

		char* gepopptes_land = s.pop ();
		char temp [strlen (gepopptes_land)];

		strcpy (temp, gepopptes_land);

		// "linear probing" der Einträge aus dem Stack
		

		for (int i=0; i < MODULOR; i++) {
			
			placefound = false;

			if (strcmp (buckets [i], "NULL") == 0) {
				strcpy (buckets [i], gepopptes_land);
				placefound = true;
				break;
			}

		}

*/		
		
	bool probing_success;

	if (probing_mode == 0) {

		probing_success = linearprobing (buckets);

		
		if (probing_success == true) {

			std::cout << "Linear Probing hat geklappt" << std::endl << std::endl;
		}	

		else {

			std::cout << "Linear Probing hat nicht geklappt" << std::endl << std::endl;
		}

	}	

/*
	if (probing_mode == 1) {

		probing_success = quadraticprobing (buckets);

		
		if (probing_success == true) {

			std::cout << "Quadratic Probing hat geklappt" << std::endl << std::endl;
		}	

		else {

			std::cout << "Quadratic Probing hat nicht geklappt" << std::endl << std::endl;
		}

	}
*/


		

	std::cout << "Es kam bis nach dem Probingaufruf" << std::endl;	

/*
	if (linearprobing (buckets [i]) == true) {

		std::cout << "Linear Probing hat geklappt" << std::endl;
	}	

	else {

		std::cout << "Linear Probing hat nicht geklappt" << std::endl;
	}
*/

	for (int i = 0; i < MODULOR; i++) {

		std::cout << buckets [i];
		printblank ( 30 - (strlen (buckets [i]) ) );
		std::cout << i << std::endl;
	}

	if (probing_success) {
		
		std::cout << std::endl << "Es gab keinen Overflow!" << std::endl << std::endl;
	}

	else {
		
		std::cout << std::endl << "Es gab Overflow!" << std::endl << std::endl;
	}


	std::cout << std::endl << "Maximale Größe des Stacks ist " << max_stack_size << std::endl 
	<< "Das heißt, dass nur " << max_stack_size 
	<< " Elemente nicht an der richtigen Stelle stehen/steht" << std::endl;



	char eingabe [32];

	std::cout << "Eingabe eines Bundeslands: " << std::endl;
	std::cin >> eingabe;

	if (strcmp (eingabe, "NULL") == 0) {

		std::cout << "NULL ist Definitiv kein Bundesland !!! Programm beendet." << std::endl;
		return 1;
	}


	// Hasht den Input des Users, um danach zu bestimmen, in welchem Container gesucht werden soll
	int eingabe_hash = asciifier (eingabe);


	std::cout << std::endl << "Eingabe Hash ist: " << eingabe_hash << std::endl;


			// Wenn Bucket mit diesem Hash leer, gibt es nichts mit dem Hash
			
			if (strcmp (buckets [eingabe_hash], "NULL") == 0) {
				
				std::cout << eingabe << " ist kein Bundesland! (Bucket leer)" << std::endl;
			}

			else {

				if (strcmp (buckets [eingabe_hash], eingabe) == 0) {

					std::cout << eingabe << " ist ein Bundesland!" << std::endl;
				}

				else {
					int j = 0;
					for (int i = eingabe_hash; j < MODULOR; i = (i+1) % MODULOR ) {

						j++;
						//std::cout << "Überprüfung" << std::endl;

						if (strcmp (buckets [i], eingabe) == 0) {

							std::cout << eingabe << " ist ein Bundesland!" << std::endl;
							return 0;
						}

						else {

							if (strcmp (buckets [i], "NULL") == 0) {

								break;
							}
						}

					}
				
					std::cout << "Überprüfungen: " << j << std::endl;
					std::cout << eingabe << " ist kein Bundesland!" << std::endl;
				}
			}


	return 0;
}
