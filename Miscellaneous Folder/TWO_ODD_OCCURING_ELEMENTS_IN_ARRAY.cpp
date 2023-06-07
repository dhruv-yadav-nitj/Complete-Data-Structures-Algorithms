// Given an array where all elements appear even number of times except two, print the two odd occurring elements.
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

void doSolve(int arr[], int n)
{
    int temp(0);
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }

    // now we divide the array into two groups viz. a group having last bit SET or a group with all odd numbers and a group with all even numbers (last bit 0).
    int x(0), y(0);
    int Sn = (temp & (~(temp - 1)));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & Sn != 0)
        {
            x = (x ^ arr[i]);
        }
        else
        {
            y = (y ^ arr[i]);
        }
    }
    cout << x << " " << y << endl;
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
    // Method 1 : Naive Method : Time Complexity : O(n2)

    // Method 2 : Using BITWISE XOR
    doSolve(arr, n);

    return 0;
}