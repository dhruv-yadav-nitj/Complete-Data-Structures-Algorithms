//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    static bool custom(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }

    long long maxPossibleValue(int N, vector<int> A, vector<int> B)
    {
        // code here

        vector<pair<int, int>> v;

        for (int i = 0; i < N; i++)
        {
            // code
            v.push_back({A[i], B[i]});
        }

        sort(v.begin(), v.end(), custom);
        for(auto x: v){cout << x.first << " " ;}  cout << endl ;

        long long ans = 0;

        int i = 0;
        while (v[i].second < 4 and i < N)
        {
            i++;
        }
        ans = v[i].first * 4;
        v[i].second -= 2;

        i= 0 ;
        while (v[i].second < 2 and i < N)
        {
            i++;
        }
        ans += v[i].first * 2;
        v[i].second -= 2; i++ ;

        while (v[i].second < 2 and i < N)
        {
            i++;
        }
        ans += v[i].first * 2;

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
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N, A, B);
        cout << ans << endl;
    }
}
// } Driver Code Ends