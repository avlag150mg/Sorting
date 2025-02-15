#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std; 

double calculateAverage(const vector<int>& arr) {
    double sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum / arr.size();
}

void partialSort(vector<int>& arr, int start, int end) {
    sort(arr.begin() + start, arr.begin() + end);
}

void reversePart(vector<int>& arr, int start, int end) {
    reverse(arr.begin() + start, arr.begin() + end);
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    vector<int> arr = {3, -1, 4, 1, 5, 9, -2, -6, 7, 8, -5, 2};
    int n = arr.size();
    double avg = calculateAverage(arr);

    if (avg > 0) {
        partialSort(arr, 0, (2 * n) / 3);
    } else {
        partialSort(arr, 0, n / 3);
    }
    
    reversePart(arr, (2 * n) / 3, n);
    
    cout << "Модифікований масив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0; 
}
