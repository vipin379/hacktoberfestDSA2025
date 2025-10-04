# Search in Rotated Sorted Array II (with Duplicates)

This Java program implements a **modified binary search algorithm** to find a target value in a **rotated sorted array** that may contain **duplicate elements**.

---

## Problem Description

You are given an integer array `nums` which was originally sorted in ascending order, but then **rotated** at some pivot index `k` (e.g., `[0,1,2,4,5,6,7]` becomes `[4,5,6,7,0,1,2]`).

The array may also contain **duplicate elements**.

Your task is to determine whether the given `target` exists in `nums`.  
Return `true` if `target` is found, otherwise return `false`.

---

## Example

**Input:**
```java
nums = [2,5,6,0,0,1,2]
target = 0
