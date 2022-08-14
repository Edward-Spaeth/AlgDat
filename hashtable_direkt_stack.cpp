#include <iostream>
#include <string.h>


class Node {

private:
	
//	char* land;
	Node* next;

public:

char* land;
	Node (char*);
	char* getLand ();
	Node* getNext ();
	void setNext (Node* n);
	void print ();

};

	Node::Node (char* input) {
		

		land = new char [strlen(input)];
		strcpy (land, input);
		next = NULL;
	}



	char* Node::getLand () {
		
		//char temp [40];
    	//strcpy(temp, land);
    	
		//strcpy(land, "Test");

		return land;
	}

	Node* Node::getNext () {
		return next;
	}

	void Node::setNext (Node* n) {
		next = n;
	}

	void Node::print () {
		std::cout << land << " ";
	}


class Stack {

private:

	Node* head;

public:

	Stack ();
	
	bool isEmpty ();

	int getSize ();

	void push (char*);

	char* pop ();

	void print ();

	~Stack ();
};


	Stack::Stack () {

		head = NULL;
	}
	
	bool Stack::isEmpty () {

		if (head == NULL) {
			return true;
		}

		else {
			return false;
		}
	}

	int Stack::getSize () {

		int size = 0;

		Node * temp = head;

		while (temp != NULL) {

			temp = temp ->getNext ();
			size++;
		}
		
		return size;
	}

	void Stack::push (char* input) {

		
		//std::cout << "Input in Push ist: " << input << std::endl;

	

		Node* temp = new Node (input);


		

		temp->setNext (head);
		

		head = temp;

		std::cout << "Das Land " << head->getLand () << " wurde gepusht" << std::endl;
	}

	char* Stack::pop () {

/*
		if (head == NULL) {

			std::cout << "Der Stack ist leer. Nichts zu poppen. Underflow!" << std::endl;
			return NULL;
		}
*/

		//char* headland = new char [100];
		
		//std::cout << "GetLand: " << head->getLand() << std::endl;

		std::cout << "Bis hier" << std::endl;

		//char* headland = head->getLand ();

		char* headland;
		strcpy (headland, head->land);


		std::cout << "Bis hier leider nicht" << std::endl;
		
		
		//strcpy (headland, head->getLand () );

		std::cout << "Headlandddddd: " << headland << std::endl;

		//char* key = new char [strlen (head->getLand () )];
		char* key;

		//char* key;
		strcpy (key, headland );
	

		std::cout << "Das Land " << key << " soll gepoppt werden" << std::endl;

		std::cout << "Vor head->getNext ? NULL" << std::endl;
		

		if (head->getNext () == NULL) {
			std::cout << "head->getNext ist NULL" << std::endl;
			delete head;
			head = NULL;
		}

		else {
			std::cout << "head->getNext ist nicht NULL" << std::endl;
			Node* temp = head->getNext ();
			delete head;
			head = temp;
		}

		std::cout << "Das Land " << key << " wurde gepoppt" << std::endl;

		return key;
	}

	void Stack::print () {


		//int size = getSize ();

		if (isEmpty ()) {

			std::cout << "Der Stack ist leer. Nichts zu printen" << std::endl;
			return;
		}

		Node* temp = head;

		std::cout << "Aktueller Stack:" << std::endl;

		while (temp != NULL) {

			//std::cout << temp->getland () << std::endl;
			temp->print ();
			temp = temp->getNext ();
		}

		std::cout << std::endl;

	}

	Stack::~Stack () {


		if (getSize() == 0) {
		
		// Wenn Liste leer muss nicht gefree'd werden, da nix allokiert wurde
		//std::cout << "Es muss nichts gelöscht werden" << std::endl;
		return;
	}	
	else {

		Node* temp_prev;
		Node* temp = head;

		while (temp->getNext () != NULL)
		{
			

			temp_prev = temp;
			temp = temp->getNext ();

			
			//std::cout << temp_prev->getland () << " gelöscht! (temp_prev)" << std::endl;
			delete [] temp_prev->getLand ();
			delete temp_prev;

		}		

		//std::cout << temp->getland () << " gelöscht! (temp)" << std::endl;
		delete temp;
	}

	//std::cout << "Ganze Liste erfolgreich gelöscht" << std::endl;
	
	}