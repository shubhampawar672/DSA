
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    
    private:
    vector<pair<int,int>>*adj;

    public:
    Graph(int size)
    {
        adj=new int[size];
    }
    void insert(int n1,int n2,int wt)
    {
        adj[n1].push_back({n2,wt});
    }
    
    void bfs(int src)
    {
       queue<pair<int,int>>q; 
       vector<int>vis(3,0);
       q.push({src,0});
       while(!q.empty())
       {
           int n=q.size();
           auto nd=q.front();
           int nod=nd.first;
           int wt=nd.second;
           vis[nod]=1;
           q.pop();
           cout<<nd.first<<"  "<<nd.second<<endl;
           for(int i=0;i<adj[nod].size();i++)
           {
               if(!vis[adj[nod][i].first])
               {
                   q.push({adj[nod][i].first,adj[nod][i].second});
               }
           }
       }
    }
    
    
};


int main()
{
    Graph g;
    g.insert(1,2,10);
    g.insert(1,3,5);
    g.insert(2,3,2);
    g.insert(2,4,3);
    g.bfs(1);

    return 0;
}
