#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std; 

void flip(vector<int>& arr, int i) {
    reverse(arr.begin(), arr.begin() + i + 1);
}

int findMaxIndex(vector<int>& arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIdx = findMaxIndex(arr, currSize);
        if (maxIdx != currSize - 1) {
            if (maxIdx != 0) {
                flip(arr, maxIdx);
                cout << "Переворот до " << maxIdx + 1 << ": ";
                for (int num : arr) cout << num << " ";
                cout << endl;
            }
            flip(arr, currSize - 1);
            cout << "Переворот до " << currSize << ": ";
            for (int num : arr) cout << num << " ";
            cout << endl;
        }
    }
}
 
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    vector<int> pancakes = {4, 1, 3, 2, 6, 5};
    
    cout << "Початковий стек оладок: ";
    for (int num : pancakes) cout << num << " ";
    cout << endl;
    
    pancakeSort(pancakes);
    
    cout << "Відсортований стек оладок: ";
    for (int num : pancakes) cout << num << " ";
    cout << endl;
    
    return 0; 
}
