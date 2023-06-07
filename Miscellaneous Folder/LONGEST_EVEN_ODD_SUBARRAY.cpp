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

int lengthofLongest(vector<int> v)
{
    int n = v.size();
    int ans(0), currentL(1);
    for (int i = 1; i < n; i++)
    {
        if ((v[i] % 2) == (v[i - 1] % 2))
        {
            ans = max(ans, currentL);
            currentL = 1;
        }
        else
        {
            currentL++;
        }
    }
    ans = max(ans, currentL) ;
    
    return ans;
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
    cout << lengthofLongest(v) << endl;

    return 0;
}