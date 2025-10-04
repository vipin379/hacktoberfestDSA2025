#include <bits/stdc++.h>
using namespace std;

/*
🧠 Binary Search Algorithm
- Works on sorted arrays.
- Repeatedly divides the search interval in half.
- Time Complexity: O(log n)
*/

int binarySearch(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // prevent overflow

        if (arr[mid] == target)
        //check
            return mid; // target found
        else if (arr[mid] < target)
            low = mid + 1; // search right half
        else
            high = mid - 1; // search left half
    }
    return -1; // target not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;
    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
}
