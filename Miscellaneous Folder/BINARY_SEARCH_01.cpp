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

// Iterative Approach of Binary Search
int binSearch(int arr[], int n, int key)
{
    int s = 0, e = n-1;
    int mid;
    while (s <= e)
    {
        // Time Complexity: O(logn)
        // Space Complexity: O(1)
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    IOS;
    int arr[] = {2, 3, 4, 10, 12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;
    cout << binSearch(arr, n, key) << endl;

    return 0;
}