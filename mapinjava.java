/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
import java.util.HashMap;
import java.util.Map;
// #include <iostream>

// using namespace std;

// int findSum(int arr[],int i,int n, int sum)
// {
//     if(i>n)
//     return sum;
//     return findSum(arr,i+1,n,sum+arr[i]);
// }
// int main()
// {
//     int arr[]={9888,2};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<findSum(arr,0,n-1,0);

//     return 0;
// }

class Main{
    
    public static void main(String args[])
    {
        Map<String, String>map=new HashMap<>();
        map.put("Shubham","Pawar");
        map.put("Harish","Kartikeyan");
        System.out.println(map.entrySet());
        for(Map.Entry<String,String>entry:map.entrySet())
        {
            System.out.println(entry.getKey()+" "+entry.getValue());
        }
    }
}
