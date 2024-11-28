#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double valueDensity;
};

bool compare(Item a, Item b) {
    return a.valueDensity > b.valueDensity;
}

int main() {
    int W = 20;
    Item items[] = {
        {3, 10}, {5, 20}, {5, 21}, {8, 30}, {4, 16}
    };

    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].valueDensity = (double)items[i].value / items[i].weight;
    }

    sort(items, items + n, compare);


    double maxValue = 0;
    int currentWeight = 0;

    cout << "\nSelected items:\n";

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
           
        } else {
            int remainingWeight = W - currentWeight;
            maxValue += items[i].valueDensity * remainingWeight;
            break;
        }
    }

    cout << "\nTotal value in the knapsack = " << maxValue << endl;

    return 0;
}
