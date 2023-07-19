#include <bits/stdc++.h>
using namespace std;

// approach #1 : using hashtable only
// though it would be giving TLE bcz we are not having O(1) time in put function

class LRUCache {
public:
    unordered_map<int, int> mp ,st ; int timer =1 ;
    int c=0 ;
    LRUCache(int capacity) {
        // code here
        this -> c= capacity ;
    }

    int get(int key) {
        // code here
        if(st.count(key)) {
            mp[key] = timer++ ;
            return st[key] ;
        }
        else{
            return -1 ;
        }
    }

    void put(int key, int value) {
        // code here
        if(st.count(key)) {
            st[key]= value ;
            mp[key] = timer++ ;
        }
        else{
            if(st.size() < c) {
                st[key]= value; mp[key]= timer++ ;
            }
            else{
                int k , val = INT_MAX ;
                for(auto it : mp) {
                    if(it.second < val) {
                        k= it.first; val= it.second ;
                    }
                }
                mp.erase(k) ; st.erase(k) ;
                mp[key]= timer++ ; st[key] = value ;
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */