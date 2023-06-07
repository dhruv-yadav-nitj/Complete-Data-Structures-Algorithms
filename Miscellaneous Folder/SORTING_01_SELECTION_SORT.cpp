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

void SelectionSort(vector<int> &arr, int n)
{
    // Time Complexity: O(n2)
    // Space Complexity: O(1)
    for (int i = 0; i < n; i++)
    {
        int current = arr[i], toSwap(i);
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[toSwap])
            {
                toSwap = j;
            }
        }
        swap(arr[i], arr[toSwap]);
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}