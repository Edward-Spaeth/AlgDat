#include <iostream>


struct Node {

	int key;
	Node* left;
	Node* right;
	Node* parent;
	bool black;

	Node (int);


};

Node::Node (int key_input) {
	key = key_input;
	left = NULL;
	right = NULL;
	parent = NULL;
	black = true; // somit gibt es mehr Elemente
}



struct RBTree {

	Node* root;

	
	RBTree ();

	void insertionqueue (int*, int);

	void insert (int);

	void insert2 (int);

	void inorder_treewalk (Node*);

	void postorder_treewalk (Node*);

	void preorder_treewalk (Node*);

	void make_child (Node*, Node*);

	void balance (Node*);

	int tree_minimum (Node*);

	int tree_maximum (Node*);

	bool tree_search_recursive (Node*, int);

	bool tree_search_iterative (Node*, int);



};

	RBTree::RBTree () {

		root = NULL;
	}



	void RBTree::insertionqueue (int* inputs, int length) {

		int i = 0;


// Wenn es keine Root gibt, ist der erste Input die Root

		if (root == NULL) {
			
			Node* temp = new Node (inputs [0]);
			root = temp;
			i = 1;
		}
 		
		for (i; i < length; i++) {
			
			insert2 (inputs [i]);
			std::cout << "Es kommt zum inserten" << std::endl;
		}
	}


	void RBTree::insert (int input) {

		Node* z = new Node (input);


		Node* y = NULL;
		Node* x = root;

		while (x != NULL) {
		
			y = x;

			if (z->key < x->key) {
				x = x->left;
			}

			else {
				x = x->right;
			}
		}


		if (y == 0) {
		
			root = z;

			//balance (z);
		}

		else {


			if (z->key < y->key) {
				y->left = z;

				z->parent = y;

				//balance (z);
			}

			else {
				y->right = z;

				z->parent = y;

				//balance (z);
			}
		}
		std::cout << "Der Wert " << z->key << " wurde inserted" << std::endl;
		//z->black = false;
		balance (z);
		std::cout << "Der Wert " << z->key << " wurde gebalanced" << std::endl;


	}


	void RBTree::insert2 (int value) {

		Node* x = new Node (value);
    	
    	x->parent = NULL;
   		x->left = NULL;
    	x->right = NULL;
    	x->black = true;	

    	Node* y = NULL;
    	Node* r = root;

    while (r != NULL) {
      		y = r;
      	if (x->key < r->key) {
       		r = r->left;
      	} 

      	else {
        	r = r->right;
      	}
    }

    x->parent = y;

    if (y == NULL) {
      
      root = x;
    } 
    else if (x->key < y->key) {
      y->left = x;
    } 

    else {
     
      y->right = x;
    }

    
    if (x->parent == NULL) {
      x->black = false;
      return;
    }

    if (x->parent->parent == NULL) {
      return;
    }

    balance(x);
  

	}



	void RBTree::inorder_treewalk (Node* x) {

		if (x != NULL) {
			
			inorder_treewalk (x->left);
			std::cout << " " << x->key;
			inorder_treewalk (x->right);
		}
	}

	void RBTree::postorder_treewalk (Node* x) {
		if (x != NULL) {
			
			postorder_treewalk (x->left);
			postorder_treewalk (x->right);
			std::cout << " " << x->key;
		}
	}

	void RBTree::preorder_treewalk (Node* x) {
		if (x != NULL) {
			
			std::cout << " " << x->key;
			preorder_treewalk (x->left);
			preorder_treewalk (x->right);
		}
	}


	void RBTree::make_child (Node* x, Node* y) {
		std::cout << "Make child starts" << std::endl;
		
		x->parent = y;

		if (y != NULL) {

			if (x->key < y->key) {
		
				// als linked kind
				y->left = x;

			}

			else {

				// als rechtes kind
				y->right = x;

			}

		}

		else {
			return;
		}

	}



	void RBTree::balance (Node* x) {


		if (x->parent == NULL) {

			x->black = true;
			return;
		}
	

		Node* y = x->parent;


		if (y->parent == NULL) {

			y->black = true;
			return;
		}

		Node* z = y->parent;

		if (!x->black && !y->black) {

			// Rot-Schwarz-Eigenschaft wieder herstellen

			if (x->key < y->key && y->key < z->key) {
				x->black = true;	// Fall 1
				z->black = true;

				z->left = y->right;
				y->right = z;

				make_child (y, z->parent);


				z->parent = y;
			

				return balance (y);
			}

			else {

				if (x->key > y->key && y->key < z->key) {

					y->black = true;	// Fall 2
					z->black = true;

					
					y->right = x->left;
					x->left = y;

					z->left = x->right;
					x->right = z;

					make_child (x, z->parent);

					z->parent = x;
					y->parent = x;

					

					return balance (y);
				}


				else {

					if (x->key < y->key && y->key >= z->key) {
						
						y->black = true;	// Fall 3
						z->black = true;

						y->left = x->right;
						x->right = y;

						z->right = x->left;
						x->left = z;

						make_child (x, z->parent);

						z->parent = x;	
						y->parent = x;

					

						return balance (y);

					}

					else {


						if (x->key > y->key && y->key >= z->key) {
							
							x->black = true;	// Fall 4
							z->black = true;

							z->right = y->left;
							y->left = z;

							make_child (y, z->parent);

							z->parent = y;

						

							return balance (y);

						}

						
					}
				}

			}



		}


		else {

			return balance (y);
		}


	}







	int RBTree::tree_minimum (Node* x) {

		while (x->left != NULL) {

			x = x->left;
		}

		return x->key;
	}


	int RBTree::tree_maximum (Node* x) {

		while (x->right != NULL) {

			x = x->right;
		}

		return x->key;
	}

	bool RBTree::tree_search_recursive (Node* x, int target) {

		if (x == NULL || x->key == target) {
			bool found;
			found = (x == NULL) ? false : true;

			return found;
		}

		if (target < x->key) {
			return tree_search_recursive (x->left, target);
		}

		else {
			return tree_search_recursive (x->right, target);
		}
	}

	bool RBTree::tree_search_iterative (Node* x, int target) {

		while (x != NULL && x->key != target) {
			if (target < x->key) {
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

//	int keys [] = {14, 33, 1, 25, 12, 4};

//	int keys [] = {1, 4, 12, 14, 25, 33}; // Baum degeneriert zur Liste

	int keys [] = {33,25,14,12,4,1};		// Antwort auf Frage 1

//	int keys [] = {1, 4, 12, 14, 25, 33}; // Antwort auf Frage 2

	int keyssize = sizeof (keys) / sizeof (int);

	RBTree T;


	T.insertionqueue (keys, keyssize);

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





} ////////////////////////// Ende Main //////////////////////////


