
// Pivot Element: For a Sorted and Rotated Array, {3, 4, 5, 6, 1, 2}, the pivot element would be 6 (index 3)
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

int findPivot(int arr[], int n, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    if (high == low)
    {
        return low;
    }

    int mid = low + (high - low) / 2;
    if (mid < high and arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    else if (mid > low and arr[mid] < arr[mid - 1])
    {
        return mid - 1;
    }
    else if (arr[low] >= arr[mid])
    {
        return findPivot(arr, n, low, mid - 1);
    }
    else
    {
        return findPivot(arr, n, mid + 1, high);
    }
}

int main()
{
    IOS;
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Pivot Element: ";
    cout << arr[findPivot(arr, n, 0, n)] << endl;

    return 0;
}