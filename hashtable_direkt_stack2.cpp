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


class Stack {

private: 
	Node* head;

public:

	Stack ();

	Node* getHead ();

	void push (char*);

	char* pop ();

	bool isEmpty ();

	int getSize ();

	void print ();

};

	Stack::Stack () {

		head = NULL;
	}



	Node* Stack::getHead () {

		return head;
	}


	void Stack::push (char* land_input) {


		Node* temp = new Node (land_input);


		temp->setNext (head);
		

		head = temp;

		std::cout << "Das Land " << head->getLand () << " wurde gepusht" << std::endl;


	}



	char* Stack::pop () {

		
    		Node* temp = head;

    		char* key = temp->getLand ();

    		head = head->getNext ();
    		delete temp;

    		return key;
 
		
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

		int i = 0;

		Node* temp = head;

		while (temp != NULL) {

			i++;
			temp = temp->getNext();
		}

		return i;
	}

	void Stack::print () {

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


