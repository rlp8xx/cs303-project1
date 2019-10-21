#include <string>

using namespace std;

class Employee {
  public:
    int get_priority() {
      return waiting_time - retaining_time;
    }
  
    void add_waiting(int days) {
      this->waiting_time += days;
    }

    void add_retaining(int days) {
      this->retaining_time += days;
    }

    string get_name() {
      return name;
    }

  private:
    string name;
    // days spent waiting and days spent retaining
    int waiting_time;
    int retaining_time;
};
