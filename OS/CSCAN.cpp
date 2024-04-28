#include<bits/stdc++.h>
using namespace std;

int cscan(vector<int>& r, int start, char direction, int diskSize){
    int total = 0;

    r.push_back(start);
    r.push_back(0);
    r.push_back(diskSize-1);

    sort(r.begin(), r.end());

    cout << "Processing requests order: \n";

    auto it = find(r.begin(), r.end(), start);
    if(direction == 'l'){
        for(auto i=it; i!=r.begin()-1; i--){
            cout << *i << " ";
            total += abs(start - *i);
            start = *i;
        }

        if(it != r.end()-1) {
            total += abs(start - 0);
            total += diskSize - 1;
            start = diskSize - 1;
            for(auto i=r.end()-1; i!=it; i--){
                cout << *i << " ";
                total += abs(start - *i);
                start = *i;
            }
        }
    } else if(direction == 'r') {
        for(auto i=it; i!=r.end(); i++){
            cout << *i << " ";
            total += abs(start - *i);
            start = *i;
        }

        if(it != r.begin()){
            total += abs(start - diskSize + 1);
            total += diskSize - 1;
            start = 0;
            for(auto i=r.begin(); i!=it; i++){
                cout << *i << " ";
                total += abs(start - *i);
                start = *i;
            }
        }
    }

    return total;
}

int main(){
    int start;
    cout << "Enter number of requests:";
    cin >> n;

    //vector<int> r = {96, 185, 35, 122, 16, 120, 55, 57};
    cout << "Enter sequence of requests: \n";
    for(int i=0; i<n; i++){
        cin >> r[i];
    }

    cout << "Enter initial position: ";
    cin >> start;

    int total = cscan(r,start, 'l', 200);

    cout << "\nTotal Head Movement = " << total;

    return 0;
}
