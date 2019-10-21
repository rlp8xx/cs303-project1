#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee (string name) {
  this->name = name;
}

int Employee::get_priority() {
  return waiting_time - retaining_time;
}

void Employee::add_waiting(int days) {
  this->waiting_time += days;
}

void Employee::add_retaining(int days) {
  this->retaining_time += days;
}

string Employee::get_name() {
  return name;
}
