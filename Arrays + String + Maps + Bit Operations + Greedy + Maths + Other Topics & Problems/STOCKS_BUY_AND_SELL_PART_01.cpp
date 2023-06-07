// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
//{ Driver Code Starts
// Initial template for C++
// The cost of stock on each day is given in an array A[] of size N. Find the maximum profit you can make by buy and sell the stock.

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

int profit(vector<int> v)
{
    // the idea is to buy the stock when price is going down and sell it when its going up
    // see the part 2 videos of GFG COURSE in ARRAYS UNIT --> LECTURE NO. 19
    int ans(0);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i - 1])
        {
            ans += v[i] - v[i - 1];
        }
        return ans;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << profit(arr) << endl;

    return 0;
}