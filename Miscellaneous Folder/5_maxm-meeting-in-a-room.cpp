
// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/
/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. Find and output the maximum number of meetings that can be accommodated in the meeting room.

Input:
6
1 2
3 4
0 6
5 7
8 9
5 9

Output:
{1, 2} {3, 4} {5, 7} {8, 9}

Note: The first of input contains an integer n, denoting the total number of activities given. Then n, line follows with two integers, start and end time of the nth meeting. You have to output the start and end times of all the meetings possible to be accomodated.
*/

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

bool custom(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    vp v;
    int s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end(), custom);
    // int count = 1 ;
    cout << "{" << v[0][0] << ", " << v[0][1] << "}"
         << " ";
    int end = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] >= end)
        {
            // count++ ;
            cout << "{" << v[i][0] << ", " << v[i][1] << "}" << " ";
            end = v[i][1];
        }
    }
    // cout << count << endl ;

    return 0;
}