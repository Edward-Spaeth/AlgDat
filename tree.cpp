#include <iostream>


struct Node {

	int value;
	Node* left;
	Node* right;
	
	Node (int);


};

Node::Node (int value_input) {
	value = value_input;
	left = NULL;
	right = NULL;
}



struct Tree {

	Node* root;

	
	Tree ();

	void insertionqueue (int*, int);

	void insert (int);

	void inorder_treewalk (Node*);

	void postorder_treewalk (Node*);

	void preorder_treewalk (Node*);

	int tree_minimum (Node*);

	int tree_maximum (Node*);

	bool tree_search_recursive (Node*, int);

	bool tree_search_iterative (Node*, int);



};

	Tree::Tree () {

		root = NULL;
	}



	void Tree::insertionqueue (int* inputs, int length) {

		int i = 0;


// Wenn es keine Root gibt, ist der erste Input die Root

		if (root == NULL) {
			
			Node* temp = new Node (inputs [0]);
			root = temp;
			i = 1;
		}
 		
		for (i; i < length; i++) {
			
			insert (inputs [i]);
			std::cout << "Es kommt zum inserten" << std::endl;
		}
	}


	void Tree::insert (int input) {

		Node* z = new Node (input);


		Node* y = NULL;
		Node* x = root;

		while (x != NULL) {
		
			y = x;

			if (z->value < x->value) {
				x = x->left;
			}

			else {
				x = x->right;
			}
		}


		if (y == 0) {
		
			root = z;
		}

		else {


			if (z->value < y->value) {
				y->left = z;
			}

			else {
				y->right = z;
			}
		}

	}


	void Tree::inorder_treewalk (Node* x) {

		if (x != NULL) {
			
			inorder_treewalk (x->left);
			std::cout << " " << x->value;
			inorder_treewalk (x->right);
		}
	}

	void Tree::postorder_treewalk (Node* x) {
		if (x != NULL) {
			
			postorder_treewalk (x->left);
			postorder_treewalk (x->right);
			std::cout << " " << x->value;
		}
	}

	void Tree::preorder_treewalk (Node* x) {
		if (x != NULL) {
			
			std::cout << " " << x->value;
			preorder_treewalk (x->left);
			preorder_treewalk (x->right);
		}
	}



	int Tree::tree_minimum (Node* x) {

		while (x->left != NULL) {

			x = x->left;
		}

		return x->value;
	}


	int Tree::tree_maximum (Node* x) {

		while (x->right != NULL) {

			x = x->right;
		}

		return x->value;
	}

	bool Tree::tree_search_recursive (Node* x, int target) {

		if (x == NULL || x->value == target) {
			bool found;
			found = (x == NULL) ? false : true;

			return found;
		}

		if (target < x->value) {
			return tree_search_recursive (x->left, target);
		}

		else {
			return tree_search_recursive (x->right, target);
		}
	}

	bool Tree::tree_search_iterative (Node* x, int target) {

		while (x != NULL && x->value != target) {
			if (target < x->value) {
				x = x->left;
			}

			else {
				x = x->right;
			}
		}
		
		bool found;
		found = (x == NULL) ? false : true;

		return found;
	}



int main (void) { ////////////////////////// Anfang Main //////////////////////////

	int values [] = {14, 33, 1, 25, 12, 4};

//	int values [] = {1, 4, 12, 14, 25, 33}; // Baum degeneriert zur Liste

//	int values [] = {33,25,14,12,4,1};		// Antwort auf Frage 1

//	int values [] = {1, 4, 12, 14, 25, 33}; // Antwort auf Frage 2

	int valuessize = sizeof (values) / sizeof (int);

	Tree T;


	T.insertionqueue (values, valuessize);

	std::cout << std::endl << std::endl << "Inorder:" << std::endl;
	T.inorder_treewalk (T.root);

	std::cout << std::endl << std::endl << "Postorder:" << std::endl;
	T.postorder_treewalk (T.root);

	std::cout << std::endl << std::endl << "Preorder:" << std::endl;
	T.preorder_treewalk (T.root);

	std::cout << std::endl << std::endl;

	std::cout << "Das kleinste Element des Trees ist " << T.tree_minimum (T.root) << std::endl;

	std::cout << "Das groesste Element des Trees ist " << T.tree_maximum (T.root) << std::endl;

	
	int target = 5;

	if (T.tree_search_recursive (T.root, target)) {
		std::cout << target << " ist im Tree" << std::endl;
	}

	else {
		std::cout << target << " ist nicht Tree" << std::endl;
	}


	/*

	Frage 1: Baum wo Postorder = Inorder ? Wie sieht Preorder aus?
	
	Antwort 1: Ein zu einer Liste degenerierter Baum, der von der Wurzel aus nur nach links geht.
				Man erhält so einen Baum, wenn man ein absteigend sortiertes Array eingibt (Wurzel = max)
				Preorder ist REVERSE von Postorder bzw. Inorder


	Frage 2: Baum wo Postorder = REVERSE von Inorder ? Wie sieht Preorder aus?			
	
	Antwort 2: Ein zu einer Liste degenerierter Baum, der von der Wurzel aus nur nach rechts geht.
				Man erhält so einen Baum, wenn man ein aufsteigend sortiertes Array eingibt (Wurzel = min)
				Dann ist Postorder der REVERSE von Inorder

				Preorder ist dann identisch zu Inorder
	

	Preorder_Traversal = DFS


	Easy zu merken:
	
	Preorder = Visit ist am Anfang (Pre)
	Inorder = Visit ist in der Mitte (In)
	Postorder = Visit ist am Ende (Post)


	*/




} ////////////////////////// Ende Main //////////////////////////


