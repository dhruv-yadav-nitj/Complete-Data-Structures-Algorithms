#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d1;
    d1.push_front(1);
    d1.push_back(2);
    d1.push_back(3);

    cout << "deque d1 --> ";
    for (auto x : d1)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Element at index 1: " << d1.at(1) << endl ;

    d1.pop_back();
    d1.pop_front();
    for (auto x : d1)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Is Empty ? " << d1.empty() << endl ;

    deque <int> d2 ;
    d2.push_back(1) ;
    d2.push_front(0) ;
    d2.push_back(2) ;
    cout << "Before erase : \n" ;
    for (int x: d2)
    {
        cout << x << " " ; 
    }cout << endl ;
    
    d2.erase(d2.begin(), d2.begin()+1) ; // means we have to erase 1 element starting from beginning
    cout << "after erase: \n" ;
    for (int x: d2)
    {
        cout << x << " " ; 
    }cout << endl ;

    return 0;
}