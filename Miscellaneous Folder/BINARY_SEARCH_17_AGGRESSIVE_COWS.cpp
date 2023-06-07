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

// https://www.youtube.com/watch?v=wSOfYesTBRk

bool isPossibleToPlace(vector<int> &stalls, int k, int mid)
{
    // temp stands for the coordinate of the last cow placed and count is the number of cows places till now, so we would obviously start placing the cows from the first indexed element
    int temp = stalls[0], count(1);
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - temp >= mid)
        {
            count++;
            temp = stalls[i];
            // if at any point we are like we have placed all the cows then we would return true
            if (count == k)
            {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    // low would be the min distance we can keep between two cows i.e., 1 and high would be max distance we can keep between two cows (i.e., the largest difference we can have)
    int low(1), high(stalls[stalls.size() - 1] - stalls[0]);
    int ans(-1);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // mid is the distance for which we have to check that whether for this minimum distance we can all the cows or not
        if (isPossibleToPlace(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}