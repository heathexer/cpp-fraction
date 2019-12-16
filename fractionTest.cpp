#include <iostream>
#include "fraction.hpp"

using namespace std;

int main() {
  Fraction a(-1, 3);
  Fraction b(2, 4);
  Fraction c;
  cout << "a: " + a.toString() + '\n';
  cout << "b: " + b.toString() + '\n';
  c = a + b;
  cout << "a+b: " + c.toString() + '\n';
  c = a - b;
  cout << "a-b: " + c.toString() + '\n';
  c = a * b;
  cout << "a*b: " + c.toString() + '\n';
  c = a / b;
  cout << "a/b: " + c.toString() + '\n';
  cout << "a as float: " + to_string(a.toFloat()) + '\n';
  cout << "b as float: " + to_string(b.toFloat()) + '\n';
  c = a + 3;
  cout << "a+3: " + c.toString() + '\n';
  c = b - 2;
  cout << "b-2: " + c.toString() + '\n';
  c = a * 4;
  cout << "a*4: " + c.toString() + '\n';
  c = b / -5;
  cout << "b/-5: " + c.toString() + '\n';
  return EXIT_SUCCESS;
}