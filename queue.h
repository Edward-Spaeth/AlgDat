#include <iostream>

// INTEGER QUEUE



class Queue_Node  {

private:
	
	int value;
	Queue_Node* next;

public:

	Queue_Node  (int);
	int getValue ();
	Queue_Node* getNext ();
	void setNext (Queue_Node* n);
	void print ();

};

	Queue_Node:: Queue_Node  (int input) {
		value = input;
		next = NULL;
	}

	int Queue_Node:: getValue () {
		return value;
	}

	Queue_Node* Queue_Node:: getNext () {
		return next;
	}

	void Queue_Node:: setNext (Queue_Node* n) {
		next = n;
	}

	void Queue_Node:: print () {
		std::cout << value << " ";
	}


class Queue {

private:

	Queue_Node* head;
	Queue_Node* tail;

public:

	Queue ();

	int getheadvalue ();

	Queue_Node* getheadaddress ();
	
	bool isEmpty ();

	int getSize ();

	void enqueue (int);

	void dequeue ();

	void print ();

	~Queue ();
};


	Queue::Queue () {

		head = NULL;
		tail = NULL;
	}
	
	int Queue::getheadvalue () {

		return head->getValue ();
	}

	Queue_Node* Queue::getheadaddress () {


		return head;
	}


	bool Queue::isEmpty () {

		if (head == NULL) {
			return true;
		}

		else {
			return false;
		}
	}

	int Queue::getSize () {

		int size = 0;

		Queue_Node* temp = head;

		while (temp != NULL) {

			temp = temp ->getNext ();
			size++;
		}
		
		return size;
	}

	void Queue::enqueue (int input) {

		Queue_Node* temp = new Queue_Node  (input);

		if (tail != NULL) {
			tail->setNext (temp);
		}
		if (head == NULL) {

			head = temp;
		}

		tail = temp;
	}

	void Queue::dequeue () {


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

	void Queue::print () {


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

	Queue::~Queue () {


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

