#include "Queue.hpp"

#include <iostream>
#include <string>

#define NDEBUG
#include <cassert>

using namespace std;

void test1() {
  cout << "Test 1" << endl;
  MyQueue<string>* q = new MyQueue<string>();
	string test = "test string";
	cout << "Adding " << test << endl;
	q->add_item(test);
	string test2 = "test string 2";
	cout << "Adding " << test2 << endl;
	q->add_item(test2);
  string test3 = "test string 3";
  cout << "Adding " << test3 << endl;
  q->add_item(test3);

  string first = q->pop();
  string second = q->pop();
  string third = q->pop();
	cout << "Top item: " << first << endl;
  assert(first == test);
	cout << "Top-1 item: " << second << endl;
  assert(second == test2);
  cout << "Top-2 item: " << third << endl;
  assert(third == test3);
  cout << "Test 1 complete." << endl << endl;
}

void test2() {
  cout << "Test 2" << endl;
  MyQueue<string>* q = new MyQueue<string>();
  string test = "asdf 1234";
  q->add_item(test);
  q->pop();
  string should_be_null = q->pop();
  assert(should_be_null == NULL);
  q->add_item(test);
  string should_be_test = q->pop();
  assert(should_be_test == test);
  cout << "Test 2 complete." << endl << endl;
}

int main() {
  test1();
  test2();
}
