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

// Note: This problem is just a little bit tweaked version of the Problem : Printing Subsequences, we have to just add one more argument as the sum of the subArray
void printF(int arr[], int n, int sum, int i, vector<int> &subs, int s)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto x : subs)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // take
    subs.push_back(arr[i]);
    s += arr[i];
    printF(arr, n, sum, i + 1, subs, s);

    // not take
    subs.pop_back();
    s -= arr[i];
    printF(arr, n, sum, i + 1, subs, s);
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
    vector<int> sub;
    printF(arr, n, sum, 0, sub, 0);

    return 0;
}