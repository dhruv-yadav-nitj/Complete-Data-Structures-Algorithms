//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void doSolve(vector<int> &A, vector<vector<int>> &ans, vector<int> temp, int index, int target)
    {
        if (index == A.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        // pick
        if (target >= A[index])
        {
            temp.push_back(A[index]);
            doSolve(A, ans, temp, index, target - A[index]);
            temp.pop_back();
        }

        // not pick
        doSolve(A, ans, temp, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        vector<vector<int>> ans;
        vector<int> temp;


        // Many of you must have searched for std::unique with a view that it will remove all the duplicate elements from the container, and now you might feel a bit disappointed to know that it removes only the consecutive duplicate elements. But, although, std::unique cannot do so as per its definition, but applying a bit of logic, we can make that happen. What we need to do is just sort the array before applying std::unique, such that all equal elements become consecutive, and now we have std::unique to remove all the duplicate consecutive elements. So, std::unique can also be used to remove all the duplicate elements from a container.
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        // since unique function cannot resize the element we are using erase function along it.


        doSolve(A, ans, temp, 0, B);
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
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends