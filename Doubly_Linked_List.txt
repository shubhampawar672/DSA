#include <iostream>

using namespace std;

class Node
{
  public:
  int data;
  Node *next;
  Node *prev;
  Node()
  {
      data=0;
      next=NULL;
      prev=NULL;
  }
  Node(int data)
  {
      this->data=data;
      next=NULL;
      prev=NULL;
  }
};


class List
{
    private:
    Node *head;
    public:
    List()
    {
        head=NULL;
    }
    
    void insert(int data)
    {
        Node *curr=new Node(data);
        if(head==NULL)
        {
            head=curr;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=curr;
            curr->prev=temp;
        }
    }
    
    bool deleteNode(int data)
    {
        if(!head)
        return false;
        
        if(head->data==data)
        {
            Node *t=head;
            head=head->next;
            head->prev=NULL;
            delete t;
            return true;
        }
        
         Node *temp=head,*pre=NULL,*nxt=NULL;
         while(temp)
         {
             if(temp->data==data)
             {
                 if(temp->next==NULL)
                 {
                     pre=temp->prev;
                     temp->prev=NULL;
                     pre->next=NULL;
                 }
                 else
                 {
                     
                     pre=temp->prev;
                     nxt=temp->next;
                     pre->next=nxt;
                     nxt->prev=pre;
                 
                 }
                 delete temp;
                 return true;
             }
             temp=temp->next;
         }
         return false;
        
    }
    void print()
    {
        Node *temp=head;
        Node *pre=NULL;
        //print list 
        while(temp)
        {
            pre=temp;
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        //print list in reverse order
        while(pre)
        {
            cout<<pre->data<<" ";
            pre=pre->prev;
        }
        cout<<endl;
    }
};
int main()
{
    List l;
    l.insert(5);
    l.insert(10);
    l.insert(15);
    l.deleteNode(15);
    l.print();

    return 0;
}
