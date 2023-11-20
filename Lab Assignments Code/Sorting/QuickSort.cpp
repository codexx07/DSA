#include <iostream>
#include <vector>
using namespace std;

// QuickSort function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end]; // End element is selected as pivot element
    int leftOfPivot = start - 1;
    for (int rightOfPivot = start; rightOfPivot < end; rightOfPivot++) {
        if (arr[rightOfPivot] < pivot) {
            leftOfPivot++;
            swap(arr[rightOfPivot], arr[leftOfPivot]);
        }
    }

    swap(arr[leftOfPivot + 1], arr[end]);
    return leftOfPivot + 1;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void QuickSort() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, arr.size() - 1);

    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    QuickSort();
}