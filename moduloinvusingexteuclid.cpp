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
long long modInverse(long long A, long long M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

int main(){

    long long a,m;
    cin>>a>>m;

   cout <<modInverse(a, m);

//    cout << d << endl;
//    cout << "Coefficients x and y are "<< x << " "<< y << endl;

  return 0;   
}
