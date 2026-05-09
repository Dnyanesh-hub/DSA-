// swap two numbers way 1 - by using third variable
/*#include <iostream>
using namespace std;
int main()
{
    
   int a=10;
    int b=20;
    cout<<a<<" "<<b<<endl;
    int temp =a;
    a=b;
    b=temp;
    
    cout<<a<<" "<<b;
    return 0;

}*/

//swap two numbers without using third variable using arithmetic operator
/*#include <iostream>
using namespace std;
int main()
{
    
   int a=10;
    int b=20;
    cout<<a<<" "<<b<<endl;
    a=a+b;
    b=a-b;
    a=a-b;

    
    
    
    
    cout<<a<<" "<<b;
    return 0;}*/

    //using logical operator bitwiae or

  /*  #include <iostream>
using namespace std;
int main()
{
    
   int a=10;
    int b=20;
    cout<<a<<" "<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;

    
    
    
    
    cout<<a<<" "<<b;
    return 0;}*/

    //question 2
    // day before n days modify it according to understanding
    /*# include <iostream>
    using namespace std;
    int main()
    {
      int d=0;//todays day
      int n=9;//day after 9 days

      int x=n%7;// it will help us to keep range in between 0-6
      int ans=d-x;
      if (ans>0)
      
        cout<<ans;
    
      else  
      
        cout<<ans+7;
      
      

    }*/

   //finding last digit of number
   /*# include <iostream>>
   using namespace std;
   int main()
   {
    int x=-357;
    int ans=abs(x)%10;
    cout<<ans;
    return 0;
   }*/

  //sum of n natural numbers
 /*  # include <iostream>
  using namespace std;
  int main()
  {
    int n=6;
    int sum = (n*(n+1))/2;
    cout<<sum;
    return 0;
  }*/

 //arithmetic progression 

 /*#include <iostream>
 using namespace std;
 int main()
 {
  int a=2;
  int d=3;
  int n=9;
  int ans=(a+(n-1)*d);
  cout<<ans;
  return 0;
 }*/

// geometric progression

/*#include <iostream>
//# include<math.h>
# include<bits/stdc++.h>
using namespace std;
int main()
{
  int a=3;
  int r=2;
  int n=6;
  int ans=a*(int)(pow(r,n-1));
  cout<<ans;
  return 0;
}*/

//perform all the arithmetic operations
/*#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;
int main()
{
  int x=7,y=2;
  int p=(x+y);
  int q=(x-y);
  int r=(x*y);

  int s=(x/y);

  int u=(x%y);
  int v=pow(x,y);
   cout<<fixed<<setprecision(5)<<s<<" "<<p<<" "
   <<q<<" "<<r<<" "<<u<<" "<<v;
   return 0;

  
}*/

//compare two numbers

/*#include <iostream>
using namespace std;
int main()
{
  int x,y;
  cout <<"enter two integer for comparison:";
  cin>>x>>y;
  if(x>y)
  cout<<1;
  else
  cout<<0;
  return 0;
}*/

// logical operator
/*# include <iostream>
using namespace std;
int main ()
{
  bool a=false;
  bool b=true;
  bool c=(a&&b);
  bool d=(a||b);
  bool e=(!a);
  cout<<std::boolalpha;
  cout<<c;
  cout<<d;
  cout<<e;
  return 0;
}*/

//solving the equation
/*# include <iostream>
using namespace std;
int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int ans=(((a+b)/c)+d);
  cout<<ans;
  return 0;
}*/

// cup game 

/*# include <iostream>
using namespace std;
int main ()
{
  int cups;
  cout<<"enter the number of cups";
  cin>>cups;
  if(cups%2==0)
  {
    cout<<"opponent won";
  }
  else
  {
    cout<<" I won";
  }
  return 0;
}*/

/*# include <iostream>
using namespace std;
int main()
{
  int x,y,z;
  cout<<"enter three numbers for comparison";
  cin>>x>>y>>z;
  if(x>=y and x>=z)
  cout<<x;
  else if (y>=x and y>=z)
  cout<<y;
  else
  cout<<z;
  return 0;

}*/

