#include <bits/stdc++.h>
using namespace std;

/*
Segment Tree for range sum.
- Build O(n), Query/Update O(log n)
*/

struct SegTree {
    int n; vector<long long> st;
    SegTree(const vector<int>& a){
        n = a.size(); st.assign(4*n,0);
        build(a,1,0,n-1);
    }
    void build(const vector<int>& a,int p,int l,int r){
        if(l==r){ st[p]=a[l]; return; }
        int m=(l+r)/2;
        build(a,p*2,l,m); build(a,p*2+1,m+1,r);
        st[p]=st[p*2]+st[p*2+1];
    }
    long long query(int p,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return 0;
        if(ql<=l && r<=qr) return st[p];
        int m=(l+r)/2;
        return query(p*2,l,m,ql,qr)+query(p*2+1,m+1,r,ql,qr);
    }
    void update(int p,int l,int r,int idx,int val){
        if(l==r){ st[p]=val; return; }
        int m=(l+r)/2;
        if(idx<=m) update(p*2,l,m,idx,val);
        else update(p*2+1,m+1,r,idx,val);
        st[p]=st[p*2]+st[p*2+1];
    }
};

int main(){
    vector<int> a={1,3,5,7,9,11};
    SegTree st(a);
    cout<<st.query(1,0,a.size()-1,1,3)<<"\n"; // 3+5+7=15
    st.update(1,0,a.size()-1,2,6);           // a[2]=6
    cout<<st.query(1,0,a.size()-1,1,3)<<"\n"; // 3+6+7=16
}
