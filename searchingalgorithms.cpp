/*#include<iostream>
#include<vector>
using namespace std;

int binary(vector<int>nums,int target)
{ 
    int n=nums.size();
    int st=0;
    int end=n-1;
    
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(target>nums[mid])
        {
            st=mid+1;
        }
        else if(target<nums[mid])
        {
            end=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int>nums={-1,0,3,4,5,9,12};
    int target=12;
    cout<<binary(nums,target)<<endl;
    return 0;
}*/

//recursive binary search
# include<iostream>
#include<vector>
using namespace std;
int recbinary(vector<int>arr,int target,int st,int end)
{
    if(st<=end)
    {
        int mid=st+(end-st)/2;
        if(target>arr[mid])
        {
            return recbinary(arr,target,mid+1,end);
        }
        else if(target<arr[mid])
        {
            return recbinary(arr,target,st,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main()
{
    vector<int>arr={-1,0,3,5,9,12};
    int target=12;
    int n=arr.size();
    cout<<recbinary(arr,target,0,n-1);
    return 0;


}
