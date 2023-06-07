//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Try 1
        // Time Complexity: O(N)
        /* sort(arr, arr + N);
        int count(1), ans(1);
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i + 1] == arr[i])
            {
                continue;
            }
            else if (arr[i + 1] == arr[i] + 1)
            {
                count++;
            }
            else
            {
                ans = max(count, ans);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans; */

        // Approach 2: using Hashing
        // Intution: We create a Hash table and insert all the elements in it and then for any arr[i] we check whether arr[i]-1 is present in the hash table or not, if it is not then we can assume that it is the start of a subsequence and then we initialise a loop from arr[i]+1 and check till when the upcoming numbers are present in the hash table and increae the count according to it.

        unordered_set<int> s;
        for (int i = 0; i < N; i++)
        {
            s.insert(arr[i]);
        }
        int ans(0);
        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) == s.end())
            {
                // means not found, then we can start checking from here
                int count(1);
                int temp(arr[i] + 1);
                while (s.count(temp))
                {
                    count++, temp++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends