//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool check(unordered_map<char, int> m1, unordered_map<char, int> m2)
    {
        if (m1.size() == m2.size())
        {
            if (m1 == m2)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    int search(string pat, string txt)
    {
        unordered_map<char, int> m, temp;
        for (int i = 0; i < pat.length(); i++)
        {
            m[pat[i]]++;
            temp[txt[i]]++;
        }
        int count(0);
        (check(m, temp)) ? (count++) : (count += 0);
        int k = pat.size();
        for (int i = k; i < txt.length(); i++)
        {
            temp[txt[i]]++;
            temp[txt[i - k]]--;
            if (temp[txt[i - k]] == 0)
            {
                temp.erase(temp.find(txt[i - k]));
            }
            (check(m, temp)) ? (count++) : (count += 0);
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends