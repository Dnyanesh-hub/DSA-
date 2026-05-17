#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {     // find out minimum in sorted rotated array 
    // array does not contain any duplicate elements
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                ans=min(nums[low],ans);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }

        }
        return ans;
    }

// find min in rotated sorted array that contains duplicates 
int findMin2(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1; 
            }
            else if(nums[mid]<nums[high]){
                high=mid;
            }
            else{
                high--;
            }

        }
        return nums[low];
        
    }
        