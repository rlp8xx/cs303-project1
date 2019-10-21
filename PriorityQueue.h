#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include "QueueNode.h"
#include <string>
#include <vector>
#include <algorithm>

class PriorityQueue {
  public:
    PriorityQueue();

    // add item to queue with priority
    // O(1) complexity
    void push(std::string data, int priority);

    // get the highest priority item
    // returns empty string if the queue is empty
    // O(1) complexity
    std::string top();
    
    // return the top item in the queue
    // returns empty string if the queue is empty
    // O(log n) complexity worst case
    std::string pop();

    // if string exists in vector, modify it's priority
    // does nothing if target doesn't exist
    // O(n) complexity
    void modify_priority(std::string target, int new_priority);
    
    // check if the queue is empty
    // O(1)
    bool empty();

  private:
    std::vector<QueueNode> heap_vec;
};
#endif
