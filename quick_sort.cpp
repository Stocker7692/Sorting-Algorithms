#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int partition(vector<int>&nums,int s,int e){
        
        int pivot = nums[s];
        
        int cnt =0;
        for(int i=s+1;i<=e;i++){
            if(nums[i]<=pivot) cnt++;
        }
        
        int pivotIndex = s+cnt;
        int i=s,j=e;
        swap(nums[s],nums[pivotIndex]);
        while(i<pivotIndex && j>pivotIndex){
            while(nums[i]<=pivot) i++;
            while(nums[j]>pivot) j--;
            
            if(i<pivotIndex && j>pivotIndex){
                swap(nums[i++],nums[j--]);
            }
        }
        return pivotIndex;
    }
    void quickSort(vector<int>&nums,int s,int e){
        if(s>=e) return ;
        
        int p = partition(nums,s,e);
        
        quickSort(nums,s,p-1);
        quickSort(nums,p+1,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
        
    }
};