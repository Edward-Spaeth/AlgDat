#ifndef _VERTEXQUEUE_H_
#define _VERTEXQUEUE_H_

#include <iostream>
#include "bfs2.cpp"
// VERTEX QUEUE



class Queue_Node  {

private:
	
	Vertex v;
	Queue_Node* next;

public:

	Queue_Node  (Vertex);
	int getValue ();
	Queue_Node* getNext ();
	void setNext (Queue_Node* n);
	void print ();

};

	Queue_Node::Queue_Node  (Vertex input) {
		color = input.getColor ();
		distance = input.getDistance ();
		predecessor = input.getPredecessor ()
		adj = input.getAdj ();
		next = NULL;
	}

	int Queue_Node:: getValue () {
		return value;
	}

	Queue_Node* Queue_Node::getNext () {
		return next;
	}

	void Queue_Node::setNext (Queue_Node* n) {
		next = n;
	}

	void Queue_Node::print () {
		std::cout << value << " ";
	}


class Vertexqueue {

private:

	Queue_Node* head;
	Queue_Node* tail;

public:

	Vertexqueue ();

	int getheadvalue ();

	Queue_Node* getheadaddress ();
	
	bool isEmpty ();

	int getSize ();

	void enqueue (Vertex);

	Vertex dequeue ();

	void print ();

	~Vertexqueue ();
};


	Vertexqueue::Vertexqueue () {

		head = NULL;
		tail = NULL;
	}
	
	int Vertexqueue::getheadvalue () {

		return head->getValue ();
	}

	Queue_Node* Vertexqueue::getheadaddress () {


		return head;
	}


	bool Vertexqueue::isEmpty () {

		if (head == NULL) {
			return true;
		}

		else {
			return false;
		}
	}

	int Vertexqueue::getSize () {

		int size = 0;

		Queue_Node* temp = head;

		while (temp != NULL) {

			temp = temp ->getNext ();
			size++;
		}
		
		return size;
	}

	void Vertexqueue::enqueue (int input) {

		Queue_Node* temp = new Queue_Node  (input);

		if (tail != NULL) {
			tail->setNext (temp);
		}
		if (head == NULL) {

			head = temp;
		}

		tail = temp;
	}

	void Vertexqueue::dequeue () {


		if (head == NULL) {

			std::cout << "Die Queue ist leer. Nichts zu Dequeuen. Underflow!" << std::endl;
			return;
		}

		int key = head->getValue ();

		if (head->getNext () == NULL) {

			delete head;
			head = NULL;
		}

		else {

			Queue_Node* temp = head->getNext ();
			delete head;
			head = temp;
		}


		return;
	}

	void Vertexqueue::print () {


		//int size = getSize ();

		if (isEmpty ()) {

			std::cout << "Die Queue ist leer. Nichts zu printen" << std::endl;
			return;
		}

		Queue_Node* temp = head;

		std::cout << "Aktuelle Queue:" << std::endl;

		while (temp != NULL) {

			//std::cout << temp->getValue () << std::endl;
			temp->print ();
			temp = temp->getNext ();
		}

		std::cout << std::endl;

	}

	Vertexqueue::~Vertexqueue () {


		if (getSize() == 0) {
		
		// Wenn Liste leer muss nicht gefree'd werden, da nix allokiert wurde
		//std::cout << "Es muss nichts gelöscht werden" << std::endl;
		return;
	}	
	else {

		Queue_Node* temp_prev;
		Queue_Node* temp = head;

		while (temp->getNext () != NULL)
		{
			

			temp_prev = temp;
			temp = temp->getNext ();

			
			//std::cout << temp_prev->getValue () << " gelöscht! (temp_prev)" << std::endl;
			delete temp_prev;

		}		

		//std::cout << temp->getValue () << " gelöscht! (temp)" << std::endl;
		delete temp;
		head = NULL;
		tail = NULL;
	}

	//std::cout << "Ganze Liste erfolgreich gelöscht" << std::endl;
	
	}




#endif