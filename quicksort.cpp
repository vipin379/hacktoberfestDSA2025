#include <bits/stdc++.h>
using namespace std;

/*
Quick Sort (Lomuto partition)
- Pick last element as pivot; partition so <= pivot on left.
- Recurse on subarrays.
Time: Avg O(n log n), Worst O(n^2) | Space: O(log n) stack
*/

int partitionL(vector<int>& a, int l, int r) {
    int pivot = a[r], i = l;
    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) swap(a[i++], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partitionL(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main() {
    vector<int> a = {9, 3, 7, 1, 4, 8, 2};
    quickSort(a, 0, (int)a.size() - 1);
    for (int x : a) cout << x << " ";
}
