#include <iostream>
#include <queue>
#include <forward_list>


#define ANZVERTEX 5
#define MAXIMALERGRAD 10


struct Vertex {

	std::string color;

	Vertex* predecessor;
	int distance;

	std::forward_list <Vertex> adj;

};


std::queue <Vertex> Q;
std::forward_list <Vertex> vertices;


void bfs (Vertex start) {

	for (int i = 0; i < ANZVERTEX; i++) {

		vertices [i].color = "white";
		vertices [i].distance = 10000;
		vertices [i].predecessor = NULL;
	}

	start.color = "gray";
	start.distance = 0;
	start.predecessor = NULL;


	Q.push (start);

	while (!Q.empty ()) {

		Vertex u = Q.front ();
		Q.pop ();

	
		for (std::forward_list<Vertex>::iterator v = u.adj.begin(); v != u.adj.end(); ++v ) {
			
			if (color == "white") {
				v.color = "gray";
				*v.distance = u.distance + 1;
				*v.predecessor = u;

				Q.push (*v);
			}



		}

		u.color = "black";
	}

	
} ////////////////////////////////////////// Ende BFS Funktion //////////////////////////////////////////

/*
void Adjacencylistsetter (int adjacencies [ANZVERTEX] [MAXIMALERGRAD], LinkedList* Adjacencylist, int* Knotengrade) {

		
	for (int j = 0; j < ANZVERTEX; j++) {


		for (int i = 0; i < Knotengrade [j]; i++) {

			Adjacencylist [j].push_front ( adjacencies [j] [i] );
		}
	}	
}
*/

int main (void) {


	Vertex vertices [ANZVERTEX];

	vertices [0].adj.push_front ();
	vertices [0].adj.push_front (3);
	vertices [0].adj.push_front (4);
	
	vertices [1].adj.push_front (2);
	vertices [1].adj.push_front (4);

	vertices [2].adj.push_front (0);
	vertices [2].adj.push_front (1);

	vertices [3].adj.push_front (0);

	vertices [4].adj.push_front (0);
	vertices [4].adj.push_front (1);




	bfs (vertices [0], vertices);

/*	
	// PETERSON-GRAPH (DAFÜR ANZVERTEX IN PRÄPROZESSORANWEISUNG AUF 10 SETZEN!!!)
	int Adjacencyinput [ANZVERTEX] [MAXIMALERGRAD] = { {1,4,5}, {0,2,6}, {1,3,7}, {2,4,8}, {0,3,9}, {0,7,8}, {1,8,9}, {2,5,9}, {3,5,6}, {4,6,7}  };

	int Knotengrade [ANZVERTEX] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};	  // Gib an, mit wievielen Knoten, Knoten i verbunden ist
*/


	
//	Adjacencylistsetter (Adjacencyinput, Adjacencylist, Knotengrade);

	// Startknoten und zu suchenden Knoten eigeben
	int startknoten = 0;
	int gesuchterknoten = 5;


//	bfs (startknoten, gesuchterknoten, Adjacencylist);



	return 0;
}