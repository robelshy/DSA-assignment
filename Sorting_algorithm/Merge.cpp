#include <iostream>
#include <memory>

// Merge two sorted subarrays using pointers
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::unique_ptr<int[]> leftArr(new int[n1]);
    std::unique_ptr<int[]> rightArr(new int[n2]);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function using pointers
void mergeSort(int* arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Wrapper function for merge sort
void mergeSort(int* arr, int size) {
    mergeSort(arr, 0, size - 1);
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

    mergeSort(arr.get(), size);

    std::cout << "Sorted array: ";
    printArray(arr.get(), size);

    return 0;
}