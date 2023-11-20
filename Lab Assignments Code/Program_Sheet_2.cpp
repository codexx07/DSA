#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort (vector<int> arr) {
    int size = arr.size();
    int min_index = 0;

    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }

    cout << endl;
    return arr;
}

int binarySearch (vector<int> array, int target) {
    int size = array.size();
    int min = 0, max = size;
    while (size >= 0) {
        int mid = (min + max) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            min = mid; 
            size /= 2;
        } else if (array[mid] > target) {
            max = mid; 
            size /= 2;
        }
    }
    return -1;
}

void Question1 () {
    vector<int> arr;
    int i = 0;

    while (true) {
        cin >> i;
        arr.push_back(i);
        cout << "Do you want to continue? <1 - yes/ 0 - no>" << endl;
        cin >> i;
        if (i == 0) break;
    }

    int target;
    cout << "Enter the element to search for: " << endl;
    cin >> target;

    int index = binarySearch(selectionSort(arr), target);
    if (index == -1) {
        cout << "No element found";
        return;
    }
    cout << "Element found at index: " << index;
}

void Question2 () {
    vector<int> arr;
    int i = 0;

    while (true) {
        cin >> i;
        arr.push_back(i);
        cout << "Do you want to continue? <1 - yes/ 0 - no>" << endl;
        cin >> i;
        if (i == 0) break;
    }

    int target;
    cout << "Enter the element to search for: " << endl;
    cin >> target;

    int index = binarySearch(selectionSort(arr), target);
    if (index == -1) {
        cout << target << " not found";
        return;
    }
    cout << target << " found at index: " << index;
}

void Question3() {
    vector<int> arr;
    int i = 0;

    while (true) {
        cin >> i;
        arr.push_back(i);
        cout << "Do you want to continue? <1 - yes/ 0 - no>" << endl;
        cin >> i;
        if (i == 0) break;
    }

    int target;
    cout << "Enter the element to search for: " << endl;
    cin >> target;

    int index = binarySearch(selectionSort(arr), target);
    if (index == -1) {
        cout << "No element found";
        return;
    }
    cout << "Element found at index: " << index;
}

int main() {
    // Question1();
    // Question2();
    Question3();
}