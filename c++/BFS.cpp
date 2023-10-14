#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    char u,v ,s;

    cout<<"number of vertices:";
    cin>>n;

    cout<<"number of edges:";
    cin>>e;

    vector<char>adj[n];
    int visited[n];

    for(int i=0; i<n; i++)
    visited[i] = 0;

   for(int i=0; i<e;i++)
   {
       cout<<"edges "<< i<< "  : ";
       cout<<"\n= ";
       cin>>u;
       cout<< "v ";
       cin>>v;

       u= toupper(u);
       v=toupper(v);

       adj[u-'A'].push_back(v-'A');
       adj[v-'A'].push_back(v-'A');


   }


   queue<int>Q;
   cout<< "starting vertex :";
   cin>>s;
   s = toupper(s);

   Q.push(s-'A');
    visited[s-'A'] = 1;
   cout<< "BFS";
   while(!Q.empty())
   {
       char var;
       var = Q.front();
       Q.pop();
       for(int i=0; i<adj[var].size(); i++)
       {

           int x = adj[var][i];
           if(visited[x] == 0)
           {
               visited[x] = 1;
               Q.push(x);

           }
       }

       cout<< (char)(var + 'A') << " ";

   }

    return 0;
}
