#include <iostream>

#include "queue.h"
#include "linkedlist.h"

// Nicht vergessen queue.h und linkedlist.h im gleichen Directory zu haben

#define ANZVERTEX 10
#define MAXIMALERGRAD 10




void bfs (int startknoten, int zielknoten, LinkedList* Adjacencylist) {

	if (startknoten >= ANZVERTEX) {

		std::cout << "Der Startknoten " << startknoten << " existiert nicht" << std::endl;
		return;
	}

	bool ziel_gefunden = false;

	std::cout << "Die BFS Reihenfolge mit dem Startknoten " << startknoten << ":" << std::endl << std::endl;

	bool visitlist [ANZVERTEX];

	for (int i = 0; i < ANZVERTEX; i++) {

		visitlist [i] = false;
	}

	Queue BFS;	// Queued, Knoten, von welchen die Nachbarn noch besucht werden sollen

	visitlist [startknoten] = true;
	if (startknoten == zielknoten) {
		
		ziel_gefunden = true;
	}
	
	BFS.enqueue (startknoten);
	std::cout << startknoten;


	while (! BFS.isEmpty () ) {


		int current = BFS.getheadvalue ();	// current ist der aktuelle Knoten, dessen Nachbarn geprüft werden
		BFS.dequeue ();

		// traverser geht die LinkedList, also die Adjazenzliste durch und checkt so alle Nachbarn

		LinkedList_Node* traverser = Adjacencylist [current].getHead (); 

		while (traverser != NULL) {

			int currentnode = traverser->getValue ();

			if (visitlist [currentnode ] == false) {

				// Printet den Knoten, der gerade zum ersten mal besucht wurde
				std::cout << " - " << currentnode;
				if (currentnode == zielknoten) {
		
					ziel_gefunden = true;
				}
				visitlist [currentnode ] = true;

				BFS.enqueue (currentnode);
			}

			traverser = traverser-> getNext ();
		}

	}

	if (ziel_gefunden) {

		std::cout << std::endl << std::endl << "Der Zielknoten " << zielknoten << " wurde in dem Graphen gefunden" << std::endl;
	}

	else {

		std::cout << std::endl << std::endl << "Der Zielknoten " << zielknoten << " wurde in dem Graphen NICHT gefunden" << std::endl;
	}

	std::cout << "BFS fertig" << std::endl;

} ////////////////////////////////////////// Ende BFS Funktion //////////////////////////////////////////


void Adjacencylistsetter (int adjacencies [ANZVERTEX] [MAXIMALERGRAD], LinkedList* Adjacencylist, int* Knotengrade) {

		
	for (int j = 0; j < ANZVERTEX; j++) {


		for (int i = 0; i < Knotengrade [j]; i++) {

			Adjacencylist [j].insert_at_tail ( adjacencies [j] [i] );
		}
	}	
}


int main (void) {

	
	LinkedList Adjacencylist [ANZVERTEX];
/*	
	// PETERSON-GRAPH (DAFÜR ANZVERTEX IN PRÄPROZESSORANWEISUNG AUF 10 SETZEN!!!)
	int Adjacencyinput [ANZVERTEX] [MAXIMALERGRAD] = { {1,4,5}, {0,2,6}, {1,3,7}, {2,4,8}, {0,3,9}, {0,7,8}, {1,8,9}, {2,5,9}, {3,5,6}, {4,6,7}  };

	int Knotengrade [ANZVERTEX] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};	  // Gib an, mit wievielen Knoten, Knoten i verbunden ist
*/


	int Adjacencyinput [ANZVERTEX] [MAXIMALERGRAD] = {
		{2}, 				//Vertex 0
		{3,4}, 				//Vertex 1
		{0,3,5,6,8}, 		//Vertex 2
		{1,2,5,6,7}, 		//Vertex 3
		{1,6,7}, 			//Vertex 4
		{2,3,6,8}, 			//Vertex 5
		{2,3,4,5,7,8,9},	//Vertex 6
		{3,4,6},			//Vertex 7
		{2,3,5,6}, 			//Vertex 8
		{6} };				//Vertex 9	


	int Knotengrade [ANZVERTEX] = {1,2,4,5,3,4,7,3,4,1};

	
	
	Adjacencylistsetter (Adjacencyinput, Adjacencylist, Knotengrade);

	// Startknoten und zu suchenden Knoten eigeben
	int startknoten = 0;
	int gesuchterknoten = 5;


	bfs (startknoten, gesuchterknoten, Adjacencylist);



	return 0;
}