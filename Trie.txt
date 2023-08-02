#include <iostream>

using namespace std;
class Trie{
    private:
    bool isComplete;
    Trie *child[26];
    public:
    
      Trie()
      {
          isComplete=false;
          for(int i=0;i<26;i++)
          {
              child[i]=nullptr;
          }
      }
          
      void insert(string word)
      {
          Trie *root=this;
          for(int i=0;i<word.size();i++)
          {
              if(!root->child[word[i]-'a'])
              {
                  root->child[word[i]-'a']=new Trie();
              }
              root=root->child[word[i]-'a'];
              
          }
           root->isComplete=true;
      }
      
      
      bool search(string word)
      {
          Trie *root=this;
          for(int i=0;i<word.size();i++)
          {
              if(root->child[word[i]-'a']==NULL)
              {
                  return false;
              }
              root=root->child[word[i]-'a'];
             
          }
          return root->isComplete==true?true:false;
      }
      
      bool search_prefix(string word)
      {
          Trie *root=this;
          for(int i=0;i<word.size();i++)
          {
              if(root->child[word[i]-'a']==NULL)
              {
                  return false;
              }
             root=root->child[word[i]-'a'];
          }
          return true;
      }
      
      bool delete_word(string word)
      {
          
          Trie *root=this;
          for(int i=0;i<word.size();i++)
          {
              if(!root->child[word[i]-'a'])
              {
                  return false;
              }
              root=root->child[word[i]-'a'];

             
          }
          if(root->isComplete==true)
          {
              root->isComplete=false;
              return true;
          }
          return false;
      }
      
};
int main()
{
    Trie t;
    //sample operations on trie
    t.insert("xyz");
    t.insert("xyza");
    t.insert("abcd");
    t.insert("abcdefg");
    cout<<t.delete_word("xyz");
    cout<<t.search("xyza");

    return 0;
}
