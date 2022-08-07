#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int minIndex=i;
            for(int j=i+1;j<n;j++){
                if(nums[minIndex]>nums[j]){
                    minIndex=j;
                }
            }
            swap(nums[minIndex],nums[i]);
        }
        return nums;
        
    }
};