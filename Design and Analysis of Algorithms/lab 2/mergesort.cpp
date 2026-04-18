#include <iostream>
using namespace std;

int A[100], B[100], n;
int steps = 0;   // counts only comparisons and recursive calls

void merge(int l, int m, int r)
{
    int x = l;
    int y = m + 1;
    int k = l;

    while (x <= m && y <= r)
    {
        steps++;            // element comparison
        if (A[x] <= A[y])
        {
            B[k] = A[x];
            x++;
        }
        else
        {
            B[k] = A[y];
            y++;
        }
        k++;
    }

    while (x <= m)
    {
        B[k] = A[x];
        x++;
        k++;
    }

    while (y <= r)
    {
        B[k] = A[y];
        y++;
        k++;
    }

    for (int i = l; i <= r; i++)
        A[i] = B[i];
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        steps++;            // recursive division
        int m = (l + r) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    cout <<"Mergesort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    mergeSort(0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\nTotal steps: " << steps;

    return 0;
}

