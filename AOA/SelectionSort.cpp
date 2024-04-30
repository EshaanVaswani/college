#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& a){
    for(int i: a){
        cout << i << " ";
    }
}

void selectionSort(vector<int>& a){
    int n = a.size();
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min])
                min = j;
        }

        swap(a[min],a[i]);

        cout << "\npass " << i << ":";
        printArray(a);
    }
}

int main(){
    vector<int> a = {3,5,7,2,1,4};

    cout << "Original Array: \n";
    printArray(a);
    cout << endl;

    selectionSort(a);

    cout << "\n\nSorted Array: \n";
    printArray(a);

    return 0;
}
