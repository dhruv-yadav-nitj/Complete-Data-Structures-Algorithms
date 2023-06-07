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

void say_hello(int t)
{
    if (t == 0)
    {
        return;
    }
    cout << "hello " << t << endl;
    say_hello(--t);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    say_hello(n);
    return 0;
}