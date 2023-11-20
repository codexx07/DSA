#include <iostream>
#include <vector>
using namespace std;

//Merge Sort
void merge(vector<int> &arr, int start, int mid, int end) {
    int n1 = mid - start + 1, n2 = end - mid;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[start + i];
    }
    
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }
    
    int firstArray = 0, secondArray = 0, arrayTraverse = start;
    while (firstArray < n1 && secondArray < n2) {
        if (arr1[firstArray] < arr2[secondArray]) {
            arr[arrayTraverse++] = arr1[firstArray++];
        } else {
            arr[arrayTraverse++] = arr2[secondArray++];
        }
    }
    
    while (firstArray < n1) {
        arr[arrayTraverse++] = arr1[firstArray++];
    }

    while (secondArray < n2) {
        arr[arrayTraverse++] = arr2[secondArray++];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(arr, 0, arr.size() - 1);
    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
