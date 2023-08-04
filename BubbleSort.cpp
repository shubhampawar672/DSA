//Bubble Sort 
//bubble sort works by repeteadly swapping the adjecent elements if they are in the wrong order
//in 1'st iteration bubble sort place the largest element at it's correct position
//int 2'nd iteration it places the 2'nd largest element in the correct position and so on...
//It's not suitable for the large dataset since it's time complexity is quite high ->O(n^2)
#include <iostream>

using namespace std;
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main()
{
   int n;
   cout<<"Enter Size of the Array"<<endl;
   cin>>n;
   cout<<"Enter Array Elements"<<endl;
   int *arr=new int[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   
   bubbleSort(arr,n);
   
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }

    return 0;
}
