
/*
Given an array of n numbers that has values in range [1, n+1]. Every no. appears exactly once. Hence one no. is missing. Find the missing no.
*/
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

// method 2 : Using XOR
// (1 ^ 2 ^ 3 ^ 4 ...... ^ n+1) ^ (arr[0] ^ arr[1] ^ arr[2] ^ .... ^ arr[n-1]) = missed number
int doSolve(int arr[], int n)
{
    int temp = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        temp = temp ^ i;
    }
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }
    return temp;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    int arr[n];

    // method 1 ; Using sum of AP , find the total sum and then subtract the sum of array from it. the missing number is found
    int sum(0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    // using sum of AP : n/2 * (a + l)
    int temp = (n + 1) * (1 + (n + 1)) / 2;
    cout << abs(temp - sum) << endl;
    // time complexity = O(n)

    cout << doSolve(arr, n) << endl;

    return 0;
}