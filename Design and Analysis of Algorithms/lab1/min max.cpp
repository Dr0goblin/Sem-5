#include <iostream>
using namespace std;

int main() {
    int a[50], n, counts = 0, swp = 0;
    int start = 0;
    
    cout <<"MinmaxSearch_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int end = n - 1;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (start < end) {
        int min = start, max = start;

        for (int i = start; i <= end; i++) {
            counts++;   // comparison for minimum
            if (a[i] < a[min])
                min = i;

            counts++;   // comparison for maximum
            if (a[i] > a[max])
                max = i;
        }

        swap(a[start], a[min]);
        swp++;

        if (max == start)
            max = min;

        swap(a[end], a[max]);
        swp++;

        start++;
        end--;
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal counts: " << counts;
    cout << "\nSwaps: " << swp;

    return 0;
}

