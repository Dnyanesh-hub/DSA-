// You are given an array of strings words, where each string represents a word containing lowercase English letters.

// You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

// The weight of a word is defined as the sum of the weights of its characters.

// For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

// Return a string formed by concatenating the mapped characters for all words in order.
#include <bits/stdc++.h>
using namespace std;
string mapWordWeights(vector<string> &words, vector<int> &weights)
{
    string ans = "";

    for (string &word : words)
    {

        int sum = 0;

        for (char ch : word)
        {
            sum += weights[ch - 'a'];
        }

        int x = sum % 26;

        char c = 'a' + (25 - x);

        ans.push_back(c);
    }

    return ans;
}
// 2130. Maximum Twin Sum of a Linked List
// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int pairSum(ListNode *head)
{

    stack<int> st;

    ListNode *slow = head;
    ListNode *fast = head;

    // Step 1: find middle
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: push second half into stack
    ListNode *temp = slow;
    while (temp != NULL)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    // Step 3: compare first half with reversed second half
    int ans = 0;
    temp = head;

    while (!st.empty())
    {
        ans = max(ans, temp->val + st.top());
        st.pop();
        temp = temp->next;
    }

    return ans;
}
// 2095. Delete the Middle Node of a Linked List
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// using slow and fast pointer and prev pointer slow pointer will be having middle node and prev pointer will having node pointing to prev of middle and then we are pointing prev next to slow next and then deleting slow
ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}
// 3612. Process String with Special Operations I
// You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

// Build a new string result by processing s according to the following rules from left to right:

// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the final string result after processing all characters in s.
string processStr(string s)
{
    string result;
    for (char ch : s)
    {
        if (islower(ch))
        {
            result = result + ch;
        }
        else if (ch == '*')
        {
            if (!result.empty())
            {
                result.pop_back();
            }
        }
        else if (ch == '#')
        {
            result += result;
        }
        else if (ch == '%')
        {
            reverse(result.begin(), result.end());
        }
    }
    return result;
}
// 1732. Find the Highest Altitude
// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
int largestAltitude(vector<int> &gain)
{
    int highest = 0;
    int n = gain.size();
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        prev += gain[i];
        highest = max(highest, prev);
    }
    return highest;
}
// Maximum Ice Cream Bars
// It is a sweltering summer day, and a boy wants to buy some ice cream bars.

// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.

// Note: The boy can buy the ice cream bars in any order.

// Return the maximum number of ice cream bars the boy can buy with coins coins.

// You must solve the problem by counting sort
int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int count = 0;
    for (int cost : costs)
    {
        if (cost <= coins)
        {
            coins -= cost;
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}
// Maximum Number of Balloons
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.
int maxNumberOfBalloons(string text)
{
    vector<int> freq(26, 0);
    for (char c : text)
    {
        freq[c - 'a']++;
    }
    int b = freq['b' - 'a'];
    int a = freq['a' - 'a'];
    int l = freq['l' - 'a'] / 2;
    int o = freq['o' - 'a'] / 2;
    int n = freq['n' - 'a'];
    return min({b, a, l, o, n});
}
// 3737. Count Subarrays With Majority Element I
// You are given an integer array nums and an integer target.
// Return the number of subarrays of nums in which target is the majority element.
// The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

int countMajoritySubarrays(vector<int> &nums, int target)
{
    int n = nums.size();
    int count = 0;
    vector<int> vec = nums;
    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        for (int j = i; j < n; j++)
        {
            if (vec[j] == target)
            {
                freq++;
            }
            int len = j - i + 1;
            if (freq > (len / 2))
            {
                count++;
            }
        }
    }
    return count;
}
// 1967.Number of substrings that appear as a substring in a word
// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
// A substring is a contiguous sequence of characters within a string.

int numOfStrings(vector<string> &patterns, string word)
{
    int count = 0;
    for (string &pat : patterns)
    {
        if (word.find(pat) != string::npos)
        {
            count++;
        }
    }
    return count;
}
// 1358.number of substring containg all three characters
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c
int numberOfSubstrings(string s)
{
    int n = s.size();

    int left = 0;
    int ans = 0;

    vector<int> count(3, 0);

    for (int right = 0; right < n; right++)
    {

        count[s[right] - 'a']++;

        while (count[0] > 0 && count[1] > 0 && count[2] > 0)
        {

            ans += n - right;

            count[s[left] - 'a']--;

            left++;
        }
    }

    return ans;
}
// 3286.find safe path  walk through the grid
bool findSafeWalk(vector<vector<int>> &grid, int health)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> best(m, vector<int>(n, -1));

    queue<pair<pair<int, int>, int>> q;

    int startHealth = health - grid[0][0];

    if (startHealth <= 0)
        return false;

    q.push({{0, 0}, startHealth});
    best[0][0] = startHealth;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty())
    {

        auto current = q.front();
        q.pop();

        int row = current.first.first;
        int col = current.first.second;
        int currHealth = current.second;

        if (row == m - 1 && col == n - 1)
            return true;

        for (int k = 0; k < 4; k++)
        {

            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            int newHealth = currHealth - grid[nr][nc];

            if (newHealth <= 0)
                continue;

            if (newHealth > best[nr][nc])
            {
                best[nr][nc] = newHealth;
                q.push({{nr, nc}, newHealth});
            }
        }
    }

    return false;
}