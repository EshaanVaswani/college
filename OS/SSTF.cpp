#include<bits/stdc++.h>
using namespace std;

int sstf(vector<int>& r, int start){
    int total = 0;
    int current = start;
    int n = r.size();
    vector<bool> v(n,false);

    cout << "Processing requests order: \n";
    for(int i=0; i<n; i++){
        int closest = INT_MAX;
        int id = -1;

        for(int j=0; j<n; j++){
            if(!v[j] && abs(current - r[j]) < closest){
                closest = abs(current - r[j]);
                id = j;
            }
        }

        if(id != -1){
            total += closest;
            cout << r[id] << " ";
            v[id] = true;
            current = r[id];
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

    int total = sstf(r,start);

    cout << "\nTotal Head Movement = " << total;

    return 0;
}
