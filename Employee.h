#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee {
  public:
    Employee (string name);

    int get_priority();
  
    void add_waiting(int days);

    void add_retaining(int days);

    string get_name();

  private:
    string name;
    // days spent waiting and days spent retaining
    int waiting_time;
    int retaining_time;
};
#endif
