#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    double value;
};

// Comparator function to sort by value/weight ratio (descending)
bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

int main() {
    int n;
    double W;
    
    cout <<"Zero_One_KnapSack_Basant_80117739"<<endl;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Sort items by value/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            // Take full item
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            // Take fractional part
            totalValue += items[i].value * (W / items[i].weight);
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum value that can be obtained = "
         << totalValue << endl;

    return 0;
}
