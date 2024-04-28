#include<bits/stdc++.h>
using namespace std;

struct MemBlock {
    int size;
};

struct Process {
    int size,id,blockId;
};

void BestFit(vector<MemBlock>& m, vector<Process>& p){
    for(int i=0; i<p.size(); i++){
        p[i].blockId = -1;
        int best = -1;

        for(int j=0; j<m.size(); j++){
            if(m[j].size >= p[i].size){
                if(best == -1)
                    best = j;
                else if(m[best].size > m[j].size)
                    best = j;

            }
        }

        if(best != -1){
            m[best].size -= p[i].size;
            p[i].blockId = best;
            cout << "Process " << p[i].id << " of size " << p[i].size << " is allocated to memory block " << best << endl;
        } else {
            cout << "Process " << p[i].id << " of size " << p[i].size << " cannot be allocated" << endl;
        }
    }
}

int main(){
    int nb,np;

    cout << "Enter no. of blocks: ";
    cin >> nb;

    vector<MemBlock> b(nb);
    cout << "Enter size of each memory block: \n";
    for(int i=0; i<nb; i++){
        cout << "Memory " << i << ": ";
        cin >> b[i].size;
    }

    cout << "\nEnter no. of processes: ";
    cin >> np;

    vector<Process> p(np);
    cout << "Enter size of each process: \n";
    for(int i=0; i<np; i++){
        cout << "Process " << i+1 << ": ";
        cin >> p[i].size;
        p[i].id = i+1;
    }

    BestFit(b,p);

    return 0;
}
