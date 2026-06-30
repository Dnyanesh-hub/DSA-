#include <bits./stdc++.h>
using namespace std;
// two sum
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int more = target - a;
        if (mp.find(more) != mp.end())
        {
            return {mp[more], i};
        }
        mp[a] = i;
    }
    return {};
}
// three sum
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        int low = i + 1;
        int high = n - 1;
        int target = -nums[i];
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum == target)
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1])
                {
                    low++;
                }
                while (low < high && nums[high] == nums[high - 1])
                {
                    high--;
                }
                low++;
                high--;
            }
            else if (sum < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    return ans;
}
// three sum closest
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int closet = nums[0] + nums[1] + nums[2];
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (abs(sum - target) < abs(closet - target))
            {
                closet = sum;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return closet;
}