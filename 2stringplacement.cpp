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