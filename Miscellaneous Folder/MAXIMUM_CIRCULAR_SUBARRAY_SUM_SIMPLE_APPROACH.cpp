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

// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

// The number of normal subarrays for an array with size n = (n*(n+1))/2
/*
What is a circular Subarray ?
Let us suppose we have {10, -5, 5}  then the normal subarrays would be {10} , {-5} , {5} , {10, -5} , {-5, 5} , {10, -5, 5} and we have some circular subarrays {5, 10, -5} , {-5, 5, 10} , {5, 10}
*/

int maxCircularSubArr(vector<int> v)
{
    // time complexity : O(n^2)
    // space complexity : O(1)
    int n = v.size();
    int currentSum(0), maxSumforCurrentElement(0);
    int ans(v[0]);
    for (int i = 0; i < n; i++)
    {
        currentSum = v[i];
        maxSumforCurrentElement = v[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            currentSum += v[index];
            maxSumforCurrentElement = max(currentSum, maxSumforCurrentElement);
        }
        ans = max(ans, maxSumforCurrentElement);
    }
    return ans;
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
    cout << maxCircularSubArr(v) << endl;

    return 0;
}