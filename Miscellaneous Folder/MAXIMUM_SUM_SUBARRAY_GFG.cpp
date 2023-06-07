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

int maxSUMMethod1Naive(vector<int> v)
{
    // Time Complexity: O(n^2)
    int n = v.size();
    int currentSum(0), ans(0);
    for (int i = 0; i < n; i++)
    {
        currentSum = v[i];
        for (int j = i + 1; j < n; j++)
        {
            currentSum += v[j];
            ans = max(ans, currentSum);
        }
    }
    return ans;
}

int maxSumMethod2Pro(vector<int> v)
{
    // Time Complexity: O(n)
    // Notes: In this method, we found out the maximum sum of a subarray that must end with this element. Iska explanation kaafi acha hain, see the video. At every iteration we have two option either we choose the previous subarray and add the current element in that subarray or we discard the previous subarray and start new subarray with the current element.
    /* 
    Elements:           1       -2         3       -1       2
    Subarray Sum:   0 or 1   -1 or -2   1 or 3   2 or -1   4 or 2 
    Max Sum:        0 or 1    1 or 2    2 or 3   3 or 2     3 or 4
    we would choose the max value at each iteration for Subarray Sum and Max Sum
    */
    // ALso we can have a addon in this question like Find the Subarray with max sum.
    int n = v.size();
    int currentSum(0), ans(0);
    for (int i = 0; i < n; i++)
    {
        currentSum = max(v[i], currentSum + v[i]);
        ans = max(ans, currentSum);
    }
    return ans;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxSumMethod2Pro(v) << endl ; 

    return 0;
}