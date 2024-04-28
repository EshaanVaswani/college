#include<bits/stdc++.h>
using namespace std;

struct MemBlock {
    int size;
};

struct Process {
    int size,id,blockId;
};

void WorstFit(vector<MemBlock>& m, vector<Process>& p){
    for(int i=0; i<p.size(); i++){
        p[i].blockId = -1;
        int worst = -1;

        for(int j=0; j<m.size(); j++){
            if(m[j].size >= p[i].size){
                if(worst == -1)
                    worst = j;
                else if(m[worst].size < m[j].size)
                    worst = j;

            }
        }

        if(worst != -1){
            m[worst].size -= p[i].size;
            p[i].blockId = worst;
            cout << "Process " << p[i].id << " of size " << p[i].size << " is allocated to memory block " << worst << endl;
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

    WorstFit(b,p);

    return 0;
}
