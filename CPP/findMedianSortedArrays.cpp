class Solution {
public:
    // array a -> n1, array b -> n2
    // so we have to know the left half after merging them
    // we just need to find the division
    // lets say n1 = 4, n2 = 6
    // so left half will contain 5 elements
    // for that we can take 0 eles from a and 5 from b
    //                      1      from a     4 from b and so on
    // so we need to find the correct division
    //     a1 a2 | a3 a4
    //  b1 b2 b3 | b4 b5 b6
    // for division to be apt since a2 is already < a3 and same for b3 and b4
    // a2 should be < b4 and (b3 < a3) for the division to be apt
    // if a2 > b4 that means we need lesser from a -> hi = mid - 1
    // if b3 > a3 that means we need more of a -> lo = mid + 1
    // after finding correct division
    // if the number of eles is odd then we will return the last element of the left half (bigger half hence will have median)
    // if the number of eles is even then formula (max(l1, l2) + min(r1, r2)) / 2
    // average of last of first half and first of second half
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1); // we want nums1 to be smaller array
        int lo = 0, hi = n1;
        int left = (n1 + n2 + 1) / 2, n = n1 + n2;
        int mid1, mid2;
        while(lo <= hi){
            mid1 = (lo + hi) / 2;
            mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN; // as they might not exist
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            // if the current division is appropriate
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1) return max(l1, l2);
                else return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if(l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0.0;
    }
};
