#include <string>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "Employee.h"
#include "Date.h"
#include "Library.h"
#include "Book.h"

using namespace std;

Book::Book(string name, Library* library) {
  this->name = name;
  this->library = library;
  this->circ_start = Date(0);
  this->circ_end = Date(0);
  this->employee_circ = new PriorityQueue();
}

Book::~Book() {
  delete this->employee_circ;
}

string Book::get_name() {
  return name;
}

// update queue with new priorities
void Book::update_employees(const vector<Employee> employees) {
  // iterate through employees and update each priority
  for (Employee e : employees) {
    employee_circ->modify_priority(e.get_name(), e.get_priority());
  }
}

void Book::add_employee(Employee employee) {
  #ifndef NDEBUG
  cout << "Book::add_employee: Adding " << employee.get_name() << endl;
  #endif
  employee_circ->push(employee.get_name(), employee.get_priority());
  #ifndef NDEBUG
  cout << "Book::add_employee: employee_circ length is now ";
  cout << employee_circ->size() << endl;
  #endif
}

// pass on the book at date
// returns name of employee to whom the book is passed or "" if archived
string Book::pass_on(Date date) {
  #ifndef NDEBUG
  cout << "Book::pass_on: Passing on boot" << endl;
  #endif
  if (employee_circ->empty()) {
    #ifndef NDEBUG
    cout << "Book::pass_on: employee_circ is empty. Archiving." << endl;
    #endif
    library->add_retaining(holder, date - circ_end);
    circ_end = date;
    archived = true;
    return "";
  }
  // circ_end gets set to the most recent pass on date
  // use it to find retaining time
  library->add_retaining(holder, date - circ_end);
  holder = employee_circ->pop();
  // find waiting time by subtracting circulation start from pass on date
  library->add_waiting(holder, date - circ_start);
  circ_end = date;
  return holder;
}

// begin circulation of book on date
// returns name of first holder
string Book::circulate(Date date) {
  // add circ_start date
  // set holder to top of queue person
  // update 
  circ_start = date;
  circ_end = date;
  holder = employee_circ->pop();
  return holder;
}

bool Book::is_archived() {
  return archived;
}

