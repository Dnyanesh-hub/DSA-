# include <iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter the number:";
    cin>>x;
    if(x%2==0)
    {
        cout<<"the given number"<<x<<" is even";
    }
    else
    {
        cout<<"the given number"<<x<<" is odd";
    }
    return 0;
}