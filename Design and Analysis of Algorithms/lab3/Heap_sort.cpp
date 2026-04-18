#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapSort(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapSort(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout <<"HeapSort_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], arr2[n];

    cout << "Enter elements:";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];   // copy original array
    }

    maxHeapSort(arr, n);
    minHeapSort(arr2, n);

    cout << "\nSorted array(Max Heap):";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nSorted array(Min Heap):";
    for(int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    return 0;
}

