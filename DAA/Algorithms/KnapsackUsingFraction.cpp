#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareItems(pair<int, int> a, pair<int, int> b) {
    return (static_cast<double>(a.second) / a.first) > (static_cast<double>(b.second) / b.first);
}

double fractionalKnapsack(int capacity, vector<pair<int, int>>& items) {
    sort(items.begin(), items.end(), compareItems);

    double maxTotalValue = 0.0;
    int currentWeight = 0;

    for (const pair<int, int>& item : items) {
        if (currentWeight + item.first <= capacity) {
            // Take the whole item.
            currentWeight += item.first;
            maxTotalValue += item.second;
        } else {
            // Take a fraction of the item to fill the capacity.
            double remainingCapacity = capacity - currentWeight;
            maxTotalValue += (static_cast<double>(item.second) / item.first) * remainingCapacity;
            break;
        }
    }

    return maxTotalValue;
}

int main() {
    vector<pair<int, int>> items = {{3, 20}, {2, 15}, {1, 10},{2,30},{4,40}};
    int capacity = 8;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
