#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // key found
        }

        if (arr[mid] < key) {
            left = mid + 1;  // search right half
        } else {
            right = mid - 1; // search left half
        }
    }
    return -1;  // key not found
}
