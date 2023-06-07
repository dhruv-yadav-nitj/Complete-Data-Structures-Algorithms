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

void generateSubsets(string s, string &temp, int i)
{
    if (i == s.length())
    {
        cout << s << endl;
        return;
    }

    // case 1: take the current element
    temp += s[i];
    generateSubsets(s, temp, i + 1);

    // case 2 : not take the element
    temp.pop_back();
    generateSubsets(s, temp, i + 1);
}

int main()
{
    IOS;
    string s;
    cin >> s;

    return 0;
}