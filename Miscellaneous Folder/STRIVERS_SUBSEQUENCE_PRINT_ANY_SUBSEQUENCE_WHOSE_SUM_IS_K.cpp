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

// Note : This problem is again a little bit tweaked version of Problem ;Printing Subsequences

bool printF(int arr[], int n, vector<int> &sub, int i, int sum, int s)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto x : sub)
            {
                cout << x << " ";
            }
            return true;
        }
        return false;
    }

    // take condition
    s += arr[i];
    sub.push_back(arr[i]);
    if (printF(arr, n, sub, i + 1, sum, s))
    {
        return true;
    }

    // not take condition
    s -= arr[i];
    sub.pop_back();
    if (printF(arr, n, sub, i + 1, sum, s))
    {
        return true;
    }

    return false;
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

    if (printF(arr, n, sub, 0, sum, 0) == false)
    {
        cout << "NO SUCH PERMUTATIONS FOUND" << endl;
    }

    return 0;
}