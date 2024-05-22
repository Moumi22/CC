#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
};
bool compareByArrival(Process p, Process q)
{
    return p.arrival_time < q.arrival_time;
}
bool compareByBurst(Process p, Process q)
{
    return p.burst_time < q.burst_time;
}
bool compareByPriority(Process p, Process q)
{
    return p.priority < q.priority;
}

void SJF_preemptive(int processes[], int arrival[], int burst[], int n)
{
    int completion[n], turnaround[n], waiting[n];
    vector<Process> v;
    for(int i=0; i < n; i++)
    {
        Process p;
        p.pid = processes[i];
        p.arrival_time=arrival[i];
        p.burst_time = burst[i];
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compareByArrival);
    int clock=0, arrived_processes;

    while(!v.empty())
    {
        arrived_processes = 0;
        for(auto x : v)
            if(x.arrival_time <= clock) arrived_processes++;
        if(arrived_processes == 0)
        {
            clock = v[0].arrival_time;
            continue;
        }
        sort(v.begin(), v.begin()+arrived_processes, compareByBurst);
        clock += v[0].burst_time;
        completion[v[0].pid] = clock;
        v.erase(v.begin());
    }

    cout << "P AT BT CT\n";
    for(int i = 0; i < n; i++)
    {
        cout << processes[i] << " " << arrival[i] << " "
        << burst[i] << " " << completion[i] << '\n';

    }
}

int main()
{
    int n=5;
    int processes[] = {0, 1, 2, 3, 4};
    int arrival[] = {0, 5, 5, 8, 20};
    int burst[] = {2, 4, 6, 5, 7};
    SJF_preemptive(processes, arrival, burst, n);
}

