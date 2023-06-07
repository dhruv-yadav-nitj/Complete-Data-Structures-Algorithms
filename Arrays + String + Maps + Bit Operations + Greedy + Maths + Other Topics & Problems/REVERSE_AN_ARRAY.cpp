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

// Time Complexity: O(n)
// Aux Space : O(1)

void rotateArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
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
    rotateArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}