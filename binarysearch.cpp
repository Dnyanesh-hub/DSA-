#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&arr,int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}
int main(){
    vector<int> arr;
    int n, x;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    int k=binarySearch(arr,n-1,21);
    cout<<"the number is present at:"<<k<<"th index";
}