#include<iostream>
#include <cmath>
#include<ctime>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
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
void Input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000001 - 10000;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int n = 50000;
    srand(time(NULL));
    int* arr;
    arr = new int[n];
    Input(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    delete[] arr;
    system("pause");
    return 0;
}