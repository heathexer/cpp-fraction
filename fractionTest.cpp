#include <iostream>
#include "fraction.hpp"

using namespace std;

int main() {
  Fraction a(-1, 3);
  Fraction b(2, -4);
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
  // cout << c.toString() << '\n';
  return EXIT_SUCCESS;
}