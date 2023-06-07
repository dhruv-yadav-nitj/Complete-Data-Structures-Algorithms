//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
    void doWork(vector<vector<int>> m , vector<string> &ans , vector<vector<bool>> isVisited , int i, int j , string s , int n){
        // main-recursion-function

        // base condition
        if(i == n-1 and j == n-1 ){
            ans.push_back(s) ;
            return ;
        }

        // since we have to travel lexicographically

        // downwards
        if(i+1 < n and !isVisited[i+1][j] and m[i+1][j] == 1){
            s += "D" ; isVisited[i][j] = false ;
            doWork(m , ans , isVisited , i+1 , j , s , n) ;
            s.pop_back() ; isVisited[i][j] = true ;
        }

        // leftwards
        if(j- 1 >= 0 and !isVisited[i][j-1] and m[i][j-1] == 1){
            s += "L" ; isVisited[i][j] = false ;
            doWork(m , ans , isVisited , i , j-1 , s, n) ;
            s.pop_back() ; isVisited[i][j] = true ;
        }

        // rightwards
        if(j+1 < n and !isVisited[i][j+1] and m[i][j+1] == 1){
            s += "R" ; isVisited[i][j] = false ;
            doWork(m , ans , isVisited , i , j+1 , s, n) ;
            s.pop_back() ; isVisited[i][j] = true ;
        }

        // upwards
        if(i- 1 >= 0 and !isVisited[i-1][j] and m[i-1][j] == 1){
            s += "U" ; isVisited[i][j] = false ;
            doWork(m , ans , isVisited , i-1 , j , s, n) ;
            s.pop_back() ; isVisited[i][j] = true ;
        }

        // well these 4 loops can be adjusted in a single loop using arrays for direction .. but this way is easy to understand this question .. though dont forget to have a look at the shorter code as well
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n){
        // code here
        vector<string> ans ;
        vector<vector<bool>> isVisited (n, vector<bool> (n , true)) ; // it would tell us whether a particular cell has been traversed or not --> if the cell is true than it can be visited and if it is false then it means that that cell is already visited and cant be visited again
        if(m[0][0] == 1){
            doWork(m , ans , isVisited , 0 , 0 , "" , n) ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends