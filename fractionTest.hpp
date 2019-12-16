#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
class Fraction {
 private:
  int numer, denom;
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
    int d = gcd(f_ptr->numer, f_ptr->denom);
    f_ptr->numer /= d;
    f_ptr->denom /= d;
  }

 public:
  Fraction(int n, int d) {
    numer = n;
    denom = d;
  };
  Fraction operator+(Fraction const &obj) {
    int d = lcm(denom, obj.denom);
    int n1 = numer * (d / denom);
    int n2 = obj.numer * (d / obj.denom);
    Fraction res(n1 + n2, d);
    reduce(&res);
    return res;
  };
  // Fraction operator-(Fraction const &obj) {
  //   Fraction res(numer * obj.numer, denom * obj.denom);
  //   reduce(&res);
  //   return res;
  // };
  Fraction operator*(Fraction const &obj) {
    Fraction res(numer * obj.numer, denom * obj.denom);
    reduce(&res);
    return res;
  };
  Fraction operator/(Fraction const &obj) {
    Fraction res(numer * obj.denom, denom * obj.numer);
    reduce(&res);
    return res;
  };
  // Fraction operator=(Fraction const &obj) {
  //   Fraction res(obj.numer, obj.denom);
  //   return res;
  // };
  string toString() { return to_string(numer) + "/" + to_string(denom); }
};