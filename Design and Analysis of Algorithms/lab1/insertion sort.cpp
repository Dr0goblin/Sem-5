#include <iostream>
using namespace std;

int main() {
    int a[50], n, count = 0;
    
    cout <<"InsertionSort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            count++;   // counting comparison
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else
                break;
        }
        a[j + 1] = key;
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal count: " << count;

    return 0;
}


