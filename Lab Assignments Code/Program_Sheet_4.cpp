#include <iostream>
#include <vector>
using namespace std;

// Question 1
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

void Question1() {
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


// Question 2
template <typename T> class Node {
public:
    T data;
    Node* next;

    Node(T data, Node* next = nullptr) : data(data), next(next) {}

    Node() {}

    ~Node() {
        delete next;
    }
};

template <typename T> class SingalyLinkedList : public Node<T>{
    private:
        Node<T>* head;

    public:
        SingalyLinkedList() : head(nullptr) {}

        // Inserting elements into the LinkedList
        void insertAtEnd(T new_data) {
            Node<T>* new_node = new Node<T>(new_data);
            if (head == nullptr) {
                head = new_node;
                return;
            }

            Node<T>* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }

            last->next = new_node;
        }

        // Displaying the elements from the LinkedList
        void display() {
            Node<T>* node = head;
            while (node != nullptr) {
                std::cout << "[" << node->data << "] "
                        << "[" << node << "]->" << node->next << std::endl; 
                node = node->next;
            }

            std::cout << std::endl << std::endl;
        }

        // Get head node
        Node<T>* getHeadPointer() {
            return head;
        }
};

void Question2() {
    int n;
    cout << "Enter the number of linked lists: ";
    cin >> n;

    // Initialization of the Linked Lists
    vector<SingalyLinkedList<int>> linkedList(n);
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter the number of elements in linked list " << i + 1 << ": ";
        cin >> num;
        for (int j = 0; j < num; j++) {
            int value;
            cin >> value;
            linkedList[i].insertAtEnd(value);
        }
        linkedList[i].display();
    }

    SingalyLinkedList<int> OutputLinkedList;
    vector<int> linkedListElements;
    for (int i = 0; i < n; i++) {
        Node<int>* node = linkedList[i].getHeadPointer();
        while (node != nullptr) {
            linkedListElements.push_back(node->data);
            node = node->next;
        }
    }

    quickSort(linkedListElements, 0, linkedListElements.size() - 1);
    for (unsigned int i = 0; i < linkedListElements.size(); i++) {
        OutputLinkedList.insertAtEnd(linkedListElements[i]);
    }
    OutputLinkedList.display();
}

int main() {
    // Question1();
    Question2();
}