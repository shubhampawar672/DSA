
#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class Tree{
  node *root;
  node *insertBST(node *root,int val)
  {
       if(root==NULL)
      {
         return new node(val);
      }
      if(val<root->data)
      root->left=insertBST(root->left,val);
      else
      root->right=insertBST(root->right,val);
      
      return root;
  }
  bool searchBST(node *root,int data)
  {
      if(!root)
      return false;
      
      if(root->data==data)
      return true;
      
      if(data<root->data)
      return searchBST(root->left,data);
      else
      {
          return searchBST(root->right,data);
      }
  }
  node* deleteBST(node *root,int data)
  {
      if(!root)
      return NULL;
      
      if(root->data==data)
      {
          
      if(!root->right && !root->left)
      return NULL;
      else if(!root->left)
      return root->right;
      else if (!root->right)
      return root->left;
      else
      {
          node *t=findMin(root->right);
          root->data=t->data;
          root->right=deleteBST(root->right,t->data);
          return root;
      }
          
      }
      
      if(data<root->data)
      {
      root->left= deleteBST(root->left,data);
      }
      else
      {
          root->right= deleteBST(root->right,data);
      }
      
      return root;
      
  }
  node* findMin(node *root)
  {
      if(!root->left && !root->right)
      return root;
      return findMin(root->left);
      
  }
  public:
  Tree()
  {
      root=NULL;
  }
  void insert(int data)
  {
      root=insertBST(root,data);
  }
  bool search(int data)
  {
      return searchBST(root,data);
  }
  bool deleteN(int data)
  {
      
      node *nd= deleteBST(root,data);
      return nd;
  }
};
int main()
{
    Tree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    cout<<t.search(20);
    cout<<t.deleteN(20);
    cout<<t.search(20);
    
    return 0;
}
