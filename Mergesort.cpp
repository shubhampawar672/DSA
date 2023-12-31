
//merge sort
#include <iostream>

using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int n1=mid-l+1;
    int n2=h-mid;
    int *arr1=new int[n1];
    int *arr2=new int[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        arr2[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k++]=arr1[i++];
    }
    while(j<n2)
    {
        arr[k++]=arr2[j++];
    }
    delete arr1[];
    delete arr2[];
    
}
void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=l+(h-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
   int n;
   cin>>n;
   int *arr=new int[n];
   cout<<"Enter Array Element: "<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   mergeSort(arr,0,n-1);
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
   

    return 0;
}
