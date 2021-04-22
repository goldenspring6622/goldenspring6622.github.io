#include <iostream> 
#include <cmath>
#include <ctime>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Input(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 2000010 - 900000;
}

void printArray(int arr[], int n)
{
    for (int i = n - 1; i >=0; i--)
        cout << arr[i] << "  ";
    cout << "\n";
}

int main()
{
    int n = pow(10, 6);
    srand(time(NULL));
    int* arr;
    arr = new int[n];
    Input(arr, n);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    delete[] arr;
    system("pause");
    return 0;
}

