#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(34);
    s.insert(12);
    s.insert(5);
    s.insert(12);
    s.insert(90);
    s.insert(5);
    s.insert(12);
    s.insert(5);
    s.insert(22);
    s.insert(5);

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for (auto x : s)
    {
        cout << x << endl;
    }

    cout << "Is 5 present ? " << s.count(5) << endl;
    // .count is used to search an element within the set

    set<int>::iterator itr = s.find(5);
    cout << "Value present at itr --> " << *it << endl;

    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}