#include<stdio.h>
#define BUFFER_SIZE 5

typedef struct{
    int a[BUFFER_SIZE];
    int *pa;
} Buffer;

void add(Buffer *b,int ele)
{
   *b->pa=ele;
    b->pa=(b->pa!=&b->a[BUFFER_SIZE-1])? b->pa+1 :&b->a[0];
}

int main()
{
    Buffer b={0};
    b.pa=&b.a[0];
    
    for(int j=0;j<1000000;j++)
    {
        add(&b,j);
    }
    
    for(int i=0;i<BUFFER_SIZE;i++)
    {
        printf("%d ",b.a[i]);
    }
    return 0;
}