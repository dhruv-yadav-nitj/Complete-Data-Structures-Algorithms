// https://cses.fi/problemset/task/2165
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;
void towerOfHanoi (int n , int from , int to  , int aux, int &count, vector<pair<int, int>>&store){
    // function
    if(n ==0){return  ;} // base condition
    count++ ;
    towerOfHanoi(n -1 , from, aux, to, count, store) ;
    store.push_back({from, to}) ;

    towerOfHanoi(n-1, aux, to, from , count, store) ;

}
int main () {
    int n; cin >> n ; // user input
    vector<pair<int, int>> store ; int count =0 ; towerOfHanoi(n , 1, 3, 2, count, store) ;
    cout << count<< endl ;
    for(auto x : store){
        cout << x.first << " " << x.second << endl ;
    }
}