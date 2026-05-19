#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int, int> mp;
         stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            if (mp.find(num) != mp.end())
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);
        }
        return ans;
        
    }

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

     vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int prev=st.top();
                st.pop();
                ans[prev]=i-prev;
            }
            st.push(i);
        }
        return ans;
    }