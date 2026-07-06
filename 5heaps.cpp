#include <bits./stdc++.h>
using namespace std;
// kth largest element in the array
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Can you solve it without sorting?
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums)
    {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}