    #include <iostream>
    #include <vector>

    using namespace std;

    void merge(vector<int>& nums, int st, int mid, int end) {
        int i = st, j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= end) {
            temp.push_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= end)
            temp.push_back(nums[j++]);

        for (int k = st; k <= end; ++k)
            nums[k] = temp[k - st];
    }

    void merge_sort(vector<int>& nums, int st, int end) {
        if (st >= end) return;
        int mid = st + (end - st) / 2;
        merge_sort(nums, st, mid);
        merge_sort(nums, mid + 1, end);
        merge(nums, st, mid, end);
    }

    int main() {
        vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
        cout << "Before: ";
        for (int x : nums) cout << x << ' ';
        cout << '\n';

        merge_sort(nums, 0, (int)nums.size() - 1);

        cout << "After:  ";
        for (int x : nums) cout << x << ' ';
        cout << '\n';
        return 0;
    }