/*# include <iostream>
using namespace std;
int main()
{
  int year ;
  cout<<"enter year :";
  cin>>year;
  if(year%4==0 && year % 100!=0)
  {
    cout<<"entered year is leap year";

  }
  else if (year%400==0)
  {
    cout<<"enterd year is leap";

  }
  else
  cout<<"enterd year is not leap year";
  return 0;

}*/

// simple calcultor

/*# include <iostream>
using namespace std;
int main()
{
  string sign;//enter the sign of operation that u want to perform
  cout<<"enter the sign of operation that u want to perform";
  cin>> sign;
  int x;
  cout<<"the first number";
  cin>>x;
  int y;
  cout<<"the second number";
  cin>>y;

  if(sign=="+")
  {
    cout<<"the sum is :"<<(x+y);
  }
  else if (sign=="-")
  {
    cout<<"the subtraction is:"<<(x-y);

  }
  else if (sign=="*")
  {
    cout<<"the multiplication is:"<<(x*y);
    
  }
  else if (sign=="/")
  {
    cout<<"the division  is:"<<(x/y);

    
  }
  else if (sign=="%")
  {
    cout<<"the remainder  is:"<<(x%y);
    
  }
  else 
  cout<<"invalid sign";
  return 0;

}*/

/*# include <iostream>
using namespace std;
int main()
{
  int n;
  cout<<"enter the number";
  cin>>n;
  if(n%3==0 and n%5==0)
  {
    cout<<"fizzbuzz";
  }
  else if (n%3==0)
  {
    cout<<"fizz";

  }
  else if  (n%5==0)
  cout<<"buzz";
  else
  {
    cout <<"the number is not divisible by 3 and 5";
  }
  return 0;
  

}*/

// use of switch 

/* # include <iostream>
using namespace std;
int main ()
{
  int x;
  cout<<"enter the number from 0-9";
  cin>>x;
  switch(x)
  {
    case 1:cout<<"One";
    break;
    case 2:cout<<" two";
    break;
    case 3:cout<<" three";
    break;
    case 4:cout<<" four ";
    break;
    case 5:cout<<" five";
    break;
    case 6:cout<<" six";
    break;
    case 7:cout<<"seven";
    break;
    case 8:cout<<" eight";
    break;
    case 9:cout<<" nine";
    break;
    default:cout<<"unknown";
    return 0;
  }
}*/

// extracting digits 2nd
# include <iostream>
using namespace std;
int firstdigit (int n )
{
  int r;
  
  while(n==0){
    r=n%10;
    n=n/10; 
  
    return r;

  }
  //return r;

}

int main ()
{
  int n ;
  cout<<"enter the number";
  cin>>n;
  cout<<"the first digit of the number is\n";
  cout<<firstdigit(n)<<"\n";
  return 0;
}

/*# include <iostream>
using namespace std ;

int isprime(int n)
{
  for (int i =2;i<n;i++) 
  {
    if (n%i==0) 
    {
      return false;
    }
    
  }
  return true;
  
}

void primefact(int n)
{
  for (int i=2;i<=n;i++)
  {
    if (isprime(i))
    {
      int x=i;
      while(n%x==0)
      {
        cout<<i<<" ";
        x=x*i;
      }
    }

  }
}

int main ()
{
  int n;
  cout<<"enter the number  for prime factorization:";
  cin>>n;
  primefact(n);
  return 0;
}*/

/*# include <iostream>
using namespace std;
int factorial (int n)
{
  if (n==0 or n==1)

  return 1;
  else
  return n* factorial(n-1);

}
int main ()
{
  int n;
  cout<<"enter the number:";
  cin>>n;
  cout<<factorial(n);
  return 0;
  }*/

 /*# include <iostream>
 using namespace std;

 float volume_cube(float side)
 {

  
  
  return float (side*side*side);
 }

 float volume_rectangle(float length ,float height ,float width)
 {
  return length*height*width;
 }
 int main()
 {
  float side;
  cout<<"enter the side of cube:";
  cin>>side;
  cout<<"volume is:"<<volume_cube(side)<<"\n";
  float length,height,width;
  cout<<"enter the length height width respectively:\n";
  cin>>length>>height>>width;
  cout<<"volume of rectangle is :\n";
  cout<<volume_rectangle(length,height,width);
  return 0;

 }*/