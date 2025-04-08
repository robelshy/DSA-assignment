#include <iostream>
#include <memory> // for smart pointers
#include <utility> // for std::swap

// Function to partition the array using the last element as pivot
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Recursive quick sort function using pointers
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Wrapper function for quick sort
void quickSort(int* arr, int size) {
    quickSort(arr, 0, size - 1);
}

// Function to print an array
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::unique_ptr<int[]> arr(new int[size]);

    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    std::cout << "Original array: ";
    printArray(arr.get(), size);

    quickSort(arr.get(), size);

    std::cout << "Sorted array: ";
    printArray(arr.get(), size);

    return 0;
}