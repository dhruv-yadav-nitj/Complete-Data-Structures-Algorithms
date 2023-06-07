
// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // int n = S.length() ;
        // int i(0) ;
        // int count(0), counter(0), ans(0);
        // map<char, int> m ;
        // while(counter < n)
        // {
        //     if(m[S[i]]>=1 or i==n)
        //     {
        //         ans = max(ans, count) ;
        //         i = counter ;
        //         m.clear() ;
        //         count =0 ;
        //         counter++ ;
        //     }
        //     else
        //     {
        //         count++ ;
        //         m[S[i]]++ ;
        //     }
        //     i++ ;
        // }
        // return ans ;
        vector<int> mp(26, -1);
        int i = 0;
        int j = 0;
        int n = S.length();
        int ans = INT_MIN;

        while (j < n)
        {
            if (mp[S[j] - 'a'] != -1)
            {
                i = max(mp[S[j] - 'a'] + 1, i);
            }
            mp[S[j] - 'a'] = j;
            ans = max(ans, j - i + 1);
            j++;
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
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}
// } Driver Code Ends