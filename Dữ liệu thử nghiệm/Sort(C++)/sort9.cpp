#include <iostream> 
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

void Input(float arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = -10000.0 + rand() / (RAND_MAX / 200000.0);
}

void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << "\n";
}

int main()
{
    int n = 5000;
    float* arr = new float[n];
    Input(arr, n);
    sort(arr, arr + n);
    cout << "Sorted array is \n";
    printArray(arr, n);
    delete[] arr;
    system("pause");
}
