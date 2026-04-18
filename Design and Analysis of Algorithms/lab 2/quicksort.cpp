#include <iostream>
using namespace std;

int A[100], n;
int steps = 0;   // counts passes + internal steps

int partition(int l, int r)
{
    int pivot = A[l];
    int x = l;
    int y = r;

    steps++;          // PASS counted (partition started)

    while (x < y)
    {
        while (A[x] <= pivot && x < r)
        {
            x++;
            steps++;  // comparison inside pass
        }

        while (A[y] > pivot)
        {
            y--;
            steps++;  // comparison inside pass
        }

        if (x < y)
        {
            swap(A[x], A[y]);
            steps++;  // swap step
        }
    }

    A[l] = A[y];
    A[y] = pivot;
    steps++;          // final pivot placement

    return y;
}

void quickSort(int l, int r)
{
    if (l < r)
    {
        int p = partition(l, r);
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}

int main()
{
    cout <<"quicksort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\nTotal steps : " << steps;

    return 0;
}

