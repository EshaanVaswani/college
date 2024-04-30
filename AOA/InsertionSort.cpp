#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& a){
    for(int i: a){
        cout << i << " ";
    }
}

void insertionSort(vector<int>& a){
    int n = a.size();
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;

        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;

        cout << "\npass " << i << ":";
        printArray(a);
    }
}

int main(){
    vector<int> a = {3,5,7,2,1,4};

    cout << "Original Array: \n";
    printArray(a);
    cout << endl;

    insertionSort(a);

    cout << "\n\nSorted Array: \n";
    printArray(a);

    return 0;
}
