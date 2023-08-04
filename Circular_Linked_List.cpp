//program to implement circular linked list. 
#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int d)
    {
        data=d;
        next=NULL;
    }
    
};

class CircularLinkedList:public Node
{
   private:
   Node *head;
    
   public:
   //initilize the head node
   CircularLinkedList()
   {
       head=new Node();
   }
   //insert node at the end of the list
   void insert(int data)
   {
       Node *temp=new Node(data);
       if(head->next==NULL)
       {
           head->next=temp;
           temp->next=head;
           
       }
       else
       {
           Node *t=head->next;
           while(t->next!=head)
           {
               t=t->next;
           }
           t->next=temp;
           temp->next=head;
       }
       
   }
   //insert node at the brgining of the list
   void insertFront(int data)
   {
       Node *temp=new Node(data);
      if(head->next==NULL)
      {
          head->next=temp;
          temp->next=head;
      }
      else
      {
          Node *t=head->next;
          head->next=temp;
          temp->next=t;
      }
       
   }
   
   //delete from the front of the list
   void deleteFront()
   {
       Node *t=head->next;
       if(head->next->next==head)
       {
           head->next=NULL;
       }
       else
       {
           head->next=head->next->next;
       }
       delete t;
   }
   
   //delete from end of the list
   void deleteN()
   {
       Node *t=head->next;
       if(head->next->next==NULL)
       {
           head->next=NULL;
           delete t;
       }
       else
       {
           while(t->next->next!=head)
           {
               t=t->next;
           }
           Node *deleteNode=t->next;
           t->next=head;
           delete deleteNode;
       }
       
   }
   //search the value
   bool find(int data)
   {
       Node* t=head->next;
       while(t->next!=head)
       {
           if(t->data==data)
           return true;
           t=t->next;
       }
       return false;
   }
   //print the value of the list
   void print()
   {
       Node *t=head->next;
       while(t->next!=head)
       {
           cout<<t->data<<" ";
           t=t->next;
       }
      cout<<t->data;
   }
   
   //print values in circular manner
   void display()
   {
       cout<<"Display 2 time. Circularly"<<endl;
       int cnt=8;
       Node *t=head->next;
           while(cnt--)
           {
                 if(t==head)
                 {
                     t=t->next;
                 }
                  cout<<t->data<<" ";
                  t=t->next;
           }
   }
   
   
};
int main()
{
    CircularLinkedList node;
    
    
    node.insert(50);
    node.insert(60);
    node.insert(70);
    node.insert(80);
    
    
    node.insertFront(10);
    node.insertFront(20);
    node.insertFront(30);
    node.insertFront(40);
    
    node.print();
    node.display();

    node.deleteFront();
    node.deleteN();

    cout<<node.find(40);
    return 0;
}
