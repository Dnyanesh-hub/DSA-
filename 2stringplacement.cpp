#include <bits./stdc++.h>
using namespace std;
// reverse the string problem
void reverseString(vector<int> &s)
{
    int st = 0;
    int end = s.size() - 1;
    while (st <= end)
    {
        swap(s[st], s[end]);
        st++;
        end--;
    }
}
// valid palindrome
bool isPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
        {
            i++;
        }
        while (i < j && !isalnum(s[j]))
        {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
// longest odd number in the string
string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 !=
            0) // the ascii value of num[i] && '0' will give the number
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}
// valid anagram
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
    {
        return true;
    }
    else
        return false;
}
// find the longest common prefix string amongst an array of strings.
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        while (strs[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix == "")
            {
                return "";
            }
        }
    }
    return prefix;
}
// 49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mpp;
    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        mpp[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto &it : mpp)
    {
        res.push_back(it.second);
    }
    return res;
}