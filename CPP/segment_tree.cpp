/*
Segment Tree Implementation
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 500005;
int tree[2 * MAXN], a[MAXN], n;
int sum(int v, int tl, int tr, int l, int r) {
//v is the node we start, tl tr is the range represented by v
//l and r shows the range we are finding
    if (l > r)  return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;//tm is the middle of tl and tr, used to find children nodes
    return sum(v*2, tl, tm, l, min(r, tm))//left child node, min of r and tm 
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);//as this part calculates the other half
}
void update(int v, int tl, int tr, int pos, int new_val) {//update new_val at pos
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}
void build(int v , int tl, int tr) {//construct a segment tree
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, 2 * n - 1);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum(1, 0, 2 * n - 1, l, r) << "\n";
        } else {
            int pos, new_val;
            cin >> pos >> new_val;
            update(1, 0, 2 * n - 1, pos, new_val);
        }
    }
    return 0;
}