#include <iostream>
#include "PriorityQueue.h"
#include "QueueNode.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(QueueNode &a, QueueNode &b) {
    return a.get_priority() < b.get_priority();
}

PriorityQueue::PriorityQueue() {
}

// add item to queue with priority
// O(1) complexity
void PriorityQueue::push(string data, int priority) {
  heap_vec.push_back(QueueNode(data, priority));
  push_heap(heap_vec.begin(), heap_vec.end(), cmp);
}

// get the highest priority item
// returns empty string if the queue is empty
// O(1) complexity
string PriorityQueue::top() {
  if (this->empty()) return "";
  return heap_vec[0].get_data();
}

// return the top item in the queue
// returns empty string if the queue is empty
// O(log n) complexity worst case
string PriorityQueue::pop() {
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
// does nothing if target doesn't exist
// O(n) complexity
void PriorityQueue::modify_priority(string target, int new_priority) {
  //Iterate through each to check for target
  // O(n)
  for(int i = 0; i < heap_vec.size(); i++) {
    if (heap_vec[i].get_data() == target) {
      heap_vec[i].set_priority(new_priority);
    }
  }
  // Rebuild the heap
  // O(n)
  make_heap(heap_vec.begin(), heap_vec.end(), cmp);
}

// check if the queue is empty
// O(1)
bool PriorityQueue::empty() {
  return heap_vec.empty();
}
