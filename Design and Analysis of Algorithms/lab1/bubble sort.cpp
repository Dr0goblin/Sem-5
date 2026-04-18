#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    cout <<"BubbleSort_Basant_80117739"<<endl;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];
    int i, j;
    
    cout << "Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> array[i];
    }

    int pass = 0;

    // Bubble sort with n passes
    for (i = 0; i < n; i++) {
        pass++;   // count every pass
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }

    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << "\nTotal number of passes: " << pass;

    return 0;
}

