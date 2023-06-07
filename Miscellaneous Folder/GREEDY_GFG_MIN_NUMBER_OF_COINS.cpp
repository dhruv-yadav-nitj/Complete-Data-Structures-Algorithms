//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int n = N;
        vector<int> ans;
        for (int i = 0; i < sizeof(notes) / sizeof(notes[0]) and n > 0; i++)
        {
            while (n >= notes[i])
            {
                ans.push_back(notes[i]);
                n -= notes[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends