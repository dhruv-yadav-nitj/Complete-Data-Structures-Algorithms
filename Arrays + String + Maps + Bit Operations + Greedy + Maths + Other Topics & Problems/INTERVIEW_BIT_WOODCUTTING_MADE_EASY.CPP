#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// binary search as it should be applied always

// https://www.interviewbit.com/problems/woodcutting-made-easy/

int solve(vector<int> &A, int B)
{

    // ojas can set the min height of blade as 0 and max height as the max height of all the trees
    int low = 0, high = A[0], n1 = A.size();
    for (int i = 0; i < n1; i++)
    {
        high = max(high, A[i]);
    }
    int ans = INT_MIN;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        long long sum = 0;
        for (int i = 0; i < n1; i++)
        {
            if (A[i] > mid)
            {
                sum += A[i] - mid;
            }
        }

        if (sum == B)
        {
            ans = mid;
            break;
        }
        else if (sum < B)
        {
            high = mid;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
