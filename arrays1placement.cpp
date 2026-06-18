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
    if (slarge == INT_MIN)
    {
        return -1;
        // array just only have the largest elemnt only throught out the length [21,21,21,21]
    }
    return slarge;
}
// check weather the array is sorted or not
bool checkIsSorted(vector<int> &nums, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            return false;
        }
    }
    return true;
}
// check weather the array is sorted and rotated
bool isSortRotateCheck(vector<int> &nums, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }
    if (count > 1)
    {
        return false;
    }
    return true;
    // if the array is sorted and rotated there will be one single
    // rotating or breaking point we need to find that if there will
    // be more than one breaking point then array will not rotated
    // and sorted sorted array has the property that the next (every
    // element>previous elemnt) after rotation there will be two
    // sorted halfs at the breaking point laregst element comes
    // first before smallest elemnt and if there are more than two
    // breaking points then array is not sorted and rotated
}
