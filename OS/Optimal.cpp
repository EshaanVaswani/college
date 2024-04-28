#include<bits/stdc++.h>
using namespace std;

void printFrames(const vector<int>& frames) {
    for (int frame : frames) {
        cout << frame << " ";
    }
    cout << endl;
}

int optimal(vector<int>& pages, int nf) {
    vector<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        // Check if the page is already in the frames
        auto it = find(frames.begin(), frames.end(), page);
        if (it == frames.end()) { // Page fault
            pageFaults++;
            if (frames.size() < nf) {
                frames.push_back(page);
            } else {
                // Find the page to be replaced
                unordered_map<int, int> nextUse;
                for (int j = 0; j < frames.size(); j++) {
                    nextUse[frames[j]] = INT_MAX // Assume far future if not found again
                    for (int k = i + 1; k < pages.size(); k++) {
                        if (pages[k] == frames[j]) {
                            nextUse[frames[j]] = k;
                            break;
                        }
                    }
                }

                // Replace the page that will not be used for the longest time
                int farthest = i, indexToReplace = 0;
                for (int j = 0; j < frames.size(); j++) {
                    if (nextUse[frames[j]] > farthest) {
                        farthest = nextUse[frames[j]];
                        indexToReplace = j;
                    }
                }
                frames[indexToReplace] = page;
            }
            cout << "Page fault - ";
        } else {
            cout << "Page hit   - ";
        }
        printFrames(frames); // Print the current state of the frames
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
    int pageFaults = optimal(refS, nf);
    int pageHits = n - pageFaults;

    float hitR = (float)pageHits / (float)n;
    float missR = (float)pageFaults / (float)n;

    cout << "Page Hits = " << pageHits << endl;
    cout << "Page Faults = " << pageFaults << endl;
    cout << "Hit ratio = " << hitR << endl;
    cout << "Miss ratio = " << missR << endl;

    return 0;
}
