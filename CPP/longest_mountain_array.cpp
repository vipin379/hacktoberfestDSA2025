#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int func(int peak,vector<int>& arr){
        int i=peak;
        int j=peak;
        int n=arr.size();

        while(i>0 && arr[i-1]<arr[i]){
                i--;
        }
        while(j<n-1 && arr[j+1]<arr[j]){
                j++;
        }
        return j-i+1;
    }
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int count=0; 
        if (n < 3) return 0;
        
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                //here is the peak i.e i
                count=max(count,func(i,arr));
            }
        }
        return (count >= 3) ? count : 0;
    }
};