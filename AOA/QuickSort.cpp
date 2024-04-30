#include<bits/stdc++.h>
using namespace std;

int c = 0;

void printArray(vector<int>& a){
    for(int i: a){
        cout << i << " ";
    }
}

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(vector<int>& a, int low, int high){
    if(low < high){
        c++;
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    vector<int> a = {3,5,7,2,1,4};

    cout << "Original Array: \n";
    printArray(a);
    cout << endl;

    quickSort(a,0,a.size()-1);

    cout << "\nSorted Array: \n";
    printArray(a);

    cout << "\nQuick Sort Calls = " << c << endl;

    return 0;
}
