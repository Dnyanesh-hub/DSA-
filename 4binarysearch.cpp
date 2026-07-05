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