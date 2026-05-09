#include<iostream>
using namespace std;
int main()
{
    int a=15;
    int*ptr=&a;
    cout<<ptr<<endl;
    ptr=ptr+2;
    cout<<ptr<<endl;


    return 0;


}