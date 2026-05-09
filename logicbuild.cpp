 /*# include <iostream>
using namespace std;
//for chechking number is prime or not
int isprime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        return false;
    }

    return true ;
}
//for checking the factors are prime or not
void primefact(int n)

{
    for (int i=2;i<=n;i++)
    {
        if(isprime(i))
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
    cin>>n;
    primefact(n);

}/**/
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
int main()
{
    int n;
    cin>>n;
    primefact(n);
    return 0;
}*/


/*# include <iostream>
using namespace std;
int main()
{
  int n;
  cout<<"enter the number for prime check:";
  cin>>n;
  if(n==0 or n==1)
  {
    cout<<"the numbers are nor prime composite";
  }
  int i=2;
  while(i<n)
  {
    if(n%i==0)
    {
      cout<<"the number is not prime";
    }
    i++;
  

  }
  cout<<"the number is prime"<<"\n";
  cout<<n;
  return 0;
}*/
# include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  //top part
  for (int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      cout<<" ";
    }
    cout<<"*";

    if(i!=0)
    {
      for (int j=0;j<2*i-1;j++)
      {
        cout<<" ";
      }
      cout<<"*";
    }
    cout<<endl;
  }
  
}

