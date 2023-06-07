// Printing Subsequences with Sum k
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void f(int arr[], int n, int k, int sum, vi subar, int idx)
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
        }
        return;
    }

    // take
    subar.push_back(arr[idx]);
    sum += arr[idx];
    f(arr, n, k, sum, subar, idx + 1);

    // not take
    subar.pop_back();
    sum -= arr[idx];
    f(arr, n, k, sum, subar, idx + 1);
}

int main()
{
    /* int arr[] = {1, 2,1} ;
    int k = 3 ;
    vi v ;
    int n = sizeof(arr)/sizeof(arr[0]) ; */
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