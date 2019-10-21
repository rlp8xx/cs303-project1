#ifndef QUEUENODE_H
#define QUEUENODE_H
#include <string>

class QueueNode {
  public:
    QueueNode(std::string data, int priority);

    int get_priority();
    void set_priority(int priority);
    std::string get_data();

  private:
    std::string data;
    int priority;
};
#endif
