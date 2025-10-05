#include <bits/stdc++.h>
using namespace std;

/*
DSU with path compression + union by rank.
- Efficiently tracks components; supports union/find.
Amortized inverse Ackermann ~ constant per op.
*/

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main() {
    DSU d(5);
    d.unite(0,1); d.unite(3,4);
    cout << (d.find(1)==d.find(0)) << " " << (d.find(2)==d.find(3));
}
