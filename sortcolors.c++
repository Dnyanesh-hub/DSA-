// given an array of zeros ones and twos sort the array in place dont use any extra space 
#include <bits/stdc++.h>
using namespace std;
 
void sortColors(vector<int>&arr,int n){
    
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
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
    sortColors(arr,n);
     for(int x : arr) {
        cout << x << " ";
    }

}