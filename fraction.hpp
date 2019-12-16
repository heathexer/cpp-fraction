#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
class Fraction {
 private:
  int numer, denom;

 public:
  Fraction(int n, int d) {
    numer = n;
    denom = d;
  };
  Fraction operator*(Fraction const &obj) {
    return Fraction(numer * obj.numer, denom * obj.denom);
  };
  string toString() {
    return "(" + to_string(numer) + "/" + to_string(denom) + ")";
  }
};