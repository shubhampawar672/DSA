//Find GCD
#include <iostream>

using namespace std;
int findGCD(int a,int b)
{
    // while(a!=b)
    // {
    //     if(a>b)
    //     {
    //         a=a-b;
    //     }
    //     else
    //     {
    //         b=b-a;
    //     }
    // }
    // return a;
    //or
    if(b==0)
    return a;
    return findGCD(b,a%b);
    
    //or
    if(b>a)
    {
        swap(a,b);
    }
    while(a%b!=0)
    {
        if(a>b)
        {
            b=a%b;
        }
        else
        {
            a=b%a;
        }
    }
    return a;
    
}
int main()
{
    int a,b;
    cin>>a>>b;
    int gcd=findGCD(a,b);
    cout<<gcd;
    cout<<"LCM = "<<(a*b)/gcd;

    return 0;
}
