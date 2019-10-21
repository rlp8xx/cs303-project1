#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include "Date.h"
#include <vector>
#include "Employee.h"
#include "Book.h"

class Library {
  public:
    // add book to library
    void add_book(string name);

    // add employee to the library
    void add_employee(string name);
  
    // add waiting days to an employee
    void add_waiting(string target, int days);

    // add retaining days to an employee
    void add_retaining(string target, int days);
    
    // pass on specified book
    void pass_on(string book_name, Date date);

    void circulate_book(string book_name, Date date);

    // iterate through books and update 
    void update_books();

  private:
    vector<Employee> employees;
    vector<Book*> books;
};
#endif
