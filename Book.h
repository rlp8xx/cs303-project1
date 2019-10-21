#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include "PriorityQueue.hpp"
#include "Date.h"

#include "Library.hpp"

class Book {
  public:
    Book(std::string name, Library* library);

    // update queue with new priorities
    void update_employees(const vector<Employee> employees);

    void add_employee(Employee employee);

    // pass on the book at date
    // returns name of employee to whom the book is passed or "" if archived
    string pass_on(Date date);

    // begin circulation of book on date
    // returns name of first holder
    string circulate(Date date);

    bool is_archived();

    string get_name();

  private:
    // parent library
    // this is necessary for modifying employee times
    Library* library;
    // name of the book
    std::string name;
    // employee currently holding the book
    std::string holder;
    // circulation start/end date
    Date circ_start;
    Date circ_end;
    bool archived;
    PriorityQueue employee_circ;
}; 
#endif
