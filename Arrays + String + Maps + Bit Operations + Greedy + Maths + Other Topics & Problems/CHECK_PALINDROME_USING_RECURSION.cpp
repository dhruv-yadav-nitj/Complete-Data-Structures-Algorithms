#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// time complexity : O(n)
// aux space : O(n)
bool isPalindrome(string s, int i)
{
    if (i >= (s.length() - 1 - i))
    {
        return true;
    }

    if (s[i] == s[s.length() - 1 - i])
    {
        return isPalindrome(s, i + 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    IOS;
    string s;
    cin >> s;
    if (isPalindrome(s, 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}