// https://www.geeksforgeeks.org/combinational-sum/?ref=gcse
// Medium Level Problem on LeetCode
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void combinationSum(vi arr, int n, int ind, int k, vi ans)
{
    if (ind == n)
    {
        if (k == 0)
        {
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // pick up the element
    if (arr[ind] <= k)
    {
        ans.push_back(arr[ind]);
        k -= arr[ind];
        // combinationSum(arr, n, ind, k, ans);
        combinationSum(arr, n, ind + 1, k, ans);
        k += arr[ind];
        ans.pop_back();
    }
    combinationSum(arr, n, ind + 1, k, ans);
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    // since we have to return the subsequences in non-decreason order we should first sort the array
    sort(arr.begin(), arr.end());

    /* //  since we have been asked for unique subsequences then we should also remove all the duplicates
    vector<int>::iterator it;
    it = arr.begin();
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            arr.erase(it + i);
            i--;
        }
    } */

    vi ans;

    // call the function
    combinationSum(arr, n, 0, k, ans);

    return 0;
}