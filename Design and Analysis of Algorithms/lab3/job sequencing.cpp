#include <iostream>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

void sortJobs(Job arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].profit < arr[j].profit)
            {
                Job temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout <<"JobSequencing_Basant_80117739"<<endl;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job arr[n];

    cout << "Enter job id, deadline and profit:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    sortJobs(arr, n);

    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }

    char slot[maxDeadline];
    for(int i = 0; i < maxDeadline; i++)
        slot[i] = '-';

    int totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = arr[i].deadline - 1; j >= 0; j--)
        {
            if(slot[j] == '-')
            {
                slot[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";
    for(int i = 0; i < maxDeadline; i++)
    {
        if(slot[i] != '-')
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit = " << totalProfit;

    return 0;
}

