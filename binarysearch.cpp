#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int binarySearchrec(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return binarySearchrec(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearchrec(arr, low, mid - 1, target);
    }
}
int lowerBound(vector<int>&arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int higherBound(vector<int>&arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}
int main()
{
    vector<int> arr;
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    int k = lowerBound(arr, n, 56);
    cout << "the lower bound is present at:" << k << "th index";
}