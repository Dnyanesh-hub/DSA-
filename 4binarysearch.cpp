#include<bits./stdc++.h>
using namespace std;
// binary search need to return the index where element is present or need to return the elemeent itself if present otherwise return -1
int binarySearch(vector<int>&nums,int tar){
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid]==tar){
            return mid;
            // return nums[mid]

        }
        else if(nums[mid]>tar){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;

}