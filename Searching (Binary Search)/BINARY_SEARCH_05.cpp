
// Count occurences of an element in a sorted array
// Logic is to count the first occurence and the last occurence of the element in the sorted array using binary search and then (subtract them + 1)

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

int firstOCC(int arr[], int n, int target, int s, int e)
{
    int mid = s + (e-s)/2 ;
    if (s > e)
    {
        return -1;
    }
    else if (arr[mid] < target)
    {
        return firstOCC(arr, n, target, mid + 1, e);
    }
    else if (arr[mid] > target)
    {
        return firstOCC(arr, n, target, s, mid - 1);
    }
    else
    {
        if (arr[mid] == target and arr[mid] != arr[mid - 1])
        {
            return mid;
        }
        else
        {
            return firstOCC(arr, n, target, s, mid - 1);
        }
    }
}

int lastOCC(int arr[], int n, int target, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return -1;
    }
    else if (arr[mid] < target)
    {
        return lastOCC(arr, n, target, mid + 1, e);
    }
    else if (arr[mid] > target)
    {
        return lastOCC(arr, n, target, s, mid - 1);
    }
    else
    {
        if (arr[mid] == target and arr[mid + 1] != target)
        {
            return mid;
        }
        else
        {
            return lastOCC(arr, n, target, mid + 1, e);
        }
    }
}

int countOcc(int arr[], int n, int target)
{
    if (firstOCC(arr, n, target, 0, n) == -1)
    {
        return 0;
    }
    else
    {
        return (lastOCC(arr, n, target, 0, n) - firstOCC(arr, n, target, 0, n) + 1);
    }
}

int main()
{
    IOS;
    int arr[] = {2, 2, 3, 4, 6, 7, 20, 20, 20, 50, 60};
    int target = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countOcc(arr, n, target) << endl;

    return 0;
}