public class rotatedBinarySearch {

    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        rotatedBinarySearch solution = new rotatedBinarySearch();

        int[] nums1 = {2, 5, 6, 0, 0, 1, 2};
        int target1 = 0;
        int target2 = 3;

        System.out.println("Searching for " + target1 + ": " + solution.search(nums1, target1)); // true
        System.out.println("Searching for " + target2 + ": " + solution.search(nums1, target2)); // false

        int[] nums2 = {1, 1, 3, 1};
        int target3 = 3;

        System.out.println("Searching for " + target3 + ": " + solution.search(nums2, target3)); // true
    }
}
