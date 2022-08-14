#include <iostream>

// INTEGER LinkedList mit Tail



class LinkedList_Node {

private:
	
	int value;
	LinkedList_Node* next;

public:

	LinkedList_Node (int);
	int getValue ();
	LinkedList_Node* getNext ();
	void setNext (LinkedList_Node* n);
	void print ();

};

	LinkedList_Node::LinkedList_Node (int input) {
		value = input;
		next = NULL;
	}

	int LinkedList_Node::getValue () {
		return value;
	}

	LinkedList_Node* LinkedList_Node::getNext () {
		return next;
	}

	void LinkedList_Node::setNext (LinkedList_Node* n) {
		next = n;
	}

	void LinkedList_Node::print () {
		std::cout << value << " ";
	}


class LinkedList {

private:

	LinkedList_Node* head;
	LinkedList_Node* tail;

public:

	LinkedList ();
	
	LinkedList_Node* getHead ();

	bool isEmpty ();

	int getSize ();

	void insert_at_head (int);

	void insert_at_tail (int);

	void delete_at_head ();

	void delete_at_tail ();

	void dequeue ();

	void print ();

	~LinkedList ();
};


	LinkedList::LinkedList () {

		head = NULL;
		tail = NULL;
	}
	
	LinkedList_Node* LinkedList::getHead () {

		return head;
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

		int size = 0;

		LinkedList_Node * temp = head;

		while (temp != NULL) {

			temp = temp ->getNext ();
			size++;
		}
		
		return size;
	}

	void LinkedList::insert_at_head (int input) {

		LinkedList_Node* temp = new LinkedList_Node (input);

		if (tail == NULL) {

			tail = temp;
		}

		temp->setNext (head);

		head = temp;
	}

	void LinkedList::insert_at_tail (int input) {


		LinkedList_Node* temp = new LinkedList_Node (input);

		if (tail != NULL) {
			tail->setNext (temp);
		}
		if (head == NULL) {

			head = temp;
		}

		tail = temp;
	}

	void LinkedList::delete_at_head () {


		if (head == NULL) {

			std::cout << "Die LinkedList ist leer. Nichts zu deleten. Underflow!" << std::endl;
			return;
		}

		int key = head->getValue ();

		if (head->getNext () == NULL) {

			delete head;
			head = NULL;
		}

		else {

			LinkedList_Node* temp = head->getNext ();
			delete head;
			head = temp;
		}

		std::cout << "Der Wert " << key << " wurde gelöscht" << std::endl;

		return;
	}

	
	void LinkedList::delete_at_tail () {


		if (head == NULL) {

			std::cout << "Die LinkedList ist leer. Nichts zu deleten. Underflow!" << std::endl;
			return;
		}

		int key = tail->getValue ();

		LinkedList_Node* tail_minuseins = head;

		while (tail_minuseins->getNext () != tail) {

			tail_minuseins = tail_minuseins->getNext ();
		}

		if (head->getNext () == NULL) {

			delete head;
			head = NULL;
		}

		else {

			delete tail;
			tail = tail_minuseins;
			tail_minuseins->setNext (NULL);
		}

		std::cout << "Der Wert " << key << " wurde gelöscht" << std::endl;

		return;
	}

	void LinkedList::print () {


		//int size = getSize ();

		if (isEmpty ()) {

			std::cout << "Der LinkedList ist leer. Nichts zu printen" << std::endl;
			return;
		}

		LinkedList_Node* temp = head;

		std::cout << "Aktuelle LinkedList:" << std::endl;

		while (temp != NULL) {

			//std::cout << temp->getValue () << std::endl;
			temp->print ();
			temp = temp->getNext ();
		}

		std::cout << std::endl;

	}

	LinkedList::~LinkedList () {


		if (getSize() == 0) {
		
		// Wenn Liste leer muss nicht gefree'd werden, da nix allokiert wurde
		//std::cout << "Es muss nichts gelöscht werden" << std::endl;
		return;
	}	
	else {

		LinkedList_Node* temp_prev;
		LinkedList_Node* temp = head;

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

