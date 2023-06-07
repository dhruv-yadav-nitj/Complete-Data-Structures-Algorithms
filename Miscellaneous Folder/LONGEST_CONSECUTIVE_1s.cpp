//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        int counter(0), count(0);
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                count++;
                counter = max(counter, count);
            }
            else
            {
                count = 0;
            }
            N = N / 2 ;
        }
        return counter;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution obj;
        // calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
}
// } Driver Code Ends