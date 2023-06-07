
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        string ans = "";
        string temp = "";
        for (int i = S.length() - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                temp += S[i];
                reverse(temp.begin(), temp.end());
                ans += temp;
            }
            else if (S[i] == '.')
            {
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += '.';
                temp = "";
            }
            else
            {
                temp += S[i];
            }
        }
        // ans.pop_back();
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends