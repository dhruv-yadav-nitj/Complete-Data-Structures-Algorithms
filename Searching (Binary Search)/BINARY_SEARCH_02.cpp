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

// Recursive Approach of Binary Search
int binarySearchUsingRecursion(int arr[], int n, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    if (e < s)
    {
        return -1;
    }
    else
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return binarySearchUsingRecursion(arr, n, mid + 1, e, target);
        }
        else
        {
            return binarySearchUsingRecursion(arr, n, s, mid - 1, target);
        }
    }
}
// time complexity: O(logn)
// space complexity: O(logn)

int main()
{
    IOS;
    int arr[] = {2, 4, 5, 10, 40, 41, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cin >> target;
    cout << binarySearchUsingRecursion(arr, n, 0, n, target);

    return 0;
}