#include<bits/stdc++.h>
using namespace std;

int totalCalls = 0;

void print2DBoard(const vector<int>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void print1DBoard(const vector<int>& board) {
    for (int i : board) {
        cout << i << " ";
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueen(vector<int>& board, int row) {
    totalCalls++;
    int N = board.size();
    if (row == N) {
        print1DBoard(board);
        print2DBoard(board);
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if(solveNQueen(board, row + 1)){
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    vector<int> board(N, -1);
    if (!solveNQueen(board, 0)) {
        cout << "No solution exists!" << endl;
    } else {
        cout << "Total recursive calls: " << totalCalls << endl;
    }
    return 0;
}
