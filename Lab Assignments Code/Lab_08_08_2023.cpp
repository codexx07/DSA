#include <iostream>
using namespace std;

void Question1() {
    cout << "Question 1" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] > 80) {
            count++;
        }
    }
    cout << count << endl;
}

void Question2() {
    cout << "Question2" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int availableRooms[n];

    for (int i = 0; i < n; i++) {
        cin >> availableRooms[i];
    }

    int target;
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (availableRooms[i] == target) {
            cout << "Room Avilable" << endl; return;
        }
    }
    cout << "Room Not Avilable" << endl;
}

void Question3() {
    cout << "Question 3" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n]; 
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            continue;
        }

        if (arr[i] > max) {
            max = arr[i];
            continue;
        }
    }
    cout << "Minimum: " << min << "\n" << "Maximum: " << max << endl;
}

void Question4() {
    cout << "Question 4" << endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int bookIDs[size];
    for (int i = 0; i < size; i++) {
        cin >> bookIDs[i];
    }

    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (bookIDs[j] > bookIDs[j + 1]) {
                int temp = bookIDs[j];
                bookIDs[j] = bookIDs[j + 1];
                bookIDs[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < size; i++) {
        cout << bookIDs[i] << "     ";
    }
    cout << endl;


    int target, index = -1, min = 0, max = size;
    cin >> target;

    while (size > 0) {
        int mid = (min + max) / 2;
        if (bookIDs[mid] == target || size == 1) {
            index = mid; break;
        } else if (bookIDs[mid] > target) {
            max = mid; size /= 2;
        } else if (bookIDs[mid] < target) {
            min = mid; size /= 2;
        }
    }
}

int main() {
    Question1();
    Question2();
    Question3();
    Question4();
    return 0;
}