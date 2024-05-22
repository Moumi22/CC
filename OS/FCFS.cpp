#include <bits/stdc++.h>
using namespace std;
void FCFS(int processes[], int arrival[], int burst[], int n)
{
    int completion[n], turnaround[n], waiting[n];
    vector<pair<int,int>> v;

    for(int i=0; i < n; i++)
        v.push_back({arrival[i], processes[i]});

    sort(v.begin(), v.end());

    int clock=0, i=0, current_process, arrival_time;

    while(i != n)
    {
        current_process = v[i].second;
        arrival_time = v[i].first;

        if(clock < arrival_time)
            clock = arrival_time;

        clock += burst[current_process];
        completion[current_process] = clock;
        turnaround[current_process] = completion[current_process] - arrival[current_process];
        waiting[current_process] = turnaround[current_process] - burst[current_process];
        i++;
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
    FCFS(processes, arrival, burst, n);
}
