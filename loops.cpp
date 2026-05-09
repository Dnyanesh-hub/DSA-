//table of number or multiple of numbers using while loop
/*# include <iostream>


using namespace std;
int main()
{
    int i;
    cin>>i;
    int n;
    cin>>n; 

    while(i<11)
    {
        cout<<n*i<<"\n";
        i++;
    }
    return 0;
}*/

//table using for loop
/*# include <iostream>
using namespace std;
int main()
{
    int n=8;
    for (int i=1;i<11;i++)
    {
        cout<<n*i<<"\n";

    }
    return 0;
}*/

//table using do while loop
/* # include <iostream>
using namespace std;
int main()
{
    int i=1;
    int n=7;

    do{
        cout<<n*i<<"\n";
        i++;
    }while(i<11);
    return 0;
}*/
// smallest divisor of number greater than 1 using for loop
/* # include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int k=n%i;
        if(k==0)
        {
            cout<<"the smallest divisor of number greater than 1 is:"<<i;
            break;
        }
    }
    return 0;
}*/

//using while loop\

/*# include <iostream>
using namespace std;
int main()
{
    int i=2;
    int n;
    cout<<"enter the number:";
    cin>>n;
    
    while(i<=n)
    {
        
        if (n%i==0)
        {
            i++;
            cout<<"the smallest divisor is:"<<i;
            
            break;
        }
        
        
        
    }
    return 0;
}*/

/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number :";
    cin>>n;
    int x;
    cout<<"enter the number to exclude multiples:";
    cin>>x;
    for(int i=1;i<=n;i++)
    {
        if(i%x==0)
        {
        
            continue;}
        cout<<i<<" ";

    }   

    
    return 0;
}*/

/*# include <iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"enter the number upto where u want to print tables:";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<11;j++)
        {
            int k=i*j;
            cout<<k<<" ";
            
        }
        cout<<"\n";
    }
    return 0;

    
}*/

/*# include <iostream>
using namespace std;
int main()
{
    int count=0;
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    while(n>0)
    {
        n=n/10;
        count=count+1;

    }
    cout<<count;
    return 0;


}*/

// 
/*# include <iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"enter the number to find divisor:";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
        }

    }
    return 0;
    
}*/

/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    int ans=1;
    
    while(n>0)
    {
        ans=ans*n;
        n=n-1;

    }
    cout<<ans;
    return 0;
    

}*/

/*# include <iostream>
using namespace std;
int getmin(int x,int y)
{
    if(x<y)
    return x;
    else
    return y;
}
int main()
{
    int ans=1;
    int a,b;
    cout<<"enter the number 1:\n";
    cin>>a;
    cout<<"enter the number 2:\n";
    cin>>b;
    int x= getmin(a,b);
    for (int i=1;i<=x;i++)
    {
        if(a%i==0 and b%i==0)
        {
            ans=i;

        }
    
    }
    cout<<ans;
    return 0;
}*/

/*# include <iostream>
using namespace std;
int getmax(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}
int main()
{
    int a,b;
    cout<<"enter the two numbers:";
    cin>>a>>b;


    int k=getmax(a,b);
    int end=a*b;
    for (int i=k;i<=end;i++)
    {
        if(i%a==0 and i%b==0)//need to divide the a and b by i
        {
            cout<<i;
            break;
        }
    }
    return 0;
}*/

// fibonacci numbers
/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of terms :";
    cin>>n;
    int a=1;
    int b=1;
    int c=0;
    cout<<"1 1 ";
    for (int i=2;i<n;i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    return 0;
}*/
/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number for prime check:";
    cin>>n;
    int count =0;
    for (int i=1;i<=n;i++)
    { 
        if(n==0 or n==1)
        {
            cout<<"1 or zero is neither prime nor composite";
            break;
        }
        else if(n%i==0)
        {
            count++;
        }
    }
    cout<<"number of factors are:"<<count<<"\n";
    if(count==2)
    cout<<"the number is prime";
    else
    cout<<"the number is not prime";

}*/

// binary to decimal
/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the binary digit for conversion:";
    cin>>n;
    int value=0;
    int base=1;
    while(n>0)
    {
        int last_digit=n%10;
        value=value+(last_digit*base);
        n=n/10;
        base=base*2;
    }
    cout<<value;
    return 0;
}*/

# include <iostream>
using namespace std;
int nextprime(int n)
{
    n++;
    while(true)
    
    {
        int i;
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            break;
        }
        if(i==n)return n;
        n++;
    }

}
int main()
{
    int n;
    cin>>n;
    cout<<nextprime(n);
    return 0;
}