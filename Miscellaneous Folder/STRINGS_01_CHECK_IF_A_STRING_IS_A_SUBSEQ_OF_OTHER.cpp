//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSubSequence(string A, string B)
    {
        // subsequence should have the same order
        int i = 0, j = 0;
        for (; i < A.length() and j < B.length();)
        {
            if (A[i] == B[j])
            {
                i++, j++;
            }
            else
            {
                j++;
            }
        }
        if (i == A.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        if (ob.isSubSequence(A, B))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}

// } Driver Code Ends