#include <bits/stdc++.h>
using namespace std;

/*
Quickselect: find k-th smallest (0-indexed).
- Partition like quicksort; recurse into side containing k.
Avg Time: O(n) | Worst: O(n^2) | Space: O(1)
*/

int partitionL(vector<int>& a, int l, int r) {
    int pivot = a[r], i = l;
    for (int j = l; j < r; ++j) if (a[j] <= pivot) swap(a[i++], a[j]);
    swap(a[i], a[r]);
    return i;
}

int quickselect(vector<int>& a, int l, int r, int k) {
    while (true) {
        int p = partitionL(a, l, r);
        if (p == k) return a[p];
        if (k < p) r = p - 1; else l = p + 1;
    }
}

int main() {
    vector<int> a = {7, 10, 4, 3, 20, 15};
    int k = 2; // 0-indexed -> 3rd smallest
    cout << quickselect(a, 0, (int)a.size() - 1, k);
}
