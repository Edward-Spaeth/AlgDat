#include <iostream>


class Node {

private:
	
	int value;
	Node* next;

public:

	Node (int);
	int getValue ();
	Node* getNext ();
	void setNext (Node* n);
	void print ();

};

	Node::Node (int input) {
		value = input;
		next = NULL;
	}

	int Node::getValue () {
		return value;
	}

	Node* Node::getNext () {
		return next;
	}

	void Node::setNext (Node* n) {
		next = n;
	}

	void Node::print () {
		std::cout << value << " ";
	}


class Stack {

private:

	Node* head;
	//int top;

public:

	Stack ();
	
	bool isEmpty ();

	int getSize ();

	void push (int);

	void pop ();

	void print ();

	~Stack ();
};


	Stack::Stack () {

		//top = -1;
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

	void Stack::push (int input) {

		Node* temp = new Node (input);

		temp->setNext (head);

		head = temp;
	}

	void Stack::pop () {


		if (head == NULL) {

			std::cout << "Der Stack ist leer. Nichts zu poppen. Underflow!" << std::endl;
			return;
		}

		int key = head->getValue ();

		if (head->getNext () == NULL) {

			delete head;
			head = NULL;
		}

		else {

			Node* temp = head->getNext ();
			delete head;
			head = temp;
		}

		std::cout << "Der Wert " << key << " wurde gepoppt" << std::endl;

		return;
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

			//std::cout << temp->getValue () << std::endl;
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

			
			//std::cout << temp_prev->getValue () << " gelöscht! (temp_prev)" << std::endl;
			delete temp_prev;

		}		

		//std::cout << temp->getValue () << " gelöscht! (temp)" << std::endl;
		delete temp;
	}

	//std::cout << "Ganze Liste erfolgreich gelöscht" << std::endl;
	
	}


	void printanweisung () {

		std::cout << std::endl << std::endl <<
		"1 - Print Stack" << std::endl << "2 - Push" << std::endl << 
		"3 - Pop" << std::endl << std::endl << "4 - Quit" << std::endl << std::endl << "Input: ";
	}



int main (void) {

	Stack s;

	int anweisung;

	while (true) {


		printanweisung ();

		std::cin >> anweisung;

		switch (anweisung) {

			case 1:
				s.print ();
				break;

			case 2:
				int input;
				std::cout << "Zu pushender Wert? ";
				std::cin >> input;
				s.push (input);
				break;

			case 3:
				if (!s.isEmpty () ) {
					s.pop ();
				}	

				else {

					std::cout << "Stack ist leer. Nichts zu poppen. Underflow!" << std::endl;
				}

				break;

			case 4:
				std::cout << "Programm beendet" << std::endl;
				return 0;
				break;			
		}
	}

	return 0;
}