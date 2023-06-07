// map is based on red black tree and unordered map is based on hashing
// map stores in an ordered way on the basis of keys but unordered map stores in unordered format
// the default value for a key in both of them is 0.
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

int main()
{
    IOS;
    unordered_map<int, int> m;
    cout << m[10] << endl;

    unordered_map<string, int> n;
    // we can insert some elements in a map using the following two ways.
    n["gfg"] = 1;
    n.insert({"dhruv", 32});

    // the elements of tha map can be accessed using tha same way as pair
    for (auto x : n)
    {
        cout << x.first << " " << x.second << endl;
    }

    // find function
    // end function returns an iterator which is just after the last element, that if find function points to that iterator then this means that element not found in the data structure
    if (n.find("dhruv") == n.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    for (auto i = n.begin(); i != n.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    // count function
    // an alternate to the find function, returns 1 or 0
    if (n.count("gfg") != 0)
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // size function
    cout << "size of n " << n.size() << endl;

    // erase function
    n.erase("dhruv");
    n.erase(n.begin(), n.end());
    cout << n.size() << endl;

    // all the function above mentioned have an avg case time complexity of O(1);

    return 0;
}