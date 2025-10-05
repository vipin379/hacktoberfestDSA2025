#include <bits/stdc++.h>
using namespace std;

/*
LRU Cache using list + unordered_map
- Most recently used at front; least at back.
get/put: O(1) average
*/

class LRUCache {
    int cap;
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> pos;
public:
    LRUCache(int capacity): cap(capacity) {}
    int get(int key){
        if(!pos.count(key)) return -1;
        auto it = pos[key];
        dll.splice(dll.begin(), dll, it); // move to front
        return it->second;
    }
    void put(int key,int value){
        if(pos.count(key)){
            auto it=pos[key];
            it->second=value;
            dll.splice(dll.begin(), dll, it);
        }else{
            if((int)dll.size()==cap){
                auto [k,_]=dll.back(); dll.pop_back(); pos.erase(k);
            }
            dll.emplace_front(key,value); pos[key]=dll.begin();
        }
    }
};

int main(){
    LRUCache c(2);
    c.put(1,1); c.put(2,2);
    cout<<c.get(1)<<"\n"; // 1
    c.put(3,3);           // evicts key 2
    cout<<c.get(2)<<"\n"; // -1
}
