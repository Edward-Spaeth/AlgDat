#include <iostream>
#include <string.h>
#include <cstring>



class Node {

private:
	char* land;
	Node* next;

public:

	// Initialisiert einen Knoten
	Node (char* land_input);

	char* getLand ();

	Node* getNext ();

	void setNext (Node *n);

	void print ();

};

	Node::Node (char* land_input) {

		
		land = new char [strlen (land_input) ];

		strcpy (land, land_input);

		next = NULL;

	}


	char* Node::getLand () {

		return land;
	}


	Node* Node::getNext () {

		return next;
	}
	

	void Node::setNext (Node *n) {

		next = n;
	}

	void Node::print () {

		std::cout << "\t" << land << std::endl;
	}


class LinkedList {

private: 
	Node* head;

public:

	LinkedList ();

	Node* getHead ();

	void insert_at_head (char*, int, int);

	void delete_at_head ();

	bool isEmpty ();

	int getSize ();

	void print ();

	~LinkedList();

};

	LinkedList::LinkedList () {

		head = NULL;
	}



	Node* LinkedList::getHead () {

		return head;
	}


	void LinkedList::insert_at_head (char* land_input, int start, int end) {


//		std::cout << "Es kam bis in insert_at_head" << std::endl;
		int size = (end - start);

		char wort [size+1];

		for (int i = 0; i < size; i++) {

			wort [i] = land_input [start+i];
		}

		wort [size] = '\0';

		Node* temp = new Node (wort);

        if (head != NULL) {
        	temp->setNext (head);
        }


        head = temp;
    	

	}



	void LinkedList::delete_at_head () {

		if (isEmpty ()) {

			std::cout << "Nichts zum deleten" << std::endl;
			return;
		}
		
		else {

    		Node* temp = head;

    		head = head->getNext ();
    		delete temp;
 
		}

	}




	bool LinkedList::isEmpty () {

		if (head == NULL) {

			return true;
		}

		else {

			return false;
		}
	}

	int LinkedList::getSize () {

		int i = 0;

		Node* temp = head;

		while (temp != NULL) {

			i++;
			temp = temp->getNext();
		}

		return i;
	}

	void LinkedList::print () {

		if (isEmpty() ) {

			std::cout << std::endl << "Die Liste ist Empty" << std::endl;
			return;
		}

			std::cout << std::endl << "Zu printende Liste:" << std::endl << std::endl;

			// sonst accidentally quadratic !
			int size = getSize();

			Node* temp = head;


			for (int i = 0; i < size; i++) {

				
						temp->print();
						temp = temp->getNext();
					}


			std::cout << std::endl;
		
	}


LinkedList::~LinkedList() {	


	if (getSize() == 0) {
		
		// Wenn Liste leer muss nicht gefree'd werden, da nix allokiert wurde
		return;
	}	
	else {


		// temp_prev ist der vorherige Knoten. Temp_prev wird temp gesetzt bevor temp selbst erhöht wird
		// dann wird temp_prev gelöscht. Dies geht weiter bis zum letzten Element bevor temp == NULL gilt
		// Es kann dann kein temp_prev geben weil es das letzte Element ist, also wird temp gelöscht

		Node* temp = head->getNext ();
		Node* temp_prev;

		while (temp != NULL)
		{
			temp_prev = temp;
			temp = temp->getNext ();

			delete temp_prev;

		}		

		delete temp;
	}

//	std::cout << "Ganze Liste erfolgreich gelöscht" << std::endl;
	
}

