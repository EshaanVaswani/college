#include<bits/stdc++.h>
using namespace std;

int main() {
    int totalMemory, blockSize, numberOfBlocks, externalFragmentation, numberOfProcesses;
    vector<int> memoryPerProcess;
    int totalInternalFragmentation = 0;
    int allocatedBlocks = 0;

    cout << "Enter the total memory available (in Bytes) -- ";
    cin >> totalMemory;
    cout << "Enter the block size (in Bytes) -- ";
    cin >> blockSize;

    numberOfBlocks = totalMemory / blockSize;
    externalFragmentation = totalMemory - numberOfBlocks * blockSize;

    cout << "\nEnter the number of processes -- ";
    cin >> numberOfProcesses;
    memoryPerProcess.resize(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++) {
        cout << "Enter memory required for process " << i + 1 << " (in Bytes)-- ";
        cin >> memoryPerProcess[i];
    }

    cout << "\nNo. of Blocks available in memory -- " << numberOfBlocks;
    cout << "\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION";
    for (int i = 0; i < numberOfProcesses && allocatedBlocks < numberOfBlocks; i++) {
        cout << "\n " << i + 1 << "\t\t" << memoryPerProcess[i];
        if (memoryPerProcess[i] > blockSize) {
            cout << "\t\tNO\t\t---";
        } else {
            cout << "\t\tYES\t" << blockSize - memoryPerProcess[i];
            totalInternalFragmentation += blockSize - memoryPerProcess[i];
            allocatedBlocks++;
        }
    }

    if (allocatedBlocks < numberOfProcesses) {
        cout << "\nMemory is Full, Remaining Processes cannot be accommodated";
    }

    cout << "\n\nTotal Internal Fragmentation is " << totalInternalFragmentation;
    cout << "\nTotal External Fragmentation is " << externalFragmentation;
    return 0;
}
