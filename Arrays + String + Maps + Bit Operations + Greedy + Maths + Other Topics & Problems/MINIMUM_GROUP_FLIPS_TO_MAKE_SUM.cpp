
// https://www.geeksforgeeks.org/minimum-group-flips-to-make-binary-array-elements-same/#:~:text=We%20need%20to%20do%20it%20using%20the%20minimum%20number%20of%20group%20flips.&text=Explanation%20%3A%20We%20have%20two%20choices,group%20flips%2C%20we%20do%20this.

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

/*
There are only two possibilities, either the first and last elements of the array are same or they are different. When they are same then the difference in group count of 1s and 0s is 1 and when they are different then the difference is 0. So, in either case we have to flip every 2nd group to make minimum number of flips.
*/

void printArray(vector<int> v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        // if current elements is not same as previous element then we have to do something
        if (v[i] != v[i - 1])
        {
            // if its not same as first element then its starting of a new group to be flipped, since we have to flip every 2nd group
            if (v[i] != v[0])
            {
                cout << "From " << i << " To ";
            }
            // else its end of the group
            else
            {
                cout << (i - 1) << endl;
            }
        }
    }
    // exceptional handling the end of last group to be flipped
    if (v[n - 1] != v[0])
    {
        cout << n - 1 << endl;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    printArray(v);

    return 0;
}