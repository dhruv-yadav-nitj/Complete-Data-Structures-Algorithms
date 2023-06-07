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

/*
Problem Statement:
You are given a number n, the total length of the rope, and other three numbers  a, b, c. You have to re
*/

// Time Complexity : O(pow(3, n))
// This problem has better solution with Dynamic Programming

int maxNumberofRopes(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int temp = max({maxNumberofRopes(n - a, a, b, c), maxNumberofRopes(n - b, a, b, c), maxNumberofRopes(n - c, a, b, c)});

    if (temp == -1)
    {
        return -1;
    }
    return temp + 1;
}

int main()
{
    IOS;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxNumberofRopes(n, a, b, c) << endl;

    return 0;
}