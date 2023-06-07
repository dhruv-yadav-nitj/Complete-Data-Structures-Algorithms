
// https://www.interviewbit.com/blog/fractional-knapsack-problem/

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
using namespace std;

bool valueWeight(pair<int, int> a1, pair<int, int> a2)
{
    double x1 = (double)a1.first / a1.second;
    double x2 = (double)a2.first / a2.second;

    // since we want decreasing weight means (i)th item should be greater than (i+1)th item
    return x1 > x2;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    vector<double> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), valueWeight);

    int i = 0;
    double value = 0;
    while (w > 0)
    {
        if (a[i].second <= w)
        {
            double insert = a[i].second;
            w -= insert;
            value += insert * (a[i].first / a[i].second);
        }
        else
        {
            double insert = w;
            w -= insert;
            value += insert * (a[i].first / a[i].second);
        }
        i++ ;
    }

    cout << value << endl;

    return 0;
}