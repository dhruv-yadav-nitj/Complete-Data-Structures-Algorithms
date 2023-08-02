#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *prev, *next ; int key, value ;
    Node (int key, int value) {
        this -> key = key ; this -> value = value ;
        this -> prev = NULL ; this -> next = NULL ;
    }
    void del (Node* node) {
        node -> prev -> next = node -> next ;
        node -> next -> prev = node -> prev ;
        delete(node) ;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp ; int c ; Node* head , *tail ;
    LRUCache(int capacity) {
        // code here
        this -> c = capacity ; this ->head = new Node(-1, -1) ; this -> tail= new Node(-1, -1) ;
        head -> next = tail ; tail -> prev = head ;
    }

    int get(int key) {
        // code here
        if(mp.count(key)) {
            Node* add = mp[key] ;
            add-> prev -> next = add -> next ; add-> next -> prev = add -> prev ;
            add -> next = head -> next ; head -> next -> prev = add ;
            head -> next = add ; add -> prev = head ;
            return add -> value ;
        }
        else{
            return -1 ;
        }
    }

    void put(int key, int value) {
        // code here
        if(mp.count(key)) {
            // if the key exist in the memory already -> just update it as recently used by placing it next to the head
            Node* add = mp[key] ;
            add-> prev -> next = add -> next ; add-> next -> prev = add -> prev ;
            add -> next = head -> next ; head -> next -> prev = add ;
            head -> next = add ; add -> prev = head ;
            add -> value = value ;
        }
        else{
            if(mp.size() < c) {
                Node* add = new Node(key, value) ;
                head -> next -> prev = add ; add ->next = head ->next ;
                head -> next = add ; add -> prev = head ;
                mp[key] = add ;
            }
            else{
                Node* rem = tail -> prev ; // this is why we used doubly linked list (it would give in O(1) time the lru task)
                rem -> prev -> next = rem -> next ; rem -> next ->prev = rem -> prev ;
                mp.erase(rem -> key) ; delete(rem) ;

                Node* add = new Node(key, value) ;
                add -> next = head -> next ; add -> next -> prev = add ;
                add -> prev = head; head -> next = add ;
                mp[key]= add ;
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