//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)
    {
        vector<int> ans;
        int top(0), left(0), right(a[0].size() - 1), bottom(a.size() - 1);
        // what we have to do is to change the above declared variables after every iteration
        // we have to increase the startTop++ , startLeft--, startRight++, startBottom--
        int rowNum(a.size()), colNum(a[0].size());

        // count is the number of elements printed till now and total is the total number of elements present in the matrix
        int count(0), total(rowNum * colNum);
        while (count < total)
        {
            // lets print the top most row of the present matrix
            for (int j = left; j <= right and count < total; j++)
            {
                ans.push_back(a[top][j]);
                count++;
            }
            top++;

            // lets print the right most columns of the present matrix
            for (int i = top; i <= bottom and count < total; i++)
            {
                ans.push_back(a[i][right]);
                count++;
            }
            right--;

            // lets print the bottom most row of the present matrix
            for (int j = right; j >= left and count < total; j--)
            {
                ans.push_back(a[bottom][j]);
                count++;
            }
            bottom--;

            // lets print the left most column of the present matrix
            for (int i = bottom; i >= top and count < total; i--)
            {
                ans.push_back(a[i][left]);
                count++;
            }
            left++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for (int i = 0; i < R * C; i++)
            cin >> a[i / C][i % C];
        Solution ob;
        vector<int> ans = ob.reverseSpiral(R, C, a);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends