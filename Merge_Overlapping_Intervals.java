// package _5_arrays.hard;

// merge overlapping subintervals 
// 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Merge_Overlapping_Intervals {

    // extreme brute force 
    // TC -> O((n)log(n)) + O(2n)
    // SC -> O(n)
    // static int[][] mergeIntervals(int[][] intervals) {
    //     int n = intervals.length;
    //     if (intervals.length <= 1) return intervals;
    //     Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        
    //     ArrayList<int[]> list = new ArrayList<>();
    //     for (int i=0; i<n; i++) {
    //         int start = intervals[i][0];
    //         int end = intervals[i][1];
    //         if (!list.isEmpty() && end <= list.get(list.size()-1)[1]) {
    //             continue;
    //         }
    //         for (int j=i+1; j<n; j++) {
    //             if (end >= intervals[j][0]) {
    //                 end = Math.max(end, intervals[j][1]);
    //             }
    //             else break;
    //         }
    //         list.add(new int[]{start,end});
    //     }        
    //     return list.toArray(new int[list.size()][]);
    // }

    // optimal solution 
    // TC -> O((n)log(n)) + O(n)
    // SC -> O(n)
    // static int[][] mergeIntervals(int[][] intervals) {
    //     if (intervals.length <= 1) return intervals;
    //     Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        
    //     ArrayList<int[]> list = new ArrayList<>();
    //     int start = intervals[0][0];
    //     int end = intervals[0][1];
    //     for (int i=1; i<intervals.length; i++) {
    //         if (end >= intervals[i][0]) {
    //             end = Math.max(end,intervals[i][1]);
    //         }
    //         else{
    //             list.add(new int[]{start,end});
    //             start = intervals[i][0];
    //             end = intervals[i][1];
    //         }
    //     }
    //     list.add(new int[]{start,end});
        
    //     return list.toArray(new int[list.size()][]);
    // }



    // optimal solution 
    // TC -> O((n)log(n)) + O(n)
    // SC -> O(n)
    static int[][] mergeIntervals(int[][] intervals) {
        if (intervals.length <= 1) return intervals;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        
        ArrayList<int[]> list = new ArrayList<>();
        for (int i=0; i<intervals.length; i++) {
            if (list.isEmpty() || intervals[i][0] > list.get(list.size() - 1)[1]) {
                list.add(intervals[i]);
            }
            else {
                list.get(list.size()-1)[1] = Math.max(list.get(list.size()-1)[1],intervals[i][1]);
            }
        }        
        return list.toArray(new int[list.size()][]);
    }

    public static void main(String[] args) {
        int[][] intervals = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{16,17},{15,18}};
        int[][] mergeInt = mergeIntervals(intervals);
        for (int i=0; i<mergeInt.length; i++) {
            for (int j=0; j<mergeInt[0].length; j++) {
                System.out.print(mergeInt[i][j] + " ");
            }
            System.out.println();
        }
    }
}
