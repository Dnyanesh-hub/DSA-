/*#include <iostream>
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
    int a=20,b=10;
    int k=getmax(a,b);
    cout<<k;
    return 0;
}*/


/*# include <iostream>
using namespace std;
void greetmsg()
{
    cout<<"hi,\n";
    cout<<"welcome to my life!\n";

}
void exitmsg()
{
    cout<<"bye,\n";
    cout<<"visit again !\n";

}
int main()
{
    greetmsg();
    cout<<"hope you are enjoying \n";
    exitmsg();
    return 0;

}*/

//declare use and function the second way to write function

/*#include<iostream>
using namespace std;
int getmax(int x,int y);


int main()

{

   int a=20,b=30;
   cout<<getmax(a,b) ;
   
}
int getmax(int x, int y)
{
    if(x>y)
    return x;
    else
    return y;
    
}*/

/*# include <iostream>
# include<cmath>
using namespace std;
int main()
{
    double  a=2,b=4;
    cout<<pow(a,b)<<endl;
    double x=100;
    cout<<log10(x);
    return 0;
}*/

// default arguements concept

/*# include<iostream>
using namespace std;
void printinfo(int id, string name="NA",string address="NA")
{
    cout<<"id is"<<id<<"\n";
    cout<<"name is"<<name<<"\n";
    cout<<"adress is "<<address<<"\n";
}
int main()
{
    printinfo(101,"dany", "pune");
    cout<<"\n";
    printinfo(301,"mali");
    cout<<"\n";
    printinfo(403);
    return 0;
}*/

//maximum of three by using function overloading
/*# include <iostream>
using namespace std;

 int getmax(int x,int y)
{
    return (x>y)?x:y;

}
int getmax(int x,int y,int z)
{
    return getmax(getmax(x,y),z);
}
int main()
{
    int a=20,b=40 ,c=50;
    cout<<getmax(a,b)<<"\n";
    cout <<getmax(a,b,c);
    return 0;
}*/

/*#include <iostream>
using namespace std;
void fun()
{
    static  int x=1;
    int y=1;
    x++;
    y++;
    cout<<x<<" "<<y<<endl;

}

int main()
{
    fun();
    fun();
    fun();
    return 0;
}*/

/*# include <iostream>
using namespace std;
void fun (int x,int y,int z)
{
    cout<<x<<" "<<y<<" "<<z<<" ";
}
int main ()
{
    int i =2;
    fun(++i,++i,++i);
    return 0;
}*/

# include <iostream>
using namespace std;
int main()
{
    cout<<"dany";
    main();
    return 0;
    
}