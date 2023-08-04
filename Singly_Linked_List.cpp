
//Singly linked list 

#include <iostream>
using namespace std;

//defining new namespace stdlist
namespace stdlist {


//Node template
template<class T>
class Node{
    public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
    Node()
    {
        data=0;
        next=NULL;
    }
};



//list template
template<class T>
class List{
  private:
  Node<T>* head;
  public:
  List()
  {
      head=NULL;
  }
  //insert at the end of list
  void insert(T data)
  {
      Node<T>*curr=new Node<T>(data);
      if(head==NULL)
      {
          head=curr;
      }else
      {
         Node<T>*temp=head;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=curr;
      }
  }
  
  //insert node at the begining of list
  void insert_front(T data)
  {
      Node<T>*curr=new Node<T>(data);
      if(head==NULL)
      {
          head=curr;
      }else
      {
          curr->next=head;
          head=curr;
          
      }
  }
  //delete a node
  void deleteNode(T data)
  {
      Node<T>*temp=head;
      if(temp->next==NULL)
      {
          if(temp->data==data)
          {
              head=NULL;
              delete temp;
              return;
          }
          else
          {
              cout<<"Node not found!"<<endl;
              return;
          }
          
      }
      else if(head->data==data)
      {
          head=head->next;
          delete temp;
          return;
      }else{
        
     if(search(data)){      
      Node<T>*prev=head;
      while(temp->data!=data)
      {
          prev=temp;
          temp=temp->next;
      }
      prev->next=temp->next;
      delete temp;
     }
     else
     {
         cout<<"Node Not found"<<endl;
     }
     
      }
  }
  
  //print list data
  void print()
  {
      Node<T>*temp=head;
      while(temp!=NULL)
      {
          cout<<temp->data<<" ";
          temp=temp->next;
      }
      cout<<endl;
  }
  
  //searching in the list
  bool search(T data)
  {
      Node<T>*temp=head;
      while(temp->next!=NULL)
      {
          if(temp->data==data)
          {
              return true;
          }
          temp=temp->next;
      }
      return false;
  }
  //reverse the list
  void reverse()
  {
      if(!head || head->next==NULL)
      return;
      Node<T>* curr=head, *prev=NULL,*Next=NULL;
      while(curr)
      {
          Next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=Next;
      }
      head=prev;
  }
};


}


int main()
{

    using namespace stdlist; //For using List template defined in stdlist namespace
    
    List<char>l;
    //sample operations
    l.insert_front('a');
    l.insert_front('c');
    l.insert('b');
    l.print();
    l.deleteNode('d');
    l.reverse();
    l.print();

    return 0;
}
