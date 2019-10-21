#include "Queue.hpp"

#include <iostream>
#include <string>

#define NDEBUG
#include <cassert>

using namespace std;

void test1() {
  PriorityQueue pq;
  string test1 = "test1";
  string test2 = "test2";
  string empty = "";
  pq.push(test1, 1);
  pq.push(test2, 2);
  string first = pq.pop();
  string second = pq.pop();
  assert(first == test2);
  assert(second == test1);
  assert(pq.pop() == empty);
}

void test2() {
  PriorityQueue pq;
  string test1 = "test1";
  string test2 = "test2";
  string test3 = "test3";
  string empty = "";
  pq.push(test1, 1);
  pq.push(test2, 2);
  pq.pop();
  pq.push(test3, 3);
  string first = pq.pop();
  string second = pq.pop();
  string third = pq.pop();
  assert(first == test3);
  assert(second == test1);
  assert(third == empty);
}

void test3() {
  PriorityQueue pq;
  string test1 = "test1";
  string test2 = "test2";
  string empty = "";
  pq.push(test1, 1);
  pq.push(test2, 2);
  pq.modify_priority(test1, 3);
  string first = pq.pop();
  string second = pq.pop();
  assert(first == test1);
  assert(second == test2);
  assert(pq.pop() == empty);
}

void test4() {
  PriorityQueue pq;
  string test1 = "test1asdfkjasd";
  string test2 = "test2d898fdyg";
  string test3 = "test3u dsf88943th";
  string test4 = "test4 fvfgji49403";
  string test5 = "test5 dfD*(F";
  string test6 = "test6 DF*(Y";
  pq.push(test3,3);
  pq.push(test6,6);
  pq.push(test1,1);
  pq.push(test4,4);
  pq.push(test5,5);
  pq.push(test2,2);
  pq.modify_priority(test3, 8);
  pq.modify_priority(test1, 9);
  assert(pq.pop() == test1);
  assert(pq.pop() == test3);
  assert(pq.pop() == test6);
  assert(pq.pop() == test5);
  assert(pq.pop() == test4);
  assert(pq.pop() == test2);
}


int main() {
  cout << "Running test1" << endl;
  test1();
  cout << "Test 1 complete" << endl;
  cout << "Running test2" << endl;
  test2();
  cout << "Test2 complete" << endl;
  cout << "Running test3" << endl;
  test3();
  cout << "Test3 complete" << endl;
  cout << "Running test4" << endl;
  test4();
  cout << "Test4 complete" << endl;
}
