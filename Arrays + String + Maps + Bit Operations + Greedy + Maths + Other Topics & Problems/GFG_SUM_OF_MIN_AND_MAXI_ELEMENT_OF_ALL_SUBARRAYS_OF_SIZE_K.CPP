#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Approach 1: Brute Force
// Time Complexity: O(n*k)
// Aux Space: O(1)

pair<int, int> doCheckMinMax(vector<int> v, int start, int end){
    int mini, maxi ; int tempMin(INT_MAX), tempMax(INT_MIN) ;
    for(int i= start ; i <= end ; i++){
        if(v[i] < tempMin){tempMin = v[i] ; mini = i ;}
        if(v[i] > tempMax){tempMax = v[i]; maxi = i ;}
    }
    pair<int, int> temp ;
    temp.first = mini , temp.second = maxi ;
    return temp ;
}

int main()
{
    IOS;
    int n, k ; cin>> n >>  k ;
    vi v(n) , ans ;
    // take the input
    for(int i=0; i< n; i++){
        cin >> v[i] ;
    }

    // this vector is for getting mini and maxi
    pair<int, int> temp ;
    temp = doCheckMinMax(v, 0, k-1) ; // checking for the first windows of size k
    int mini = temp.first , maxi = temp.second ;
    ans.push_back(v[mini] + v[maxi]) ; // ans for the first windows
    cout << "Windows: " << mini << " " << maxi << endl ;
    for(int i=k ; i < n ; i++){
        if(mini < (i-k+1) or maxi < (i-k+1)){
            temp = doCheckMinMax(v, i-k+1 , i) ;
            mini = temp.first ; maxi = temp.second ;
        }
        else{
            if(v[i] < v[mini]){mini = i ;}
            if(v[i] > v[maxi]){maxi = i ;}
        }
        ans.push_back(v[mini] + v[maxi]) ;
    }

    loop(i, 0 , ans.size()){
        cout << ans[i] << " " ;
    }cout << endl;

    return 0;
}