//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        // Your code goes here
        // using unordered_set
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }
        int count(0);
        for (int i = 0; i < m; i++)
        {
            if (s.find(b[i]) != s.end())
            {
                count++;
                s.erase(s.find(b[i]));

                // why s.erase is necessary
                // suppose we have a[] = {10,15,20,15,30,30,5}; and b[] = {30,5,30,80}

                // then the set s would be having {5,10,15,20,30} and when we traverse the second array and when 30 comes then the count would be incremented two times so we are removing 30 after the first traversal
            }
        }
        return count;

        /* Approach 2
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }
        unordered_set<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.insert(b[i]);
        }
        int count(0);
        for (auto x : s)
        {
            if (temp.count(x))
            {
                count++;
            }
        }
        return count;
         */
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends