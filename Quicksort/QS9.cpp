#include<iostream>
#include <cmath>
#include<ctime>
#include<iomanip>
using namespace std;

float partition(float arr[], int low, int high)
{
    float pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && arr[left] < pivot) left++;
        while (right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void Input(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = -10000.0 + rand() / (RAND_MAX / 20000.0);
}
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        float pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(2) << arr[i] << setw(12);
    cout << endl;
}

float main()
{
    int n = 1000;
    srand(time(NULL));
    float* arr;
    arr = new float[n];
    Input(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    delete[] arr;
    system("pause");
    return 0;
}