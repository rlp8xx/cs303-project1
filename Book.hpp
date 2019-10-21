#include <string>
#include <iostream>
#include "PriorityQueue.hpp"
#include "Employee.hpp"

using namespace std;

class Book {
  public:
    Book(string name, Library* library) {
      this->name = name;
      this->home = library;
    }

    // update queue with new priorities
    void update_employees(const vector<Employee> employees) {
      // iterate through employees and update each priority
      for (Employee e : employees) {
        employee_circ.modify_priority(e.get_name(), e.get_priority());
      }
    }

    void add_employee(Employee employee) {
      employee_circulation.push(employee.get_name(), employee.get_priority());
    }

    void pass_on(Date date) {
      // 
    }

    void circulate(Date date) {
      // add circ_start date
      // set holder to top of queue person
      // update 
    }

    bool archived() {
      return archived;
    }

  private:
    // parent library
    // this is necessary for modifying employee times
    Library* home;
    // name of the book
    string name;
    // employee currently holding the book
    string holder;
    // circulation start/end date
    Date circ_start;
    Date circ_end;
    bool archived;
    PriorityQueue employee_circ;
}; 
