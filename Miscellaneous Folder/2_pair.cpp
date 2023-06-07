
// pair is useful when we have to return more than one value from a function

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int main()
{
    pair<int, int> p[5];
    p[0] = {1, 2}, p[1] = {1, 4}, p[2] = {2, 0}, p[3] = {3, 1}, p[5] = {9, 1};
    sort(p, p + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }

    // sorting is done with increasing first element, and if there's a tie than the second elements is compared.

    // creating a rank-list
    vector<pair<int, string>> rank = {{99, "Dhruv"}, {98, "Saurabh"} , {97, "Mayank"}};
    // taking some input in a vector pair
    for (int i = 0; i < 2; i++)
    {
        int a;
        string s ;
        cin >> a >> s ;
        rank.push_back(make_pair(a, s)) ;
    }
    
    
    sort(rank.begin(), rank.end());
    for (int i = 0; i < rank.size(); i++)
    {
        cout << rank[i].first << " " << rank[i].second << endl;
    }

    return 0;
}