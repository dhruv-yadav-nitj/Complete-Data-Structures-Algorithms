//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string isSumOfTwo(int N)
    {
        // well we would first apply sieve to get all the numbers smaller than N
        // then for every prime number 'x' where x < 34 we would check if there exist a prime number (34-x);
        int n = N;
        bool prime[n + 1];
        memset(prime, true, n + 1);
        // memset is used to initialize a block of memory with some predefined values.
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                // cout << i << " ";
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true and prime[n - i] == true)
            {
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends