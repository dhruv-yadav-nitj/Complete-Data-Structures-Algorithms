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

// Getting TLE

void solve()
{
    l n;
    cin >> n;
    // while (n % 2 == 0)
    // {
    //     n /= 2;
    // }
    int i(0);
    while (i * i <= n)
    {
        i++;
    }
    int s(0), e(i);
    while (s <= e)
    {
        if (s * s + e * e == n)
        {
            cout << s << " " << e << endl;
            return;
        }
        else if (s * s + e * e > n)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    cout << -1 << endl;
    return;
}

int main()
{
    IOS;
    l t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
Other Tries
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

    // method 1:- using Hashing --> Getting TLE
    /* if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
    {
        cout << sqrt(n) << " " << 0 << endl;
        return;
    }
    unordered_set<int> s;
    for (int i = 1; i * i <= n; i++)
    {
        s.insert(i * i);
        if (s.count(n - (i * i)))
        {
            cout << (i) << " " << sqrt(n - (i * i)) << endl;
            return;
        }
    }
    cout << -1 << endl;

// method 2:- same as method 1 but modified
int temp(0);
while (n % 2 == 0)
{
    temp++;
    n /= 2;
}
if ((temp & 1) == 1)
{
    temp--;
    n = n * 2;
}
for (int i = 0; i * i <= n / 2; i++)
{
    int temp2 = n - (i * i), temp3 = sqrt(temp2);
    if (temp3 * temp3 == temp2)
    {
        cout << (temp3 << (temp / 2)) << " " << (i << (temp / 2)) << endl;
        return;
    }
}
cout << -1 << endl;
}

int main()
{
    IOS;
    l t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
*/