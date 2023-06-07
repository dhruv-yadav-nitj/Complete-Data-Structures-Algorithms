//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Time Complexity: O(n^2)
    // More efficient approach is possible, whose Time Complexity is Linear O(n)
    long long factorial(long long num)
    {
        return (num <= 1) ? (1) : (num * factorial(num - 1));
    }
    long long countSmaller(string str, int low, int high)
    {
        long long count(0);
        for (int i = low + 1; i < high; i++)
        {
            if (str[i] < str[low])
            {
                count++;
            }
        }
        return count;
    }
    long long findRank(string str)
    {
        long long l = str.length(), rank(0);
        long long fact = factorial(l), smallRight;
        for (long long i = 0; i < l; i++)
        {
            fact = fact / (l - i);
            // we need to count the alphabetically smaller letters but only which comes to the right of the current letter
            smallRight = countSmaller(str, i, l);

            rank += (smallRight * fact);
        }
        return rank + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout << ans << endl;
    }
}
// } Driver Code Ends