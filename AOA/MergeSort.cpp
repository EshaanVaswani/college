#include<bits/stdc++.h>
using namespace std;

int c = 0;

void printArray(vector<int>& a){
    for(int i: a){
        cout << i << " ";
    }
}

void merge(vector<int>& a, int l, int m, int r){
    vector<int> L(a.begin()+l, a.begin()+m+1);
    vector<int> R(a.begin()+m+1, a.begin()+r+1);

    int i=0, j=0, k=l;

    while(i<L.size() && j<R.size()){
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i<L.size()){
        a[k++] = L[i++];
    }

    while(j<R.size()){
        a[k++] = R[j++];
    }
}

void mergeSort(vector<int>& a, int l, int r){
    if(l < r){
        c++;
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    vector<int> a = {3,5,7,2,1,4};

    cout << "Original Array: \n";
    printArray(a);
    cout << endl;

    mergeSort(a,0,a.size()-1);

    cout << "\nSorted Array: \n";
    printArray(a);

    cout << "\nMerge Sort Calls = " << c << endl;

    return 0;
}
