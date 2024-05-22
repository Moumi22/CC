#include<bits/stdc++.h>
using namespace std;
struct pro
{
    int pid;
    int atime;
    int btime;
    int priority;
};

bool cya(pro p, pro q)
{
    return p.atime < q.atime;
}

bool cyb(pro p, pro q)
{
    return p.btime < q.btime;
}

bool cyp(pro p, pro q)
{
    return p.priority < q.priority;
}

void prio(int process[],int arrival[],int bust[],int py[],int n)
{
    int com[n+2];
    vector<pro>v;

    for(int i=0;i<n;i++)
    {
        pro p;
        p.pid = process[i];
        p.atime = arrival[i];
        p.btime = bust[i];
        p.priority = py[i];
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cya);
    int clock = 0, cp;

    while(!v.empty())
    {
        cp = 0;
        for(auto x:v)
        {
            if(x.atime <= clock)
            {
                cp++;
            }
        }
        if(cp == 0)
        {
            clock = v[0].atime;
            continue;
        }
        sort(v.begin(),v.begin()+cp,cyp);

        clock += v[0].btime;
        com[v[0].pid] = clock;
        v.erase(v.begin());
    }

    for(int i=0;i<n;i++)
    {
        cout<<com[i]<<" ";
    }

}

int main()
{
    int n = 6;
    int p[] = {0,1,2,3,4,5};
    int a[] ={3,2,5,4,1,0};
    int b[] = {5,4,1,7,6,2};
    int py[] = {2,1,3,4,3,5};

    prio(p,a,b,py,n);
    return 0;
}

