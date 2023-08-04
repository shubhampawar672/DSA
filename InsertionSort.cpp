
//Insertion short
//Insertion sort partition array in such way that it sorted element are in one side of array and unsorted are on the other side

#include <iostream>

using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
         int key=arr[i];
         int j=i-1;
         while(key<arr[j] && j>=0)
         {
             arr[j+1]=arr[j];
             j--;
         }
         arr[j+1]=key;
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
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
