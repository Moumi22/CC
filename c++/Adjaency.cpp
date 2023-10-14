#include<iostream>
using namespace std;
int main()
{
    int n, e, w, i, j, u, v;
    cout<< "Enter vertex and edge: ";
    cin>> n >> e;
    int adj[n][n];
    for (i=0; i<n; i++)
    {

        for(j=0; j<e; j++)
        {
            adj[i][j] = -1;
        }
    }
    for(i=0; i<e; i++)
    {

        cout<< "Edge "<< i+1 <<"Source Destination and Weight:";
        cin>> u>> v>> w;
        adj[u][v]=w;
        adj[v][u]=w;

    }
    cout<<"\nadj Matrix: \n";
    for(i=0; i<n; i++)
    {
        cout<<"Vertex "<< i << ":";
        for(j=0; j<n; j++)
        {

            if(adj[i][j]!=-1)
                cout<< j<< " ";

        }
        cout<< endl;
    }


}


