//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool customSort(const pair<int, int> &a, const pair<int, int> &b)
    {
        // sorting the temp in increasing order of ending time
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(make_pair(start[i], end[i]));
        }
        sort(temp.begin(), temp.end(), customSort);
        int count(1);
        // phla meet to hmesa hoga
        // jo meeting phla khtm ho rhi hain usko khtm kro by comparing the start time of ith meet with comparing the end time of last meet conducted.

        int abhishek = temp[0].second;
        for (int i = 1; i < n; i++)
        {
            if (temp[i].first > abhishek)
            {
                count++;
                abhishek = temp[i].second;
            }
        }
        return count;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends