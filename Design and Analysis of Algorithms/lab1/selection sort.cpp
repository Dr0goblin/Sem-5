#include <iostream>
using namespace std;

int main() {
    int n;
    long long steps = 0;
    
    cout <<"Selectionsort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            steps++;  // comparison
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            steps++;  // swap
        }
    }

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal number of steps: " << steps << endl;

    return 0;
}



