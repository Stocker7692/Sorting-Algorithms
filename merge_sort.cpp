#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>&nums,int s,int e){
        int mid = (s+e)/2;
        
        int len1 = mid-s+1;
        int len2 = e-mid;
        
        int *v1 = new int[len1];
        int *v2 = new int[len2];
        
        int mainArrayIndex=s;
        for(int i=0;i<len1;i++){
            v1[i]=nums[mainArrayIndex++];
        }
        
        mainArrayIndex = mid+1;
        for(int i=0;i<len2;i++){
            v2[i]=nums[mainArrayIndex++];
        }
        
        int index1=0;
        int index2=0;
        mainArrayIndex=s;
        while(index1<len1 && index2<len2){
            if(v1[index1]<v2[index2]){
                nums[mainArrayIndex++]=v1[index1++];
            }
            else{
                nums[mainArrayIndex++]=v2[index2++];
            }
        }
        
        while(index1<len1) nums[mainArrayIndex++]=v1[index1++];
        while(index2<len2) nums[mainArrayIndex++]=v2[index2++];
        
        
        
        
    }
    void mergeSort(vector<int>&nums,int s,int e){
        if(s>=e) return;
        int mid = (s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
        
    }
};