#include <bits./stdc++.h>
using namespace std;
// to find the laregest element in the given array
int largestelement(vector<int> &nums, int n)
{
    int large = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > large)
        {
            large = nums[i];
        }
    }
    return large;
}
// find the second largest element in the array if the array is having duplicate elemnts one pass solution 
int secondLargest(vector<int> &nums, int n)
{
    int large = INT_MIN;
    int slarge = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > large)
        {
            slarge = large;
            large = nums[i];
        }
        else if (nums[i] > slarge && nums[i] < large)
        {
            slarge = nums[i];
        }
    }
    return slarge;
}