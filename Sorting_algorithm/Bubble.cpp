#include <iostream>

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) { // Array notation works with pointers too
                std::swap(arr[j], arr[j + 1]); // Using std::swap
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    
    int* arr = new int[size];
    
    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    
    bubbleSort(arr, size);
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    
    delete[] arr; // Manual cleanup
    return 0;
}