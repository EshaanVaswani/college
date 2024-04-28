#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int bt;
    int wt;
    int tat;
};

bool compareBT (const Process& a, const Process& b){
    return a.bt < b.bt;
}

void calculateWT(vector<Process>& p) {
    p[0].wt = 0;

    for(int i=1; i<p.size(); i++){
        p[i].wt = p[i-1].bt + p[i-1].wt;
    }
}

void calculateTAT(vector<Process>& p) {
    for(int i=0; i<p.size(); i++){
        p[i].tat = p[i].bt + p[i].wt;
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
    int n;
    cout << "Enter no. of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter burst time of each process:" << endl;
    for(int i=0; i<n; i++){
        cout << "Process " << i+1 << ":";
        cin >> p[i].bt;
        p[i].id = i+1;
    }

    sort(p.begin(), p.end(), compareBT);

    calculateWT(p);
    calculateTAT(p);

    cout << "\nProcess\t\tBurstTime\tWaitingTime\tTurnaroundTime\n";
    for(int i=0; i<n; i++){
        cout << p[i].id << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tat << endl;
    }

    calculateAvg(p);

    return 0;
}
