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

bool check_palindrome(string s, int i)
{
    if (i == s.size() - 1)
    {
        if (s[i] == s[s.size() - 1 - i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return check_palindrome(s, ++i);
}

int main()
{
    IOS;
    string s;
    cin >> s;
    if (check_palindrome(s, 0))
    {
        cout << "Yes, a palindrome." << endl;
    }
    else
    {
        cout << "No, not a palindrome." << endl;
    }

    return 0;
}