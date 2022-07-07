#include<iostream>
using namespace std;
//This algorithm is used when A and B are co-prime to get modulo inverse.
//In such cases, x becomes the multiplicative modulo inverse of A under modulo B, 
//and y becomes the multiplicative modulo inverse of B under modulo A.

long long d, x, y;
void extendedEuclid(long long A, long long B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        long long temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main(){

    long long a,b;
    cin>>a>>b;

   extendedEuclid(a, b);

   cout << d << endl;
   cout << "Coefficients x and y are "<< x << " "<< y << endl;

  return 0;   
}
// 224071575 364495063 502891141 446040648
// 155984643
// 969109092 60139073 122541116 75884463
// 22271562