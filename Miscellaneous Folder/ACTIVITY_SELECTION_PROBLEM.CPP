//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/

// } Driver Code Ends
class Solution{
public:
    static bool custom(const pair<int, int> &a, const pair<int, int>&b){
        return a.second < b.second ;
    }
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n){
        // Your code here

        vector<pair<int, int>> v ;
        for(int i=0; i < n; i++){v.push_back(make_pair(start[i], end[i])) ;}
        // phir isko sort krna pdhega
        // jo kaam phle khtm hoga usko phle khtm kro bhai --> sort the vector in increasing order of the ending time
        sort(v.begin(), v.end(), custom);

        // phla kaam to hmesa hoga
        int count(1), ending=v[0].second ;
        for(int i=0; i < n; i++){
            if(v[i].first > ending){count++ ; ending = v[i].second ;}
        }
        return count ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    // testcases
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        // adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        // function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends