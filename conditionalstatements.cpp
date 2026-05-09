/*# include <iostream>
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
}*/

/*# include <iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter the number to check:";
    cin>>x;
    if(x>0)
    {
        cout<<"the given number is positive";
    
    }
    else if(x<0)
    {
        cout<<"the given number is negtive";

    }
    else
    {
        cout<<"the given number is zero";

    }
    return 0;

    
}*/

/*#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    if(n>0)
    {
        cout<<"positive ";
        if(n%2==0)
        cout<<"even";
        else
        cout<<"odd";

    }
    else if (n<0)
    {
        cout<<"negative ";

        if(n%2==0)
        cout<<"even ";
        else
        cout<<"odd";
    }
    else if (n==0)
    cout<<"zero";
    else
    cout<<"the number is not valid";
    return 0;

} */       
//SWITCH 
/*# include <iostream>
using namespace std;
int main()
{
    int x=0,y=0;
    cout<<"enter a choice (L R U D):\n";
    char move;
    cin>>move;
    switch(move)
    {
        case 'R':x--;
        break;
        case 'L':x++;
        break;
        case 'U':y--;
        break;
        case 'D':y++;
        break;
        default:cout<<"invalid choice ";

    }
    cout<<x<<" "<<y;
    return 0;
}*/
#include <iostream>
using namespace std;
int main()
{int n,r;

    cout<<"Enter Your Number:";
    cin>>n;


    while(n!=0)
    {
               r=n%10;
               n=n/10;

               cout<<r<<"\n";
    }
    

    
    return 0;
}