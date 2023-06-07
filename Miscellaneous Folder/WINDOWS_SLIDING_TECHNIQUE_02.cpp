// Given an unsorted array of non-negative integers. Find if there exist a subarray with given sum.
// Very very intersting problem from interview perspective (as told by Mr. Sandeep Jain)

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

bool findSubArr(vector<int> v, int k)
{
    int n = v.size();
    // Revision : A Subarray is a contiguous part of an array. an array that is inside another array.
    int currentSum(v[0]), s = 0;
    for (int e = 1; e < n; e++)
    {
        // clean the previous window
        while (currentSum > k and s < e - 1)
        {
            currentSum -= v[s];
            s++;
        }
        if (currentSum == k)
        {
            return true;
        }
        if (e < n)
        {
            currentSum += v[e];
        }
    }
    return (currentSum == k);
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
    int k;
    cin >> k;
    if (findSubArr(v, k))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}