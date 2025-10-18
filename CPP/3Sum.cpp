#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;   //to store ans
        int n=nums.size();
        sort(nums.begin(),nums.end());  //sorting the input array to avoid sorting st last
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){ continue;} // this condition avoids the case when the duplicate arrives in i iteration
            int j=i+1;
            int k=n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int> nw={nums[i],nums[j],nums[k]};
                    ans.push_back(nw);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){ j++;}     // this condition avoids the case when the duplicate arrives in j iteration
                    while(j<k && nums[k]==nums[k+1]){ k--;}     // this condition avoids the case when the duplicate arrives in k iteration
                }
            }
        }
        return ans;
    }
};