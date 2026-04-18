#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int steps = 0;   // changed from long long to int

void swap(int &a, int &b) {
    steps++;
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int A[], int l, int r) {
    int p = A[l];
    int x = l;
    int y = r + 1;

    while (true) {
        do {
            x++;
            steps++;
        } while (x <= r && A[x] <= p);

        do {
            y--;
            steps++;
        } while (A[y] > p);

        if (x >= y)
            break;

        swap(A[x], A[y]);
    }

    A[l] = A[y];
    A[y] = p;
    steps++;

    return y;
}

// Randomized partition
int random_partition(int A[], int l, int r) {
    int k = l + rand() % (r - l + 1);
    swap(A[l], A[k]);
    return partition(A, l, r);
}

// Randomized Quick Sort
void randomized_quicksort(int A[], int l, int r) {
    steps++;
    if (l < r) {
        int p = random_partition(A, l, r);
        randomized_quicksort(A, l, p - 1);
        randomized_quicksort(A, p + 1, r);
    }
}

int main() {
    srand(time(0));

    int n;
    cout <<"randomized_quicksort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[1000];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    randomized_quicksort(A, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << "\nTotal steps: " << steps << endl;

    return 0;
}

