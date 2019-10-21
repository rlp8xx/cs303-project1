#ifndef DATE_H
#define DATE_H

class Date {
  public:
    Date() {
      days = 0;
    }

    Date(int epoch_days) {
      days = epoch_days;
    }

    friend int operator-(Date &d1, Date &d2) {
      return d1.days - d2.days;
    }
  
  private:
    int days;
};
#endif
