#include <iostream>
#include <string>

#define NDEBUG

using namespace std;

class PriorityQueueNode;

class PriorityQueue {
  public:
    void push(string data, int priority) {
      
    }
  private:
    PriorityQueueNode* items;
    
};

class PriorityQueueNode {
  public:
    int priority;
    string data;
  
    bool operator<(PriorityQueueNode const &a, PriorityQueueNode const &b) {
      return a->data < b->data;
    };
}
