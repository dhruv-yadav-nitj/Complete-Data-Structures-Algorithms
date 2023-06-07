//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Explanation:
    // Edge Case: [{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}]
    // Note that its not necessary that we have to do some work at that given deadline but we can also do the work before the deadline
    // Like in example we can do the work with 27 Profit in t= 1 and work with 100 profit in t = 2;

    // Function to find the maximum profit and the number of jobs done.

    static bool customSort(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, customSort);
        int count(0), profit(0);
        int maxi(INT_MIN);
        for (int i = 0; i < n; i++)
        {
            // for storing the work with last dead line
            maxi = max(maxi, arr[i].dead);
        }

        bool deads[maxi + 1];
        memset(deads, true, maxi + 1);

        // its more logical to do the work with late deadline more late, so that we can finish the work with early dead line , early to gain maxm  profit
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j >= 1; j--)
            {
                if (deads[j])
                {
                    count++, profit += arr[i].profit;
                    deads[j] = false;
                    break;
                    // jb is particular work ko ek slot assign ho gya hain then break
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends