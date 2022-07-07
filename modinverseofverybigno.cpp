#include <iostream>
#include <utility>
#include <exception>
#include <tuple>

using namespace std;

long long calcInverse(long long a, long long n)
{
    long long t = 0, newt = 1;
    long long r = n, newr = a;  
    while (newr != 0) {
        auto quotient = r /newr;
        tie(t, newt) = make_tuple(newt, t- quotient * newt);
        tie(r, newr) = make_tuple(newr, r - quotient * newr);
    }
    if (r > 1)
        throw runtime_error("a is not invertible");
    if (t < 0)
        t += n;
    return t;
}

int main ()
{
  long long int a , n;

  cout << "Enter a: ";
  cin >> a;
  cout << "Enter n: ";
  cin >> n;
  
  try {
    auto inverse = calcInverse(a, n);
    cout << "The multiplicative inverse is " << inverse << endl;
  }
  catch(exception& e) {
      cout << e.what() << endl;
  }
  return 0;
}