#include <bits/stdc++.h>
using namespace std;

/*
🧠 Dutch National Flag Algorithm
--------------------------------
This algorithm is used to sort an array containing only three distinct elements
(typically 0, 1, and 2) in a single traversal — in O(n) time and O(1) space.

💡 Problem Example:
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]

🧩 Idea:
We maintain three pointers:
- low: all elements before 'low' are 0
- mid: current element being checked
- high: all elements after 'high' are 2

Steps:
1. If arr[mid] == 0 → swap(arr[low], arr[mid]), ++low, ++mid
2. If arr[mid] == 1 → just ++mid
3. If arr[mid] == 2 → swap(arr[mid], arr[high]), --high

*/

void dutchNationalFlag(vector<int> &arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    dutchNationalFlag(arr);

    cout << "Sorted Array (Dutch National Flag Order): ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}
