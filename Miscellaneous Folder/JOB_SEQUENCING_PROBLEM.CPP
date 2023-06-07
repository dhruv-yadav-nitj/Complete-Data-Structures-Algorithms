//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution{
private:
    static bool custom(Job a, Job b){
        return a.profit > b.profit ; // profit agar same hua to kaise bhi rkh do because neeche lgani loop hi hain
    }
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){
        // sort the arr according to the profit earned
        sort(arr, arr+n, custom); int count(0), profit(0) ;
        int maxi(INT_MIN) ;
        for(int i=0;i < n ; i++){maxi = max(maxi, arr[i].dead) ;} // to store the last deadline
        // means maxi is now the last day till which we have to work
        bool isDone[maxi +1 ]; // maxi+1 because array to 0-indexed based hota hain and hme kaam to 1st day se krna hain
        memset(isDone, true, maxi+1) ; // koi day true hain iska mtlb us din abhi tk koi kaam assign nhi hua hain
        for(int i=0; i < n; i++){
            for(int j = arr[i].dead ; j >= 1; j--){
                if(isDone[j]){
                    // mean is din abhi tk kaam assign nhi hua hain
                    isDone[j]= false;
                    count++ ; profit += arr[i].profit ;
                    break ; // since ab is kaam ko ek din allot ho gya then break
                }
            }
        }
        vector<int> ans ; ans.push_back(count) ; ans.push_back(profit) ;
        return ans ;
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