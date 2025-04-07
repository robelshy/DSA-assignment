#include <iostream>
using namespace std;

int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return smallest;
}

int main() {
    int arr[] = {34, 15, 88, 2, 51, 100, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int smallest = findSmallest(arr, size);

    cout << "The smallest number in the array is: " << smallest << endl;
    return 0;
}