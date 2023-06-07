#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void solve()
{
    unordered_map<int, int> m ; int n, k ; cin >> n >> k ;
    vi cat(n), time(n); loop(i, 0, n){cin >> cat[i] ;} 
    loop(i, 0, n){
        cin>> time[i] ;
    }
    loop(i, 0, n){
        if(m.find(cat[i]) == m.end()){
            m[cat[i]] = time[i];
        }
        else{
            m[cat[i]] = min(m[cat[i]] , time[i]) ;
        }
    }
    if(m.size() < k){cout << -1 << endl;  return ;}
    
    // now we need to sort the map accoring to values of the keys .. which is possible using custom sort
    vi v ; for (auto &&i : m)
    {
        v.push_back(i.second) ;
    }
    sort(v.begin(), v.end()) ;

    l sum(0) ;
    loop(i, 0, k){
        sum += v[i] ;
    }cout << sum << endl;
}

int main()
{
    IOS;
    l t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    return 0;
}