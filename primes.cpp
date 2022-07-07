#include<iostream>
using namespace std;
int main(){

    int a,b;
    cin>>a>>b;
    for (int  i = a; i <=b; i++)
    {
        int j;
        for ( j=2; j < i; j++)
        {
            if (i%j==0)
            {
                cout<<"j at which it is breaking is "<<j<<endl;
                break;
            }
             cout<<"unb j is "<<j<<endl;
        }
          cout<<"j is "<<j<<endl;
          cout<<"i is "<<i<<endl;
        if (j==i)
        {
            cout<<"ans is "<<i<<endl;
        }
    }
    return 0;

}