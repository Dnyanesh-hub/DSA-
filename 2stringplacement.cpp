#include <bits./stdc++.h>
using namespace std;
void reverseString(vector<int>&s){
    int st=0;
    int end=s.size()-1;
    while (st<=end)
    {
        swap(s[st],s[end]);
        st++;
        end--;
    }
    
}