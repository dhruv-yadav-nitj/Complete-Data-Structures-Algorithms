#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        map<int, int> m ; stack<int> s;
        for(int i=0; i< nums2.size(); i++){
            m[nums2[i]]= -1;        
        }
        for(int i=0; i< nums2.size() ; i++){
            if(s.empty()){
                s.push(nums2[i]) ;
            }
            else{
                while(!s.empty() and s.top() < nums2[i]){
                    m[s.top()] = nums2[i] ;
                    s.pop() ;
                }
                s.push(nums2[i]) ;
            }
        }
        vector<int> ans;
        for(int i= 0; i< nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }return ans;
    }
};