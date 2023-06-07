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

void solve()
{
    int n;
    cin >> n;
    int score1(0), score2(0);
    int maxi(INT_MIN);
    int win(INT_MIN), lead(INT_MIN);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        score1 += a, score2 += b;
        if (maxi < abs(score1 - score2))
        {
            maxi = abs(score1 - score2);
            (score1 < score2) ? (win = 2) : (win = 1);
        }
    }
    cout << win << " " << maxi << endl;
}

int main()
{
    solve();
    return 0;
}