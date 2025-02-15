#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std; 

void improvedBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    vector<int> arr = {5, 3, 8, 1, 2, 7, 6, 4};
    
    cout << "Масив перед сортуванням: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    improvedBubbleSort(arr);
    
    cout << "Масив після сортування: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0; 
}
