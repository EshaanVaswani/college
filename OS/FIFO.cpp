#include<bits/stdc++.h>
using namespace std;

void printFrames(const vector<int>& frames) {
    for (int frame : frames) {
        cout << frame << " ";
    }
    cout << endl;
}

int fifo(vector<int>& pages, int nf){
    queue<int> q;
    vector<int> f;
    int pageFaults = 0;

    for(auto p: pages){
        auto i = find(f.begin(), f.end(), p);
        if(i == f.end()){
            pageFaults++;
            if(f.size() < nf){
                f.push_back(p);
                q.push(p);
            } else {
                int pageToReplace = q.front();
                q.pop();
                auto replaceIt = find(f.begin(), f.end(), pageToReplace);
                if (replaceIt != f.end()) {
                    *replaceIt = p;
                }
                q.push(p);
            }
            cout << "Page fault - ";
        } else {
            cout << "Page hit   - ";
        }
        printFrames(f);
    }
    return pageFaults;
}

int main(){
    int np, nf;

    cout << "Enter number of pages: ";
    cin >> np;

    vector<int> refS(np);

    cout << "Enter reference string: ";
    for(int i=0; i<np; i++){
        cin >> refS[i];
    }

    cout << "Enter number of frames: ";
    cin >> nf;

    int n = refS.size();
    int pageFaults = fifo(refS, nf);
    int pageHits = n - pageFaults;

    float hitR = (float)pageHits / (float)n;
    float missR = (float)pageFaults / (float)n;

    cout << "Page Hits = " << pageHits << endl;
    cout << "Page Faults = " << pageFaults << endl;
    cout << "Hit ratio = " << hitR << endl;
    cout << "Miss ratio = " << missR << endl;

    return 0;
}
