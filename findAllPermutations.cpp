//print all permutations of string
#include <iostream>
#include<vector>
using namespace std;
void findAllPermutations(string s,int l,int n,vector<string>&ans)
{
    if(l>=n)
    {
       ans.push_back(s); 
       return ;
        
    }
    for(int i=l;i<n;i++)
    {
        swap(s[i],s[l]);
        findAllPermutations(s,l+1,n,ans);
        swap(s[i],s[l]);
        
    }
}
vector<string>permute(string s)
{
    int n=s.size();
    vector<string>ans;
     findAllPermutations(s,0,n,ans);
     return ans;
}
int main()
{
   string s;
   cin>>s;
   
   vector<string>ans=permute(s);
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i]<<endl;
   }

    return 0;
}
