
/*# include<iostream>
using namespace std;
int main()
{
    int revnum=0;
    int n;
    cin>>n;
    if(n<0)
    {
        cout<<"palindrome does not exist";
    }
    int y=n;
    while(y>0)
    {
        revnum=revnum*10+y%10;
        y/=10;

    }
    cout<<revnum<<endl;
    if(revnum==n)
    {
        cout<<"is palindrome";
    }
    else{
        cout<<"not palindrome"
;    }
return 0;
    

    

}*/

/*#include<iostream>
# include<vector>
using namespace std;
int main()
{
    vector<int>num={0,10,5,2};
    int i=0;
    while(num[i]<num[i+1])
    {
        i++;
    }
    cout<<i;
    return 0;
}*/

#include<iostream>
#include<vector>
using namespace std;
int main()//brute force approach tc=O(n);
{
    vector<int>arr={1,1,2,3,3,4,4,8,8};
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1])
        {
            cout<<arr[i];
        }

    }
    return 0;
}




