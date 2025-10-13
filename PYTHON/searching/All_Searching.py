# =========================================================
# Different Types of Searching Algorithms in Python
# =========================================================
# Each function returns the index of the target element if found,
# otherwise it returns -1.

import math

# ---------------------------------------------------------
# 1. LINEAR SEARCH
# ---------------------------------------------------------
# Works on any list (sorted or unsorted)
# Checks each element one by one
# Time Complexity: O(n)

def linear_search(arr, target):
    print("\nLinear Search:")
    for i in range(len(arr)):
        print(f"  Checking index {i} → {arr[i]}")
        if arr[i] == target:
            return i
    return -1


# ---------------------------------------------------------
# 2. BINARY SEARCH (Iterative)
# ---------------------------------------------------------
# Works only on sorted lists
# Repeatedly divides the search range in half
# Time Complexity: O(log n)

def binary_search_iterative(arr, target):
    print("\nBinary Search (Iterative):")
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        print(f"  Middle index {mid}, value {arr[mid]}")

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            print("  Target is bigger → go right")
            left = mid + 1
        else:
            print("  Target is smaller → go left")
            right = mid - 1

    return -1


# ---------------------------------------------------------
# 3. BINARY SEARCH (Recursive)
# ---------------------------------------------------------
# Same as above but uses recursion

def binary_search_recursive(arr, left, right, target):
    if left <= right:
        mid = (left + right) // 2
        print(f"  [Recursive] Middle index {mid}, value {arr[mid]}")

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return binary_search_recursive(arr, mid + 1, right, target)
        else:
            return binary_search_recursive(arr, left, mid - 1, target)
    return -1


# ---------------------------------------------------------
# 4. JUMP SEARCH
# ---------------------------------------------------------
# Works on sorted lists
# Jumps ahead by √n steps to find the block, then searches linearly
# Time Complexity: O(√n)

def jump_search(arr, target):
    print("\nJump Search:")
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    # Jump ahead until we find the block where the target might be
    while prev < n and arr[min(step, n) - 1] < target:
        print(f"  Jumping from {prev} to {step}")
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    # Linear search inside the identified block
    for i in range(prev, min(step, n)):
        print(f"  Checking index {i}")
        if arr[i] == target:
            return i

    return -1


# ---------------------------------------------------------
# 5. INTERPOLATION SEARCH
# ---------------------------------------------------------
# Works best on uniformly distributed sorted data
# Uses a formula to guess the position of the target
# Time Complexity: O(log log n) on average

def interpolation_search(arr, target):
    print("\nInterpolation Search:")
    low = 0
    high = len(arr) - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1

        # Estimate the position using interpolation formula
        pos = low + ((high - low) * (target - arr[low])) // (arr[high] - arr[low])
        print(f"  Estimated position {pos}, value {arr[pos]}")

        if arr[pos] == target:
            return pos
        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1


# ---------------------------------------------------------
# 6. EXPONENTIAL SEARCH
# ---------------------------------------------------------
# Works on sorted lists
# Quickly finds a range, then applies binary search
# Time Complexity: O(log n)

def exponential_search(arr, target):
    print("\nExponential Search:")

    if arr[0] == target:
        return 0

    n = len(arr)
    i = 1

    # Keep doubling i to find the range
    while i < n and arr[i] <= target:
        print(f"  Expanding range: i = {i}")
        i *= 2

    # Do binary search in the found range
    print(f"  Binary search between {i//2} and {min(i, n-1)}")
    return binary_search_recursive(arr, i // 2, min(i, n - 1), target)


# ---------------------------------------------------------
# Testing All Search Methods
# ---------------------------------------------------------

if __name__ == "__main__":
    arr_unsorted = [10, 25, 3, 7, 18, 12]
    arr_sorted = sorted(arr_unsorted)
    target = 18

    print("=========================================================")
    print("Original Unsorted Array:", arr_unsorted)
    print("Sorted Array:", arr_sorted)
    print("Target Element:", target)
    print("=========================================================")

    # Linear search works on unsorted data
    index = linear_search(arr_unsorted, target)
    print("Result:", index if index != -1 else "Not Found")

    # All other methods work on sorted data
    index = binary_search_iterative(arr_sorted, target)
    print("Result:", index if index != -1 else "Not Found")

    print("\nBinary Search (Recursive):")
    index = binary_search_recursive(arr_sorted, 0, len(arr_sorted) - 1, target)
    print("Result:", index if index != -1 else "Not Found")

    index = jump_search(arr_sorted, target)
    print("Result:", index if index != -1 else "Not Found")

    index = interpolation_search(arr_sorted, target)
    print("Result:", index if index != -1 else "Not Found")

    index = exponential_search(arr_sorted, target)
    print("Result:", index if index != -1 else "Not Found")
