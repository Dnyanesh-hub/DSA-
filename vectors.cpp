/*# include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec={1,2,3};
    
    vec.push_back(45);
    vec.pop_back();
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;
    cout<<vec.at(2)<<endl;
    for(int value:vec)
    {
        cout<<value<<endl;
    }
    vector<char>vec2(4,'A');
    for (int val:vec2)
    {
        cout<<val<<endl;
    }

    return 0;
}*/

#include<iostream>
using namespace std;
int main()
{
    int arr[]={4,3,1,6};
    int n=4;
    for(int i=0;i<n;i++)
    {
        if((arr[i]%2==0 != arr[i+1]%2!=0) or (arr[i]%2!=0 != arr[i+1]%2==0 ) )
        {
            continue;
        }
        else{
            cout<<"false";
      
      
      }
      cout<<"true";
    }
}
