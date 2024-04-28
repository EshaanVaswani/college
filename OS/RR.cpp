#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int bt;
    int rt;
    int wt;
    int tat;
};

void calculateTime(vector<Process>& p, int quantum){
    queue<int> q;
    int ct = 0;

    for(int i=0; i<p.size(); i++){
        p[i].rt = p[i].bt;
        q.push(i);
    }

    while(!q.empty()){
        int i = q.front();
        q.pop();

        if(p[i].rt > quantum){
            ct += quantum;
            p[i].rt -= quantum;
            q.push(i);
        } else {
            ct += p[i].rt;
            p[i].tat = ct;
            p[i].wt = ct - p[i].bt;
            p[i].rt = 0;
        }
    }
}

void calculateAvg(vector<Process>& p) {
    int totalWT = 0;
    int totalTAT = 0;

    int n = p.size();

    for(int i=0; i<n; i++){
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    cout << "Average Waiting Time = " << (float)totalWT/(float)n << endl;
    cout << "Average Turnaround Time = " << (float)totalTAT/(float)n << endl;
}

int main() {
    int n,q;
    cout << "Enter no. of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> q;

    vector<Process> p(n);

    cout << "Enter burst time of each process:" << endl;
    for(int i=0; i<n; i++){
        cout << "Process " << i+1 << " Burst Time:";
        cin >> p[i].bt;
        p[i].id = i+1;
    }

    calculateTime(p,q);

    cout << "\nProcess\t\tBurstTime\tWaitingTime\tTurnaroundTime\n";
    for(int i=0; i<n; i++){
        cout << p[i].id << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tat << endl;
    }

    calculateAvg(p);

    return 0;
}
