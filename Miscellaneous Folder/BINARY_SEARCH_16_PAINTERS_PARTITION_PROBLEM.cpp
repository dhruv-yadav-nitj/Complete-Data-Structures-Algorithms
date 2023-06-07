
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

// https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557?leftPanelTab=1
// Painters Partition Problem
// Exact same as Book Allocation Problem

bool isPossible(vector<int> &boards, int k, int barrier)
{
    int n = boards.size();
    int sum(0), count(1);
    for (int i = 0; i < n; i++)
    {
        if (sum + boards[i] <= barrier)
        {
            sum += boards[i];
        }
        else
        {
            count++;
            if (count > k or boards[i] > barrier)
            {
                return false;
            }
            sum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low(0), high(accumulate(boards.begin(), boards.end(), 0));
    int ans(-1) ;
    while (low <= high)
    {
        int barrier = low + (high - low) / 2;
        if (isPossible(boards, k, barrier))
        {
            ans = barrier;
            high = barrier - 1;
        }
        else
        {
            low = barrier + 1;
        }
    }
    return ans;
}

int main()
{
    IOS;

    return 0;
}