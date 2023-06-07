// this is just a variation of previous program
// we have to print exactly one subsequence whose sum is k
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

bool f(int arr[], int n, int k, int sum, vi subar, int idx)
{
    if (idx == n)
    {
        if (sum == k)
        {
            for (auto x : subar)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    // take
    subar.push_back(arr[idx]);
    sum += arr[idx];
    if (f(arr, n, k, sum, subar, idx + 1))
    {
        return true;
    }

    // not take
    subar.pop_back();
    sum -= arr[idx];
    if (f(arr, n, k, sum, subar, idx + 1))
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vi v;
    f(arr, n, k, 0, v, 0);

    return 0;
}