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

void bubbleSort(vector<int> &arr, int n)
{
    // in bubble sort we go in rounds
    // in ith round, the ith largest element gets its appropriate place
    // its a stable sorting algorithm
    // Time Complexity: O(n2)

    for (int i = n - 1; i >= 0; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!flag)
        {
            break;
        }
    }
    // bubble sort can be optimised in the case when let say at some round in betweeen theres no swapping occur, hence we can conclude at that point the array is already sorted. this can be done using adding a flag = false parameter.
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
    bubbleSort(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}