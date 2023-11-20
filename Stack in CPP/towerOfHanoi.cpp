#include <iostream>
#include <stack>

void moveDisk(char source, char destination, int disk) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        moveDisk(source, destination, 1);
        return;
    }

    std::stack<int> stackSource, stackAuxiliary, stackDestination;

    // Push disks onto source stack
    for (int i = numDisks; i >= 1; --i)
        stackSource.push(i);

    char temp;
    if (numDisks % 2 == 0)
        temp = auxiliary;
    else
        temp = destination;

    int totalMoves = (1 << numDisks) - 1;

    for (int move = 1; move <= totalMoves; ++move) {
        if (move % 3 == 1) {
            if (!stackSource.empty() && (stackAuxiliary.empty() || stackSource.top() < stackAuxiliary.top())) {
                moveDisk(source, temp, stackSource.top());
                stackAuxiliary.push(stackSource.top());
                stackSource.pop();
            } else {
                moveDisk(temp, source, stackAuxiliary.top());
                stackSource.push(stackAuxiliary.top());
                stackAuxiliary.pop();
            }
        } else if (move % 3 == 2) {
            if (!stackSource.empty() && (stackDestination.empty() || stackSource.top() < stackDestination.top())) {
                moveDisk(source, destination, stackSource.top());
                stackDestination.push(stackSource.top());
                stackSource.pop();
            } else {
                moveDisk(destination, source, stackDestination.top());
                stackSource.push(stackDestination.top());
                stackDestination.pop();
            }
        } else if (move % 3 == 0) {
            if (!stackAuxiliary.empty() && (stackDestination.empty() || stackAuxiliary.top() < stackDestination.top())) {
                moveDisk(temp, destination, stackAuxiliary.top());
                stackDestination.push(stackAuxiliary.top());
                stackAuxiliary.pop();
            } else {
                moveDisk(destination, temp, stackDestination.top());
                stackAuxiliary.push(stackDestination.top());
                stackDestination.pop();
            }
        }
    }
}

int main() {
    int numDisks = 3; // Number of disks
    char source = 'A', auxiliary = 'B', destination = 'C'; // Tower labels

    std::cout << "Tower of Hanoi with " << numDisks << " disks:" << std::endl;
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
