#include<bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& available, const vector<vector<int>>& allocation, const vector<vector<int>>& need, int p, int r, vector<int>& safeSequence) {
    vector<bool> finish(p, false);
    vector<int> work = available;
    int count = 0;

    while (count < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == r) {
                    for (int k = 0; k < r; k++)
                        work[k] += allocation[i][k];

                    finish[i] = true;
                    found = true;
                    safeSequence.push_back(i);
                    count++;
                }
            }
        }

        if (!found) {
            return false;
        }
    }
    return true;
}

bool requestResources(const vector<int>& request, int processId, vector<int>& available, vector<vector<int>>& allocation, vector<vector<int>>& need, int p, int r) {
    for (int i = 0; i < r; i++) {
        if (request[i] > need[processId][i]) {
            cout << "Error: Process has exceeded its maximum claim." << endl;
            return false;
        }
        if (request[i] > available[i]) {
            cout << "Error: Resources not available." << endl;
            return false;
        }
    }

    vector<int> oldAvailable = available;
    vector<int> safeSequence;
    for (int i = 0; i < r; i++) {
        available[i] -= request[i];
        allocation[processId][i] += request[i];
        need[processId][i] -= request[i];
    }

    if (isSafe(available, allocation, need, p, r, safeSequence)) {
        cout << "Request can be granted. System is in a safe state." << endl;
        cout << "Safe Sequence: ";
        for (int i : safeSequence) {
            cout << "P" << i << " ";
        }
        cout << endl;
        return true;
    } else {
        for (int i = 0; i < r; i++) {
            available[i] = oldAvailable[i];
            allocation[processId][i] -= request[i];
            need[processId][i] += request[i];
        }
        cout << "Request cannot be granted. System would be unsafe." << endl;
        return false;
    }
}

int main() {
    int p = 5, r = 3;
    vector<int> available = {10, 5, 7};

    vector<vector<int>> maxDemand = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> need(p, vector<int>(r));

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = maxDemand[i][j] - allocation[i][j];
        }
    }

    int processId = 1;
    vector<int> request = {1, 0, 2};

    cout << "Process " << processId << " requesting resources: ";
    for (int elem : request) {
        cout << elem << " ";
    }
    cout << endl;

    requestResources(request, processId, available, allocation, need, p, r);

    return 0;
}
