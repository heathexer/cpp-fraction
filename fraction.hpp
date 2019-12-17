#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
class Fraction {
 private:
  int numer, denom;
  bool isNeg;
  int gcd(int a, int b) {
    // x is the smaller of a or b, y is the larger
    int x = min(a, b), y = max(a, b);
    while (x != y) {
      // set the larger number to the difference between the numbers make sure y
      // is still the largest
      y = y - x;
      if (x > y) swap(x, y);
    }
    return x;
  }
  int lcm(int a, int b) { return (a * b) / gcd(a, b); }

  void reduce(Fraction *f_ptr) {
    // check if either the numerator or the denominator are negative, and if
    // they are then store it in the Fractions's isNegative property and make
    // the number positive
    if (f_ptr->numer < 0) {
      f_ptr->numer *= -1;
      f_ptr->isNeg = !f_ptr->isNeg;
    }
    if (f_ptr->denom < 0) {
      f_ptr->denom *= -1;
      f_ptr->isNeg = !f_ptr->isNeg;
    }

    int d = gcd(f_ptr->numer, f_ptr->denom);
    f_ptr->numer /= d;
    f_ptr->denom /= d;
  }

 public:
  Fraction(int n = 1, int d = 1) {
    numer = n;
    denom = d;
    isNeg = false;
    reduce(this);
  };
  // Addition
  Fraction operator+(Fraction const &obj) {
    int d = lcm(denom, obj.denom);
    int n1 = numer * (d / denom) * ((isNeg) ? -1 : 1);
    int n2 = obj.numer * (d / obj.denom) * ((obj.isNeg) ? -1 : 1);
    Fraction res(n1 + n2, d);
    reduce(&res);
    return res;
  };
  Fraction operator+(int const n) {
    Fraction res((numer * (isNeg) ? -1 : 1) + (n * denom), denom);
    reduce(&res);
    return res;
  };
  // Subtraction
  Fraction operator-(Fraction const &obj) {
    int d = lcm(denom, obj.denom);
    int n1 = numer * (d / denom) * ((isNeg) ? -1 : 1);
    int n2 = obj.numer * (d / obj.denom) * ((obj.isNeg) ? -1 : 1);
    Fraction res(n1 - n2, d);
    reduce(&res);
    return res;
  };
  Fraction operator-(int const n) {
    Fraction res((numer * (isNeg) ? -1 : 1) - (n * denom), denom);
    reduce(&res);
    return res;
  };
  // Multiplication
  Fraction operator*(Fraction const &obj) {
    Fraction res(numer * obj.numer, denom * obj.denom);
    if (isNeg) res.isNeg = !(res.isNeg);
    if (obj.isNeg) res.isNeg = !(res.isNeg);
    reduce(&res);
    return res;
  };
  Fraction operator*(int const n) {
    Fraction res((numer * (isNeg) ? -1 : 1) * n, denom);
    reduce(&res);
    return res;
  };
  // Division
  Fraction operator/(Fraction const &obj) {
    Fraction res(numer * obj.denom, denom * obj.numer);
    if (isNeg) res.isNeg = !(res.isNeg);
    if (obj.isNeg) res.isNeg = !(res.isNeg);
    reduce(&res);
    return res;
  };
  Fraction operator/(int const n) {
    Fraction res((numer * (isNeg) ? -1 : 1), denom * n);
    reduce(&res);
    return res;
  };
  // Comparisons
  bool operator<(Fraction &obj) { return (toDouble()) < (obj.toDouble()); }
  bool operator>(Fraction &obj) { return (toDouble()) > (obj.toDouble()); }
  bool operator==(Fraction &obj) {
    return numer == obj.numer && denom == obj.denom;
  }
  bool operator!=(Fraction &obj) {
    return numer != obj.numer || denom != obj.denom;
  }
  bool operator<=(Fraction &obj) { return (this < &obj || this == &obj); }
  bool operator>=(Fraction &obj) { return (this > &obj || this == &obj); }
  // Conversions
  string toString() {
    return ((isNeg) ? "-" : "") + to_string(numer) + "/" + to_string(denom);
  }
  float toFloat() { return ((isNeg) ? -1 : 1) * (float)numer / (float)denom; }
  double toDouble() {
    return ((isNeg) ? -1 : 1) * (double)numer / (double)denom;
  }
};