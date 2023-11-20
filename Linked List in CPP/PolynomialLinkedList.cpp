#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        int exponent;
        Node* next;

        Node(int data, int exponent, Node* next = nullptr) : data(data), exponent(exponent), next(next) {}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void insert(int data, int exponent) {
        Node* newNode = new Node(data, exponent);
        if (head == nullptr || head->exponent < exponent) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->exponent > exponent) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        }

        LinkedList operator+ (LinkedList& other) {
            LinkedList result;
            Node* currentThis = head;
            Node* currentOther = other.head;

            while (currentThis != nullptr && currentOther != nullptr) {
                if (currentThis->exponent > currentOther->exponent) {
                    result.insert(currentThis->data, currentThis->exponent);
                    currentThis = currentThis->next;
                } else if (currentThis->exponent < currentOther->exponent) {
                    result.insert(currentOther->data, currentOther->exponent);
                    currentOther = currentOther->next;
                } else {
                    result.insert(currentThis->data + currentOther->data, currentThis->exponent);
                    currentThis = currentThis->next;
                    currentOther = currentOther->next;
                }
            }

            while (currentThis != nullptr) {
            result.insert(currentThis->data, currentThis->exponent);
            currentThis = currentThis->next;
            }

            while (currentOther != nullptr) {
                result.insert(currentOther->data, currentOther->exponent);
                currentOther = currentOther->next;
            }

            return result;
        }

        LinkedList operator- (LinkedList& other) {
            LinkedList result;
            Node* currentThis = head;
            Node* currentOther = other.head;

            while (currentThis != nullptr && currentOther != nullptr) {
                if (currentThis->exponent > currentOther->exponent) {
                    result.insert(currentThis->data, currentThis->exponent);
                    currentThis = currentThis->next;
                } else if (currentThis->exponent < currentOther->exponent) {
                    result.insert(-currentOther->data, currentOther->exponent);
                    currentOther = currentOther->next;
                } else {
                    result.insert(currentThis->data - currentOther->data, currentThis->exponent);
                    currentThis = currentThis->next;
                    currentOther = currentOther->next;
                }
            }

            while (currentThis != nullptr) {
            result.insert(currentThis->data, currentThis->exponent);
            currentThis = currentThis->next;
            }

            while (currentOther != nullptr) {
                result.insert(currentOther->data, currentOther->exponent);
                currentOther = currentOther->next;
            }

            return result;
        }

        LinkedList operator* (LinkedList& other) {
            LinkedList result;

            Node* currentThis = head;
            while (currentThis != nullptr) {
                Node* currentOther = other.head;
                while (currentOther != nullptr) {
                    int productData = currentThis->data * currentOther->data;
                    int productExponent = currentThis->exponent + currentOther->exponent;
                    result.insert(productData, productExponent);

                    currentOther = currentOther->next;
                }
                currentThis = currentThis->next;
            }

            return result;
        }


        void refactorPolynomial() {
            Node* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (current->exponent == current->next->exponent) {
                    current->data += current->next->data;
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                } else {
                    current = current->next;
                }
            }
        }

        void display() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << "x^" << current->exponent;
                if (current->next != nullptr)
                    cout << " + ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList poly1;
    LinkedList poly2;

    int n1, n2;
    cout << "Enter the number of elements in each polynomial: ";
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) {
        int data, expo;
        cout << "Enter coefficient " << i + 1 << " of polynomial 1: ";
        cin >> data;
        cout << "Enter exponent " << i + 1 << " of polynomial 1: ";
        cin >> expo;
        poly1.insert(data, expo);
    }

    for (int i = 0; i < n2; i++) {
        int data, expo;
        cout << "Enter coefficient " << i + 1 << " of polynomial 2: ";
        cin >> data;
        cout << "Enter exponent " << i + 1 << " of polynomial 2: ";
        cin >> expo;
        poly2.insert(data, expo);
    }

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    LinkedList sum = poly1 + poly2;
    cout << "Addition result: ";
    sum.display();

    LinkedList subtraction = poly1 - poly2;
    cout << "Addition result: ";
    subtraction.display();

    LinkedList product = poly1 * poly2;
    cout << "Multiplication result: ";
    product.refactorPolynomial();
    product.display();

    return 0;
}
