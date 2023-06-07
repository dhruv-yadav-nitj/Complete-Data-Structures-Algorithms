// Given an array of integers, find if it has an equilibrium point
//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {
        int summ(0);
        for (int i = 0; i < n; i++)
        {
            summ += a[i];
        }
        int temp(0);
        for (int i = 0; i < n; i++)
        {
            temp += a[i];
            if (temp - a[i] == summ - temp)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends