
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
  void inorderBST(node *root)
  {
      if(!root)
      return;
      inorderBST(root->left);
      cout<<root->data<<" ";
      inorderBST(root->right);
  }
  node *createMirror(node *root)
  {
      if(!root)
      return root;
      node *l=createMirror(root->right);
      node *r=createMirror(root->left);
      root->left=l;
      root->right=r;
      return root;
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
  void inorder()
  {
      inorderBST(root);
  }
  void mirrorImage()
  {
      root=createMirror(root);
  }

};
int main()
{
    Tree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.inorder();
    t.mirrorImage();
    cout<<endl;
    t.inorder();
    
    return 0;
}
