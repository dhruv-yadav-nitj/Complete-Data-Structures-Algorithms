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

void solve()
{
    string s;
    cin >> s;
    // min cost is the difference in the number of the last indexed element and the first indexed element of the string in the Alphabet Table.
    int minCost = abs(s[s.length() - 1] - s[0]);
    int numJumps(0);
    // Polycarp would only jump at the letters which lie between s[0] and s[s.length()-1]
    /*
    Intuition:
    Suppose we have to go from a to e
    a b c d e
    1 2 3 4 5
    then we can go from a to b then b to c then c to d then d to e or we can go from a to c then c to d then d to e or we can go from a to d then to e or we can direct go from a to e
    in either case you notice that the cost is same, which is 4. also if we have to go from a to e then we would definitely not go to f since this would make a minimum cost of 6 (a to f then to e). from this we can conclude that we would only travel to those tiles which has letter which lie between [s[0], s[s.length()-1]]
    */

    map<char, vector<int>> m;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= s[0] and s[i] <= s[s.length() - 1]) or (s[i] >= s[s.length() - 1] and s[i] <= s[0]))
        {
            m[s[i]].push_back(i + 1);
            numJumps++;
        }
    }

    // now we would store the number of times the tiles where we have to jump occurs in the string and store its index. notice the 1 based indexing
    // we would do this with help of a map

    // The map::find() is a built-in function in C++ STL that returns an iterator or a constant iterator that refers to the position where the key is present in the map. If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end()

    cout << minCost << " " << numJumps << endl;

    if (s[0] <= s[s.length() - 1])
    {
        for (char i = s[0]; i <= s[s.length() - 1]; i++)
        {
            if (m.find(i) != m.end())
            {
                for (auto x : m[i])
                {
                    cout << x << " ";
                }
            }
        }
    }
    else
    {
        for (char i = s[0]; i >= s[s.length() - 1]; i--)
        {
            if (m.find(i) != m.end())
            {
                for (auto x : m[i])
                {
                    cout << x << " ";
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    IOS;
    l t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}