#include <iostream>
#include "fraction.hpp"

using namespace std;

int main() {
  Fraction a(1, 3);
  Fraction b(2, 3);
  Fraction c = a * b;
  cout << c.toString() << '\n';
  return EXIT_SUCCESS;
}