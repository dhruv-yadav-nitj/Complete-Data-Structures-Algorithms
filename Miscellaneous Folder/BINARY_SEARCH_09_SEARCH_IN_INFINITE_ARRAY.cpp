// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
// Find position of an element in a sorted array of infinite numbers
// Practically its not possible to have an array of infinite size but if we have an array of size of about millions then also it would be enough to act as like infinite array.
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

int binarySearch(int arr[], int n, int target, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, n, target, s, mid - 1);
    }
    else
    {
        return binarySearch(arr, n, target, mid + 1, e);
    }
}

int doThisforMe(int arr[], int n, int target)
{
    if (arr[0] == target)
    {
        return 0;
    }
    int i = 1;
    while (arr[i] < target)
    {
        i = i * 2;
    }
    if (arr[i] == target)
    {
        return i;
    }
    // now we would apply binary search for the part of array with s = 0 and e = i ;
    return binarySearch(arr, n, target, 0, i);
}

int main()
{
    IOS;
    int arr[] = {10, 45, 90, 324, 9508};
    // so in the case of much larger sized array we would be narrowing down our search area first.
    int target = 45;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << doThisforMe(arr, n, target);

    return 0;
}