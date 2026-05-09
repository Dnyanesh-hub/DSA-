 /*# include <iostream>
using namespace std;
int main()
{
    int size=5;
    int marks[size];
    for (int i=0;i<size;i++)
    {
        cin>>marks[i];
    }
    
    for (int i=0;i<size;i++)
    {
        cout<<marks[i]<<endl;
    }

}*/

// smallest in array

/*# include <iostream>
using namespace std;
int main()
{
    int nums[]={5,15,7,-15,4,-24};
    int size=6;
    int k=0;
    int smallest=INT32_MAX;

    for(int i=0;i<size;i++)

    {
        if(nums[i]<smallest)
        smallest=nums[i];
        
        
    }

    for (int j=0;j<size;j++)
    {
        if(smallest==nums[j])
        {
            k=j;
            break;

        }
    }
    cout<<"the smallest value index:"<<k<<endl;
    cout<<smallest;
}*/

// linear search algorithm

/*# include<iostream>
using namespace std;
int linear_search(int arr[],int sz,int target)
{
    for (int i=0;i<sz;i++)
    {
        if(arr[i]==target)
        {
            return 1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={8,9,87,4,6};
    int sz=5;
    int target ;
    cout<<"enter the target:";
    cin>>target;
    cout<<linear_search(arr,sz,target);
    return 0;

}*/

/*# include<iostream>
using namespace std;
void reverse(int arr[],int sz)
{
    int start =0;
    int end=sz-1;
    int k;
    while(start<end)
    {
        k=arr[start];
        arr[start]=arr[end];
        arr[end]=k;
        start ++;
        end--;
    }
    
}
int main()
{
    int arr[]={9,8,6,9,4};
    int sz=5;
    
    reverse(arr,sz);
    for (int i=0;i<sz;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}*/

/*# include <iostream>
using namespace std;
int sum(int arr[],int sz)
{
    int sum=0;
    
    for(int i=0;i<sz;i++)
    {
        sum=sum+arr[i];
        
    }
    return sum;
    
}

int product(int arr[],int sz)
{
    int product=1;
    for (int i=0;i<sz;i++)
{
    product=product*arr[i];
}
return product;
}

int main()
{
    int arr[]={2,3,4};
    int sz=3;
    cout<<"the sum of all the elements in array:"<<sum(arr,sz)<<"\n";
    cout<<"the product of all the elements in array:"<<product(arr,sz);
    return 0;
}*/


//swapping smallest and largest number in array
/*# include<iostream>
using namespace std;

void swapmaxmin(int arr[],int sz)
{
    int maxindex=0;
    int minindex=0;
    for (int i=i;i<sz;i++)
    {
        if(arr[i]>arr[maxindex])
        {
            maxindex=i;
            
        }
        if(arr[i]<arr[minindex])
        {
            minindex=i;
        
        }
    }
    
    
    
    int temp=arr[maxindex];
    arr[maxindex]=arr[minindex];
    arr[minindex]=temp;

}

int main()
{
    int arr[]={2,3,6,1,9,4};
    int sz=6;
    swapmaxmin(arr,sz);
    for (int i=0;i<sz;i++)
    {
        cout<<arr[i];
    }
    return 0;
}*/

//unique elemnts

/*# include<iostream>
using namespace std;
int main()
{
    int ans=0;
    int arr[]={1,4,5,5,1};
    int sz=5;
    for(int val:arr)
    {
        ans=ans^val;
        
    }
    cout<<ans;
    
    return 0;
}*/

/*# include<iostream>
using namespace std;

int singledigit(int arr[],int sz)
{
    for(int i=0;i<sz;i++)
    {
        bool issingle=true;
        for(int j=0;j<sz;j++)
        {
            if(i!=j and arr[i]==arr[j])
            {
                issingle=false;
                //break;
            }
        }
        if(issingle)
        {
            return arr[i];
        }
    }
    return -1;
    
}
int main()
{
    int arr[]={1,4,5,5,1};
    int sz=5;
    cout<<singledigit(arr,sz);
    return 0;
}*/

/*# include<iostream>
#include<vector>
using namespace std;

int linear(vector<int>vec,int sz,int target)
{
    for(int val:vec)
    {
        if(val==target)
        {
            return 1;
            
        }
    
    }
    return -1;

}

int main()
{
    vector<int>vec={1,2,67,89,90,54};
    int target=90;
    int sz=6;
    cout<<linear(vec,sz,target);
    return 0;
}*/

