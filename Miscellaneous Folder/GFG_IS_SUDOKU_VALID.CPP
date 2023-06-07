//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        unordered_set<string> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] != 0)
                {
                    string box = "box", row = "row", col = "col";
                    box += to_string(i / 3 * 3 + j / 3) + to_string(mat[i][j]);
                    row += to_string(i) + to_string(mat[i][j]);
                    col += to_string(j) + to_string(mat[i][j]);

                    if (s.count(box) == 1 or s.count(row) == 1 or s.count(col) == 1)
                    {
                        return 0;
                    }

                    s.insert(box);
                    s.insert(row);
                    s.insert(col);
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends