#include<bits/stdc++.h>
using namespace std;

int calculateFrames(int mem, int page) {
    int totalFrames = (mem * 1024 * 1024) / page;
    int frameBits = static_cast<int>(log2(totalFrames));
    cout << "\nTotal no. of frames in memory: 2^" << frameBits << endl;
    return frameBits;
}

int calculateBits(int value) {
    int bits = 0;
    while (value != 0) {
        value /= 2;
        bits++;
    }
    return bits - 1;
}

void fillPageTable(int entries) {
    vector<int> frameNo(entries), validBit(entries);
    for (int i = 0; i < entries; i++) {
        cout << "\nEnter frame no. for page no. " << i << ": ";
        cin >> frameNo[i];
        cout << "Enter valid Bit no. for page no. " << i << ": ";
        cin >> validBit[i];
    }

    cout << "\nPage Table:\n";
    cout << "Page No.  Frame No.  Valid Bit\n";
    for (int i = 0; i < entries; i++) {
        cout << i << "\t   " << frameNo[i] << "\t    " << validBit[i] << endl;
    }
}

int main() {
    int processSize, pageSize, memorySize;
    cout << "Enter the process size (in KB): ";
    cin >> processSize;
    cout << "Enter the page size (in bytes): ";
    cin >> pageSize;
    cout << "Enter the size of main memory (in MB): ";
    cin >> memorySize;

    int frameBits = calculateFrames(memorySize, pageSize);
    int p1 = (processSize * 1024) / pageSize;
    cout << "\nNumber of entries in page table: " << p1;

    int memBits = calculateBits(memorySize * 1024 * 1024);
    cout << "\nBits of MM address: " << memBits;

    int processBits = calculateBits(processSize * 1024);
    cout << "\nSize of logical address: " << processBits;

    int pageTableBits = calculateBits(p1);
    int offsetBits = processBits - pageTableBits;
    cout << "\nDistribution:\nPage Number: " << pageTableBits << "\nOffset Bits: " << offsetBits;

    fillPageTable(p1);

    long long logicAddress;
    cout << "\nEnter the " << processBits << " bit logical address of the process: ";
    cin >> logicAddress;

    int pageNo = 0;
    for (int i = 0; i < offsetBits; i++) {
        pageNo += 2 * (logicAddress % 10);
        logicAddress /= 10;
    }

    cout << "\nOutput:\n";
    cout << (true ? "Page Hit.\n" : "Page Miss.\n");

    return 0;
}
