//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        long long temp(-1);
        long long s(0), e(n - 1);
        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            if (v[mid] == x)
            {
                return mid;
            }
            else if (v[mid] < x)
            {
                temp = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends