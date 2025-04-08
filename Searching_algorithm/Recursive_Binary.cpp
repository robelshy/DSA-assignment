// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // key found
        }

        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key);  // search right half
        } else {
            return binarySearchRecursive(arr, left, mid - 1, key);   // search left half
        }
    }
    return -1;  // key not found
}
