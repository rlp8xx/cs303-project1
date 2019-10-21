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
}

string Book::get_name() {
  return name;
}

// update queue with new priorities
void Book::update_employees(const vector<Employee> employees) {
  // iterate through employees and update each priority
  for (Employee e : employees) {
    employee_circ.modify_priority(e.get_name(), e.get_priority());
  }
}

void Book::add_employee(Employee employee) {
  employee_circ.push(employee.get_name(), employee.get_priority());
}

// pass on the book at date
// returns name of employee to whom the book is passed or "" if archived
string Book::pass_on(Date date) {
  // if employee passing on book is last in queue, archive book
  // retaining time for employee passing book gets adjusted
  //    date - circ_end
  // waiting time for employee receiving book gets adjusted
  //    date - circ_start
  // set circ_end to date
  
  if (employee_circ.empty()) {
    library->add_retaining(holder, date - circ_end);
    circ_end = date;
    archived = true;
    return "";
  }

  library->add_retaining(holder, date - circ_end);
  holder = employee_circ.pop();
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
  holder = employee_circ.pop();
  return holder;
}

bool Book::is_archived() {
  return archived;
}

