#include<bits/stdc++.h>
using namespace std;

int main() {
    int totalMemory, tempMemory, processMemory;
    vector<int> memoryPerProcess;
    char continueInput='y';
    int i = 0;

    cout << "\nEnter the total memory available (in Bytes)-- ";
    cin >> totalMemory;
    tempMemory = totalMemory;

    while (continueInput == 'y') {
        cout << "\nEnter memory required for process " << i + 1 << " (in Bytes) -- ";
        cin >> processMemory;

        if (processMemory <= tempMemory) {
            cout << "\nMemory is allocated for Process " << i + 1;
            tempMemory -= processMemory;
            memoryPerProcess.push_back(processMemory);
        } else {
            cout << "\nMemory is Full";
            break;
        }

        cout << "\nDo you want to continue (y/n) -- ";
        cin >> continueInput;

        i++;
    }

    cout << "\n\nTotal Memory Available -- " << totalMemory;
    cout << "\n\n\tPROCESS\t\t MEMORY ALLOCATED";
    for (int j = 0; j < memoryPerProcess.size(); j++) {
        cout << "\n \t" << j + 1 << "\t\t" << memoryPerProcess[j];
    }

    cout << "\n\nTotal Memory Allocated is " << totalMemory - tempMemory;
    cout << "\nTotal External Fragmentation is " << tempMemory;

    return 0;
}
