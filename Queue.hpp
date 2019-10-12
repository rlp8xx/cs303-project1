#include <iostream>
#define NDEBUG

using namespace std;

template <class T>
class QueueNode;

template <class T>
class MyQueue {
	public:
		void add_item(T* data) {
			// empty queue
			if (tail == NULL && head == NULL) {
        #ifdef NDEBUG
          cout << "Adding new node to empty queue" << endl;
        #endif
				tail = head = new QueueNode<T>(data);
			  return;
			}
      #ifdef NDEBUG
        cout << "Adding new node to queue" << endl;
      #endif
			// set the next pointer on the tail
			this->tail->next = new QueueNode<T>(data);
			// set the tail to what's current the next pointer on current tail
			this->tail = this->tail->next;
		}

		T* pop() {
			if (tail == NULL && head == NULL) {
        #ifdef NDEBUG
          cout << "Tried to pop empty queue, returning null" << endl;
        #endif
        return NULL;
      }
			if (tail == head) {
        #ifdef NDEBUG
          cout << "Popping while Tail = Head" << endl;
        #endif
				T* val = head->data;
        delete head;
				tail = head = NULL;
        #ifdef NDEBUG
          cout << "Tail and head now nulled by pop with tail=head" << endl;
        #endif
				return val;
			}
      #ifdef NDEBUG
        cout << "Popping" << endl;
      #endif
			T* val = this->head->data;
      QueueNode<T>* old_head = head;
      this->head = this->head->next;
      delete old_head;
      return val;
		}

		T* first() {
			return this->head->data;
		}

  private:
		QueueNode<T>* head = NULL;
		QueueNode<T>* tail = NULL;
};

template <class T>
class QueueNode {
	public:
		QueueNode(T* data) {
			this->data = data;
		}
    
		T* data;
		QueueNode<T>* next = NULL;
};
