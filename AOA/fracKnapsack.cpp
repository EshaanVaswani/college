#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;

    Item(int v, int w): value(v), weight(w){}
};

bool compare(Item a, Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1 > r2;
}

double fracKnapsack(int W, vector<Item>& items){
    sort(items.begin(), items.end(), compare);

    int current = 0;
    double finalValue = 0.0;

    for(auto& i: items){
        if(current + i.weight <= W){
            current += i.weight;
            finalValue += i.value;
            cout << "Added: " << i.weight << "kg for $" << i.value << endl;
        } else {
            int rem = W - current;
            int k = i.value * ((double)rem/i.weight);
            finalValue += k;
            cout << "Added: " << rem << "kg for $" << k << "(fractional)" << endl;
            break;
        }
    }

    return finalValue;
}

int main(){
    int W = 50;
    vector<Item> items = {{60,10},{100,20},{120,30}};

    double max = fracKnapsack(W, items);
    cout << "\nTotal Knapsack Value = " << max;

    return 0;
}
