#include <bits./stdc++.h>
using namespace std;
// binary search need to return the index where element is present or need to return the elemeent itself if present otherwise return -1
int binarySearch(vector<int> &nums, int tar)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (nums[mid] == tar)
        {
            return mid;
            // return nums[mid]
        }
        else if (nums[mid] > tar)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
// lower bound
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0;      // Start of search range
    int high = n - 1; // End of search range
    int ans = n;      // Default to n (not found)

    // Binary search loop
    while (low <= high)
    {
        int mid = (low + high) / 2; // Middle index

        if (arr[mid] >= x)
        {
            ans = mid;      // Store possible answer
            high = mid - 1; // Try to find smaller index on left side
        }
        else
        {
            low = mid + 1; // Move right if current element is less than x
        }
    }
    return ans; // Return the index of the lower bound
}
// upper bound
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n; // Default answer if x is >= all elements

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;      // Potential answer found
            high = mid - 1; // Try to find smaller valid index on the left
        }
        else
        {
            low = mid + 1; // Move right if mid is <= x
        }
    }
    return ans; // Index of the first element > x
}
// find first and last occurance
int first(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int last(vector<int> &nums, int target)
{
    int n = nums.size();
    int last = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int fto = first(nums, target);
    if (fto == -1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int lto = last(nums, target);
    ans.push_back(fto);
    ans.push_back(lto);
    return ans;
}
// search in rotated sorted array
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // we need to identify which half of the array will be sorted as in
        // binary search we eliminate the search space so for that purpose
        // we need to find the sorted half first
        // after identifying which half is soretd then will check weather
        // that elemet lies in that range or not
        if (nums[low] <=
            nums[mid])
        { // this will telll that the left half is sorted if
          // this condtion gets satisfy
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}