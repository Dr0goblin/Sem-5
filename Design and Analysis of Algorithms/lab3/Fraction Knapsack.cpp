#include <iostream>
using namespace std;

struct Item
{
    int weight;
    int profit;
    float ratio;
};

void sortItems(Item arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].ratio < arr[j].ratio)
            {
                Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;
    
    cout <<"FractionKnapSack_Basant_80117739"<<endl;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[n];

    // Input Weights
    cout << "Enter weights (Wi):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].weight;
    }

    // Input Profits
    cout << "Enter profits (Vi):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].profit;
    }

    // Calculate ratio
    for(int i = 0; i < n; i++)
    {
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sortItems(arr, n);

    float totalProfit = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(capacity >= arr[i].weight)
        {
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        }
        else
        {
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}

