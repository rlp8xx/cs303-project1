#include <iostream>
#include "Book.h"
#include "Date.h"
#include "Employee.h"
#include "Library.h"

void Library::add_book(string name) {
  books.push_back(Book(name, this));
  cout << "Book " << name << " added to library!" << endl;
  #ifdef NDEBUG
  cout << "Library::add_book: current books: ";
  for (Book b : books) {
    cout << b.get_name() << " ";
  }
  cout << endl;
  #endif
}

// add employee to the library
void Library::add_employee(string name) {
  // init employee
  Employee employee(name);
  // add to list of employees
  employees.push_back(employee);
  // iterate through books and add employee to each book's list
  for (Book book : books) {
    #ifdef NDEBUG
    cout << "Library::add_employee: adding employee to book ";
    cout << book.get_name() << "." << endl;
    #endif
    book.add_employee(employee);
  }
  cout << "Employee " << name << " added to library!" << endl;
}

// add waiting days to an employee
void Library::add_waiting(string target, int days) {
  #ifdef NDEBUG
  cout << "Library::add_waiting: adding " << days << " days to employee ";
  cout << target << endl;
  #endif
  // update the employee's waiting time
  for (Employee employee : employees) {
    if (employee.get_name() == target) {
      #ifdef NDEBUG
      cout << "Library::add_waiting: found target. Adding days." << endl;
      #endif
      employee.add_waiting(days);
      cout << "Added " << days << " days waiting to " << employee.get_name() << endl;
      break;
    }
  }
  // update the waiting queues for the books
  update_books();
}

// add retaining days to an employee
void Library::add_retaining(string target, int days) {
  // update the employee's retaining time
  for (Employee employee : employees) {
    if (employee.get_name() == target) {
      employee.add_retaining(days);
      cout << "Added " << days << " days retaining to " << employee.get_name() << endl;
      break;
    }
  }      
  // update the waiting queues for the books
  update_books();
}

// pass on specified book
void Library::pass_on(string book_name, Date date) {
  for (Book book : books) {
    if (book.get_name() == book_name) {
      string employee = book.pass_on(date);
      string no_employee = "";
      if (employee == no_employee) {
        cout << "Archived book " << book.get_name() << "." << endl;
      } else {
        cout << "Passed on book " << book.get_name() << " to employee " << employee << endl;
      }
    }
  }
}

void Library::circulate_book(string book_name, Date date) {
  for (Book book : books) {
    if (book.get_name() == book_name) {
      string employee = book.circulate(date);
      cout << "Circulated book " << book.get_name() << " to employee " << employee << endl;
    }
  }
}

// iterate through books and update 
void Library::update_books() {
  for (Book book : books) {
    book.update_employees(employees);
  }
}
