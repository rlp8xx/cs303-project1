#include <string>

using namespace std;

class Book {
  public:
    Book(string name) {
      this->name = name;
    }

    string get_name() {
      return this->name;
    }

    int get_days_waiting() {
      return this->days_waiting;
    }

    int get_days_retaining() {
      return this->days_retaining;
    }

  private:
    string name;
    int days_waiting = 0;
    int days_retaining = 0;
};
