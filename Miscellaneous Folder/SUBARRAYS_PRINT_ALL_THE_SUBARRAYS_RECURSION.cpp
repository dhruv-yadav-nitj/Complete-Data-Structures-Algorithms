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

void printSubArr(vector<int> v, int start, int end)
{
    // time complexity: O(2^n)
    if (end == v.size())
    {
        return;
    }
    else if (start > end)
    {
        printSubArr(v, 0, end + 1);
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            cout << v[i] << " ";
        }
        cout << v[end] << endl ;
        printSubArr(v, start+1, end);
    }
    return ;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    printSubArr(v, 0, 0);

    return 0;
}