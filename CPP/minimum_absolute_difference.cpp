#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        int absdiff=INT_MAX;  //maximum integer value
        for(int i=1;i<n;i++){
            absdiff=min(absdiff,abs(arr[i]-arr[i-1]));    //first finding the minimum to set a reference for others
        }
        
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==absdiff){  //checking if the pairs have absolute differnce equal to ref
                ans.push_back({arr[i-1],arr[i]});
            }

        }
        return ans;
    }
};