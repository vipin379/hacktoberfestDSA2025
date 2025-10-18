#include <stdio.h>

// Function to rotate array to the right by k positions
void rotateArray(int arr[], int n, int k) {
    k = k % n; // In case k > n
    int temp[k];
    
    // Store last k elements in temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy temp elements to the beginning
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Rotate by 3 positions

    printf("Original array: ");
    printArray(arr, n);

    rotateArray(arr, n, k);

    printf("Array after rotating by %d positions: ", k);
    printArray(arr, n);

    return 0;
}
