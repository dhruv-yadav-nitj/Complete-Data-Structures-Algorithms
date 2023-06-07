//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// } Driver Code Ends

int longestSubstrDistinctChars(string S)
{
    int maxi(0), count(0);
    unordered_map<char, int> m;
    int i(0), j(1);
    while (i < S.length())
    {
        if (m[S[i]] == 0)
        {
            m[S[i]]++;
            count++;
            i++;
        }
        else
        {
            maxi = max(maxi, count);
            count = 0;
            m.clear();
            i = j;
            j++;
        }
    }
    maxi = max(maxi, count);
    return maxi;
}