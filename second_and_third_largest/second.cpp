#include <iostream>
using namespace std;

void findSecondAndThirdLargest(int arr[], int n) {
    if (n < 3) {
        cout << "Array is too small to find second and third largest elements." << endl;
        return;
    }

    int largest = arr[0];
    int secondLargest = -1;
    int thirdLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        }
        else if (arr[i] > thirdLargest && arr[i] != secondLargest && arr[i] != largest) {
            thirdLargest = arr[i];
        }
    }

    if (secondLargest == -1) {
        cout << "No second largest element found." << endl;
    } else {
        cout << "Second largest element: " << secondLargest << endl;
    }

    if (thirdLargest == -1) {
        cout << "No third largest element found." << endl;
    } else {
        cout << "Third largest element: " << thirdLargest << endl;
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecondAndThirdLargest(arr, n);

    return 0;
}