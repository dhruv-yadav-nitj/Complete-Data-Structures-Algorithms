#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_front(0);
    l1.push_back(3);
    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    // we have to travel through each element to delete it , we cant go to an element directly and erase it
    l1.erase(l1.begin());
    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    // now we would copy l1 to some other list named l2
    list<int> l2(l1);
    for (auto x : l2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}