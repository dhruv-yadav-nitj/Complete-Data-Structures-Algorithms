
// 2-pointers approach

/* #include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

void reverse(vi v, int s, int e)
{
    if (s>e)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " " ;
        }
        return ;
    }
    swap(v[s], v[e]) ;
    reverse(v, s+1, e-1) ;
}

int main()
{
    vi v = {1, 2, 3, 4, 5} ;
    reverse (v, 0, v.size()-1) ;

    return 0;
}
 */

// instaed of taking s and e we can also take s and n-s-1 
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

void reverse (vi v,int i)
{
    if (i >= v.size()/2)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " " ;
        }
        return ;
    }
    swap (v[i], v[v.size()-i-1]) ;
    reverse(v, i+1) ;
}

int main()
{
    vi v = {1, 2, 3, 4} ;
    reverse (v, 0) ;

    return 0;
}