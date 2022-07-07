#include<bits/stdc++.h>
using namespace std;
int n;
bool isSafe(vector<vector<int>>&v, int x, int y){
        for (int i = 0; i <= x; i++)
        {
            if (v[i][y] == 1)
            {
                return false;
            }            
        }
        int row = x, col = y;
        while (row>=0 && col>=0)
        {
            if (v[row][col] == 1)
            {
                return false;
            }
            row--;
            col--;
        }
     row = x; col = y;
    while (row>=0 && col<n)
    {
        if (v[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool nQueen(vector<vector<int>>&v, int y){

    if (y>=n)
    {
        return true;
    }
    
    for (int i = 0; i < v.size(); i++)
    {
         if (isSafe(v, y, i))
         {
             v[y][i] = 1;
             if (nQueen(v, y+1))
             {
                 return true;
             }
         }
             v[y][i] = 0;
    }
    return false;
}
int main(){
    
     cin>>n;
     vector<vector<int>>v;
     for (int i = 0; i < n; i++)
     {
         vector<int>temp;
         for (int j = 0; j < n; j++)
         {
             temp.push_back(0);
         }
         v.push_back(temp);
     }
     nQueen(v, 0);
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
            cout<<v[i][j]<<" ";
         }
         cout<<endl;
     }
}