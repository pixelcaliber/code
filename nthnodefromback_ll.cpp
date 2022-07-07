#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public: 
    ll data;
    Node *nxt;
};
Node *head;
void addTofront(ll data){
    Node* new_node = new Node;
    new_node->data = data;

    new_node->nxt = head;
    head = new_node;
}
int main(){
     for (int i = 0; i < 6; i++)
     {
         ll x;
         cin>>x;
         addTofront(x);
     }
      Node*temp1, *temp2;
      temp1 = head;
      temp2 = head;
      ll n;cin>>n;
      for (int i = 0; i < n; i++)
      {
          temp2 = temp2->nxt;
      }
       while (temp2 != nullptr)
       {
            temp2 = temp2->nxt;
            temp1 = temp1->nxt;
       }
       cout<<temp1->data<<endl;
}