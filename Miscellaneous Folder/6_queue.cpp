
// opposite of stack, GO FIRST , GET FIRST applies here,
// queue assume as a line, FIRST IN , FIRST OUT

#include <bits/stdc++.h>
using namespace std ;

int main()
{
    queue <string> q ;
    q.push("dhruv") ;
    q.push("yadav") ;

    cout << "First Element: " << q.front() << endl ; 
    q.pop() ;
    cout << "First Element: " << q.front() << endl ; 
    
    cout << q.size() << endl ;

    return 0;
}