// Given an array of integers and a number k, find the maximum sum of k consecutive elements
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

int maxSumKElem(vector<int> v, int k)
{
    // Time Complexity: O(n)
    /*
    Note:
    */
    int n = v.size();
    int currentSum(0), maxSum(0);
    // first consider the sum of first k elements
    for (int i = 0; i < k; i++)
    {
        currentSum += v[i];
    }
    maxSum = currentSum;
    // then just add the current element in the currentsum and subtract the first element of previous set of k elements from the current sum
    for (int i = k; i < n; i++)
    {
        currentSum += (v[i] - v[i - k]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
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
    cout << maxSumKElem(v, k) << endl;

    return 0;
}