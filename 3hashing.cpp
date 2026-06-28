#include <bits./stdc++.h>
using namespace std;
// two sum 
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int more=target-a;
            if(mp.find(more)!=mp.end()){
                return {mp[more],i};
            }
            mp[a]=i;
        }
        return {};

        
    }