#include <bits/stdc++.h>
using namespace std ;

class Solution{
private:
    static bool customSort(const pair<int, int>&a, const pair<int, int> &b){
        if(a.second != b.second){
            return a.second > b.second ;
        }
        else{
            return a.first < b.first ;
        }
    }
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k){
        map<string, int> m ;
        for (auto &&i : positive_feedback){
            m[i] = 1 ;
        }
        for(auto &&i: negative_feedback){
            m[i] = -1 ;
        }
        vector<pair<int, int>> res ;
        for(int i=0; i< report.size();i++){
            int score= 0 ; string word ="" ;
            for(auto x: report[i]){
                if(x == ' '){
                    if(m[word] == 1){score += 3 ;}
                    else if(m[word] == -1){score -= 1 ;}

                    word = "" ;
                }
                else{
                    word = word + x ;
                }
            }
            if(m[word] == 1){score += 3 ;}
            else if(m[word] == -1){score -= 1 ;}
            res.push_back(make_pair(student_id[i] , score)) ;
        }

        // now we need to custom sort this thing
        sort(res.begin(), res.end(), customSort) ;

        vector<int> ans ;
        for(int i=0; i< k; i++){
            ans.push_back(res[i].first) ;
        }
        return ans ;
    }
};