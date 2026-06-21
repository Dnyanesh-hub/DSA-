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
int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int cost : costs) {
            if (cost <= coins) {
                coins-=cost;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
