#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<int> array;
    for (int i = 0; i < 10; i++) {
        array[i] = i + 1;
    }

    int target = 3;
    cout << binarySearch(array, target);
}