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

// remove duplicates in place and give the number of unique elemnts from the array if the array will be having k elements
// first k elements should be unique elemnts then after that k+1 element index does not matter
int removeDuplicates(vector<int> &nums, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
    // the array is already sorted all the duplicate elements will be infront of each other if we are having same
    // elements in front of each other like nums[i]==nums[j] just ignore it no need to do anything if
    // nums[i]!=nums[j]  we are incresing i++ and swapping or assigning value of j to i the index
    // Since the array is sorted, duplicates are adjacent. I keep one pointer at the last unique element and move another pointer to find new values. Whenever I find a new value, I place it after the unique section
}
// rotate array to the left by one place arr=[3,8,7,6] ==> after rotation it would be arr=[8,7,6,3]==>brute force approach
// is to create a temporary array put all the elemnt in that array by one place left shifiting one place left and in the end of temp array put the 0th index element of the array and return the array
// now optimal approach inplace left shifting by one place we will store the 1st index i mean 0th index element to store in some variabl
// after storing that variable we will left shift each element by one and in the end we will put that elemnt last of the array
void rotateLeftByOne(vector<int> &nums, int n)
{
    int temp = nums[0];
    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = temp;
}
// void rotate element to right by one
void rotateRightByOne(vector<int> &nums, int n)
{
    int temp = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        nums[i + 1] = nums[i];
    }
    nums[0] = temp;
}
// rotate array to the right by k places using reversal algortihm
void rotateToRightByK(vector<int> &nums, int k)
{
    // reverse first n-k elements from 0 to n-k+1
    int n = nums.size();
    // if the value of k is greater than n then we need to modulize it cuz after particular times of rotation it is gonna be same like if n=3 and k=6
    k = k % n;
    // reverse(nums.begin(),nums.end());
    // reverse(nums.begin(),nums.begin()+k);
    // reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(), nums.begin() + (n - k));
    reverse(nums.begin() + (n - k), nums.end());
    reverse(nums.begin(), nums.end());
}
// void rotate elemnt to the left by k places using reversal algorithm
void rotateToLeftByK(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}
// linear search
int linearSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return nums[i];
            // return i;
        }
    }
}
// move zeros using two pointers optimal one pass approach
void moveZeros(vector<int> &nums, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    
}