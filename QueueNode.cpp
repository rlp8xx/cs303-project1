#include "QueueNode.h"
#include <string>

using namespace std;

QueueNode::QueueNode(string data, int priority) {
  this->data = data;
  this->priority = priority;
}

int QueueNode::get_priority() { return priority; }
void QueueNode::set_priority(int priority) {
  this->priority = priority;
}
string QueueNode::get_data() { return data; }
