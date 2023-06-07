//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {

        // Try 1 --> Naive Solution Using Hashing --> Got TLE
        /* vector<int> ans;
        for (int i = 0; i + k <= n; i++)
        {
            unordered_set<int> s;
            for (int j = i; j < i + k; j++)
            {
                s.insert(A[j]);
            }
            ans.push_back(s.size());
        }
        return ans; */

        // Try 2
        /*
        Approach:
        Create a frequency map of first k items
        Print Size of the frequency map
        for(int i =k ; i < n;i++)
            decrease frequency of arr[i-k]
            if the frequency of arr[i-k] becomes zero then remove it from the map
            if arr[i] does not exist in the map insert it else increase the frequency of it
            print size of the map
        */
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            m[A[i]]++;
        }
        ans.push_back(m.size());
        for (int i = k; i < n; i++)
        {
            m[A[i - k]]--;
            if (m[A[i - k]] == 0)
            {
                m.erase(A[i - k]);
            }
            m[A[i]]++;
            ans.push_back(m.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends