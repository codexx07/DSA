#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) { //Finding the max element in the array
        if (arr[i] > max) max = arr[i];
    }

    vector<int> count(max + 1);
    for (int i = 0; i < size; i++) { //Getting Count Array
        count[arr[i]]++;
    }

    for (int i = 1; i < max + 1; i++) { //Getting Position Array
        count[i] += count[i - 1];
    }

    vector<int> output(size);
    for (int i = size - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    countSort(arr, arr.size());

    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}
