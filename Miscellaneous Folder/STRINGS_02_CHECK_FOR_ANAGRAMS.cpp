//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        // Method 1: using Sorting
        if (a.length() != b.length())
        {
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;

        // method 2: we can use  two unordered_map for storing frequency of the characters of each string
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends