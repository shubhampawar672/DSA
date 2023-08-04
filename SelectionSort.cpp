//Selection Sort
//select the minimum element and put it at the begining of list 
#include <iostream>

using namespace std;

void selectionSort(int arr[],int n)
{
   for(int i=0;i<n-1;i++)
   {
       int idx=i;
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]<arr[idx])
           idx=j;
       }
       swap(arr[idx],arr[i]);
   }
}

int main()
{
    int n;
    cout<<"Enter size of the Array"<<endl;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
