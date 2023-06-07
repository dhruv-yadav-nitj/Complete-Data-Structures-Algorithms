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

void insertionSort(vector<int> &arr, int n)
{
    // Time Complexity: O(n2)
    // A Stable Sorting Algorithm
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    insertionSort(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}