#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define ll          long long
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define vin(a)      ll x; cin >> x; a.pb(x);
#define loop(i,x,y) for(int i = x; i < y; i++)

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef vector<pair<ll, ll>> vpl;

const ll N = 2e5 + 2;
class Node{
public:
	int data;
	Node *next;
};
Node *head;

void addAtFront(int data){

	Node *new_node = new Node;// create a new node and assign it the data
	new_node->data = data;

	new_node->next = head; //make the nxt of new node point towards head

	head = new_node;  //make the ad of new node the add of head or update the head
}
void addAtEnd(int data){

	Node *new_node = new Node; //create a new node and assign it the data value
	new_node->data = data;

	new_node->next = nullptr; // make the next of new node null as it will be present at the end

	Node *last = head;   //now we need to find the last node iterate from head until we reach last
	//tc is o(n)
	if (head == nullptr)	// if list is empty i.e. head is null assign it to new node
	{
		head = new_node;
		return;
	}
	while(last->next != nullptr){
		last = last->next;
	}
	last->next = new_node;  //assign last node nexts to new node i.e. update its value
}
void addAtMiddle(int data, int index){

	Node *prev = head;
	for (int i = 0; i < index - 1; ++i)
	{
		prev = prev->next;
	}
	if (prev == nullptr)
	{
		return;
	}

	Node *new_node = new Node;
	new_node->data = data;

	new_node->next = prev->next;
	prev->next = new_node;

}


void display(int start, int end){

	Node *new_node = head;
	for (int i = 0; i < start - 1; ++i)
	{
		new_node = new_node->next;
	}
	if (new_node == nullptr)
	{
		return;
	}
	for (int i = 0; i < end and new_node != nullptr; ++i)
	{
		cout<<new_node->data<<" --> ";
		new_node = new_node->next;
	}
	if (new_node == nullptr)
	{
		cout<<"null";
	}

}
void del_specific_pos(int pos){

	if (pos == 1)
	{
		head = head->next;
		return;
	}

	Node *newNode = new Node;
	newNode = head;

	for (int i = 0; i < pos - 2; ++i)
	{
		newNode= newNode->next;
	}
	if (newNode == nullptr)
	{
		return;
	}

	Node *temp = new Node;
	temp = newNode->next->next;
	free(newNode->next);
	newNode->next = temp;
}
void del_specific_key(int key){

	Node *newNode = new Node;
	newNode = head;

	if (newNode->data == key)
	{
		head = head->next;
		return;
	}
	while (newNode->next != nullptr){
		if (newNode->next->data == key)
		{
			break;
		}
		newNode = newNode->next;
	}
	if (newNode == nullptr)
	{
		cout<<"cannoy find key\n";
		return;
	}

	Node *temp = new Node;
	temp = newNode->next->next;
	free(newNode->next);
	newNode->next = temp;

}
void del_wholeList(){

	Node *c = new Node, *temp = nullptr;
	while(c != nullptr){
		temp = c->next;
		free(c);
		c = temp;
	}
	head = nullptr;
}

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		addAtFront(i + 1);
	}
	for (int i = 0; i < 1; ++i)
	{
		addAtMiddle(10, 1);
	}
	for (int i = 0; i < 2; ++i)
	{
		addAtEnd(i + 5);
	}
	display(1, 7);

	del_specific_pos(7);
	cout<<endl;
	display(1, 6);

	del_specific_key(10);
	cout<<endl;
	display(1, 5);

}