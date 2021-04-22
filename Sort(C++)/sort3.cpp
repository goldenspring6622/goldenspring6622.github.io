#include <iostream> 
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

void Input(int arr[], int n)
{
    srand(time(NULL));
    int t = rand() % 2000010 - 900000;
    for (int i = 0; i < n; i++)
        arr[i] = t;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << "  ";
    cout << "\n";
}

int main()
{
    int n = pow(10, 6);
    int* arr = new int[n];

    Input(arr, n);
    sort(arr, arr + n);
    cout << "Sorted array is \n";
    printArray(arr, n);
    delete[] arr;
    system("pause");
}
