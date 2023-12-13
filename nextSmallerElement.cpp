//next smaller element to the right

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void nextSmallerElement(vector<int>arr,int sz,vector<int>&ans)
{
    stack<int>st;
    for(int i=sz-1;i>=0;i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans.push_back(-1);
        }else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
}

int main()
{
    vector<int>arr={4,2,1,5,3};
    vector<int>ans;
    nextSmallerElement(arr,arr.size(),ans);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}