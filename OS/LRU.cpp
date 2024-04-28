#include<bits/stdc++.h>
using namespace std;

void printFrames(const list<int>& frames) {
    for (auto it = frames.begin(); it != frames.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int lru(vector<int>& pages, int nf){
    list<int> l;
    unordered_map<int,list<int>::iterator> m;
    int pageFaults = 0;

    for(auto p: pages){
        auto i = m.find(p);
        if(i == m.end()){
            pageFaults++;
            if(l.size() == nf){
                int lru = l.back();
                l.pop_back();
                m.erase(lru);
            }
            cout << "Page fault - ";
        } else {
            l.erase(i->second);
            cout << "Page hit   - ";
        }
        l.push_front(p);
        m[p] = l.begin();

        printFrames(l);
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
    int pageFaults = lru(refS, nf);
    int pageHits = n - pageFaults;

    float hitR = (float)pageHits / (float)n;
    float missR = (float)pageFaults / (float)n;

    cout << "Page Hits = " << pageHits << endl;
    cout << "Page Faults = " << pageFaults << endl;
    cout << "Hit ratio = " << hitR << endl;
    cout << "Miss ratio = " << missR << endl;

    return 0;
}
