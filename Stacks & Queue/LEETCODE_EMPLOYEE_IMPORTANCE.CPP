#include <bits/stdc++.h>
using namespace std ;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// this time did this question using maps only......... thats a big achievement doing dfs and bfs question using maps only

// this ques's approach is based on the the approach of this simpler problem --> Keys and Rooms on Leetcode

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id){
        map<int, bool> m, add ; int sum(0) ;
        for(int i=0; i< employees.size() ; i++){
            if(employees[i]-> id == id){
                m[employees[i] -> id] = true ; sum += employees[i]->importance ; add[employees[i]-> id] = true ;
                for(int j=0; j< employees[i]->subordinates.size() ; j++){
                    m[employees[i]-> subordinates[j]] = true ;
                }
            }
        }
        // abhi tk hmne given id waale employee aur uske saare subordinates ko true kr dia hain
        bool check = true ;
        while(check){
            check = false; 
            for(int i=0; i< employees.size() ; i++){
                if(m[employees[i]-> id] and !add[employees[i]-> id]){
                    sum += employees[i]-> importance ; add[employees[i]-> id]= true ;
                    for(int j=0; j< employees[i]-> subordinates.size(); j++){
                        if(m[employees[i]->subordinates[j]] == false){
                            m[employees[i]->subordinates[j]] = true ;
                            check = true ;
                        }
                    }
                }
            }
        }
        return sum ;
    }
};