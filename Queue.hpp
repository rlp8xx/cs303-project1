#include <iostream>

using namespace std;

template <class T>
class QueueNode;

template <class T>
class MyQueue {
	public:
		void add_item(T data) {
			// empty queue
			if (tail == NULL && head == NULL) {
				tail = head = new QueueNode<T>(data);
			  return;
			}
			// set the next pointer on the tail
			this->tail->next = new QueueNode<T>(data);
			// set the tail to what's current the next pointer on current tail
			this->tail = this->tail->next;
		}

		T pop() {
			if (tail == NULL && head == NULL) return NULL;
			if (tail == head) {
				T val = head->data;
        delete head;
				tail = head = NULL;
				return val;
			}
			T val = this->head->data;
      QueueNode<T>* old_head = head;
      this->head = this->head->next;
      delete old_head;
      return val;
		}

		T first() {
			return this->head->data;
		}

  private:
		QueueNode<T>* head = NULL;
		QueueNode<T>* tail = NULL;
};

template <class T>
class QueueNode {
	public:
		QueueNode(T data) {
			this->data = data;
		}

		T data;
		QueueNode<T>* next = NULL;
};
