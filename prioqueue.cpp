// Array Implementation
#include <iostream>

#define MAX_SIZE 4


class PrioQueue {

private:
	int A [MAX_SIZE];
	int max_index = MAX_SIZE-1;
	int head;
	int tail;

public:
	
	PrioQueue ();

	int getHead ();
	int getTail ();
	int getMaxIndex ();
	int getSize ();

	bool isEmpty ();

	void setHead (int);
	void setTail (int);
	void setMaxSize (int);
	
	void swap (int, int);
	void enQ (int);
	void deQ ();

	void print ();

};

	PrioQueue::PrioQueue () {

		//head = -1;
		//tail = -1;

		head = -1;
		tail = -1;
	}

	int PrioQueue::getHead () {
		return head;
	}

	int PrioQueue::getTail () {
		return tail;
	}

	int PrioQueue::getMaxIndex () {
		return max_index;
	}

	int PrioQueue::getSize () {
		int size = tail-1 - head;
		return size;
	}

	bool PrioQueue::isEmpty () {

		if (tail <= head) {
			return true;
		}

		else {
			return false;
		}
	}

	void PrioQueue::setHead (int input) {
		head = input;
	}

	void PrioQueue::setTail (int input) {
		tail = input;
	}
	void PrioQueue::setMaxSize (int input) {
		max_index = input;
	}
	

	void PrioQueue::swap (int index1, int index2) {
		int temp = A[index1];
		A[index1] = A[index2];
		A[index2] = temp;
	}

	void PrioQueue::enQ (int input) {



		if (getSize () < max_index ) {


			tail++;
			A[tail] = input;
			std::cout << "Der Wert " << A[tail] <<" wurde Enqueued" << std::endl;
		}
		
		else {
			std::cout << "Die Queue ist voll. Kein Platz zum Enqueuen" << std::endl;
		}
		
	}
	void PrioQueue::deQ () {

		if (!isEmpty ()) {

			
			head++;
			std::cout << "Der Wert " << A[head] <<" wurde Dequeued" << std::endl;	
		}
		
		else {
			std::cout << "Die Queue ist leer. Nichts zum Dequeuen" << std::endl;
		}
	}


	void PrioQueue::print () {

		if (isEmpty () ) {

			std::cout << /*"Zu printende Queue:" << */ std::endl << "[ LEER ]" << std::endl << std::endl;
		}

		else {

			std::cout << /*"Zu printende Queue:" <<*/ std::endl << "[ ";

			for (int i = head+1; i < tail+1; i++) {

				std::cout << A[i] << " ";
			}
			std::cout << "]" << std::endl << std::endl;
		}
	}









int main (void) {

	PrioQueue q;
	q.print();
	q.enQ (5); q.print();

	q.enQ (10); q.print();

	q.enQ (15); q.print();

	q.enQ (20); q.print();

	q.enQ (25); q.print();

	q.deQ (); q.print ();

	q.deQ (); q.print ();

	q.deQ (); q.print ();

	q.deQ (); q.print ();

	q.deQ (); q.print ();

	q.enQ (30); q.print ();

	q.deQ (); q.print ();


	return 0;
}