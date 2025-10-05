#include <bits/stdc++.h>
using namespace std;

/*
Fenwick Tree (1-indexed)
- point update, prefix sum query
Time per op: O(log n)
*/

struct Fenwick {
    int n; vector<long long> bit;
    Fenwick(int n): n(n), bit(n+1,0) {}
    void add(int idx, long long val){
        for(; idx<=n; idx += idx&-idx) bit[idx]+=val;
    }
    long long sum(int idx){
        long long s=0;
        for(; idx>0; idx -= idx&-idx) s+=bit[idx];
        return s;
    }
    long long rangeSum(int l,int r){ return sum(r)-sum(l-1); }
};

int main(){
    Fenwick ft(5);
    ft.add(1,5); ft.add(3,2); ft.add(5,7);
    cout<<ft.rangeSum(1,3)<<"\n"; // 7
}
