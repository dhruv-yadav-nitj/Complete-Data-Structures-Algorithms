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
    unordered_set<int> s;
    // set is based on Red Black tree and unordered set is based on Hashing.
    // elements are stored in sorted order in a set, but since unordered_set is based on Hash tables, so the elements are stored in any random order
    // like set, unordered_set also does not store duplicate elements
    s.insert(5);
    s.insert(10);
    s.insert(100);
    s.insert(-1);
    s.insert(3);
    s.insert(3);
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    // the above program printed 5 10 100 3 -1 in vs code and printed 3 -1 100 10 5 in onlinegdb
    // begin function returns the iterator to the first element and end function returns iterator beyond the last element and is used to check whether it has reached to the last or not

    // A few function on unordered_set
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    s.clear();
    cout << s.size() << endl;

    s.insert(5);
    s.insert(10);
    s.insert(100);
    s.insert(-1);
    s.insert(3);
    s.insert(3);

    // find function
    if (s.find(10) == s.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << (*s.find(10)) << " Found" << endl;
    } // s.find() also returns an iterator to the element and *s.found(element) means print the element itself

    // count function : an alternative to the find function
    // if the element is present in the s then count function returns 1 and if not present then the count function returns 0
    if (s.count(-2))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    cout << "UNORDERED_SET" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }cout << endl;
    // erase function
    // there are 2 ways to erase the element
    s.erase(10);
    // or use the iterator to delete the element
    auto it = s.find(3);
    s.erase(it);
    cout << "After Deleting 10 and 3" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }cout << endl;
    // we can also use the erase function to delete a range of elements
    // s.erase(starting iterator, ending iterator)
    // starting iterator from which element we want to delete and the ending iterator till which we want to delete
    s.erase(s.begin(), s.find(5));
    // where it will delete from the iterator s.begin() and goes till the -1 iterator s.find(5), means first element is inclusive and last iterator is exclusive
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }

    // Average Time Complexity for insert, erase , find,search , size , empty and count is O(1)

    // Applications of unordered_map
    // However, the worst-case complexity is O(n2).
    // When the input data is big and input values are multiples of this prime number a lot of collisions take place and may cause the complexity of O(n2).
    


    return 0;
}