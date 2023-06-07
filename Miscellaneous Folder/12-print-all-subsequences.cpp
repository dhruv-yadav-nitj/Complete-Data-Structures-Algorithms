#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void f(int arr[], int idx, vi subarr, int n)
{
    // base condition
    if (idx == n)
    {
        // print subarr
        for (auto x : subarr)
        {
            cout << x << " ";
        }
        cout << "\n";

        return;
    }

    // else we would take the element and increment the index
    subarr.push_back(arr[idx]);
    f(arr, idx + 1, subarr, n);

    // else we can also "not" take the element and increment the index
    subarr.pop_back();
    f(arr, idx + 1, subarr, n);
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
    cout << "\n";
    vi v;

    // empty subsequence
    cout << "{ }" << endl;

    f(arr, 0, v, n);

    return 0;
}