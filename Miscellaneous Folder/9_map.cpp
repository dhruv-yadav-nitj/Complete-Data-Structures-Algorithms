#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "national";
    m[13] = "jalandhar";
    m[2] = "institute of";

    m.insert({5, "technology"});

    cout << "Before Erase --> \n";
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << "Is 13 present ? " << m.count(13) << endl;

    m.erase(13);
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    auto it = m.find(5);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    return 0;
}