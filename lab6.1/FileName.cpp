﻿
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

void processArray(int arr[], int size, int& count, int& sum, int i = 0) {
    if (i >= size) return;
    if (arr[i] > 0 || arr[i] % 2 != 0) {
        count++;
        sum += arr[i];
        arr[i] = 0;  
    }
    processArray(arr, size, count, sum, i + 1);
}

int main() {
    const int SIZE = 27;
    int arr[SIZE], count = 0, sum = 0;
    int Low = -35, High = 25;

    srand(time(0)); 

   
    Create(arr, SIZE, Low, High);

   
    cout << "Start massive ";
    printArray(arr, SIZE);

    
    processArray(arr, SIZE, count, sum);

    
    cout << "Elements " << count << endl;
    cout << "Sum of elements " << sum << endl;

    cout << "New massive ";
    printArray(arr, SIZE);

    return 0;
}
