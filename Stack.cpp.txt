#include <iostream>

using namespace std;
template<class T>
class Node
{
  public:
  T data;
  Node *next;
  Node *prev;
  Node()
  {
      data=0;
      next=NULL;
      prev=NULL;
  }
  Node(T data)
  {
      this->data=data;
      next=NULL;
      prev=NULL;
  }
};

template<class T>
class Stack
{
    private:
    Node<T> *Top;
    public:
    Stack()
    {
        Top=NULL;
    }
    
    void push(T data)
    {
        Node<T> *curr=new Node<T>(data);
        if(Top==NULL)
        {
            Top=curr;
        }
        else
        {
            Top->next=curr;
            curr->prev=Top;
            Top=curr;
        }
    }
    
    T pop()
    {
        if(!isEmpty())
        {
            Node<T>* curr=Top;
            if(Top->next==NULL && Top->prev==NULL)
            {
              Top=NULL;
            }
            else{
            Top=Top->prev;
            Top->next=NULL;
                
            }
            T d=curr->data;
            delete curr;
            return d;
        }
        else
        {
            cout<<"error! Stack Empty!!"<<endl;
            return (T)-1;
        }
    }
    T top()
    {
        if(!isEmpty())
        {
            return Top->data;
        }
        else
        {
            cout<<"error! Stack Empty"<<endl;
            return (T)-1;
        }
    }
    bool isEmpty()
    {
        return Top==NULL;
    }

};
int main()
{
    Stack<char>st;
    
    //sample operations
    st.push('c');
    st.push('b');
    st.push('a');
    cout<<st.top();
    cout<<st.pop();
    cout<<st.top();
    cout<<st.pop();
    cout<<st.pop();

    return 0;
}
