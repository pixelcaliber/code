#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
    public:
      int data;  //attribute
      Node *nxt; //attribute
      // Node(int value)  //we can also create a constructor using which data will be assigned to the new node...
      // {
      //   data = value;
      //   nxt = nullptr;
      // }
};
Node *head;
void addAtFirst(int data)
{
      // creating a new node with data as the value stored in it.
      Node *new_node = new Node;
      new_node->data = data;
      // nxt pointer of new node is at head.
      new_node->nxt = head;
      // head is at new_node beginning.
      head = new_node;
}
void addAtEnd(int data)
{
      // creating a new node with data as value in it.
      Node *new_node = new Node;  
      new_node->data = data;
      
      // using contructor insted of above 2 steps only this one is enough..
      //Node *new_node = new Node(data);

      // nxt pointer of new node is at end or nullptr.
      new_node->nxt = nullptr;
      
      // now, we need to reach the end in order to add a node at the end.
      // time comp is of the order of N.
      Node *last = head;

      if (head == nullptr)
      {
        head = new_node; //if adding to an empty linked list.
        return;
      }
      while (last->nxt != nullptr)
      {
          last = last->nxt;
      }
      // once we reach the end we assign, such that it points newnode's address.
      last->nxt = new_node;
}
void addAtMiddle(int data, int index)
{
     Node *prev_node = head;
     for (int i = 0; i < index-1; i++)
     {
         prev_node = prev_node->nxt;
     }
     if (prev_node == nullptr)
     {
         return;
     }
      // creating a new node with data as value in it.
      Node *new_node = new Node;  
      new_node->data = data;
      
      // using contructor insted of above 2 steps only this one is enough..
      //Node *new_node = new Node(data);

      // nxt pointer of new node is pointing at nxt of prevnode.
      new_node->nxt = prev_node->nxt;

      // moving nxt of prev to new node.
      prev_node->nxt = new_node;
}
void del_Specific_pos(int pos){
    
    if (pos == 0)
    {
        head = head->nxt;
        return;
    }
    Node *prev_node = new Node;
    prev_node = head;
    for (int i = 0; i < pos-1; i++)
    {
        prev_node = prev_node->nxt;
    }
    Node *temp = new Node;
    temp = prev_node->nxt->nxt;
    free(prev_node->nxt);
    prev_node->nxt = temp;

}
void del_Specific_key(int data){
    
    Node *prev_node = new Node;
    prev_node = head;
    if (prev_node->data == data)
    {
         head = head->nxt;
         return;
    }
    while(prev_node != NULL)
    {
        if (prev_node->nxt->data == data)
        {
           break;
        }
        else
        prev_node = prev_node->nxt;
    }
    if (prev_node == NULL){
        cout<<"CANNOT FIND"<<endl; return;
    }
    Node *temp = new Node;
    temp = prev_node->nxt->nxt;
    free(prev_node->nxt);
    prev_node->nxt = temp;

}
void del_wholeList(){
    Node *crr = new Node, *temp = nullptr;
    crr = head;
    while (crr != NULL)
    {
        temp = crr->nxt;
        free(crr);
        crr = temp;
    }
    head = nullptr;

}
void display(Node *position)
{
      Node *node = position;
      while (node != nullptr)
      {
          cout << node->data << "-->";
          node = node->nxt;
      }
      if (node == nullptr)
      {
          cout << "null"<<endl;;
      }
}
int main()
{
    //   for (int i = 0; i < 3; i++)
    //   {
    //       addAtFirst(4);
    //   }
    //   for (int i = 0; i < 3; i++)
    //   {
    //       addAtEnd(2);
    //   }
    //    for (int i = 0; i < 2; i++)
    //   {
    //       addAtFirst(1);
    //   }
    //       int index = 4;
    //       addAtMiddle(0, index);
    //       //del at start.
    //       head = head->nxt;

    //       //del at end.
    //       Node *temp = head;
    //       while (temp->nxt->nxt!=nullptr)
    //       {
    //           temp = temp->nxt;
    //       }
    //       temp->nxt = nullptr;

    //       //del at a given pos.
    //       Node *pos = head;
    //       for (int i = 0; i < index-1; i++)
    //       {
    //            pos = pos->nxt;
    //       }
    //       Node *temp2 = pos->nxt->nxt;
    //       pos->nxt = temp2;
    //       // head = nullptr; // clear all linked list
    //       Node *position = head;
    //       //  position = position->nxt;
    //         display(position);
            for (int i = 0; i < 6; i++)
            {
                addAtFirst(6 - i);
            }
              display(head);
              del_Specific_pos(5);

              del_Specific_key(4);

              display(head);
              del_wholeList();
              display(head);
}