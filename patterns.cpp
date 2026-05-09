
// patterns 
/* # include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"*"<<endl;

    }


    return 0;
}*/

/*# include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j =1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}*/

/*# include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j =1;j<=n;j++)
        {
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}*/


/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        char ch='A';
        for (int j=0;j<n;j++)
        {
            cout<<ch<<" ";
            ch=ch+1;


        }
        cout<<endl;
    } 
    return 0;

}*/


/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number n:";
    cin>>n;
    int k=1;
    for (int i=0;i<n;i++)
    {
        
        for (int j=0;j<n;j++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}*/

/*# include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    char ch='A';
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<ch;
            ch=ch+1;
        }
        cout<<endl;
    }
    return 0;

}*/


/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
        {
        cout<<"*";
        }
        cout<<endl;


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
    int k=1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            cout<<k<<" ";
            k++;

        }
        cout<<endl;
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
    for (int i=0;i<n;i++)
    {
        
        for(int j=0;j<i+1;j++)
        {
            cout<<(i+1);
            
            

        }
    
        cout<<endl;
    }
    return 0;
}*/
/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n";
    cin>>n;
    char ch='A';
    for (int i = 0; i <n; i++)
    {
        
        for(int j=0;j<i+1;j++)
        {
            cout<<ch;
            
        }
        ch=ch+1;
        cout<<endl;
        
    }
    
}*/

/* # include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for (int i=0;i<n;i++)

    {
        int k=1;
        for ( int j=0;j<i+1;j++)
        {
            cout<<k;
            k=k+1;
        }
        cout<<endl;

    }
    return 0;
}*/

/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j>0;j--)
        {
            cout<<j;
        }
    
        cout<<endl;
    }
    return 0;
}*/

/* # include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of the :";
    cin>>n;
    char ch='A';
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;

    }
    return 0;
}*/


/*# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            cout<<" ";

        }
        for (int j=0;j<n-i;j++);
        {
            cout<<(i+1);
        }
        cout<<endl;
    }
    return 0;
}*/
/* # include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number :";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for ( int j=1;j<=i+1;j++)
        {
            cout<<j;
        }
        for ( int j=i;j>0;j--)
        {
            cout<<j;
        }
        cout<<endl;
    
        
    }
    return 0;
    
}*/

# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<"*";

        if (i!=0)
        {
            for (int j=0;j<2*i-1;j++)
            {
                cout<<" ";

            }
            cout<<"*";

        }
        cout<<endl;

    }
    
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            cout<<" ";

        }
        cout<<"*";
        if(i!=n-2)
        {
            for (int j=0;j<2*(n-i)-5;j++)
            {
        
            cout<<" ";
            }
            cout<<"*";
        }

        cout<<endl;
    

    }
    return 0;

}