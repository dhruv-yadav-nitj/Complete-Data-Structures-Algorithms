
// Find index of last occurence of an element in a sorted array

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

int lastOcc(int arr[], int n, int target, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return -1;
    }
    else if (arr[mid] > target)
    {
        return lastOcc(arr, n, target, s, mid - 1);
    }
    else if (arr[mid] < target)
    {
        return lastOcc(arr, n, target, mid + 1, e);
    }
    else
    {
        if (mid == n - 1 or arr[mid] != arr[mid + 1])
        {
            return mid;
        }
        else
        {
            return lastOcc(arr, n, target, mid + 1, e);
        }
    }
}

int main()
{
    IOS;
    int arr[] = {10, 20, 20, 30, 20, 40, 50};
    // after sorting
    // arr[] = {10, 20, 20, 20, 30, 40 ,50};
    int target = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << lastOcc(arr, n, target, 0, n - 1) << endl;

    return 0;
}