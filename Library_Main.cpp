#include <iostream>
#define NDEBUG
#include "Date.h"
#include "Library.h"

int main(){
  Library library;
  library.add_book("Software Engineering");
  library.add_book("Chemistry");
  library.add_employee("Adam");
  library.add_employee("Sam");
  library.add_employee("Ann");

  library.circulate_book("Chemistry", Date(2));
  library.circulate_book("Software Engineering", Date(3));

  library.pass_on("Chemistry", Date(4)); 
  library.pass_on("Chemistry", Date(5));
  library.pass_on("Chemistry", Date(6)); 

  library.pass_on("Software Engineering", Date(5));
  library.pass_on("Software Engineering", Date(10));
  library.pass_on("Software Engineering", Date(10));
}
