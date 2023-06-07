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

int countF(int arr[], int n, int sum, int i, int s)
{
    if (i == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }

    // add in s
    s += arr[i];
    int lef = countF(arr, n, sum, i + 1, s);

    // not add in s
    s -= arr[i];
    int right = countF(arr, n, sum, i + 1, s);

    return lef + right;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    cout << countF(arr, n, sum, 0, 0) << endl;

    return 0;
}