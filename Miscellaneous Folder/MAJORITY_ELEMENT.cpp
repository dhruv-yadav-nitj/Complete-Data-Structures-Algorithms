// https://www.geeksforgeeks.org/majority-element/
// An element is said to be a Majority Element if it appears more than n/2 times in the array where n is the size of the given array.
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Other ways to solve the problem
// https://www.geeksforgeeks.org/majority-element/

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // Solution 1: Naive Solution
        // Time Complexity: O(n)
        // Aux Space: O(n) bcz we are using a map
        /* int n = size;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
            if (m[a[i]] > n / 2)
            {
                return a[i];
            }
        }
        return -1; */

        // Solution 2: More Efficient Solution
        // Time Complexity: O(n)
        // Aux Space: O(1)
        int curr(0), count(1);
        for (int i = 1; i < size; i++)
        {
            if (a[i] == a[curr])
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    curr = i, count = 1;
                }
            }
        }
        count = 0;
        // now let see whether the chosen element is a majority element or not
        for (int i = 0; i < size; i++)
        {
            if (a[curr] == a[i])
            {
                count++;
            }
        }
        if (count <= size / 2)
        {
            return -1;
        }
        return a[curr];
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends