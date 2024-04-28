#include<bits/stdc++.h>
using namespace std;

int clook(vector<int>& r, int start, char direction){
    int total = 0;

    r.push_back(start);

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
            auto jump = r.end()-1;
            cout << *jump << " ";
            total += abs(start - *r.rbegin());
            start = *jump;
            for(auto i=jump-1; i!=it; i--){
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
            auto jump = r.begin();
            cout << *jump << " ";
            total += abs(start - *r.begin());
            start = *jump;
            for(auto i=jump+1; i!=it; i++){
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

    int total = clook(r,start, 'l');

    cout << "\nTotal Head Movement = " << total;

    return 0;
}
