int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 13;

    // Iterative Binary Search
    int resultIterative = binarySearchIterative(arr, n, key);
    if (resultIterative != -1) {
        cout << "Iterative Binary Search: Element found at index " << resultIterative << endl;
    } else {
        cout << "Iterative Binary Search: Element not found" << endl;
    }

    // Recursive Binary Search
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    if (resultRecursive != -1) {
        cout << "Recursive Binary Search: Element found at index " << resultRecursive << endl;
    } else {
        cout << "Recursive Binary Search: Element not found" << endl;
    }

    return 0;
}
