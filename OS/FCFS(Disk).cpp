#include<bits/stdc++.h>
using namespace std;

int fcfs(vector<int>& requests, int start){
    int total = 0;
    int current = start;

    cout << "Processing requests order: \n";
    for(int r: requests){
        total += abs(r - current);
        cout << r << " ";
        current = r;
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

    int total = fcfs(r,start);

    cout << "\nTotal Head Movement = " << total;

    return 0;
}
