#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class Solution{
public:
    vector<int> getDistinctDifference(int N, vector<int> &A){
        // code here

        vector<int> ans ; unordered_map<int, int> right, left ; unordered_set<int> s ;
        int i = A.size()-1 ;
        while(i >= 0){
            right[i] = s.size() ; s.insert(A[i--]) ;
        }
        s.clear() ; i =0 ;
        while(i < N){
            left[i] = s.size() ; s.insert(A[i++]) ;
        }
        for(int j=0; j < N ; j++){
            ans.push_back(left[j] - right[j]) ;
        }
        return ans ;        
    }
};