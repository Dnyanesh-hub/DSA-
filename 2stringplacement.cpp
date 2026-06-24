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