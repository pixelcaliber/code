#include <bits/stdc++.h>
using namespace std;
int getbit(int n, int i){

    return ((n & (1<<i)!=0));
}
int setbit(int n, int i){

    return (n | (1<<i));
}
int clearbit(int n, int i){

    return (n & ~(1<<i));
}
int updatebit(int n, int i, int value){

     n = (n & ~(1<<i));

    return (n | (value<<i));
}
int main(){
   
cout<<getbit(5 ,1)<<endl;
cout<<setbit(5 ,1)<<endl;
cout<<clearbit(5 ,1)<<endl;
cout<<updatebit(5 ,1, 1)<<endl;



}