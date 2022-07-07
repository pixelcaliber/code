#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define ll          long long
#define pb          push_back

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef vector<pair<ll, ll>> vpl;

const ll mod = 1e9 + 7, N = 2e5 + 2, alphabetSize = 26;
int n;

struct Trie{
    Trie* links[26];
    bool isEnd;
};

Trie *getnode()
{
    Trie* newNode = new Trie;
    newNode->isEnd = false;
    for (int i = 0; i < 26; ++i)
        newNode->links[i] = nullptr;

    return newNode;
}

void insert(Trie *root, string key)
{
    Trie *newNode = root;
    for (int i = 0; i < (int) key.length(); ++i)
    {
        int ind = key[i] - 'a';
        if (!newNode->links[ind])
            newNode->links[ind] = getnode();

        newNode = newNode->links[ind];
    }
    newNode->isEnd = true;
}
bool search(Trie *root, string key)
{
    Trie *newNode = root;
    for (int i = 0; i < (int) key.length(); ++i)
    {
        int ind = key[i] - 'a';
        if(!newNode->links[ind])
            return false;

        newNode = newNode->links[ind];
    }
    return newNode->isEnd;
}

int main()
{
    vector<string>keys = {"the", "a", "there","answer", "any", "anyy", "bye", "their"};
    n = keys.size();

    Trie *root = getnode();
    for (int i = 0; i < n; ++i)
    {
        insert(root, keys[i]);
    }

    search(root, "anyy")? cout << "Yes\n" : cout << "No\n";
    search(root, "these")? cout << "Yes\n" : cout << "No\n";
    search(root, "their")? cout << "Yes\n" : cout << "No\n";
    search(root, "thaw")? cout << "Yes\n" : cout << "No\n";

    int cap = 5;
    try{
        if (cap < 0)
        {
            throw "abc";
        }
        cout<<cap<<endl;
    }
    catch(const char *Message) {
        cout<<Message;
    }

}
                                     // ** Word Break ** //
    // struct Trie{
    //     Trie *links[26];
    //     bool isEnd;
    // };
    // Trie* getnode()
    // {
    //     Trie *newNode = new Trie;
    //     for(int i=0;i<26;i++)
    //         newNode->links[i] = nullptr;
    //     newNode->isEnd = false;
    //     return newNode;
    // }
    // void insert(Trie *root, string key)
    // {
    //     Trie *newnode = root;
    //     for(int i=0;i<key.length();i++)
    //     {
    //         int id = key[i] - 'a';
    //         if(!newnode->links[id])
    //         {
    //             newnode->links[id] = getnode();
    //         }
    //         newnode = newnode->links[id];
    //     }
    //     newnode->isEnd = true;
    // }
    // bool search(Trie *root, string key)
    // {
    //     Trie* newnode = root;
    //     for(int i=0;i<key.length();i++)
    //     {
    //         int id = key[i] - 'a';
    //         if(!newnode->links[id])
    //             return false;
    //         newnode = newnode->links[id];
    //     }
    //     return newnode->isEnd;
    // }
   
    // bool wordBreak(string s, vector<string>& a) {
        
    //     Trie *root = getnode();
    //     for(int i=0;i<a.size();i++)
    //     {
    //         insert(root, a[i]);
    //     }
    //     vector<bool> dp(s.size()+1, false);
    //     dp[0]=true;
        
    //     for(int len=1; len<=s.size(); len++){
    //         for(int i=0; i<len; i++){
    //             if(dp[i] && search(root, s.substr(i, len-i)))
    //                 dp[len]=true;
    //         }
    //     }
    //     return dp[s.size()];
    // }