/*# include<iostream>
using namespace std;
int main()
{
    int arr[]={3,-4,5,4,-1,7,-8};
    int n=7;
    int maxsum=INT32_MIN;
    for(int start=0;start<n;start++)
    {
        int currentsum=0;
        for(int end=start;end<n;end++)
        {
            currentsum+=arr[end];
            maxsum=max(currentsum,maxsum);



        }
        
    }
    cout<<"maximum subarray sum is:"<<maxsum;
    return 0;
}*/

//brut force approach for pair sum

/*# include<iostream>
# include<vector>
using namespace std;
vector<int>pairsum(vector<int>num,int target)
{
    vector<int>ans;
    int n=num.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]+num[j]==target)
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }


}

int main()
{
    vector<int>num={2,7,11,15};
    int target=18;
    vector<int>ans=pairsum(num,target);
    cout<<ans[0]<<" ,"<<ans[1]<<endl;
    return 0;

}*/

/*#include<iostream>
#include<vector>
using namespace std;
vector<int>pairsum(vector<int>num,int target)
{
    vector<int>ans;
    int n=num.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int ps=num[i]+num[j];
        if(ps>target)
        {
            j--;
        }
        else if(ps<target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
int main()
{
    vector<int>num={2,7,11,15};
    int target=13;
    vector<int>ans=pairsum(num,target);
    cout<<ans[0]<<" ,"<<ans[1]<<endl;
    return 0;
}*/
// brutt force approach to find majority element
/*# include<iostream>
# include<vector>
using namespace std;
int majority(vector<int>num)
{
    int n=num.size();
    for(int val:num)
    {
        int freq=0;
        for(int el:num)
        {
            if(el==val)
            {
                freq++;

            }
        }
        if(freq>n/2)
        {
            return val;
        }
    }
    return -1;
}

int main()
{
    vector<int>num={1,2,2,2,1};
    cout<<majority(num);
    return 0;
}*/

// container with most water

/*# include<iostream>
#include<vector>
using namespace std;

int maxcapacity(vector<int>height)
{
    int maxwater=0;
    for (int i=0;i<height.size();i++)//left boundary of tank
    {
        for(int j=i+1;j<height.size();j++)
        {//right boundary of tank
        int width=j-1;
        int ht=min(height[i],height[j]);
        int currwater=ht*width;
        maxwater=max(currwater,maxwater);
        }
    }
    return maxwater;
}

int main()
{
    vector<int>height={1,8,6,2,5,4,8,3,7};
    cout<<maxcapacity(height);
    return 0;
}*/
// product of array expect itself

/*# include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[]={1,7,2,9,11};
    int largest=arr[0];
    int n=5;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }

    }
    cout<<largest;
    return 0;
        
    
}*/
// remove duplicates and give array

/*# include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i=0;
    int arr[]={1,1,2,2,2,3,3};
    vector<int>a2={};
    a2.push_back(arr[i]);
    int n=7;
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
            a2.push_back(arr[j]);
        }

        
    }
    cout<<i+1<<endl;
    for(int val:a2)
    {
        cout<<val<<endl;
    }
    
}  */
/*#include<iostream>
using namespace std;
int main()
{ 
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

    
}*/
/*# include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>temp;

    int a[]={1,2,2,3,3,4,5,6};
    int n1=8;
    int b[]={2,3,3,5,6,6,7};
    int n2=7;
    for (int i=0;i<n1;i++)
    {
        for (int j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                temp.push_back(a[i]);
            }
        }
    }
    vector<int>ans;
    int p=sizeof(temp)/sizeof(temp[0]);
    int count =1;


    for(int k=0;k<p;p++ )

    {
        if(temp[k]==count)
        {
            ans.push_back(temp[k]);
        }

    }
    for(int val:ans)
    {
        cout<<val;
    }

}*/

/*#include<iostream>
using namespace std;
int main()
{
    int rev=0;
    int x;
    cout<<"enter the number:";
    cin>>x;
    while(x!=0)
    {
        int ld=x%10;
        rev=(rev*10)+ld;
        x=x/10;

    }
    cout<<"the reversed number is:"<<rev;
    return 0;
    
}*/

#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,7,8,9};
    int n=4;

    
        for(int i=1;i<n;i++ )
        {
            if(arr[i]>=arr[i-1])
            {
                
            }
            else
            {
                cout<<false;
            }
        }
        cout<<true;
        
    
}

