#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define NDEBUG

using namespace std;

class QueueNode {
  public:
    QueueNode(string data, int priority) {
      this->data = data;
      this->priority = priority;
    }

    int get_priority() { return priority; }
    void set_priority(int priority) {
      this->priority = priority;
    }
    string get_data() { return data; }

  private:
    string data;
    int priority;
};

bool cmp(QueueNode &a, QueueNode &b) {
    return a.get_priority() < b.get_priority();
}

class PriorityQueue {
  public:
    PriorityQueue() {
    }

    // add item to queue with priority
    void push(string data, int priority) {
      heap_vec.push_back(QueueNode(data, priority));
      push_heap(heap_vec.begin(), heap_vec.end(), cmp);
    }

    // get the highest priority item
    // returns empty string if the queue is empty
    string top() {
      if (this->empty()) return "";
      return heap_vec[0].get_data();
    }
    
    // return the top item in the queue
    // returns empty string if the queue is empty
    string pop() {
      if (this->empty()) return ""; 
      // swap highest priority to back of vector and re-heap it
      pop_heap(heap_vec.begin(), heap_vec.end(), cmp);
      // save the highest priority item
      string back = heap_vec.back().get_data();
      // remove and return highest priority which is now at back
      heap_vec.pop_back();
      return back;
    }

    // if string exists in vector, modify it's priority
    void modify_priority(string target, int new_priority) {
      for(int i = 0; i < heap_vec.size(); i++) {
        if (heap_vec[i].get_data() == target) {
          heap_vec[i].set_priority(new_priority);
          make_heap(heap_vec.begin(), heap_vec.end(), cmp);
          return;
        }
      }
    }
    
    // check if the queue is empty
    bool empty() {
      return heap_vec.empty();
    }
  private:
    vector<QueueNode> heap_vec;
};
