#include <bits./stdc++.h>
using namespace std;
// jump game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxIndex)
        {
            return false;
        }
        maxIndex = max(maxIndex, nums[i] + i);
        if (maxIndex >= n - 1)
        {
            return true;
        }
    }
    return true;
}
// Candy
// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int sum = 1;
    int i = 1;
    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        { // constant slope flat surface
            sum += 1;
            i++;
            continue;
        }
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        { // increasing slope
            peak += 1;
            sum += peak;
            i++;
        }
        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1])
        { // decrasing slope
            sum += down;
            down++;
            i++;
        }
        if (down > peak)
        {
            sum += down - peak;
        }
    }
    return sum;
}