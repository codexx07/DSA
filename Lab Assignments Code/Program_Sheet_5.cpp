#include <iostream>
#include <vector>
using namespace std;

// Question 1

int binarySearchQuestion1(vector<int> arr, int target) {
    int min = 0, max = arr.size();
    while(min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            min = mid + 1;
        } else if (arr[mid] > target) {
            max = mid - 1;
        }
    }
    return -1;
}

int Question1() {
    int m = 5, n = 4;
    vector<vector<int>> matrix = {{10, 26, 55, 90}, {12, 34, 63, 110}, {17, 39, 78, 154}, {19, 47, 81, 179}, {22, 49, 88, 199}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        if (binarySearchQuestion1(matrix[i], 179) != -1) {
            cout << "Found";
            return 0;
        }
    }
    cout << "Not Found";
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Question 2

void Question2() {
    vector<int> arr = {15, 2, 9, 17, 24, 1, 18, 11, 3};
    
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }

    int mid = arr.size() / 2;
    for (int i = 0; i < ((mid + arr.size()) / 2) - mid; i++) {
        swap(arr[mid + i], arr[arr.size() - 1 - i]);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Question 4

// QuickSort function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];   // End element is selected as pivot element
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

// Fibonacci Series
vector<int> fibbonacciSeries(int max) {
    vector<int> result = {1};
    int n0 = 0, n1 = 1;
    while(n0 < max) {
        int nth = n0 + n1;
        result.push_back(nth);
        n0 = n1;
        n1 = nth;
    }
    return result;
}

int inFib(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return 1;
    }
    return 0;
}

void Question4() {
    vector<int> arr = {87, 23, 56, 91, 42, 18, 70, 65, 33, 79};
                    //  1   2   3   4   5   6   7   8   9  10;
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) max = arr[i];
    }

    vector<int> fibbonacci = fibbonacciSeries(max);
    vector<int> result(arr.size());
    int start = 0, end = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++) {
        if (inFib(fibbonacci, i + 1) == 1) {
            result[start++] = arr[i];
        } else {
            result[end--] = arr[i];
        }
    }

    quickSort(result, 0, start);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Question 5
int FIXIT2(int p) {
    int h = 0;
    while(p != 0) {
        p = p / 2;
        int q = p % 10;
        h += q;
    }
    return h;
}

void FIXIT1(vector<int> arr) {
    int n = arr.size();
    int l = n % 2;
    for(int k = 1; k < n; k++) {
        int f = FIXIT2(arr[k]);
        if (f % 2 != 0) l+= f;
        else l-= f;
    }
    cout << l << endl;
}

void Question5() {
    vector<int> arr = {1029, 1567, 33789, 44444};
    FIXIT1(arr);
    return;
}

int main() {
    // Question1();
    // Question2();
    // Question4();
    Question5();
}