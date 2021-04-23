#include <iostream> 
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

void heapify(float arr[], int n, int i)
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

void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Input(float arr[], int n)
{
    srand(time(NULL));
    float t = -10000.0 + rand() / (RAND_MAX / 200000.0);
    for (int i = 0; i < n; i++)
        arr[i] = t;
}

void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(2) << arr[i] << setw(12);
    cout << endl;
}

int main()
{
    int n = 5000;
    float* arr;
    arr = new float[n];
    Input(arr, n);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    delete[] arr;
    end = clock();
    cout << endl << ((double)(end - start)) / CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}