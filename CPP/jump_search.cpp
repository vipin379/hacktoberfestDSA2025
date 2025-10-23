//description: To implement jump search inc++
//Author: Hansika Arora
//Hacktoberfest-2025

#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;

    while(arr[min(step, n)-1] < target) {
        prev = step;
        step += sqrt(n);
        if(prev >= n) return -1;
    }

    for(int i = prev; i < min(step, n); i++) {
        if(arr[i] == target) return i;
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int index = jumpSearch(arr, n, target);
    if(index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
