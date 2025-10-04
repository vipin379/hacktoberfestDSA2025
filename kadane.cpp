#include <bits/stdc++.h>
using namespace std;

/*
🧠 Kadane’s Algorithm
- Finds the maximum sum subarray in linear time.
- Idea: Track current sum and reset if it becomes negative.
- Time Complexity: O(n)
*/

int maxSubarraySum(vector<int> &arr) {
    int maxSum = INT_MIN, currSum = 0;

    for (int num : arr) {
        currSum += num;
        maxSum = max(maxSum, currSum);

        // if sum becomes negative, reset it
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr);
}
