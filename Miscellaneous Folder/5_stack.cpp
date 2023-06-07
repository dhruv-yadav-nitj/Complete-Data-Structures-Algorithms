
// hm shaadi mein jaate hain, hm kya krte hain jo plates sbse uppar rkhi hoti hain usko phle uthate hain, hm kbhi aisa nhi krte ki last ki plate utha le to usi concept ko stack khte hain, (LAST IN, FIRST OUT)
#include <bits/stdc++.h>
using namespace std ;

int main()
{
    stack <string> s ;
    // no push back here
    s.push("dhruv") ;
    s.push("yadav") ;
    cout << "top element: " << s.top() << endl ;

    // delete the top element
    s.pop () ;
    cout << "top element: " << s.top() << endl ;

    cout << s.size() << endl ;
    
    return 0;
}