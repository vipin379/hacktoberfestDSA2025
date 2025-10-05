//Square of sorted array in O(n) time complexity
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        int left = 0, right = n - 1; //two-pointer approach
        int pos = n - 1;
      
        //The logic
      
        while (left <= right) {
            int leftSq = arr[left] * arr[left];
            int rightSq = arr[right] * arr[right];

            if (leftSq > rightSq) {
                result[pos--] = leftSq;
                left++;
            } else {
                result[pos--] = rightSq;
                right--;
            }
        }
        return result;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
  //take input array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    vector<int> ans = ob.sortedSquares(arr);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
