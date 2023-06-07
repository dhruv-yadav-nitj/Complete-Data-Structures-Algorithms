// this file contains :- implementation of stack using STL
#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
    // stacks are some sort of data structure that follows the LIFO (last in first out) or FILO (first in last out). insertion and deletion happend at the same end.
    stack<int> s ;
    s.push(4) ; s.push(3) ; s.push(2) ; s.push(1) ;

    cout << s.top() << endl ;
    while (!s.empty()) // this means jb tk s.empty() false return kr rha hain tb tk
    {
        cout << s.top() << " " ;
        s.pop() ;
    }cout << endl ;

    stack<int> s1 , s2 ;
    s1.push(4);  s1.push(3) ; s1.push(2) ; s1.push(1) ; s2.push(9) ; s2.push(8) ;
    s1.swap(s2) ;

    while (!s1.empty()) // this means jb tk s.empty() false return kr rha hain tb tk
    {
        cout << s1.top() << " " ;
        s1.pop() ;
    }cout << endl ;
    
    while (!s2.empty()) // this means jb tk s.empty() false return kr rha hain tb tk
    {
        cout << s2.top() << " " ;
        s2.pop() ;
    }cout << endl ;
    
    // basically swap fx swaps the elements of two stacks with same or different sizes

    s1.emplace(100) ; 
    while (!s1.empty()) // this means jb tk s.empty() false return kr rha hain tb tk
    {
        cout << s1.top() << " " ;
        s1.pop() ;
    }cout << endl ;

    // emplace function works like push function, but theres only one difference see on net


    return 0;
}
