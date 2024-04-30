#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;

    Item(int v, int w): value(v), weight(w){}
};

int knapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    vector<int> selection(n, 0);

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i-1].weight <= w) {
                dp[i][w] = max(dp[i-1][w], items[i-1].value + dp[i-1][w - items[i-1].weight]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selection[i-1] = 1;
            w -= items[i-1].weight;
        }
    }

    cout << "Item selection vector: ";
    for (int isSelected : selection) {
        cout << isSelected << " ";
    }
    cout << endl;

    return dp[n][W];
}

int main(){
    int W = 8;
    vector<Item> items = {{1,2},{2,3},{5,4},{6,5}};

    int max = knapsack(W, items);
    cout << "\nTotal Knapsack Value = " << max;

    return 0;
}
