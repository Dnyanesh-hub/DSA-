#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums)
{

    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

// next smaller element
vector<int> nextSmallerElement(vector<int> &nums)
{

    stack<int> st;
        int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n - 1; i++)
    {
        while (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

vector<int> dailyTemperatures(vector<int> &temperatures)
{

    int n = temperatures.size();
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }
        st.push(i);
    }
    return ans;
}