// //selection sort
// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

// void selection_sort(int arr[],int n)
// {
//     for(int i=0;i<n-2;i++)
//     {
//         int mini=i;
//         for(int j=i;j<=n-1;j++)
//         {
//             if(arr[j]<arr[mini])
//             {
//                 mini=j;
//             }
//             int temp=arr[mini];
//             arr[mini]=arr[i];
//             arr[i]=temp;

            

            
//         }
//     }
// }

// void bubble_sort(int arr[],int n)
// {
//     for(int i=n-1;i>=0;i--)

//     {
//         int didswap=0;
//         for (int j=0;j<=i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 int temp=arr[j+1];
//                 arr[j+1]=arr[j];
//                 arr[j]=temp;
//                 didswap=1;
//             }
//         }
//         if(didswap==0)
//         {
//             break;
//         }
//     }
// }

// void insertion_sort(int arr[],int n)
// {
//     for(int i=0;i<=n-1;i++)
//     {
//         int j=i;
//         while(j>0 && arr[j-1]>arr[j])

//         {
//             int temp=arr[j-1];
//             arr[j-1]=arr[j];
//             arr[j]=temp;
//             j--;

//         }

        
//     }
// }



// int main()
// {
//     int n;
//     cout<<"enter the length of array:";
//     cin>>n;
//     int arr[n]={};
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     insertion_sort(arr,n);
//     cout<<"sorted array:"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
        
//     }
//     return 0;


// }


// selection sort 
// main thing or main logic in selection sort is as the name suggest that select minimum and swap it with first index in first setp and in next steps
// subsequently do the same swap i+1 index to mini index in the array 
void selectionsort(vector<int>&arr,int n){

    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}
// bubble sort 
// the main core logic in bubble sort is to push the maximum number from the array to the last by using adjacent swapping 
// in first pass by comparing adjacent numbers we are sending the lasrgest number to the last simillarly in next pass we are swapping the second lasgest number to the second last position
// simultaneously we are iterating from 0 to n-1 in first past 0 to n-2 0 to n-3 like thiss upto 0 to 1 cuz we do not care about the single elemnt 
#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>& arr, int n) {

    for(int i = n - 1; i >= 1; i--) {
        int didswap=0;


        for(int j = 0; j <= i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap=1;
            }
        }
        if(didswap=0){
            break;    
        }   
            }        // in best case scenario if all the array is sorted why to to look for all just check for first step 0 to n-1        
}
// insertion sort it takes element and it puts it at correct position 
// so basically it checks that the element by comparison to the elemnt who is at left it will check with it and compare if left element is is greater than the right element  then swap happens 
void insertionsort(vector<int>&arr,int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);        // why not till j>=0 cuz when u took j==0 arr[j-1]=arr[-1] so it becomes negative to avoid this 
            j--;
        }
    }
}

// merge sort sorting algorthim which works on the concept of divide and conquer 
// basically it divides array hypothetically in based on index it divides divides till array will be having single element 
// as array reach the single elemnt after dividng each in the end it will compare to the elemnts and will merge in sorted order 
// first we will write a merge sort function 
// // now next step is to write the merge function 

void merge(vector<int>&arr,int low,int mid ,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;

    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>&arr,int low,int high){
    if(low==high){
        return ;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

// quick sort -it is also a divide conquer here we are havig 3 main steps
// 1.find the piovot piovot can be anything first element last elemnt median elemnt any random element 
// 2.place the pivot at its correct position 
//3.after placing it at correct position swap elemnts 
// so first we will write the quick sort fucntion and then we will write function to find out the partion index 
// what is the partion index the point where the elemnts at left are smaller and elemnts are right are larger than the piovot
// how to find piovot then we need to take 4 pointer low high and i j at any point of time if j crosses i that will be th epartion index
int partionf(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }
} 
void quicksort(vector<int>&arr,int low ,int high){
    if(low<high){
        int partionind=partionf(arr,low,high);
        quicksort(arr,low,partionind-1);
        quicksort(arr,partionind+1,high);
    }
}



int main() {

    vector<int> arr;
    int n, x;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    quicksort(arr,0,n-1);

    for(int x : arr) {
        cout << x << " ";
    }
}